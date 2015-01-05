@echo off
@rem D&D preparations:
set mapname=%~n1

echo ripent.exe -import -textdata 1 %mapname%
@echo on