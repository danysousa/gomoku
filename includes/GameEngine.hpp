#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <RenderEngine.hpp>
# include <Goban.hpp>
# include <Stones.hpp>
# include <Player.hpp>
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
		int			currentPlayer;
		std::vector<Stones *>		*stones;

		void		addPlayerStone(double x, double y);
		void		checkCapture();
		void		deleteStone( int, int );
};

#endif