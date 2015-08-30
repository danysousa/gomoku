#include <Computer.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Computer::Computer( void )
{
	this->player = 1;
}

Computer::Computer( int player ) : Player( player )
{

}

Computer::Computer( Computer const & cpy ) : Player( player )
{
	*this = cpy;
}

Computer::~Computer( void )
{

}

/*
** OPERATOR
*/
Computer Computer::operator=( Computer const & cpy )
{
	this->player = cpy.getPlayer();
	this->captured = cpy.getCaptured();
	return ( *this );
}

/*
** METHOD
*/
void					Computer::play( Goban *goban, std::vector<Stones *> *stones )
{
	std::vector<Stones *> *canMove = new std::vector<Stones *>;
	this->findFreeMove( goban, stones, canMove );

	return ;
}

void	Computer::findFreeMove( Goban *goban, std::vector<Stones *> *stones, std::vector<Stones *> *canMove )
{
	int		j = 0;
	int		x;
	int		y;

	for ( unsigned int i = 0; i < stones->size(); ++i)
	{
		x = stones->at(i)->getX();
		y = stones->at(i)->getY();
		for ( int a = -1; a <= 1; a++ )
		{
			for ( int b = -1; b <= 1; b++ )
			{
				if ( goban->playerHere( x - a, y - b ) == 0 )
				{
					if ( checkMoveExist( x - a, y - b, canMove ) == 0 )
					{
						j++;
						canMove->push_back( new Stones( x - a, y - b, 0 ) );
					}
				}
			}
		}
	}
	this->numberFreeMove = j;
}

int			Computer::checkMoveExist(int x, int y, std::vector<Stones *> *canMove)
{
	for ( unsigned int i = 0; i < canMove->size(); ++i )
	{
		if ( canMove->at(i)->getX() == x && canMove->at(i)->getY() == y )
			return (1);
	}
	return (0);
}

/*
** GETTER & SETTER
*/
