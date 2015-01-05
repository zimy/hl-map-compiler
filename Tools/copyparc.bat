@echo off
@rem D&D preparations:
set maps=%~dp1
set mapname=%~n1
timecopier %maps% %mapname%

@rem echo copy ^%whatis^%\ripent.exe
@rem echo copy ^%whatis^%\ripin.bat
@rem echo copy ^%whatis^%\riout.bat
@echo on