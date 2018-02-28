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

* Component-based GameObjects, allowing users to add component classes to their GameObjects

* Customize Engine Library, including Scene, Math, Physics, etc...

* High Speed Memory Allocator, reducing average dynamic allocation time by 60%

* Shared_ptr and Weak_ptr for resource management and avoiding memory leaks

* One-click Asset Builder Tool

## Gameplay Programming

* Source code in LaiEngine/ExampleGame_

* Custom event system with Observer pattern, improving performance for GameObjects spawning and destroying

* Implemented artificial intelligence with State pattern, facilitating changes to the GameObjects’ behaviors based on the project requirements 
 
* Implemented game subsystems with Mediator pattern and Façade pattern, making it easier to maintain gameplay features  

* Created a Lua-driven balance sheet system, to help facilitate the game design workflow and rapid iteration