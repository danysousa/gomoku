#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <stdlib.h>
# include <iostream>

class Player
{
	public:
		Player( int player );
		Player( Player const & cpy );
		~Player( void );

		Player	operator=( Player const & cpy );

		int		getPlayer( void ) const;

	private:
		Player( void );

		int		player;
};

#endif