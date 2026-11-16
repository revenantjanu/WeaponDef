@echo off
rem Open "x64 Native Tools Command Prompt for VS" and run this file from this folder.
cl /nologo /O2 /GS- /Zl /LD WeaponDef.cpp /link /NODEFAULTLIB /ENTRY:DllMain /SUBSYSTEM:WINDOWS kernel32.lib user32.lib gdi32.lib /OUT:6x_WeaponDef_by_Janu.dll
