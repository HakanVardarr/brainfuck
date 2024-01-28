@echo off

MSBuild.exe .\build\brainfuck.sln /verbosity:q
.\build\Debug\brainfuck.exe main.bf