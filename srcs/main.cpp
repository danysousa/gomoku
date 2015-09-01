#include <gomoku.hpp>

int main(void)
{
	CoreEngine	*core;

	for (int i = 0; i < 1000; i++)
		std::cout << "POK" << std::endl;
	core = new CoreEngine();
	core->start();

	delete core;
}