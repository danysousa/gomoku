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

Computer::Computer( Computer const & cpy )
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
void		Computer::play( Goban *goban, std::vector<Stones *> *stones )
{
	return ;
}

/*
** GETTER & SETTER
*/
