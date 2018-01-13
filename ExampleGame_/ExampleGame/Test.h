#pragma once

#include <iostream>

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
