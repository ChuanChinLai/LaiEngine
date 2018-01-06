#include <stdlib.h>

#include <ExampleGame_\ExampleGame\EngineDemo.h>
#include <Engine\Math\Vector4D.h>

class base
{
public:

	base()
	{
		std::cout << "base constructor" << std::endl;
	}
	virtual ~base()
	{
		std::cout << "base deconstructor" << std::endl;
	}
	void call()
	{
		std::cout << "base call" << std::endl;
	}

	virtual void vcall()
	{
		std::cout << "base vcall" << std::endl;
	}
};


class derived : public base
{
public:

	derived()
	{
		std::cout << "derived constructor" << std::endl;
	}

	~derived()
	{
		std::cout << "derived deconstructor" << std::endl;
	}

	void call()
	{
		std::cout << "derived call" << std::endl;
	}

	virtual void vcall() override
	{
		std::cout << "derived vcall" << std::endl;
	}
};

void test(void* par)
{
	base* c = static_cast<base*>(par);
	c->call();
	c->vcall();
}


int main(int argc, char *args[])
{
	{
		{
			derived b;
			b.call();
			b.vcall();
		}

		{
			base* b = new derived();
			b->call();
			b->vcall();

			test(b);


			void *a = b;
			base* c = static_cast<base*>(a);
			c->call();
			c->vcall();

			delete b;
		}
	}


	Engine::EngineDemo* Game = new Engine::EngineDemo();

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