using UniversalVR.Models;

namespace UniversalVR.Adapters;

public abstract class StubAdapterBase : IGameAdapter
{
    public abstract string Id { get; }

    public abstract string DisplayName { get; }

    public virtual bool IsCompatible()
    {
        return false;
    }

    public virtual bool Initialize()
    {
        return false;
    }

    public virtual void Update()
    {
    }

    public virtual bool SetArmProfile(ArmProfile profile)
    {
        return false;
    }

    public virtual void Shutdown()
    {
    }
}
