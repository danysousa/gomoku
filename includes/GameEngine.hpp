#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <RenderEngine.hpp>
# include <Goban.hpp>
# include <Stones.hpp>
# include <vector>
# include <cmath>

class GameEngine
{
	public:
		GameEngine();
		~GameEngine();

		void		updateAll();
		void		renderAll( RenderEngine * );

	private:
		Goban		*goban;
		int			currentPlayer;
		std::vector<Stones *>		*stones;

		void		addPlayerStone(double x, double y);
		void		checkCapture();
		void		deleteStone( int, int );
		void		checkWin();
		int			checkAlignement( int axeX1, int axeY1, int axeX2, int axeY2, Stones *lastStone );
};

#endif