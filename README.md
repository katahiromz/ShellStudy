# Windows Shell Study (ShellStudy) by katahiromz

## Notation

- `user32!MessageBoxW` ― The `MessageBoxW` function in `user32.dll`.
- `Win` ― Windows.
- `Ros` ― ReactOS.
- `WinXP` ― Windows XP.
- `Win2k3` ― Windows Server 2003.
- `Win:user32!MessageBoxW` ― The `MessageBoxW` function in Windows `user32.dll`.
- `Ros:user32!MessageBoxW` ― The `MessageBoxW` function in ReactOS `user32.dll`.
- `$(REACTOS)` ― ReactOS repository.

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

## What is "Explorer"?

In the context of Microsoft Windows operating systems, "Explorer" typically refers
to the File Explorer application. File Explorer is the file management application
that allows users to navigate and manage files and folders on their computer. It
provides a graphical user interface (GUI) for interacting with the file system,
including features such as browsing directories, copying, moving, renaming,
deleting files, and creating new folders.

## What is "shell extension" in Windows?

In Windows, a "shell extension" refers to a type of software component that extends or
enhances the functionality of the Windows shell, which is the user interface of the
operating system. Shell extensions allow developers to add custom features or integrate
their applications more deeply into the Windows operating system's graphical interface.

Shell extensions can take various forms and serve different purposes. Some common
examples include:

1. Context menu extensions: These add options to the right-click context menu when you
   right-click on files, folders, or the desktop. For example, you might install a
   context menu extension that allows you to perform additional actions on files,
   such as encryption, compression, or sending them to a specific application.

2. Icon overlays: These modify the icons of files and folders to provide visual cues
   or status information. For instance, a cloud storage service might use an icon
   overlay to indicate whether a file is synchronized with the cloud or not.

3. Property sheet extensions: These add custom tabs or pages to the properties dialog
   of files and folders, allowing users to view or modify additional metadata or
   settings. For example, a media player might add a tab to the properties dialog
   of audio or video files to display detailed information about the media content.

4. Thumbnail handlers: These generate thumbnails or previews for specific types of
   files so that they can be displayed in File Explorer's thumbnail view. For
   instance, a document management system might provide a thumbnail handler to
   generate thumbnails for documents stored in its repository.

Shell extensions can greatly enhance the user experience by providing convenient
shortcuts, additional functionality, or integration with third-party applications
directly within the Windows shell. However, poorly designed or buggy shell extensions
can also cause performance issues or instability in the operating system, so it's
essential to choose and manage them carefully.

## What is `browseui.dll`?

`browseui.dll` is a component of the Microsoft Windows operating system. It stands
for "Browse User Interface" and is primarily associated with the graphical user
interface (GUI) elements related to browsing files and folders.

## What is `shell32.dll`?

`shell32.dll` is a Dynamic Link Library (DLL) file in Microsoft Windows operating
systems. It plays a crucial role in providing various functions and resources
related to the Windows shell, which is the user interface of the operating system.

Here are some of the key functions and features provided by `shell32.dll`:

1. User interface elements: `shell32.dll` contains resources and functions used
   to create various user interface elements, such as icons, dialog boxes, menus,
   and controls, which are integral parts of the Windows shell.
2. File management: It provides functions for file and folder manipulation,
   including copying, moving, deleting, renaming, and accessing properties of
   files and folders. These functions are used by applications and the operating
   system itself to manage files and folders.
3. Shell extensions: `shell32.dll` includes functions and interfaces that allow
   developers to create shell extensions, which are components that extend the
   functionality of the Windows shell. Shell extensions can add custom features,
   context menu options, icon overlays, and other enhancements to the user
   interface.
4. Shell namespace: `shell32.dll` implements the shell namespace, which is a
   hierarchical structure used to organize and represent various system and
   user-defined objects, such as files, folders, drives, printers, and network
   resources. This namespace is used by File Explorer and other shell-related
   components to navigate and manipulate objects in the file system and beyond.
5. Shortcut (`.lnk`) handling: It provides functions for creating, resolving,
   and manipulating shortcut files (.lnk files), which are used to represent
   links to files, folders, applications, and other resources.

Overall, `shell32.dll` is a core system file that is essential for the proper
functioning of the Windows shell and many of its associated features and components.

## What is "shell namespace"?

The shell namespace is a conceptual framework used by Microsoft Windows
operating systems to organize and represent various objects, such as files,
folders, drives, printers, network resources, and other system and user-defined
items. It provides a hierarchical structure that allows users and applications
to navigate and manipulate these objects in a consistent and intuitive manner.

