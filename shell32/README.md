# ShellStudy shell32

## What is `shell32.dll`?

`shell32.dll` is a Dynamic Link Library (DLL) file in Microsoft Windows operating
systems. It plays a crucial role in providing various functions and resources
related to the Windows shell, which is the user interface of the operating system.

Here are some of the key functions and features provided by `shell32.dll`:

1. **User interface elements**: `shell32.dll` contains resources and functions used
   to create various user interface elements, such as icons, dialog boxes, menus,
   and controls, which are integral parts of the Windows shell.

2. **File management**: It provides functions for file and folder manipulation,
   including copying, moving, deleting, renaming, and accessing properties of
   files and folders. These functions are used by applications and the operating
   system itself to manage files and folders.

3. **Shell extensions**: `shell32.dll` includes functions and interfaces that allow
   developers to create shell extensions, which are components that extend the
   functionality of the Windows shell. Shell extensions can add custom features,
   context menu options, icon overlays, and other enhancements to the user
   interface.

4. **Shell namespace**: `shell32.dll` implements the shell namespace, which is a
   hierarchical structure used to organize and represent various system and
   user-defined objects, such as files, folders, drives, printers, and network
   resources. This namespace is used by File Explorer and other shell-related
   components to navigate and manipulate objects in the file system and beyond.

5. **Shortcut (`.lnk`) handling**: It provides functions for creating, resolving,
   and manipulating shortcut files (`.lnk` files), which are used to represent
   links to files, folders, applications, and other resources.

Overall, `shell32.dll` is a core system file that is essential for the proper
functioning of the Windows shell and many of its associated features and components.

See:

- [$(REACTOS)/dll/win32/shell32](https://github.com/reactos/reactos/tree/master/dll/win32/shell32) .

## `dumpbin /imports /exports`

- [winxp-shell32.dll.dumpbin.txt](winxp-shell32.dll.dumpbin.txt)
- [win2k3-shell32.dll.dumpbin.txt](win2k3-shell32.dll.dumpbin.txt)

## ReactOS spec file

- [$(REACTOS)/dll/win32/shell32/shell32.spec](https://github.com/reactos/reactos/tree/master/dll/win32/shell32/shell32.spec)

## Resource data

- [winxp-shell32.dll-resource](winxp-shell32.dll-resource)
- [win2k3-shell32.dll-resource](win2k3-shell32.dll-resource)

## What is the major difference between `CreateProcess` and `ShellExecute`?

The major difference between `CreateProcess` and `ShellExecute` lies in
their intended usage and functionality:

1. **CreateProcess**:
   - `kernel32!CreateProcess` is a lower-level function used to create
     a new process and execute an executable file or command-line
     application.
   - It provides precise control over the creation and execution of
     the new process, allowing you to specify various parameters such
     as the executable path, command-line arguments, process creation
     flags, and environment variables.
   - `CreateProcess` does not handle file associations or shell verbs,
     and it does not invoke shell features such as file type associations,
     verb execution, or URL handling.

2. **ShellExecute**:
   - `shell32!ShellExecute` is a higher-level function used to execute a
     specified file or perform an operation on a specified file or folder.
   - It is designed to invoke shell features such as file type associations,
     verb execution, and URL handling, allowing you to open files with their
     associated applications, explore folders, launch URLs in the default
     web browser, and perform other shell-related tasks.
   - `ShellExecute` automatically handles file associations and shell verbs,
     determining the appropriate action to take based on the file type
     and the specified verb (e.g., "open", "print", "edit").
   - `ShellExecute` provides a more user-friendly and integrated experience
     compared to `CreateProcess`, as it leverages the Windows Shell to
     execute files and perform operations using the default applications
     and settings configured by the user.

## What is `shell:ControlPanelFolder`?

`shell:ControlPanelFolder` is a special shell namespace item (also known as
a shell namespace GUID) in Windows that represents the Control Panel folder.
It is a virtual folder within the Windows Shell that provides access to
various system settings and configuration options.

For example, typing shell:ControlPanelFolder in the Run dialog
(Windows key + R) and pressing Enter will open the Control Panel window.

## Please tell me well-known special shell namespace items

- `shell:ControlPanelFolder`
- `shell:MyComputerFolder`
- `shell:RecycleBinFolder`
- `shell:NetworkPlacesFolder`
- `shell:PrintersFolder`
- `shell:UserProfile`
- `shell:CommonPrograms`
- `shell:Desktop`
- `shell:AppData`
- `shell:Fonts`

See also:

- [$(REACTOS)/dll/win32/shell32/wine/shellpath.c](https://github.com/reactos/reactos/tree/master/dll/win32/shell32/wine/shellpath.c)

## Please tell me well-known namespace GUIDs

Here are some well-known namespace GUIDs in Windows:

1. **{20D04FE0-3AEA-1069-A2D8-08002B30309D}**: This GUID (`CLSID_MyComputer`) represents the "My Computer" or "This PC" namespace.
2. **{450D8FBA-AD25-11D0-98A8-0800361B1103}**: This GUID (`CLSID_MyDocuments`) represents the "My Documents" namespace.
3. **{645FF040-5081-101B-9F08-00AA002F954E}**: This GUID (`CLSID_RecycleBin`) represents the "Recycle Bin" namespace.
4. **{21EC2020-3AEA-1069-A2DD-08002B30309D}**: This GUID (`CLSID_ControlPanel`) represents the "Control Panel" namespace.
5. **{208D2C60-3AEA-1069-A2D7-08002B30309D}**: This GUID (`CLSID_NetworkPlaces`) represents the "Network Places" namespace.
6. **{871C5380-42A0-1069-A2EA-08002B30309D}**: This GUID (`CLSID_Internet`) represents the "Internet Explorer namespace.

See also:

- [$(REACTOS)/sdk/include/psdk/shlguid.h](https://github.com/reactos/reactos/tree/master/sdk/include/psdk/shlguid.h)

You can convert representation of GUID by [katahiromz/refguid](https://github.com/katahiromz/refguid).

---

[Back](../README.md)
