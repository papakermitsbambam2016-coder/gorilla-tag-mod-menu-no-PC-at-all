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

struct Vector3
{
    float x;
    float y;
    float z;

    Vector3 operator-(const Vector3& other) const
    {
        return {
            x - other.x,
            y - other.y,
            z - other.z
        };
    }

    Vector3 operator+(const Vector3& other) const
    {
        return {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }

    Vector3 operator*(float scale) const
    {
        return {
            x * scale,
            y * scale,
            z * scale
        };
    }
};

namespace UniversalVR
{
    static std::atomic<bool> enabled { true };

    static std::atomic<float> leftArmScale  { 1.25f };
    static std::atomic<float> rightArmScale { 1.25f };

    Vector3 CalculateLongArmPosition(
        const Vector3& headPosition,
        const Vector3& trackedHandPosition,
        float scale)
    {
        Vector3 offset =
            trackedHandPosition - headPosition;

        return headPosition + offset * scale;
    }

    void SetEnabled(bool value)
    {
        enabled.store(value);
    }

    void SetArmScale(float scale)
    {
        if (scale < 1.0f)
            scale = 1.0f;

        if (scale > 3.0f)
            scale = 3.0f;

        leftArmScale.store(scale);
        rightArmScale.store(scale);
    }

    void SetLeftArmScale(float scale)
    {
        if (scale < 1.0f)
            scale = 1.0f;

        if (scale > 3.0f)
            scale = 3.0f;

        leftArmScale.store(scale);
    }

    void SetRightArmScale(float scale)
    {
        if (scale < 1.0f)
            scale = 1.0f;

        if (scale > 3.0f)
            scale = 3.0f;

        rightArmScale.store(scale);
    }

    void Reset()
    {
        leftArmScale.store(1.0f);
        rightArmScale.store(1.0f);

        LOGI("Long Arms reset.");
    }
}

extern "C"
__attribute__((visibility("default")))
void setup(ModInfo& info)
{
    info.id = "universalvr-gtag";
    info.version = "0.2.0";

    LOGI("UniversalVR Gorilla Tag adapter setup.");
}

extern "C"
__attribute__((visibility("default")))
void load()
{
    LOGI("UniversalVR Gorilla Tag adapter loaded.");

    UniversalVR::SetArmScale(1.25f);

    /*
        IMPORTANT:

        The long-arm math is now implemented.

        What remains is connecting these three things:

        1. Gorilla Tag head transform
        2. Gorilla Tag left controller transform
        3. Gorilla Tag right controller transform

        Every frame we will do:

        left.position =
            CalculateLongArmPosition(
                head.position,
                trackedLeft.position,
                leftArmScale
            );

        right.position =
            CalculateLongArmPosition(
                head.position,
                trackedRight.position,
                rightArmScale
            );

        We deliberately do NOT guess the current Gorilla Tag
        IL2CPP class names or hook signature here.
    */
}

extern "C"
__attribute__((visibility("default")))
void late_load()
{
    LOGI("UniversalVR Gorilla Tag adapter late_load.");
}
