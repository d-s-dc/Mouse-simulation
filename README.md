# Mouse-simulation 🖱️

This is a mouse simulation that performs taps, holds and swipes (*as on a mobile touch screen*) on Ubuntu. 
I developed it as a part of my project to **fully run ARM-based games** on linux via [waydroid](https://waydro.id/).


## Pre-requisites
- You need to install ydotool. For ubuntu users follow this [SO link](https://askubuntu.com/questions/1413829/how-can-i-install-and-use-the-latest-ydotool-keyboard-automation-tool-working-o).

## Installation
You can just download the [C file](https://github.com/d-s-dc/Mouse-simulation/blob/master/game_mouse_via_keyboard.c) and run it.

## Key mappings

This code will perform the following simulation
| Key                         | Simulation                                                           |
|----------------------------|---------------------------------------------------------------------|
| Left arrow key (hold)      | Will hold the right-click on the left part of the screen.           |
| Left arrow key (release)   | Will release the right-click on the left part of the screen.        |
| Right arrow key (hold & release) | Same as the left key.                                           |
| Up arrow key                | Will perform an up swipe (*similar to that on the touch screen*) from the middle of the PC screen. |
| Down arrow key              | Will perform a down swipe (*similar to that on the touch screen*) from the middle of the PC screen. |
