#include <android/log.h>
#include <atomic>

#define LOG_TAG "UniversalVR-GTAG"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

struct ModInfo
{
    const char* id;
    const char* version;
};

namespace UniversalVR
{
    static std::atomic<bool> enabled{true};
    static std::atomic<float> reachScale{1.25f};

    static float originalMaxArmLength = 0.0f;
    static bool originalValueCaptured = false;

    float ClampReachScale(float value)
    {
        if (value < 1.0f)
            return 1.0f;

        if (value > 2.0f)
            return 2.0f;

        return value;
    }

    void SetReachScale(float value)
    {
        value = ClampReachScale(value);

        reachScale.store(value);

        LOGI(
            "UniversalVR Reach Scale changed to %.2fx",
            value
        );
    }

    void SetEnabled(bool value)
    {
        enabled.store(value);

        LOGI(
            "UniversalVR Long Arms: %s",
            value ? "ON" : "OFF"
        );
    }

    void CaptureOriginalArmLength(float value)
    {
        if (!originalValueCaptured)
        {
            originalMaxArmLength = value;
            originalValueCaptured = true;

            LOGI(
                "Original Gorilla Tag maxArmLength captured: %.3f",
                value
            );
        }
    }

    float GetDesiredArmLength()
    {
        if (!originalValueCaptured)
            return 0.0f;

        if (!enabled.load())
            return originalMaxArmLength;

        return originalMaxArmLength * reachScale.load();
    }

    float RestoreOriginalArmLength()
    {
        if (!originalValueCaptured)
            return 0.0f;

        return originalMaxArmLength;
    }

    void Reset()
    {
        reachScale.store(1.0f);

        LOGI("UniversalVR reach reset to 1.00x.");
    }
}

extern "C"
__attribute__((visibility("default")))
void setup(ModInfo& info)
{
    info.id = "universalvr-gtag";
    info.version = "0.3.0";

    LOGI("UniversalVR Gorilla Tag adapter v0.3 setup.");
}

extern "C"
__attribute__((visibility("default")))
void load()
{
    LOGI("UniversalVR Gorilla Tag adapter v0.3 loaded.");

    UniversalVR::SetEnabled(true);
    UniversalVR::SetReachScale(1.25f);

    /*
        NEXT CONNECTION:

        Once GTPlayer is resolved:

        float current =
            GTPlayer.maxArmLength;

        UniversalVR::CaptureOriginalArmLength(current);

        GTPlayer.maxArmLength =
            UniversalVR::GetDesiredArmLength();


        When disabled:

        GTPlayer.maxArmLength =
            UniversalVR::RestoreOriginalArmLength();


        IMPORTANT:

        Do not change the Quest Guardian / physical boundary.

        This only changes Gorilla Tag's own locomotion
        arm-distance clamp.
    */
}

extern "C"
__attribute__((visibility("default")))
void late_load()
{
    LOGI("UniversalVR Gorilla Tag adapter v0.3 late_load.");
}
