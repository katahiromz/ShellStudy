#include <windows.h>
#include <stdio.h>
#include <shlobj.h>
#include <initguid.h>
#include <string>
#include <vector>
#include <strsafe.h>

template <typename T_CHAR>
inline void mstr_trim(std::basic_string<T_CHAR>& str, const T_CHAR* spaces)
{
    typedef std::basic_string<T_CHAR> string_type;
    size_t i = str.find_first_not_of(spaces);
    size_t j = str.find_last_not_of(spaces);
    if ((i == string_type::npos) || (j == string_type::npos))
    {
        str.clear();
    }
    else
    {
        str = str.substr(i, j - i + 1);
    }
}

template <typename T_STR>
inline bool
mstr_replace_all(T_STR& str, const T_STR& from, const T_STR& to)
{
    bool ret = false;
    size_t i = 0;
    for (;;) {
        i = str.find(from, i);
        if (i == T_STR::npos)
            break;
        ret = true;
        str.replace(i, from.size(), to);
        i += to.size();
    }
    return ret;
}

template <typename T_STR>
inline bool
mstr_replace_all(T_STR& str,
                 const typename T_STR::value_type *from,
                 const typename T_STR::value_type *to)
{
    return mstr_replace_all(str, T_STR(from), T_STR(to));
}

template <typename T_STR_CONTAINER>
inline void
mstr_split(T_STR_CONTAINER& container,
    const typename T_STR_CONTAINER::value_type& str,
    const typename T_STR_CONTAINER::value_type& chars)
{
    container.clear();
    size_t i = 0, k = str.find_first_of(chars);
    while (k != T_STR_CONTAINER::value_type::npos)
    {
        container.push_back(str.substr(i, k - i));
        i = k + 1;
        k = str.find_first_of(chars, i);
    }
    container.push_back(str.substr(i));
}

std::wstring BytesTextFromCLSID(REFCLSID clsid)
{
    std::wstring ret;
    const BYTE *pb = (LPBYTE)&clsid;
    for (size_t ib = 0; ib < sizeof(clsid); ++ib)
    {
        if (ib)
            ret += L' ';
        WCHAR sz[3];
        StringCchPrintfW(sz, _countof(sz), L"%02X", pb[ib]);
        ret += sz;
    }
    return ret;
}

CLSID CLSIDFromDefineGUID(std::wstring arg)
{
    CLSID ret;
    mstr_trim(arg, L" \t");
    if (arg.find(L"DEFINE_GUID") == 0)
        arg.erase(0, 11);
    mstr_trim(arg, L" \t");
    if (arg.size() && arg[0] == L'(')
        arg.erase(0, 1);
    mstr_trim(arg, L" \t");
    if (arg.size() && arg[arg.size() - 1] == L';')
        arg.erase(arg.size() - 1, 1);
    mstr_trim(arg, L" \t");
    if (arg.size() && arg[arg.size() - 1] == L')')
        arg.erase(arg.size() - 1, 1);
    mstr_trim(arg, L" \t");
    mstr_replace_all(arg, L" ", L"");
    mstr_replace_all(arg, L"\t", L"");

    std::vector<std::wstring> items;
    mstr_split(items, arg, L",");

    if (items.size() != 12)
    {
        ret = GUID_NULL;
        return ret;
    }

    ret.Data1 = wcstoul(items[1].c_str(), NULL, 0);
    ret.Data2 = (USHORT)wcstoul(items[2].c_str(), NULL, 0);
    ret.Data3 = (USHORT)wcstoul(items[3].c_str(), NULL, 0);
    ret.Data4[0] = (BYTE)wcstoul(items[4].c_str(), NULL, 0);
    ret.Data4[1] = (BYTE)wcstoul(items[5].c_str(), NULL, 0);
    ret.Data4[2] = (BYTE)wcstoul(items[6].c_str(), NULL, 0);
    ret.Data4[3] = (BYTE)wcstoul(items[7].c_str(), NULL, 0);
    ret.Data4[4] = (BYTE)wcstoul(items[8].c_str(), NULL, 0);
    ret.Data4[5] = (BYTE)wcstoul(items[9].c_str(), NULL, 0);
    ret.Data4[6] = (BYTE)wcstoul(items[10].c_str(), NULL, 0);
    ret.Data4[7] = (BYTE)wcstoul(items[11].c_str(), NULL, 0);

    return ret;
}

CLSID CLSIDFromBytesText(std::wstring arg)
{
    mstr_replace_all(arg, L"0x", L"");

    CLSID ret;
    std::vector<BYTE> bytes;
    WCHAR sz[3];
    size_t ich = 0, ib = 0;
    for (auto ch : arg)
    {
        if (!iswxdigit(ch))
            continue;
        if ((ich % 2) == 0)
        {
            sz[0] = ch;
        }
        else
        {
            sz[1] = ch;
            sz[2] = 0;
            BYTE byte = (BYTE)wcstoul(sz, NULL, 16);
            bytes.push_back(byte);
            ib++;
        }
        ich++;
    }

    if (ib != sizeof(CLSID))
        ret = GUID_NULL;
    else
        CopyMemory(&ret, bytes.data(), sizeof(ret));

    return ret;       
}

void PrintGUID(REFCLSID clsid)
{
    printf("#include <initguid.h>\n");

    printf("DEFINE_GUID(<Name>, 0x%08X, 0x%04X, 0x%04X, 0x%02X, 0x%02X, 0x%02X, "
        "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X);\n",
        clsid.Data1, clsid.Data2, clsid.Data3,
        clsid.Data4[0], clsid.Data4[1], clsid.Data4[2], clsid.Data4[3],
        clsid.Data4[4], clsid.Data4[5], clsid.Data4[6], clsid.Data4[7]);

#if 1
    WCHAR szCLSID[40];
    StringFromGUID2(clsid, szCLSID, _countof(szCLSID));
    printf("%ls\n", szCLSID);
#else
    printf("{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}\n",
        clsid.Data1, clsid.Data2, clsid.Data3,
        clsid.Data4[0], clsid.Data4[1], clsid.Data4[2], clsid.Data4[3],
        clsid.Data4[4], clsid.Data4[5], clsid.Data4[6], clsid.Data4[7]);
#endif

    auto strBytes = BytesTextFromCLSID(clsid);
    printf("%ls\n", strBytes.c_str());
}

int _wmain(int argc, wchar_t **argv)
{
    if (argc <= 1 || lstrcmpiW(argv[1], L"--help") == 0)
    {
        std::puts("Usage: guidconv guid_str");
        return 0;
    }

    std::wstring arg = argv[1];
    mstr_trim(arg, L" \t\r\n");

    CLSID clsid;
    if (arg[0] == L'{')
    {
        CLSIDFromString(arg.c_str(), &clsid);
    }
    else if (arg.find(L"DEFINE_GUID(") == 0)
    {
        clsid = CLSIDFromDefineGUID(arg);
    }
    else if (iswxdigit(arg[0]))
    {
        clsid = CLSIDFromBytesText(arg);
    }

    if (IsEqualGUID(clsid, GUID_NULL))
    {
        printf("error: GUID_NULL\n");
    }

    PrintGUID(clsid);

    return 0;
}

int main(void)
{
    INT argc;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    INT ret = _wmain(argc, argv);
    LocalFree(argv);
    return ret;
}
