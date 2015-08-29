#include <Player.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Player::Player( void )
{
	this->player = 1;
}

Player::Player( int player ) : player( player )
{
	
}

Player::Player( Player const & cpy )
{
	*this = cpy;
}

Player::~Player( void )
{

}

/*
** OPERATOR
*/
Player Player::operator=( Player const & cpy )
{
	this->player = cpy.getPlayer();
	return ( *this );
}

/*
** METHOD
*/


/*
** GETTER & SETTER
*/
int			Player::getPlayer( void ) const
{
	return ( this->player );
}