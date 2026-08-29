using UniversalVR.Models;

namespace UniversalVR.Adapters;

public interface IGameAdapter
{
    string Id { get; }
    string DisplayName { get; }

    bool IsCompatible();
    bool Initialize();

    void Update();

    bool SetArmProfile(ArmProfile profile);

    void Shutdown();
}
