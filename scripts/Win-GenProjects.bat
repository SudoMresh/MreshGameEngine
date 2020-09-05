@echo off
pushd %~dp0\..\
call ThirdParty\premake\bin\premake5.exe vs2019
popd
PAUSE
