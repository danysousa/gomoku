#ifndef COMPUTER_HPP
# define COMPUTER_HPP
# include <stdlib.h>
# include <Player.hpp>
# include <Goban.hpp>
# include <Stones.hpp>
# include <vector>
# include <iostream>

class Computer : public Player
{
	public:
		Computer( int Player );
		Computer( Computer const & cpy );
		~Computer( void );

		Computer	operator=( Computer const & cpy );

		void		play( Goban *, std::vector<Stones *> *);

	private:
		Computer( void );
		int			scoreAlignement( int **goban, int axeX, int axeY, int x, int y ) const;
		int			score( int **goban, int player ) const;

};

#endif