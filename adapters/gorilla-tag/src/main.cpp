#include <android/log.h>

#define LOG_TAG "UniversalVR-GTAG"

#define LOGI(...) \
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

struct ModInfo
{
    const char* id;
    const char* version;
};

extern "C"
__attribute__((visibility("default")))
void setup(ModInfo& info)
{
    info.id = "universalvr-gtag";
    info.version = "0.1.0";

    LOGI("UniversalVR Gorilla Tag adapter setup.");
}

extern "C"
__attribute__((visibility("default")))
void load()
{
    LOGI("UniversalVR Gorilla Tag adapter loaded.");

    /*
        Future Long Arms hook goes here.

        Target behavior:

        adjustedHand =
            headPosition +
            (realHandPosition - headPosition)
            * armScale;

        Example:
        armScale = 1.00f -> normal
        armScale = 1.25f -> longer arms
        armScale = 1.50f -> stronger long arms

        We are NOT adding guessed Gorilla Tag IL2CPP hooks yet.
    */
}

extern "C"
__attribute__((visibility("default")))
void late_load()
{
    LOGI("UniversalVR Gorilla Tag adapter late_load.");
}
