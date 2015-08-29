#ifndef ICOMPONENT
# define ICOMPONENT

# include <RenderEngine.hpp>

class IComponent
{
	public:
		virtual			~IComponent() = 0;

		virtual void	update( void ) = 0;
		virtual void	render( RenderEngine * ) = 0;

};

#endif