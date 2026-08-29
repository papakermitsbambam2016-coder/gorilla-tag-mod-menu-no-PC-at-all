using UniversalVR.Adapters;
using UniversalVR.Models;

namespace UniversalVR.LongArms;

public sealed class LongArmManager
{
    private readonly GameAdapterManager _adapters;

    public ArmProfile Profile { get; } = new();

    public float MinLength => 0.50f;
    public float MaxLength => 3.00f;

    public LongArmManager(GameAdapterManager adapters)
    {
        _adapters = adapters;
    }

    public void SetBoth(float value)
    {
        value = Math.Clamp(value, MinLength, MaxLength);

        Profile.LeftLength = value;
        Profile.RightLength = value;

        Apply();
    }

    public void SetLeft(float value)
    {
        Profile.LeftLength =
            Math.Clamp(value, MinLength, MaxLength);

        Apply();
    }

    public void SetRight(float value)
    {
        Profile.RightLength =
            Math.Clamp(value, MinLength, MaxLength);

        Apply();
    }

    public void SetOffsets(
        Vector3Value left,
        Vector3Value right)
    {
        Profile.LeftOffset = left;
        Profile.RightOffset = right;

        Apply();
    }

    public void Reset()
    {
        Profile.Reset();
        Apply();
    }

    public bool Apply()
    {
        return _adapters.ActiveAdapter?.SetArmProfile(Profile) == true;
    }
}
