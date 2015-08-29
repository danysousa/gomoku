#include <Color.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Color::Color()
{

}

Color::Color( float red, float green, float blue ) : red( red ), green( green ), blue( blue )
{

}

Color::~Color()
{

}

/*
** OPERATOR
*/
Color Color::operator=( Color const & cpy )
{
	this->red = cpy.getRed();
	this->green = cpy.getGreen();
	this->blue = cpy.getBlue();
	return ( *this );
}

/*
** METHOD
*/


/*
** GETTER & SETTER
*/
float		Color::getRed( void ) const
{
	return ( this->red );
}

float		Color::getGreen( void ) const
{
	return ( this->green );
}

float		Color::getBlue( void ) const
{
	return ( this->blue );
}

void		Color::setColors( float r, float g, float b )
{
	this->red = r;
	this->green = g;
	this->blue = b;
}