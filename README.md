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

## What is `browseui.dll`?

`browseui.dll` is a component of the Microsoft Windows operating system. It stands
for "Browse User Interface" and is primarily associated with the graphical user
interface (GUI) elements related to browsing files and folders.

## What is "shell extension" in Windows?

In Windows, a "shell extension" refers to a type of software component that extends or
enhances the functionality of the Windows shell, which is the user interface of the
operating system. Shell extensions allow developers to add custom features or integrate
their applications more deeply into the Windows operating system's graphical interface.

Shell extensions can take various forms and serve different purposes. Some common
examples include:

1. **Context menu extensions**: These add options to the right-click context menu when you
   right-click on files, folders, or the desktop. For example, you might install a
   context menu extension that allows you to perform additional actions on files,
   such as encryption, compression, or sending them to a specific application.

2. **Icon overlays**: These modify the icons of files and folders to provide visual cues
   or status information. For instance, a cloud storage service might use an icon
   overlay to indicate whether a file is synchronized with the cloud or not.

3. **Property sheet extensions**: These add custom tabs or pages to the properties dialog
   of files and folders, allowing users to view or modify additional metadata or
   settings. For example, a media player might add a tab to the properties dialog
   of audio or video files to display detailed information about the media content.

4. **Thumbnail handlers**: These generate thumbnails or previews for specific types of
   files so that they can be displayed in File Explorer's thumbnail view. For
   instance, a document management system might provide a thumbnail handler to
   generate thumbnails for documents stored in its repository.

Shell extensions can greatly enhance the user experience by providing convenient
shortcuts, additional functionality, or integration with third-party applications
directly within the Windows shell. However, poorly designed or buggy shell extensions
can also cause performance issues or instability in the operating system, so it's
essential to choose and manage them carefully.

## What is "shell namespace"?

The shell namespace is a conceptual framework used by Microsoft Windows
operating systems to organize and represent various objects, such as files,
folders, drives, printers, network resources, and other system and user-defined
items. It provides a hierarchical structure that allows users and applications
to navigate and manipulate these objects in a consistent and intuitive manner.

Key features and concepts related to the shell namespace include:

1. **Hierarchy**: The shell namespace organizes objects in a hierarchical structure
   similar to a tree, where each node represents a different type of object or
   container. For example, the root of the namespace typically represents the
   entire computer system, with branches representing drives, folders, and
   individual files.
2. **Integration with File Explorer**: The shell namespace is tightly integrated
   with File Explorer, the file management application in Windows. File Explorer
   uses the shell namespace to display the contents of drives and folders,
   allowing users to navigate and manipulate files and folders using a familiar interface.
3. **Special folders**: The shell namespace includes special folders, such as
   `"My Computer"`, `"Desktop"`, `"Documents"`, `"Downloads"`, and others,
   which provide convenient access to commonly used locations on the system.
   These special folders are virtual representations that can include both
   physical and virtual items.
4. **Virtual objects**: In addition to physical objects such as files and folders,
   the shell namespace can also include virtual objects that represent
   dynamically generated or transient items. For example, the
   `"Control Panel"` and `"Network Neighborhood"` folders are virtual folders
   that display system settings and network resources, respectively.
5. **Namespace extensions**: Developers can extend the shell namespace by creating
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

Here are some key points about shortcut (`.LNK`) files:

1. **Icon**: Shortcut files typically have a distinct icon overlay to
   differentiate them from regular files or folders. This icon often
   includes a small arrow or shortcut symbol to indicate that it is a shortcut.
2. **Properties**: Shortcut files contain various properties and attributes that
   specify information about the target item, such as its location (path),
   filename, icon, and any command-line arguments or parameters needed to
   open the target.
3. **Creation**: Users can create shortcut files manually by right-clicking on an
   item (such as a file, folder, or application) and selecting the
   `"Create shortcut"` option from the context menu. Additionally, some
   applications automatically create shortcuts during installation to provide
   easy access to their executable files or resources.
4. **Accessibility**: Shortcut files provide a convenient way for users to access
   frequently used items or resources without having to navigate through the
   file system to find them. Users can place shortcut files on the desktop,
   in the Start menu, or in other locations for easy access.
5. **Versatility**: Shortcut files can point to various types of targets, including
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

1. **String Manipulation**: `shlwapi.dll` includes functions for working with
   strings, such as text manipulation, comparison, and formatting. These
   string-handling functions are often used by applications and system
   components for tasks like parsing file paths, working with URLs, and
   handling user input.
2. **Path Manipulation**: It provides functions for working with file and
   directory paths, including functions for combining, splitting, and
   normalizing paths. These functions help ensure compatibility and
   consistency when dealing with file system paths across different
   versions of Windows.
3. **URL Handling**: `shlwapi.dll` includes functions for parsing and manipulating
   Uniform Resource Locators (URLs), such as extracting components like the
   protocol, host, path, and query parameters. These functions are used by
   web browsers, email clients, and other applications that interact with
   web resources.
4. **File Operations**: It provides functions for performing various file
   operations, such as copying, moving, deleting, and renaming files. These
   functions supplement the file management capabilities provided by other
   system libraries and APIs.
5. **Registry Operations**: `shlwapi.dll` includes functions for working with the
   Windows Registry, such as reading and writing registry keys and values.
   These functions are used by applications and system components to store
   and retrieve configuration settings and other persistent data.

## What of the registry does a shell extension use?

