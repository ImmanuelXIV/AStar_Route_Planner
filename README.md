# C++ OpenStreetMap Route Planning Project

This repo contains the starter code for the Route Planning project.

<img src="map.png" width="600" height="450" />

## Cloning

Make sure to clone the project using the `--recurse-submodules` flag. This will install the necessary submodules located in `/thirdparty` and checkout the commits used for this project.
```
git clone https://github.com/ImmanuelXIV/AStar_Route_Planner.git --recurse-submodules
```

## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it

## Compiling and Running

### Compiling
To compile the project, first change into the cloned directory:
```
cd AStar_Route_Planner
```
Then create a `build` directory and change to that directory:
```
mkdir build
cd build
```
From within the `build` directory, run `cmake` and `make` as follows:
```
cmake ..
make
```
### Testing and Running
The executables will be placed in the `build` directory. From within `build`, you can test and run the project as follows.

#### Test
```
./test
```
This should show you the passed tests and the execution runtime.

#### Run
```
./OSM_A_star_search
```
Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

### References
This project is part of the [Udacity C++ Nanodegree](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) curriculum. Thanks to to preoject instructors and code reviewers!


