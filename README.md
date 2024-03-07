# Windows Shell Study (ShellStudy) by katahiromz

## Notation

- `user32!MessageBoxW` ― The `MessageBoxW` function in `user32.dll`.
- `Win` ― Windows.
- `Ros` ― ReactOS.
- `WinXP` ― Windows XP.
- `Win2k3` ― Windows Server 2003.
- `Win:user32!MessageBoxW` ― The `MessageBoxW` function in Windows `user32.dll`.
- `Ros:user32!MessageBoxW` ― The `MessageBoxW` function in ReactOS `user32.dll`.

## Components

- [shell32](shell32/README.md)
- [explorer](explorer/README.md)
- [browseui](browseui/README.md)
- [interface](interface/README.md)
- [tools](tools/README.md)

## What is "shell" in Windows OS?

In the context of Windows operating systems, the term "shell" typically refers to the user
interface that allows users to interact with the operating system. It encompasses elements
such as the desktop, taskbar, Start menu, File Explorer (previously known as Windows
Explorer), and other graphical components that users utilize to navigate and manage files,
folders, and applications.

The Windows shell provides a graphical way for users to interact with the operating system,
as opposed to using only command-line interfaces. It enables users to perform various tasks
such as launching applications, managing files, configuring system settings, and more, all
through a visual interface. Over the years, the Windows shell has undergone significant
updates and enhancements to improve usability and functionality.

See:

- [$(REACTOS)/base/shell/explorer](https://github.com/reactos/reactos/tree/master/base/shell/explorer)
- [$(REACTOS)/base/shell/rshell](https://github.com/reactos/reactos/tree/master/base/shell/rshell)
- [$(REACTOS)/dll/shellext](https://github.com/reactos/reactos/tree/master/base/dll/shellext)
- [$(REACTOS)/dll/win32/browseui](https://github.com/reactos/reactos/tree/master/dll/win32/browseui)
- [$(REACTOS)/dll/win32/shell32](https://github.com/reactos/reactos/tree/master/dll/win32/shell32)
- [$(REACTOS)/dll/win32/shlwapi](https://github.com/reactos/reactos/tree/master/dll/win32/shlwapi)

(Under construction)

## References

- Win32 Programmer's Reference
- [Geoff Chappell, Software Analyst](https://geoffchappell.com/studies/windows/)
- [Microsoft Learn](https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows)
- [The Old New Thing](https://devblogs.microsoft.com/oldnewthing/)

## License

- MIT

## Copyright

- Copyright © 2024 katahiromz. All Rights Reserved.
