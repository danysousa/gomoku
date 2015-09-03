#include <gomoku.hpp>

int main( int argc, char **argv)
{
	CoreEngine	*core;

	if ( argc == 2 )
	{
		if ( argv[1][0] == '1' || argv[1][0] == '2' )
		{
			core = new CoreEngine( argv[1][0] );
			core->start();

			delete core;
		}
		else
			std::cout << "./gomoku --numberPlayer(1, 2)" << std::endl;
	}
	else
		std::cout << "./gomoku --numberPlayer(1, 2)" << std::endl;

	return (0);
}