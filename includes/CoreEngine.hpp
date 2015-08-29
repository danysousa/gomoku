#ifndef COREENGINE_HPP
# define COREENGINE_HPP

# include <RenderEngine.hpp>

class CoreEngine
{
	public:
		CoreEngine();
		~CoreEngine();
		void		start( void );

	private:
		RenderEngine	*render;
		void		test(void);
};

#endif