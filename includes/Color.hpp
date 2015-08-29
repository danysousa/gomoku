#ifndef COLOR_HPP
# define COLOR_HPP

# include <RenderEngine.hpp>

class Color
{
	public:
		Color( void );
		Color( float red, float green, float blue );
		~Color( void );

		Color	operator=( Color const & cpy );

		float		getRed( void ) const;
		float		getGreen( void ) const;
		float		getBlue( void ) const;

	private:
		float	red;
		float	green;
		float	blue;
};

#endif