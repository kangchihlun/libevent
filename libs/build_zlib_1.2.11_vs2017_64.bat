set VS="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsx86_amd64.bat"
call %VS%
E:
cd zlib-1.2.11/zlib-1.2.11
nmake /f win32/Makefile.msc clean
nmake /f win32/Makefile.msc
@echo "build zlib end"
pause

