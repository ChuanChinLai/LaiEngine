# The LaiEngine

LaiEngine is a 2D game engine built from the ground up using C++ with [Simple DirectMedia Layer](https://www.libsdl.org/) (SDL 2.0). LaiEngine’s features include: GameObjects, Heap Manager, Smart Pointers, Mathematics Library, and Asset Builder. Also available in the project is an example game I built with the LaiEngine to showcase 
the engine’s features.  


### How to:

* Environment setup: Win10 and Visual Studio 2017

* Open the TowerDefenseGame.sln

* Build the **ExampleGame** project and **BuildExampleGameAssets** project in Solution Explorer

* Run the .exe in LaiEngine/temp/($Platform)/$(Configuration)/ExampleGame_

## Engine Programming

* Source code in LaiEngine/Engine

* Component-based GameObjects, allowing users to add component classes to their GameObjects

* Custom Engine Library, including Scene, Math, Physics, etc...

* High Speed Memory Allocator, reducing average dynamic allocation time by 60%

* Shared_ptr and Weak_ptr for resource management and avoiding memory leaks

* One-click Asset Builder Tool

## Gameplay Programming

* Source code in LaiEngine/ExampleGame_

* Custom event system with Observer pattern, improving performance for GameObjects spawning and destroying

* Implemented artificial intelligence with State pattern, facilitating changes to the GameObjects’ behaviors based on the project requirements 
 
* Implemented game subsystems with Mediator pattern and Façade pattern, making it easier to maintain gameplay features  

* Created a Lua-driven balance sheet system, to help facilitate the game design workflow and rapid iteration