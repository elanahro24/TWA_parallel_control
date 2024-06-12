set MATLAB=C:\MATLAB\R2010a
set MSVCDir=c:\program files (x86)\microsoft visual studio 9.0\VC

"C:\MATLAB\R2010a\rtw\bin\win32\envcheck" INCLUDE "c:\program files (x86)\microsoft visual studio 9.0\VC\include"
if errorlevel 1 goto vcvars32
"C:\MATLAB\R2010a\rtw\bin\win32\envcheck" PATH "c:\program files (x86)\microsoft visual studio 9.0\VC\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSINSTALLDIR=c:\program files (x86)\microsoft visual studio 9.0
set VCINSTALLDIR=c:\program files (x86)\microsoft visual studio 9.0\VC
set FrameworkSDKDir=c:\program files (x86)\microsoft visual studio 9.0\SDK\v3.5
call "C:\MATLAB\R2010a\toolbox\rtw\rtw\private\vcvars32_900.bat"

:make
cd .
nmake -f twa_parallel.mk  GENERATE_REPORT=1 INCLUDE_MDL_TERMINATE_FCN=1 COMBINE_OUTPUT_UPDATE_FCNS=0 MAT_FILE=1 MULTI_INSTANCE_CODE=0 INTEGER_CODE=0 PORTABLE_WORDSIZES=0 EXT_MODE=1
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
