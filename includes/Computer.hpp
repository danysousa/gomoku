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

		void					play( Goban *, std::vector<Stones *> * );
		void					findFreeMove( Goban *goban, std::vector<Stones *> *stones, std::vector<Stones *> *canMove );
		int						checkMoveExist(int x, int y, std::vector<Stones *> *canMove);
	private:
		Computer( void );

		int						numberFreeMove;
};

#endif