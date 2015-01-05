@rem @echo off
@rem D&D preparations:
set maps=%~dp1
set mapname=%~n1

cd %~dp0


@Settings:
@rem in this version, with query support Type parametr is not actual
@rem set tip=custom
set csg=hlcsg.exe
set bsp=hlbsp.exe
set vis=hlvis.exe
set rad=hlrad.exe
set res=RESGen.exe
set cop=timecopier.exe
set rip=ripent.exe
@rem this setting can change output format to very strange....
@rem set shrpar= -verbose -chart -dev 6 -low -estimate
set shrpar= -dev -noinfo -estimate
@rem You can change variables below but you should not forget
@rem to place SPACE at the begin and end of string
set csgpar= -nowadtextures 
set bsppar= 
set vispar= -full 
set radpar= -bounce 8 -extra -smooth 100 
set respar= -o -k -f 
set rippar= -export -textdata 1 
@rem Old version:
@rem set temp=%~dp1%mapname%\%tip%_temp\
@rem New version:
set temp=%~dp1%mapname%\temp\

@Pre-compile process
@rem making temp folder
mkdir "%maps%%mapname%"
mkdir "%temp%"

@rem Copying map data
copy "%maps%%mapname%.map" "%temp%"
copy "%maps%%mapname%.rad" "%temp%"

@compilation
cd tools\
pushd c
%csg%%shrpar%%csgpar%"%temp%%mapname%"
%bsp%%shrpar%%bsppar%"%temp%%mapname%"
%vis%%shrpar%%vispar%"%temp%%mapname%"
%rad%%shrpar%%radpar%"%temp%%mapname%"
%res%%respar%"%temp%%mapname%"
%rip%%rippar%"%temp%%mapname%"
@rem  upper string makes .res file and .ent file
popd

@rem finalization
 
cmd.exe /c toripin.bat %* >"%maps%%mapname%\temp\ripin.bat"
cmd.exe /c toripout.bat %* >"%maps%%mapname%\temp\ripout.bat"
cmd.exe /c copyparc.bat %* >"%maps%%mapname%\timeend.bat"

copy %rip% "%maps%%mapname%\temp\"

call "%maps%%mapname%\timeend.bat"

erase "%maps%%mapname%\timeend.bat"


rmdir /s /q "%temp%"

pause