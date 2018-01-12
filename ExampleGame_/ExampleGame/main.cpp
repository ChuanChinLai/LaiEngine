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

	int par;
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
	std::cout << c->par << std::endl;
}


void Bar(int Max, int* Result)
{
	if (Max > 0)
	{
		*Result += Max;
		Bar(Max - 1, Result);
	}
}

int Foo()
{
	int Max = 3;
	int Result = 0;
	Bar(Max, &Result);
	return Result;
}


int main(int argc, char *args[])
{
	{
		int a = Foo();
		int vb = 0;
	}



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
			b->par = 20;
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