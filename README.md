# Build
A Linux and Windows C program dedicated to helping develop the basic program structure of
gradle managed java apps.


## Version
1.0

## How It Works

The application accepts two arguments from version 1.0

-v : Shows current running  version of the build 

build : Building The File Structure


## Installation

Open your .bashrc in your home directory to set your new env properties

Configure your system path

### Commands :rocket:

#### Example
BUILD_HOME=<Directory where build is>
BUILD_PATH=$PATH:$HOME/bin:$BUILD_HOME

export BUILD_HOME
export BUILD_PATH

#### Open terminal

sudo update-alternatives --install "/usr/bin/build" "build"  "<Directory where build is>/build" 2

Confirm Installation

build -v :+1:


## BY

Collins Magondu

## LICENSE

TO GET LICENSE CLICK [HERE](LICENSE);














