# {EPITECH} my_radar Project

## Overview

**My Radar** is a 2D air traffic control simulation that visualizes aircrafts and control towers on a map. The program takes a script as input to simulate air traffic management, showcasing aircraft movement, control tower areas, and handling various events like aircraft collisions and landings.

The goal of the project is to render and control air traffic efficiently with user interactions, while displaying important data such as hitboxes, control tower areas, and a timer.

## Features

- **Aircraft Simulation**: Displays aircrafts with specific takeoff and landing coordinates, along with a constant speed.
- **Control Towers**: Displays control towers and their respective control areas.
- **Collision Detection**: Aircrafts collide and are destroyed unless they are within control tower areas. A bonus in this project is that the collision detection is handled using a quad-tree method.
- **User Interaction**: 
  - Press `L` to toggle visibility of hitboxes and control areas.
  - Press `S` to toggle visibility of aircraft sprites.
  - Press `G` to toggle visibility of the collision collision detection grid
- **Timer**: Displays a timer at the top-right corner of the window.
- **Error Handling**: The program exits with error code 84 in case of issues and prints error messages on the standard error output.

## Requirements

- **Language**: C
- **Libraries**: CSFML for graphical rendering.
- **Compiling**: Uses `Makefile` for compiling, including the `re`, `clean`, and `fclean` rules.

### Makefile Rules:
- `make` - Compile the program.
- `make clean` - Remove object files.
- `make fclean` - Remove binaries and object files.
- `make re` - Clean and recompile the program.

### Dependencies:
- CSFML library
- Standard C library functions (`malloc`, `free`, `time`, etc.)

## Compilation

You can compile the project by running the following commands:

```bash
make
