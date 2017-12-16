#include <stdlib.h>
#include <iostream>

#include <External\SDL2\Includes.h>
#include <stdio.h>

#include <fstream>
#include <filesystem>

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\SmartPointer\WeakPointer.h>

int main(int argc, char *args[])
{

	{
		Engine::Memory::shared_ptr<int> a(new int(5));
		Engine::Memory::weak_ptr<int> b = a;
	}




	Engine::GameEngine GE;

	GE._Init();

	GE._Loop();

	return 0;
}