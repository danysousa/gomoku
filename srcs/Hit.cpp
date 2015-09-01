#include <Hit.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Hit::Hit()
{

}

Hit::Hit( int x, int y, int player, Goban const &goban ) : x( x ), y( y ), player( player ), score( 0 )
{
	this->stateAfter = goban;
	this->stateAfter.addStone( x, y, this->player );
}

Hit::~Hit()
{

}

/*
** OPERATOR
*/
Hit		&Hit::operator=( Hit const & cpy )
{
	this->x = cpy.getX();
	this->y = cpy.getY();
	return ( *this );
}

/*
** METHOD
*/

void	Hit::addPossibility( Hit *elem )
{
	this->possibility.push_back( elem );
}

int		Hit::getMinScore( void )
{
	int		result;
	int		tmp;

	for (size_t i = 0; i < this->possibility.size(); ++i)
	{
		tmp = this->possibility.at(i)->getScore();
		result = i == 0 || tmp < result ? tmp : result;
	}

	return ( result );
}

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

Goban	const &Hit::getStateAfter( void ) const
{
	return ( this->stateAfter );
}

void	Hit::setScore( int value )
{
	this->score = value;
}

