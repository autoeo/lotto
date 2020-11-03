# Microsoft Developer Studio Project File - Name="LT" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=LT - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LT.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LT.mak" CFG="LT - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LT - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "LT - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LT - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "./" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"bin/LT.exe"

!ELSEIF  "$(CFG)" == "LT - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "./" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"binD/LT.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "LT - Win32 Release"
# Name "LT - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DlgGetNumberList.cpp
# End Source File
# Begin Source File

SOURCE=.\LT.cpp
# End Source File
# Begin Source File

SOURCE=.\LT.rc
# End Source File
# Begin Source File

SOURCE=.\LTDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgGetNumberList.h
# End Source File
# Begin Source File

SOURCE=.\LT.h
# End Source File
# Begin Source File

SOURCE=.\LTDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\LT.ico
# End Source File
# Begin Source File

SOURCE=.\res\LT.rc2
# End Source File
# End Group
# Begin Group "CommonSrc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CommonSrc\CmbRecentThNumber.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\CmbRecentThNumber.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\Defines.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\ListCtrlNum.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\ListCtrlNum.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\listctrlnumall.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\listctrlnumall.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\NumberFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\NumberFilter.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\NumberManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\NumberManager.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\XLAutomation.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\XLAutomation.h
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\XLEzAutomation.cpp
# End Source File
# Begin Source File

SOURCE=.\CommonSrc\XLEzAutomation.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
