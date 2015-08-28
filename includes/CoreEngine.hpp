#ifndef COREENGINE_HPP
# define COREENGINE_HPP

# include <RenderEngine.hpp>

class CoreEngine
{
	public:
		CoreEngine();
		~CoreEngine();

	private:
		RenderEngine	*render;
		void		test(void);
};

#endif