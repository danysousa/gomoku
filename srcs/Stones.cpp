#include <Stones.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Stones::Stones()
{

}

Stones::Stones( int x, int y ) : x( x ), y( y )
{

}

Stones::~Stones()
{

}

/*
** OPERATOR
*/
Stones Stones::operator=( Stones const & cpy )
{
	this->x = cpy.getX();
	this->y = cpy.getY();
	return ( *this );
}

/*
** METHOD
*/
void	Stones::update()
{
	std::cout << "Stones update" << std::endl;
}

void	Stones::render(RenderEngine *render)
{
	std::cout << "Stones render" << std::endl;
}

/*
** GETTER & SETTER
*/
int		Stones::getX( void ) const
{
	return ( this->x );
}

int		Stones::getY( void ) const
{
	return ( this->y );
}