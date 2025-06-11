#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
	int	who = std::rand() % 3;
	if (who == 0)
		return (new A);
	else if (who == 1)
		return (new B);
	else if (who == 2)
		return (new C);
	else
		return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unidentified" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Unidentified" << std::endl;
			}
		}
	}
}

int main(void)
{
	std::srand(std::time(NULL));

	Base *p = generate();

	// --- Identify with pointer --- //
	identify(p);

	// --- Identify with ref --- //
	identify(p);

	delete p;
	return (0);
}
