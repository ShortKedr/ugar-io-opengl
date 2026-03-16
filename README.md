# Ugar.io OpenGL

Simplest single-player copy of Agar.io game, made with C++ and OpenGL.

This project have another implementation with Qt framework: [watch here](https://github.com/ShortKedr-OpenSource/ugar-io-qt).

### Requirements:
1. Visual Studio 2022 with the Desktop development with C++ workload
1. MSVC v143 toolset with C++20 support
1. Windows 10/11 SDK
1. FreeGLUT headers and libraries available to the Visual Studio project
1. Microsoft Visual C++ Redistributable for Visual Studio 2022 on the target machine

### Game build:
Game build placed in `BuildRelease` folder.  

### Building with Visual Studio 2022
Open `Ugar.io OpenGL.sln` in Visual Studio 2022 and build either `Debug|Win32` or `Release|Win32`.

The project now explicitly targets the MSVC `v143` toolset and the C++20 language standard.
