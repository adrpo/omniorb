# omniorb
omniORB with changes to support mingw64 from msys2

1. start mingw64-shell.bat in msys2
2. clone this repo locally
3. go to the omniORB clone directory
4. install python64 bit on your computer https://www.python.org/ftp/python/2.7.10/python-2.7.10.amd64.msi
4. edit mk\platforms\x86_win32_mingw and change PYTHON variable to point to where you installed python
5. build omniORB > cd src; make export
6. you have the directories bin/ include/ lib/ inside the top directory containing the executable and libraries



