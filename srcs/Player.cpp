#include <Player.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Player::Player( void )
{
	this->player = 1;
}

Player::Player( int player ) : player( player ), captured( 0 )
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
	this->captured = cpy.getCaptured();
	return ( *this );
}

/*
** METHOD
*/
void		Player::addCaptureCount( int count )
{
	this->captured += count;
	if ( this->captured >= 10 )
	{
		std::cout << "Player " << this->player << " win by capture" << std::endl;
		exit( 1 );
	}
}

/*
** GETTER & SETTER
*/
int			Player::getPlayer( void ) const
{
	return ( this->player );
}

int			Player::getCaptured( void ) const
{
	return ( this->captured );
}