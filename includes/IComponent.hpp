#ifndef ICOMPONENT
# define ICOMPONENT

class IComponent
{
	public:
		virtual			~IComponent() = 0;

		virtual void	update( void ) = 0;
		virtual void	render( void ) = 0;

};

#endif