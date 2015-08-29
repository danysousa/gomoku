#ifndef COREENGINE_HPP
# define COREENGINE_HPP

# include <RenderEngine.hpp>
# include <GameEngine.hpp>
# include <time.h>
# include <unistd.h>

class CoreEngine
{
	public:
		CoreEngine();
		~CoreEngine();
		void		start( void );

	private:
		RenderEngine			*render;
		GameEngine				*game;

		long double		startF;

		void		test(void);
};

#endif