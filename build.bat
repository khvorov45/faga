@echo off

if exist shell.bat call shell.bat

where /q cl || (
  echo ERROR: "cl" not found - please run this from the "MSVC x64 native tools command prompt" or create shell.bat to set up the environment.
  exit /b 1
)

cl /nologo /Zi /FC /diagnostics:column ^
	/D_CRT_SECURE_NO_WARNINGS /DPLATFORM_WINDOWS /W3 ^
	/Fdbuild.pdb ^
	build.c ^
	/link Shell32.lib && build.exe
