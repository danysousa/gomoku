#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <RenderEngine.hpp>
# include <Goban.hpp>
# include <Stones.hpp>
# include <Player.hpp>
# include <Computer.hpp>
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
		Player		*players[2];
		Computer	*computer;
		int			currentPlayer;
		std::vector<Stones *>		*stones;

		void		addPlayerStone(double x, double y);
		void		checkCapture();
		void		deleteStone( int, int );
		void		checkWin();
		int			checkCounterWin();

		int			checkAlignement( int axeX1, int axeY1, int axeX2, int axeY2, Stones *lastStone );
		bool		isCaptureZone( int, int );
		bool		canPlayHere( int, int );

		static		int counterWin;
};

#endif