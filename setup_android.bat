@echo off

git > nul
if %errorlevel% == 9009 goto nogit

rem   we need admin for symlinks for some reason
net session > nul
if not %errorlevel% == 0 goto noadmin

cd /d %~dp0
copy_assets
cd android-project\app\jni
git clone --recursive https://github.com/libsdl-org/SDL.git
git clone --recursive https://github.com/libsdl-org/SDL_image.git
git clone --recursive https://github.com/libsdl-org/SDL_ttf.git
git clone --recursive https://github.com/madler/zlib.git
mklink /d liblcf "..\..\..\external_liblcf"
cd src
mklink /d voidsprite "..\..\..\..\freesprite"
exit

:noadmin
echo --------------------------
echo Please launch this script with admin privileges
pause
exit

:nogit
echo --------------------------
echo git is not installed.
echo Install it now? [Y/N]
set /p "ch=>"
if "%ch%" == "Y" goto psinstallgit
if "%ch%" == "y" goto psinstallgit
pause
exit

:wingetdoesntfeellikeit
echo Failed to install git through winget
echo Download git manually at https://git-scm.com/downloads
pause
exit

:psinstallgit
for /f %%i in ('winget -v') do set wingetversion=%%i
rem  if winget is older than 1.6 it will always fail because the cdn url is outdated
winget install -e --id Git.Git
if %errorlevel% == 9009 goto wingetdoesntfeellikeit
if %errorlevel% == -1073741819 goto wingetdoesntfeellikeit
pause
echo Git should now be installed
echo Restart this script.
pause
exit