Key features and concepts related to the shell namespace include:

1. Hierarchy: The shell namespace organizes objects in a hierarchical structure
   similar to a tree, where each node represents a different type of object or
   container. For example, the root of the namespace typically represents the
   entire computer system, with branches representing drives, folders, and
   individual files.
2. Integration with File Explorer: The shell namespace is tightly integrated
   with File Explorer, the file management application in Windows. File Explorer
   uses the shell namespace to display the contents of drives and folders,
   allowing users to navigate and manipulate files and folders using a familiar interface.
3. Special folders: The shell namespace includes special folders, such as
   `"My Computer"`, `"Desktop"`, `"Documents"`, `"Downloads"`, and others,
   which provide convenient access to commonly used locations on the system.
   These special folders are virtual representations that can include both
   physical and virtual items.
4. Virtual objects: In addition to physical objects such as files and folders,
   the shell namespace can also include virtual objects that represent
   dynamically generated or transient items. For example, the
   `"Control Panel"` and `"Network Neighborhood"` folders are virtual folders
   that display system settings and network resources, respectively.
5. Namespace extensions: Developers can extend the shell namespace by creating
   namespace extensions, which are components that provide custom views or
   representations of objects within the namespace. Namespace extensions allow
   third-party applications to integrate seamlessly with the Windows shell and
   provide users with additional functionality or access to specialized resources.

Overall, the shell namespace provides a unified and consistent way to organize
and access objects on the Windows operating system, making it easier for users
and applications to work with files, folders, and other resources.

## What is shortcut (`.LNK`) file?

A shortcut file, often denoted by the file extension `".LNK"`, is a type of
file in Microsoft Windows operating systems that serves as a pointer or
reference to another file, folder, application, or resource on the system.
Instead of containing the actual data of the target item, a shortcut file
stores information about the location and properties of the target, allowing
users to access it quickly and conveniently.

Here are some key points about shortcut (`.`LNK) files:

1. Icon: Shortcut files typically have a distinct icon overlay to
   differentiate them from regular files or folders. This icon often
   includes a small arrow or shortcut symbol to indicate that it is a shortcut.
2. Properties: Shortcut files contain various properties and attributes that
   specify information about the target item, such as its location (path),
   filename, icon, and any command-line arguments or parameters needed to
   open the target.
3. Creation: Users can create shortcut files manually by right-clicking on an
   item (such as a file, folder, or application) and selecting the
   `"Create shortcut"` option from the context menu. Additionally, some
   applications automatically create shortcuts during installation to provide
   easy access to their executable files or resources.
4. Accessibility: Shortcut files provide a convenient way for users to access
   frequently used items or resources without having to navigate through the
   file system to find them. Users can place shortcut files on the desktop,
   in the Start menu, or in other locations for easy access.
5. Versatility: Shortcut files can point to various types of targets, including
   files, folders, applications, documents, web pages, network resources, and
   more. This versatility allows users to create shortcuts to a wide range of
   items and resources on their system.

## What is `shlwapi.dll`?

`shlwapi.dll` is a Dynamic Link Library (DLL) file in Microsoft Windows
operating systems. The name stands for `"Shell Light-Weight utility library"`
API. It contains a collection of utility functions and APIs (Application
Programming Interfaces) that provide various functionalities related to the
Windows shell and other system components.

Here are some key functions and features provided by `shlwapi.dll`:

1. String Manipulation: shlwapi.dll includes functions for working with
   strings, such as text manipulation, comparison, and formatting. These
   string-handling functions are often used by applications and system
   components for tasks like parsing file paths, working with URLs, and
   handling user input.
2. Path Manipulation: It provides functions for working with file and
   directory paths, including functions for combining, splitting, and
   normalizing paths. These functions help ensure compatibility and
   consistency when dealing with file system paths across different
   versions of Windows.
3. URL Handling: shlwapi.dll includes functions for parsing and manipulating
   Uniform Resource Locators (URLs), such as extracting components like the
   protocol, host, path, and query parameters. These functions are used by
   web browsers, email clients, and other applications that interact with
   web resources.
4. File Operations: It provides functions for performing various file
   operations, such as copying, moving, deleting, and renaming files. These
   functions supplement the file management capabilities provided by other
   system libraries and APIs.
5. Registry Operations: shlwapi.dll includes functions for working with the
   Windows Registry, such as reading and writing registry keys and values.
   These functions are used by applications and system components to store
   and retrieve configuration settings and other persistent data.

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
