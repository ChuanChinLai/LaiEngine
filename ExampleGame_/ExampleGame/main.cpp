#include <stdlib.h>
#include <iostream>

#include <External\SDL2\Includes.h>
#include <stdio.h>

#include <fstream>
#include <filesystem>

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Input\Input.h>
#include <ExampleGame\ExampleGame.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\SmartPointer\WeakPointer.h>
#include <Engine\Math\Vector3D.h>
#include <Engine\Math\Vector4D.h>

int main(int argc, char *args[])
{

	{
		Engine::Math::Vector3D<float> v1(1.2f, 2.4f, 3.6f);
		Engine::Math::Vector3D<float> v2(1.1f, 3.3f, 5.5f);

		float res = Engine::Math::dot(v1, v2);
		Engine::Math::Vector3D<float> v3 = Engine::Math::cross(v1, v2);


		{
			Engine::Math::Vector4D<float> v3(v1);
			Engine::Math::Vector4D<float> v4(v2);

			int a = 0;
		}



		int z = 0;
	}

	{
		Engine::Math::Vector3D<int> v1(1, 2, 3);
		Engine::Math::Vector3D<int> v2(1, 3, 5);

		int res = Engine::Math::dot(v1, v2);
		Engine::Math::Vector3D<int> v3 = Engine::Math::cross(v1, v2);


		int z = 0;
	}



	Engine::GameDemo* Game = new Engine::GameDemo();

	if (!Game->_Init())
	{
		Game->_Release();
		return 0;
	}

	Game->_Loop();

	delete Game;

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	system("pause");

	return 0;
}