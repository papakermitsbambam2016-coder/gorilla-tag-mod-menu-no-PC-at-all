namespace UniversalVR.Menu;

public sealed class MenuModel
{
    public string Title => "UniversalVR";

    public bool Open { get; private set; }

    public event Action<bool>? OpenChanged;

    public void Toggle()
    {
        Open = !Open;

        OpenChanged?.Invoke(Open);
    }

    public void SetOpen(bool open)
    {
        if (Open == open)
            return;

        Open = open;

        OpenChanged?.Invoke(Open);
    }
}
