#include <Stones.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Stones::Stones()
{

}

Stones::Stones( int x, int y, int player ) : x( x ), y( y ), player( player )
{
	this->win = false;
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
}

void	Stones::render(RenderEngine *render)
{
	float	tmp;
	float	a;
	float	b;
	Color	*color;

	tmp = (2 * 0.85) / 18;
	a = -0.85 + tmp * this->x;
	b = 0.85 - tmp * this->y;
	if (this->win)
		color = new Color(1, 0, 0);
	else
		color = new Color(this->player - 1, this->player - 1, this->player - 1);
	render->draw_circle(a, b, 0.045, color);
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

int		Stones::getPlayer( void ) const
{
	return ( this->player );
}