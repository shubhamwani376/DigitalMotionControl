
cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2022b\bin\win64\gmake"  DEPRULES=1 -j5  -f wednesday_stuff.mk all) else ("C:\PROGRA~1\MATLAB\R2022b\bin\win64\gmake"  DEPRULES=1 -j5  -f wednesday_stuff.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1