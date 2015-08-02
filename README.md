# omniorb
omniORB with changes to support mingw64 from msys2

1. start mingw64-shell.bat in msys2
2. clone this repo locally
3. go to the omniORB clone directory
4. install python32 bit or python64 from https://www.python.org/downloads/
5. edit mk\platforms\x86_win32_mingw.mk and change PYTHON variable to point to where you installed python
6. build omniORB > cd src; make export
7. you have the directories bin/ include/ lib/ inside the top directory containing the executable and libraries


If you have issue with linking with libpython27.a, re-generate the python*/libs/libpython27.a
- 32bit: gendef.exe /c/Windows/SysWOW64/python27.dll && dlltool --dllname /c/Windows/SysWOW64/python27.dll --def python27.def --output-lib /f/bin/python32/libs/libpython27.a -m i386
- 64bit: gendef.exe /c/Windows/System32/python27.dll && dlltool --dllname /c/Windows/System32/python27.dll --def python27.def --output-lib /f/bin/python64/libs/libpython27.a



