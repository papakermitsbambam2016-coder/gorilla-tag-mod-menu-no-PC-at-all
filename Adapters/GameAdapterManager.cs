namespace UniversalVR.Adapters;

public sealed class GameAdapterManager
{
    private readonly List<IGameAdapter> _adapters = new();

    public IReadOnlyList<IGameAdapter> Adapters => _adapters;

    public IGameAdapter? ActiveAdapter { get; private set; }

    public void Register(IGameAdapter adapter)
    {
        if (!_adapters.Any(a =>
            a.Id.Equals(adapter.Id, StringComparison.OrdinalIgnoreCase)))
        {
            _adapters.Add(adapter);
        }
    }

    public bool TryInitialize()
    {
        foreach (var adapter in _adapters)
        {
            try
            {
                if (adapter.IsCompatible() && adapter.Initialize())
                {
                    ActiveAdapter = adapter;
                    return true;
                }
            }
            catch
            {
                // Keep trying other adapters.
            }
        }

        return false;
    }

    public void Update()
    {
        try
        {
            ActiveAdapter?.Update();
        }
        catch
        {
        }
    }

    public void Shutdown()
    {
        try
        {
            ActiveAdapter?.Shutdown();
        }
        catch
        {
        }

        ActiveAdapter = null;
    }
}
