# ![icon](winfile.png) Windows File Manager (WinFile) for Windows XP (32-bit NT 5.1) thru Windows 10

The Windows File Manager lives again and runs as a native x86, now supporting Windows XP.
The goal of this project was to build a version of WinFile that would run fairly reliably on all versions of Windows from Windows XP SP3 (NT 5.1 32-bit) to Windows 10/11.
While there have been some forks that aimed to work on Server 2003/XP Professional x64 edition (NT 5.2), there was not a version that worked for Windows XP 32-bit based on NT 5.1

This current master was forked off from [maintainer Hermann Schinagl's excellent fork of the Microsoft trunk](https://github.com/schinagl/winfile) and contains changes/additions to WinFile over the years by many contributors.

I will consider bugs fixes and suggestions for minor changes to the master branch. Feel free to create a pull request or post issues as you see fit.

**NOTE**: support for versions of Windows older than XP / NT 5.1 is not the goal of this project, nor do I plan to test this on such systems. The binary may work on Win2k but will likely have more bugs.

![Winfile running in XP Professional SP3 32-bit](winfile_xpsp3_running.png)

## Download The App
See the [releases](https://github.com/wesinator/winfile_xp/releases)!
Binaries are statically linked so they run without installing the VC redist.

## Design changes and notes

To get this working for Windows XP, the main challenge was identifying APIs that were unsupported, and switching them out to dynamic loading of the addresses using `GetModuleHandleA`.
Fortunately, another (incomplete) fork started this work - https://github.com/blackwingcat/winfile_nt5/commit/e55dd95ea869383ad52c2bcbd58bf4f0ee0681d2

For this project, I created a separate header file `nt51_aliasing.h`, to make it easy to add necessary changes, and so that it is easier to track what changes were needed.

The following APIs were the main changes:
 - `GetLocaleInfoEx` and `LocaleNametoLCID` were changed to conditional dynamic loading.
 - `IO_REPARSE_TAG` definitions which are apparently used by tools such as OneDrive were hardcoded.
 - The Wow64Redirection APIs needed to be changed to dynamic loading, since 32-bit XP lacks these.
 - Symbolic linking that was introduced in NT6.0/Vista and [added to in Windows 10](https://blogs.windows.com/windowsdeveloper/2016/12/02/symlinks-windows-10/) needed to be defined.
 - `SetWindowTheme` which handles the window panes with the NT6+ theme was set to conditional dynamic loading, conditional on the presence of `uxtheme.dll` AND the GetModuleHandle call.

## Known issues
- Start PowerShell does not work on Windows XP
- Changing language/locales does not work on XP

All the functionality on Windows 7 (NT6.x) through Windows 10/11 is known to work.

------

## History
The Windows File manager was originally released with Windows 3.0 in the early 1990s.  You
can read more about the history at https://en.wikipedia.org/wiki/File_Manager_(Windows).

## Contributing

### Contributor License Agreement
As mentioned above, this project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.microsoft.com.

When you submit a pull request, a CLA-bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., label, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## License
Copyright (c) Microsoft Corporation. All rights reserved.

Licensed under the [MIT](LICENSE) License.

[NO_TRAIN]::
