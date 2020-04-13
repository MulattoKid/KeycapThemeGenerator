# KeycapThemeGenerator
Simple tool for generating themes for code editors based on keycap sets.

## Supported Editors
- VSCode

## Build
```
git clone https://github.com/MulattoKid/KeycapThemeGenerator.git
cd KeycapThemeGenerator
mkdir build
cd build
```
### Linux
```
cmake ..
make <debug/release>
```
### Windows
```
cmake -G <Visual Studio Version> ..
<build using CMake or Visual Studio>
```

## Run
```
./keycap_theme_generator --base ffffff --primary 85b0cc --secondary efb9c0
```
This will print a configuration which you can copy and paste into your settings file.

For further instructions, run ```./keycap_theme_generator --help```.

## Examples
[GKM Fuyu](https://geekhack.org/index.php?topic=104148.0)
<img src="https://i.imgur.com/So1foDs.png" alt="drawing" width="1000"/>
