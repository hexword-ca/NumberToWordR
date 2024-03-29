# numbToWords - WinNumberToWordR

## About this Project
This project is Recursive C/C++ function to convert a Whole number to Words.  
   
This code was originally uploaded and tested at codepad.org  
[http://codepad.org/C29M1wUQ](http://codepad.org/C29M1wUQ)
  
## Compiling Instructions - Linux
Install CMake and all other required compilers and tools.
Then use:
```
wsl01@XYZ:~/Source/NumberToWordR$ mkdir output
wsl01@XYZ:~/Source/NumberToWordR$ cmake -B ./output
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wsl01/Source/NumberToWordR/output
wsl01@XYZ:~/Source/NumberToWordR$ cmake --build ./output
[ 50%] Building CXX object CMakeFiles/NumberToWordR.dir/NumberToWordR.cpp.o
[100%] Linking CXX executable NumberToWordR
[100%] Built target NumberToWordR
wsl01@XYZ:~/Source/NumberToWordR$ ./output/NumberToWordR
Hello World!
Number to Convert: 2305843008139952128
Converted result: two quintillion three hundred five quadrillion eight hundred forty three trillion eight billion one hundred thirty nine million nine hundred fifty two thousand one hundred twenty eight

wsl01@XYZ:~/Source/NumberToWordR$
```

## Compiling Instructions - Windows 11
Install CMake and Vistual Studio 2017 Build Tools.
Then use:
```
C:\Users\XYZ\Source\NumberToWordR>mkdir output

C:\Users\XYZ\Source\NumberToWordR>cmake -B ./output
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.26085.
-- The C compiler identification is MSVC 19.39.33520.0
-- The CXX compiler identification is MSVC 19.39.33520.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (5.7s)
-- Generating done (0.0s)
-- Build files have been written to: C:/Users/XYZ/Source/NumberToWordR/output

C:\Users\XYZ\Source\NumberToWordR>cmake --build ./output
MSBuild version 17.9.5+33de0b227 for .NET Framework

  1>Checking Build System
  Building Custom Rule C:/Users/XYZ/Source/NumberToWordR/CMakeLists.txt
  NumberToWordR.cpp
  NumberToWordR.vcxproj -> C:\Users\XYZ\Source\NumberToWordR\output\Debug\NumberToWordR.exe
  Building Custom Rule C:/Users/XYZ/Source/NumberToWordR/CMakeLists.txt

C:\Users\XYZ\Source\NumberToWordR>output\Debug\NumberToWordR.exe
Hello World!
Number to Convert: 2305843008139952128
Converted result: two quintillion three hundred five quadrillion eight hundred forty three trillion eight billion one hundred thirty nine million nine hundred fifty two thousand one hundred twenty eight


C:\Users\XYZ\Source\NumberToWordR>
```


