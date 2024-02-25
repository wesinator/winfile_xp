/*
contains defns for all the changes required for Winfile to run on Windows XP.
credit to https://github.com/blackwingcat/winfile_nt5/commit/e55dd95ea869383ad52c2bcbd58bf4f0ee0681d2 for starting this effort.

Copyright (c) 2024 wesinator
*/
#pragma once

// used in wfloc.c, wfinit.c
typedef int(__stdcall* GetLocaleInfoEx_)(LPCWSTR lpLocaleName, LCTYPE LCType, LPWSTR lpLCData, int cchData);
typedef LCID(__stdcall* LocaleNameToLCID_)(LPCWSTR lpName, DWORD dwFlags);

// used in wfgoto.cpp
// modified from https://github.com/restic/restic/issues/4155
#define IO_REPARSE_TAG_MOUNT_POINT      (0xA0000003)
#define IO_REPARSE_TAG_HSM              (0xC0000004)
#define IO_REPARSE_TAG_DRIVE_EXTENDER   (0x80000005)
#define IO_REPARSE_TAG_HSM2             (0x80000006)
#define IO_REPARSE_TAG_SIS              (0x80000007)
#define IO_REPARSE_TAG_WIM              (0x80000008)
#define IO_REPARSE_TAG_CSV              (0x80000009)
#define IO_REPARSE_TAG_DFS              (0x8000000A)
#define IO_REPARSE_TAG_FILTER_MANAGER   (0x8000000B)
#define IO_REPARSE_TAG_SYMLINK          (0xA000000C)
#define IO_REPARSE_TAG_IIS_CACHE        (0xA0000010)
#define IO_REPARSE_TAG_DFSR             (0x80000012)
#define IO_REPARSE_TAG_DEDUP            (0x80000013)
#define IO_REPARSE_TAG_NFS              (0x80000014)
#define IO_REPARSE_TAG_FILE_PLACEHOLDER (0x80000015)
#define IO_REPARSE_TAG_WOF              (0x80000017)
#define IO_REPARSE_TAG_WCI              (0x80000018)
#define IO_REPARSE_TAG_WCI_1            (0x90001018)
#define IO_REPARSE_TAG_GLOBAL_REPARSE   (0xA0000019)
#define IO_REPARSE_TAG_CLOUD            (0x9000001A)
#define IO_REPARSE_TAG_CLOUD_1          (0x9000101A)
#define IO_REPARSE_TAG_CLOUD_2          (0x9000201A)
#define IO_REPARSE_TAG_CLOUD_3          (0x9000301A)
#define IO_REPARSE_TAG_CLOUD_4          (0x9000401A)
#define IO_REPARSE_TAG_CLOUD_5          (0x9000501A)
#define IO_REPARSE_TAG_CLOUD_6          (0x9000601A)
#define IO_REPARSE_TAG_CLOUD_7          (0x9000701A)
#define IO_REPARSE_TAG_CLOUD_8          (0x9000801A)
#define IO_REPARSE_TAG_CLOUD_9          (0x9000901A)
#define IO_REPARSE_TAG_CLOUD_A          (0x9000A01A)
#define IO_REPARSE_TAG_CLOUD_B          (0x9000B01A)
#define IO_REPARSE_TAG_CLOUD_C          (0x9000C01A)
#define IO_REPARSE_TAG_CLOUD_D          (0x9000D01A)
#define IO_REPARSE_TAG_CLOUD_E          (0x9000E01A)
#define IO_REPARSE_TAG_CLOUD_F          (0x9000F01A)
#define IO_REPARSE_TAG_CLOUD_MASK       (0x0000F000)
#define IO_REPARSE_TAG_APPEXECLINK      (0x8000001B)
#define IO_REPARSE_TAG_GVFS             (0x9000001C)
#define IO_REPARSE_TAG_STORAGE_SYNC     (0x8000001E)
#define IO_REPARSE_TAG_WCI_TOMBSTONE    (0xA000001F)
#define IO_REPARSE_TAG_UNHANDLED        (0x80000020)
#define IO_REPARSE_TAG_ONEDRIVE         (0x80000021)
#define IO_REPARSE_TAG_GVFS_TOMBSTONE   (0xA0000022)

// used in lfn.c
typedef BOOL(__stdcall* Wow64DisableWow64FsRedirection_)(PVOID* OldValue);
typedef BOOL(__stdcall* Wow64RevertWow64FsRedirection_)(PVOID OldValue);

// GetProcAddress should call `CreateSymbolicLinkW`
typedef BOOL(__stdcall* CreateSymbolicLink_)(LPCWSTR lpSymlinkFileName, LPCWSTR lpTargetFileName, DWORD dwFlags);

// hardcoding SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE to avoid compile errors for win7/xp target build
// // https://blogs.windows.com/windowsdeveloper/2016/12/02/symlinks-windows-10/
#ifndef SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE
#define SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE 0x2


// used in tbar.c
typedef HRESULT(__stdcall* SetWindowTheme_)(HWND hwnd, LPCWSTR pszSubAppName, LPCWSTR pszSubIdList);

// used in wfcomman.c
// GetProcAddress has to call the `RegGetValueW` function to work correctly 
typedef LSTATUS(__stdcall* RegGetValue_)(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
