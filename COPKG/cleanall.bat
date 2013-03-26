@echo off

nmake /f ms\ntdll86.mak clean   > nul 2> nul
rmdir /s /q intermediate        > nul 2> nul
REM rmdir /s /q output              > nul 2> nul
