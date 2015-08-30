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
		int		getCaptured( void ) const;

		void	addCaptureCount( int );

	protected:
		Player( void );

		int		player;
		int		captured;
};

#endif