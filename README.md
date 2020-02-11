# Find Median
Zixuan Guo - guozixua@grinnell.edu

## Getting Started
To compile the source code into binary, run ```make```. All the object files generated during compilation phase will be placed under ```obj``` folder. You can run ```make clean``` to get ride them. Alternatively, you can also use ```cmake``` to build your code.

By default, the Makefile use gcc to compile the source code, you can also switch to other compiler by changing the ```CC``` variable in the Makefile. Notice that our codes include some feature that only supported after C99. Therefore, please ensure that your compiler atleast support C99.

Here is the gcc we used
```cmd
$ gcc --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 11.0.0 (clang-1100.0.33.17)
Target: x86_64-apple-darwin19.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```
