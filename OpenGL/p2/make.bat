@echo off
echo.
GOTO compile
echo Setting compiler parameters...

set "flags=-Wall"

set "include_glew=-I..\glew-2.0.0\include\GL"
set "include_glm=-I..\glm-0.9.8.4\glm"

set "lib_glew=-L..\glew-2.0.0\lib\Release\x64"

set include=%include_glew% %include_glm% %include_sdl%
set lib=%lib_glew% %lib_sdl% %bin_sdl%

set "mingw32=-lmingw32"
set "opengl=-opengl"

set link=%mingw32% %opengl%

IF "%1%"=="" (
	echo No parameter found. 
	GOTO default
)

IF "%1%"=="-freeglut" (
	echo FreeGLUT setted.
)

IF "%1%"=="-glfw" (
	echo GLFW setted.
)

IF "%1%"=="-sdl2" (
:default
	echo SDL2 setted.
	set "lib_sdl=-L..\SDL2-2.0.5\i686-w64-mingw32\lib"
	set "bin_sdl=-L..\SDL2-2.0.5\i686-w64-mingw32\bin"
	set "include_sdl=-I..\SDL2-2.0.5\i686-w64-mingw32\include\SDL2"
	set "link_SDL2main=-lSDL2main"
	set "link_SDL2=-lSDL2"
	echo TESTE1
	set "%include%=%include% %include_sdl%"
	set "%lib%=%lib% %lib_sdl% %bin_sdl%"
	set "%link%=%link% %link_SDL2main% %link_SDL2%"
	echo TESTE
)

echo Done!
echo Compiling...
echo.

g++ main.cpp %flags% %include% %lib% %link% -o main

echo Done!
echo %flags% %include% %lib% %link%
:compile
g++ main.cpp --std=c++14 -Wall -I../include -L../lib -lmingw32 -lSDL2main -lSDL2 -lglew32s -lopengl32 -o main