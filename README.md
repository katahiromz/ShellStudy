# Windows Shell Study by katahiromz

This is a personal study about the Windows shell by Katayama Hirofumi MZ.

## Notation

- `user32!MessageBoxW` ― The `MessageBoxW` function in `user32.dll`.
- `Win` ― Windows.
- `Ros` ― ReactOS.
- `WinXP` ― Windows XP.
- `Win2k3` ― Windows Server 2003.
- `Win:user32!MessageBoxW` ― The `MessageBoxW` function in Windows `user32.dll`.
- `Ros:user32!MessageBoxW` ― The `MessageBoxW` function in ReactOS `user32.dll`.
- `$(REACTOS)` ― ReactOS repository.
- `$(REACTOS)/dll/win32/shell` ― File path `dll/win32/shell` of ReactOS repository.

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

- [browseui](browseui/README.md)
- [explorer](explorer/README.md)
- [shell32](shell32/README.md)
- [shlwapi](browseui/README.md)
- [interface](interface/README.md)
- [tools](tools/README.md)

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

See:

- [$(REACTOS)/dll/shellext](https://github.com/reactos/reactos/tree/master/base/dll/shellext)

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

A shortcut file, or shell link, often denoted by the file extension `".LNK"`,
is a type of file in Windows that serves as a pointer or reference to another file,
folder, application, or resource on the system. Instead of containing the actual
data of the target item, a shortcut file stores information about the location and
properties of the target, allowing users to access it quickly and conveniently.

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

See:

- [$(REACTOS)/dll/cpl/appwiz/createlink.c](https://github.com/reactos/reactos/tree/master/dll/cpl/appwiz/createlink.c)
- [$(REACTOS)/dll/win32/shell32/CShellLink.h](https://github.com/reactos/reactos/tree/master/dll/win32/shell32/CShellLink.h)
- [$(REACTOS)/dll/win32/shell32/CShellLink.cpp](https://github.com/reactos/reactos/tree/master/dll/win32/shell32/CShellLink.cpp)

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
     header files.

3. **CLSID (Class Identifier)**:
   - A CLSID is another type of GUID used to uniquely identify COM
     classes, which are implementations of COM objects.
   - Each COM class has a unique CLSID associated with it, which is
     used to instantiate and manipulate instances of the class.
   - CLSIDs are registered in the Windows Registry along with
     information about the associated COM class, including the
     location of the class's executable code.

A GUID can typically represented as constant values defined using the
`DEFINE_GUID` macro.

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

See also `REF005`.

## What are the well-known GUIDs?

Here are some examples of well-known GUIDs:

- `IID_IUnknown`: `{00000000-0000-0000-C000-000000000046}` - This GUID
   represents the interface identifier for the `IUnknown` interface in COM,
   which is the base interface for all COM interfaces.
- `IID_IDispatch`: `{00020400-0000-0000-C000-000000000046}` - This GUID
   represents the interface identifier for the `IDispatch` interface in COM,
   which provides late-bound access to COM objects through automation.
- `IID_IStream`: `{0000000C-0000-0000-C000-000000000046}` - This GUID
   represents the interface identifier for the `IStream` interface in COM,
   which is used for reading from and writing to streams of data.
- `GUID_NULL`: `{00000000-0000-0000-0000-000000000000}` - This GUID
   represents a null or empty GUID, often used to indicate the absence of a
   meaningful GUID value.

## What are the essential functions of COM?

Some of the key functions and concepts of COM include:

1. **Component Registration**: COM components are registered in the Windows
   Registry, where information about their classes, interfaces, and other
   properties is stored. Registration allows clients to locate and instantiate
   components dynamically at runtime.

2. **Interfaces**: COM components expose functionality through interfaces,
   which define a contract specifying the methods and properties that clients
   can use to interact with the component. Interfaces are language-neutral
   and define a standard way for clients to communicate with components.

3. **Object Creation**: COM provides mechanisms for creating and managing
   instances of objects. Clients can create objects using factory functions,
   class factories, or other instantiation methods provided by the component.

4. **Lifetime Management**: COM components implement reference counting to
   manage their lifetime. Clients can add references to objects using the
   `AddRef` method and release references using the `Release` method. When
   the reference count reaches zero, the object is automatically destroyed.

5. **Query Interface**: COM provides the `QueryInterface` method, which allows
   clients to query a component for specific interfaces it supports. This
   allows clients to dynamically discover and use interfaces provided by
   components at runtime.

6. **Marshaling**: COM provides mechanisms for marshaling data and interfaces
   between different processes or across network boundaries. This allows
   components to communicate across process boundaries and enables
   distributed computing scenarios.

7. **Threading Models**: COM supports different threading models, including
   single-threaded apartment (STA), multi-threaded apartment (MTA), and
   free-threaded apartment (FTA). Threading models define how objects can
   be accessed and used in different threading environments.

8. **Error Handling**: COM components return `HRESULT` values to indicate
   the success or failure of operations. Error codes are standardized and
   provide detailed information about the cause of an error, allowing
   clients to handle errors gracefully.

9. **Activation Contexts**: COM provides activation contexts, which allow
   clients to specify additional context information when activating objects.
   Activation contexts can be used to control aspects such as security,
   transaction support, and configuration settings.

See also:

- [ole32!CoInitialize function](https://learn.microsoft.com/en-us/windows/win32/api/objbase/nf-objbase-coinitialize) - Microsoft Learn
- [ole32!CoInitializeEx function](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) - Microsoft Learn
- [ole32!CoUninitialize function](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-couninitialize) - Microsoft Learn
- [ole32!CoCreateInstance function](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) - Microsoft Learn
- [IUnknown interface](https://learn.microsoft.com/en-us/windows/win32/api/unknwn/nn-unknwn-iunknown) - Microsoft Learn

## What is `HRESULT`?

`HRESULT` stands for "Handle to Result" and is a standardized data type
used in Microsoft Windows programming to represent the outcome of a
function call. It is a 32-bit value that indicates whether a function call
succeeded or failed and, if it failed, provides additional information about
the cause of the failure.

In general, `HRESULT` values can be divided into two categories:

1. **Success Codes**: `HRESULT` values where bit 31 is set to 0, indicating
   that the function call succeeded. Success codes typically have a value of 0 or a positive integer.

2. **Error Codes**: `HRESULT` values where bit 31 is set to 1, indicating
   that the function call failed. Error codes typically have negative
   values, but they can vary depending on the facility code and error code.

## Please tell me the typical HRESULT values

Here are some of the typical `HRESULT` values used in Windows programming:

1. **`S_OK`**: This value indicates that the operation completed successfully.
   It is commonly returned by functions to indicate successful execution.

2. **`E_FAIL`**: This value indicates that the operation failed for unspecified
   reasons. It is a generic error code used when no specific error
   information is available.

3. **`E_INVALIDARG`**: This value indicates that one or more arguments
   passed to a function are invalid. It is commonly used to indicate
   parameter validation failures.

4. **`E_OUTOFMEMORY`**: This value indicates that the operation failed
   due to insufficient memory. It is commonly returned when memory
   allocation or other resource allocation fails.

5. **`E_NOINTERFACE`**: This value indicates that the requested interface
   is not supported by the object. It is commonly returned by the
   `QueryInterface` method when the requested interface cannot be obtained.

## What macros handle `HRESULT`?

In Microsoft Windows programming, there are several macros commonly used to
handle `HRESULT` values. These macros help developers check the result of
function calls and handle errors appropriately.

Some of the most commonly used macros include:

1. **`SUCCEEDED`**: This macro checks whether an `HRESULT` value represents a
   successful operation. It returns `TRUE` if the value's high-order bit (bit 31)
   is 0, indicating success.

    ```cxx
    #define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
    ```

    Example usage:
    ```cxx
    HRESULT hr = SomeFunction();
    if (SUCCEEDED(hr))
    {
        // Operation succeeded
    }
    ```

2. **`FAILED`**: This macro checks whether an `HRESULT` value represents a
   failed operation. It returns true if the value's high-order bit (bit 31) is 1,
   indicating failure.

    ```cxx
    #define FAILED(hr) (((HRESULT)(hr)) < 0)
    ```

    Example usage:
    ```cxx
    HRESULT hr = SomeFunction();
    if (FAILED(hr))
    {
        // Handle error
    }
    ```

3. **`HRESULT_FROM_WIN32`**: This macro converts a Win32 error code (represented
   as an integer) into an HRESULT value. It combines the Win32 error code with
   the `FACILITY_WIN32` facility code.

    ```cxx
    #define FACILITY_WIN32 7
    #define HRESULT_FROM_WIN32(x) (x ? ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)) : 0)
    ```

    Therefore, `HRESULT_FROM_WIN32(...)` becomes a `HRESULT` value that can
    be represented as `0x8007XXXX` or `S_OK` (0).

    Example usage:
    ```cxx
    DWORD dwError = GetLastError();
    HRESULT hr = HRESULT_FROM_WIN32(dwError);
    ```

4. **`HRESULT_CODE`**: This macro extracts the error code portion (bits 15-0)
   from an `HRESULT` value.

    ```cxx
    #define HRESULT_CODE(hr) ((hr) & 0xFFFF)
    ```

    Example usage:
    ```cxx
    HRESULT hr = SomeFunction();
    DWORD dwErrorCode = HRESULT_CODE(hr);
    ```

These macros are commonly used in Windows programming to simplify error handling
and make code more readable and maintainable. They help developers check the
result of function calls, handle errors, and extract error information from
`HRESULT` values.

## How to register a COM component in programming?

To register a COM component programmatically, you typically use the
`DllRegisterServer` function of a DLL file, which is a standard entry point
for registering COM objects. Here's a general outline of the steps involved
in registering a COM component programmatically:

1. **Implement DllRegisterServer**: Implement the `DllRegisterServer` function
   in your COM component's code. This function is responsible for adding the
   necessary registry entries to register the component with the operating system.

    ```cxx
    STDAPI DllRegisterServer(void)
    {
        // Add registry entries to register COM component
        // Return S_OK if registration is successful
        // Return an appropriate HRESULT value if registration fails
    }
    ```

2. **Add Registry Entries**: Within the `DllRegisterServer` function, add
   the necessary registry entries to register the COM component. These entries
   typically include information about the class identifier (CLSID),
   programmatic identifier (ProgID), interfaces, and other properties of the
   component.

    Example registry entry for a COM class:

    ```
    HKEY_CLASSES_ROOT\CLSID\{YourCLSID}:
        (Default) = "Your COM Class Name"
    HKEY_CLASSES_ROOT\CLSID\{YourCLSID}\InprocServer32:
        (Default) = "Path to Your DLL"
        ThreadingModel = "Apartment" (or other threading model)
    ```

3. **Call RegCreateKeyEx and RegSetValueEx**: Use the Windows API functions
   `RegCreateKeyEx` and `RegSetValueEx` to create registry keys and
   set registry values within the `DllRegisterServer` function.

    Example:

    ```cxx
    HKEY hKey;
    DWORD dwDisposition;
    LSTATUS result = RegCreateKeyEx(HKEY_CLASSES_ROOT, L"CLSID\\{YourCLSID}", 0, NULL, 0, KEY_WRITE, NULL, &hKey, &dwDisposition);
    if (result == ERROR_SUCCESS)
    {
        result = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE*)"Your COM Class Name", sizeof("Your COM Class Name"));
        // Check result and continue with other registry entries
        RegCloseKey(hKey);
    }
    ```

4. **Return Appropriate HRESULT**: Return `S_OK` from the `DllRegisterServer`
   function if the registration is successful. If registration fails,
   return an appropriate HRESULT value indicating the reason for the failure.

5. **Call DllRegisterServer**: Finally, call the `DllRegisterServer` function
   of your COM component from a command prompt or a script to register the
   component with the operating system.

Keep in mind that registering a COM component programmatically requires
administrative privileges, as it involves modifying the system registry.
Additionally, unregistering the component can be done similarly by
implementing the `DllUnregisterServer` function and calling it to remove
the registry entries.

## What is `regsvr32.exe`?

`regsvr32.exe` is a command-line utility in Microsoft Windows used for
registering and unregistering DLL (Dynamic Link Library) files as COM
(Component Object Model) components in the Windows Registry. COM components
are software entities that expose functionality to other components or
applications through a standardized interface.

Here's a brief overview of how `regsvr32.exe` works:

1. **Registering DLLs**: When you run `regsvr32.exe` with the path to a
   DLL file as an argument, it calls the `DllRegisterServer` function
   exported by the DLL. This function typically performs tasks such as
   adding information about the COM components to the Windows Registry,
   including class identifiers (CLSIDs), programmatic identifiers (ProgIDs),
   and other registration information.

   Example: 
   ```
   regsvr32.exe MyComponent.dll
   ```

2. **Unregistering DLLs**: Conversely, running `regsvr32.exe` with the
   `/u` option unregisters a DLL by calling the `DllUnregisterServer`
   function exported by the DLL. This function removes the registration
   information from the Windows Registry.

   Example:
   ```
   regsvr32.exe /u MyComponent.dll
   ```

`regsvr32.exe` is commonly used during the installation and registration
of COM components, such as ActiveX controls, custom DLLs, and other system
extensions. It is an essential tool for developers and system administrators
working with COM-based applications and components in the Windows environment.

See also: [$(REACTOS)/base/system/regsvr32](https://github.com/reactos/reactos/tree/master/base/system/regsvr32)

## How to register a COM component in ATL programming?

In ATL (Active Template Library) programming, you can register a COM
component using the `CComModule::RegisterServer` method. This method is
typically called during the initialization of your ATL-based COM server
to register the component's CLSID (Class Identifier), ProgID (Programmatic
Identifier), and other registration information in the Windows Registry.

Here's how you can register a COM component in ATL programming:

1. Implement the `DllRegisterServer` function in your COM server project.
   This function should call the `RegisterServer` method of the global
   `CComModule` object to register the component in the Windows Registry.

   ```cxx
   CComModule gModule;

   HRESULT DllRegisterServer()
   {
       // Register the COM server
       return gModule.RegisterServer(TRUE);
   }
   ```

2. In your COM server's `DllMain` function, initialize the `gModule` object.

   ```cxx
   BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
   {
       if (dwReason == DLL_PROCESS_ATTACH)
       {
           // Initialize ATL module
           gModule.Init(ObjectMap, hInstance, NULL);
       }
       else if (dwReason == DLL_PROCESS_DETACH)
       {
           // Terminate ATL module
           gModule.Term();
       }
       return TRUE;
   }
   ```

3. Add `ObjectMap`.

   ```cxx
   BEGIN_OBJECT_MAP(ObjectMap)
       OBJECT_ENTRY(CLSID_YourClass1, YourClass1)
       OBJECT_ENTRY(CLSID_YourClass2, YourClass2)
       ...
   END_OBJECT_MAP()
   ```

5. Register the COM component by running `regsvr32.exe` with the path to the
   DLL file as an argument.

   ```
   regsvr32.exe YourComponent.dll
   ```

6. Verify that the component is registered correctly by checking the Windows
   Registry for the registered CLSID and ProgID entries.

## What is `DllCanUnloadNow`?

The `DllCanUnloadNow` function is called by the COM runtime to determine
whether it is safe to unload the DLL. The function returns an `HRESULT` value
indicating whether the DLL can be unloaded:

- If the function returns `S_OK`, it indicates that there are no active
  references to any objects in the DLL, and it is safe to unload.
- If the function returns `S_FALSE`, it indicates that there are still
  active references to objects in the DLL, and it is not safe to unload.

The typical implementation of `DllCanUnloadNow` is:

```c
STDAPI DllCanUnloadNow()
{
    return (g_dwRefCount == 0) ? S_OK : S_FALSE;
}
```

Or:

```c
STDAPI DllCanUnloadNow()
{
    return gModule.DllCanUnloadNow();
}
```

## What is `DllGetClassObject`?

`DllGetClassObject` is a function typically implemented in a DLL file that contains
COM (Component Object Model) components. It is used to create instances of COM objects
implemented by the DLL.

The typical implementation of `DllGetClassObject` is:

```c
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
    HRESULT hr = E_FAIL;

    if (IsEqualCLSID(rclsid, CLSID_MyComponent))
    {
        CMyComponentFactory *pFactory = new CMyComponentFactory();
        if (pFactory)
        {
            // Query for the requested interface
            hr = pFactory->QueryInterface(riid, ppv);
            pFactory->Release();
        }
        else
        {
            hr = E_OUTOFMEMORY;
        }
    }

    return hr;
}
```

Or:

```cxx
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
    return gModule.DllGetClassObject(rclsid, riid, ppv);
}
```

## How to use `QueryInterface`?

```cxx
// Query for the IID of the desired interface
IMyInterface *pMyInterface = NULL;
HRESULT hr = pUnknown->QueryInterface(IID_IMyInterface, (void**)&pMyInterface);
if (SUCCEEDED(hr)) // Success!
{
    // Use pMyInterface...
    pMyInterface->SomeMethod();

    // Release the interface when done
    pMyInterface->Release();
}
```

Or:

```
CComPtr<IMyInterface> pMyInterface;
HRESULT hr = pUnknown->QueryInterface(IID_IMyInterface, (void**)&pMyInterface);
if (SUCCEEDED(hr)) // Success!
{
    // Use pMyInterface...
    pMyInterface->SomeMethod();

    // pMyInterface will be automatically released.
}
```

## References

- `REF001`: Win32 Programmer's Reference
- `REF002`: [Geoff Chappell, Software Analyst](https://geoffchappell.com/studies/windows/)
- `REF003`: [Microsoft Learn](https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows)
- `REF004`: [The Old New Thing](https://devblogs.microsoft.com/oldnewthing/)
- `REF005`: [Component Object Model - Wikipedia](https://en.wikipedia.org/wiki/Component_Object_Model)

## License

- MIT

## Copyright

- Copyright © 2024 katahiromz.
- Some auto-generated resource data is copyrighted by Microsoft. You may not use them directly in your products.
