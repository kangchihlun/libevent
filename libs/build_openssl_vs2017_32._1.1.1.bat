@echo "开始编译openssl 可加入学员QQ群979056499交流"
set VS="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsamd64_x86.bat"
set OUT=E:\libevent\out\vs2017_32\openssl
call %VS%
E:
cd E:\libevent\openssl-1.1.1
perl Configure VC-WIN32 --prefix=%OUT%
nmake clean
nmake
nmake install
@echo "build openssl end"
pause

