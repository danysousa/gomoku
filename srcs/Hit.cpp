#include <Hit.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Hit::Hit()
{

}

Hit::Hit( int x, int y, int player, int score, Goban *goban ) : x( x ), y( y ), player( player ), score( score )
{
	this->stateAfter = new Goban( *goban );
	this->stateAfter->addStone( x, y, this->player );
}

Hit::~Hit()
{
	delete this->stateAfter;
}

/*
** OPERATOR
*/
Hit		Hit::operator=( Hit const & cpy )
{
	this->x = cpy.getX();
	this->y = cpy.getY();
	return ( *this );
}

/*
** METHOD
*/

/*
** GETTER & SETTER
*/
int		Hit::getX( void ) const
{
	return ( this->x );
}

int		Hit::getY( void ) const
{
	return ( this->y );
}

int		Hit::getPlayer( void ) const
{
	return ( this->player );
}

int		Hit::getScore( void ) const
{
	return ( this->score );
}