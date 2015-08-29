#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <RenderEngine.hpp>
# include <Goban.hpp>
# include <Stones.hpp>
# include <vector>

class GameEngine
{
	public:
		GameEngine();
		~GameEngine();

		void		updateAll();
		void		renderAll( RenderEngine * );

		std::vector<IComponent *>	getComponents( void ) const;

	private:
		Goban		*goban;
		Stones		*stones;
};

#endif