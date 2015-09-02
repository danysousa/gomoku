#include <gomoku.hpp>

int main(void)
{
	CoreEngine	*core;

	core = new CoreEngine();
	core->start();

	delete core;
}