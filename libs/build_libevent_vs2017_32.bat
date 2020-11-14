@echo "开始编译libevent"
set VS="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsamd64_x86.bat"
set OUT=E:\libevent\out\vs2017_32\libevent
call %VS%
cd libevent-master
nmake /f Makefile.nmake clean
nmake /f Makefile.nmake OPENSSL_DIR=E:\libevent\out\vs2017_32\openssl
md %OUT%\lib
md %OUT%\bin
md %OUT%\include
copy /Y *.lib %OUT%\lib
xcopy /S/Y include %OUT%\include\
xcopy /S/Y WIN32-Code\nmake %OUT%\include\
copy /Y *.dll %OUT%\bin
copy /Y *.exe %OUT%\bin
@echo "libevent编译结束"