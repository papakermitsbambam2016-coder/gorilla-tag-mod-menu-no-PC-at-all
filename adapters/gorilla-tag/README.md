# UniversalVR Gorilla Tag Adapter

Quest ARM64 native adapter for UniversalVR.

Current version:
0.1.0

Current status:
- Native ARM64 build project
- QMOD manifest
- Scotland2 loader entry points
- Logging
- Long Arms hook placeholder

Planned Long Arms behavior:

adjustedHand =
headPosition +
(realHandPosition - headPosition) * armScale

Planned settings:

- Enabled
- Arm Scale
- Left Arm Scale
- Right Arm Scale
- Left Hand Offset
- Right Hand Offset
- Reset

Important:

This adapter requires Gorilla Tag to already have a compatible Quest mod loader installed.

The current adapter does not yet modify Gorilla Tag player transforms.
