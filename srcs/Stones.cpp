#include <Stones.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Stones::Stones()
{

}

Stones::Stones( float x, float y ) : x( x ), y( y )
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
	// std::cout << "Stones update" << std::endl;
}

void	Stones::render(RenderEngine *render)
{
	x = -0.85 + (0.10 * this->x);
	y = 0.85 - (0.10 * this->y);
	Color *color = new Color(1.0f, 1.0f, 1.0f);
	render->draw_circle(x, y, 0.04, color);
	delete color;
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