# o3de-dccsi-test-project

----

This repository contains:

A test project that caters to the DccScriptingInterface Gems needs (aka DCCsi)

DCCsi Gem is located here in O3DE repo:[o3de/Gems/AtomLyIntegration/TechnicalArt/DccScriptingInterface at development · o3de/o3de · GitHub](https://github.com/o3de/o3de/tree/development/Gems/AtomLyIntegration/TechnicalArt/DccScriptingInterface)

Notice:

- This is a developer oriented guide (building from source)

- This project also requires the o3de-multiplayersample-assets: https://github.com/o3de/o3de-multiplayersample-assets

# Get Started

## Clone O3DE Engine

```shell
# clone the o3de engine
> git clone https://github.com/o3de/o3de.git
Cloning into 'o3de'...
```

### Register the Engine

```batch
:: register the the engine, you only need to do this once
> c:\path\to\o3de\scripts\o3de register --this-engine
```

## Clone the o3de-multiplayersample-assets repo

```shell
# clone the project into a folder outside your engine repository folder
> git clone https://github.com/o3de/o3de-multiplayersample-assets.git
Cloning into 'o3de-multiplayersample-assets'...
```

### Register the Asset Gems with the Engine

Now make sure that the source gems are registered

```batch
:: register the gems with the engine, you only need to do this once
> o3de register --all-gems-path c:\path\to\o3de-multiplayersample-assets\Gems
```

## Clone the o3de-dccsi-test-project repo

```shell
# clone the project into a folder outside your engine repository folder
> git https://github.com/HogJonny-AMZN/o3de-dccsi-test-project
Cloning into 'o3de-dccsi-test-project'...
```

### Register the Project

Make sure your project is registered.

```batch
:: register the project with the engine, you only need to do this once
> c:\path\to\o3de\scripts\o3de register -p c:\path\to\o3de-dccsi-test-project
```

### Build the Engine and Project

## Option 1. Add Project to O3DE Project Manager

1. Launch your O3DE Project Manager (`o3de.exe`)

2. Use the blue button in the upper right labeled "New Project ...", and with the pulldown select "`Open Existing Project`"

3. Browse to and add the MPS Asset Test Project folder:  `C:\path\to\repo\o3de-dccsi-test-project`

4. You may be prompted to rebuild the project, you can attempt to build from the Project Manager (this will build in a project-centric way)

5. there are other options for building as a developer, I tend to build in an engine-centric way (option 2)

6. Launch the Editor for the project

## Option 2. Add via cli and build yourself

You can use the o3de cli tools to register your project with your engine.

```shell
# change directory to the egine root folder
> cd c:\path\to\your\o3de-engine
# register the gems with the engine, you only need to do this once
> scripts\o3de register --project-path C:\path\to\o3de-dccsi-test-project
```

[Configure and Build - Open 3D Engine](https://www.o3de.org/docs/user-guide/build/configure-and-build/)

As a developer, I often find it useful to build in an engine-centric way

```shell
# change directory to the egine root folder
> cd c:\path\to\your\o3de-engine
# create a build folder
> mkdir build
> cd build
# configure cmake and create sollutiuon
> cmake .. -G "Visual Studio 16" -A x64 -DLY_3RDPARTY_PATH="%LY_3RDPARTY_PATH%" -DLY_UNITY_BUILD=OFF -DLY_PROJECTS="C:\path\to\repo\o3de-multiplayersample-assets\Project"
```

This should generate a build\O3DE.sln file, which can be opened in Visual Studio 2019 and compiled.

Don't forget to build the project in Profile

![image](https://user-images.githubusercontent.com/23222931/185497967-b94e1e5e-722c-4b84-b950-a00477343e56.png)

Building the Editor project will build with all dependencies.

![image](https://user-images.githubusercontent.com/23222931/185498026-0f235b71-ff10-4135-8008-ba067b6a285b.png)

The built binary executables will be in:

```shell
# bin folder
> cd C:\depot\o3de-dev\build\bin\profile\
# executbales
# C:\depot\o3de-dev\build\bin\profile\o3de.exe
# C:\depot\o3de-dev\build\bin\profile\editor.exe
# ...
```

If this is the project you are primarily working with, you can also set it as the "default project". 

```shell
# change directory to the egine root folder
> cd c:\path\to\your\o3de-engine
# register the gems with the engine, you only need to do this once
> scripts\o3de set-global-project -pp <project-path>
```

This will make this the project that launches by default if you manually directly double-click on a o3de executable like editor.exe