Shell extensions typically use specific sections of the Windows Registry to
register themselves and provide information to the operating system about
their functionality and integration with the Windows shell. Here are some
key areas of the registry that shell extensions commonly use:

1. **File Type Associations**:
   - `HKEY_CLASSES_ROOT\.extension`: Shell extensions that provide functionality
      specific to certain file types register here to associate themselves
      with those file types.
   - `HKEY_CLASSES_ROOT\filetype\shell`: This key is used to register context
      menu entries for specific file type `filetype`.
2. **Context Menu Entries**:
   - `HKEY_CLASSES_ROOT\*\shell` and `HKEY_CLASSES_ROOT\Directory\shell`:
      These keys are used by context menu extensions to register context
      menu entries for all file types and directories, respectively.
3. **Icon Overlays**:
   - `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\ShellIconOverlayIdentifiers`:
     Icon overlay extensions register here to specify their icon overlays.
4. **Property Sheet Extensions**:
   - `HKEY_CLASSES_ROOT\filetype\shellex\PropertySheetHandlers`: Shell extensions
      that add custom property sheet pages register here to integrate with
      the Properties dialog of files.
5. **Thumbnail Handlers**:
   - `HKEY_CLASSES_ROOT\filetype\shellex\{BB2E617C-0920-11d1-9A0B-00C04FC2D6C1}`: Thumbnail handlers
      register here to provide thumbnail images for specific file type `file type`.
6. **Other Shell Extensions**:
   - `HKEY_CLASSES_ROOT\CLSID`: Shell extensions that don't fit into the
      above categories often register under this key using their
      `CLSID` (Class Identifier).

These are just some examples of the registry keys and locations commonly
used by shell extensions. The exact registry keys and values used can vary
depending on the type and functionality of the shell extension. Proper
registration in these registry locations ensures that shell extensions
are integrated correctly into the Windows shell and function as intended.

## What is GUID, IID, CLSID etc.?

GUID, IID, and CLSID are identifiers used in programming, particularly
in the context of Microsoft Windows development. They serve different
purposes and are defined as follows:

1. **GUID (Globally Unique Identifier)**:
   - A GUID is a 128-bit value that is globally unique and is used to
     identify various objects, components, interfaces, and other entities
     in software development.
   - GUIDs are typically represented as a sequence of hexadecimal
     digits separated by hyphens, such as `"{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}"`.
   - GUIDs are generated using algorithms that ensure their uniqueness
     across different systems and environments.
2. **IID (Interface Identifier)**:
   - An IID is a specific type of GUID used to uniquely identify COM
     (Component Object Model) interfaces in Windows programming.
   - Each COM interface has a unique IID associated with it, which is
     used by clients to query and interact with the interface.
   - IIDs are defined in the Windows SDK (Software Development Kit)
     header files and are typically represented as constant values defined
     using the `DEFINE_GUID` macro.
3. **CLSID (Class Identifier)**:
   - A CLSID is another type of GUID used to uniquely identify COM
     classes, which are implementations of COM objects.
   - Each COM class has a unique CLSID associated with it, which is
     used to instantiate and manipulate instances of the class.
   - CLSIDs are registered in the Windows Registry along with
     information about the associated COM class, including the
     location of the class's executable code.
   - Like IIDs, CLSIDs are defined in the Windows SDK header files
     and are represented as constant values defined using the `DEFINE_GUID` macro.

In summary, GUIDs, IIDs, and CLSIDs are unique identifiers used in
Windows programming to uniquely identify various entities such as
interfaces, classes, objects, and components. They play a crucial
role in component-based software development, allowing different software
components to interact with each other in a standardized and interoperable
manner.

## What is Component Object Model (COM)?

The Component Object Model (COM) is a Microsoft technology that
enables software components, written in different programming
languages, to interact and communicate with each other in a
platform-independent and language-independent manner. COM provides
a framework for building modular, reusable, and extensible software
components that can be used across different applications and
programming languages.

Key features and concepts of COM include:

1. **Interfaces**: COM components expose functionality through interfaces,
   which define a contract specifying the methods and properties that
   clients can use to interact with the component. Interfaces are
   language-neutral and define a standard way for clients to communicate
   with components.
2. **Objects**: COM components are implemented as objects, which
   encapsulate data and behavior and expose functionality through
   interfaces. Objects can be created, manipulated, and destroyed at
   runtime, and they provide a way to organize and encapsulate complex
   functionality.
3. **Binary Compatibility**: COM components provide binary compatibility,
   which means that clients can use components without needing to know how
   they are implemented internally. This allows components to be upgraded
   or replaced without affecting client code, as long as the interfaces
   remain unchanged.
4. **Late Binding**: COM supports late binding, allowing clients to
   discover and use interfaces at runtime without needing to know their
   details at compile time. This enables dynamic composition of software
   components and supports scenarios such as scripting and automation.
5. **Registration**: COM components are registered in the Windows Registry,
   where information about their classes, interfaces, and other properties
   is stored. Registration allows clients to locate and instantiate
   components dynamically at runtime.
6. **Marshaling**: COM provides mechanisms for marshaling data and
   interfaces between different processes or across network boundaries.
   This allows components to communicate across process boundaries and
   enables distributed computing scenarios.

COM has been widely used in Windows development for building a wide range
of software components, including libraries, controls, services, and
applications. It forms the foundation for other Microsoft technologies
such as ActiveX, OLE (Object Linking and Embedding), and OLE Automation,
and it continues to be an important part of the Windows platform.

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
