#ifndef COREENGINE_HPP
# define COREENGINE_HPP

# include <RenderEngine.hpp>
# include <Player.hpp>
# include <GameEngine.hpp>

class CoreEngine
{
	public:
		CoreEngine();
		~CoreEngine();
		void		start( void );

	private:
		RenderEngine	*render;
		GameEngine		*game;
		void		test(void);
};

#endif