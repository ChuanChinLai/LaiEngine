# The LaiEngine

A homemade 2D game engine written in C++ using [Simple DirectMedia Layer](https://www.libsdl.org/) (SDL 2.0).

A Tower Defense Game made by the engine.

### How to:

* Environment setup: Win10 and Visual Studio 2017

* Open the TowerDefenseGame.sln

* Build the **ExampleGame** project and **BuildExampleGameAssets** project in Solution Explorer

* Run the .exe in LaiEngine/temp/($Platform)/$(Configuration)/ExampleGame_

## Engine Programming

* Source code in LaiEngine/Engine

* Customize Engine Library, including Scene, Math, Physics, etc...

* High Speed Memory Allocator, reducing average dynamic allocation time by 60%

* Smart Pointer for GameObject Management

* One-click Asset Builder Tool

## Gameplay Programming

* Source code in LaiEngine/ExampleGame_

* Using LaiEngine to make a TowerDefenseGame

* Design and implement gameplay with design patterns, including Facade, Mediator, Observer, etc...

* Using Lua table for data input