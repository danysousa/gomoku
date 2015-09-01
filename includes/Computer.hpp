#ifndef COMPUTER_HPP
# define COMPUTER_HPP
# include <stdlib.h>
# include <Player.hpp>
# include <Goban.hpp>
# include <Stones.hpp>
# include <Hit.hpp>
# include <vector>
# include <iostream>

class Computer : public Player
{
	public:
		Computer( int Player );
		Computer( Computer const & cpy );
		~Computer( void );

		Computer	operator=( Computer const & cpy );

		Stones	*play( Goban *, std::vector<Stones *> );
		int		checkMoveExist(int x, int y, std::vector<Stones *> *canMove);
	private:
		Computer( void );
		int		scoreAlignement( int **goban, int axeX, int axeY, int x, int y ) const;
		int		score( Goban const &goban, int player ) const;
		void	findFreeMove( Goban const &, std::vector<Stones *>, std::vector<Stones *> *, int );
		Hit		*simulate( Goban *goban, std::vector<Stones *> *canMove, std::vector<Stones *> stones );

		int		numberFreeMove;
};

#endif