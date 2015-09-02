#include <Goban.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Goban::Goban()
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			this->stones[i][j] = 0;
	}
}

Goban::Goban( Goban const & cpy )
{
	*this = cpy;
}

Goban::Goban( int **goban )
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			this->stones[i][j] = goban[i][j];
	}
}

Goban::~Goban()
{

}

/*
** OPERATOR
*/

Goban		&Goban::operator=( Goban const & cpy )
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			this->stones[i][j] = cpy.playerHere(i, j);
	}

	return ( *this );
}

/*
** METHOD
*/
void	Goban::addStone( int x, int y, int player )
{
	if ( x < 0 || x > 18 || y < 0 || y > 18 )
		return ;

	this->stones[x][y] = player;
}

void	Goban::deleteStone( int x, int y )
{
	if ( x < 0 || x > 18 || y < 0 || y > 18 )
		return ;

	this->stones[x][y] = 0;
}

int		Goban::playerHere( int x, int y ) const
{
	if ( x < 0 || x > 18 || y < 0 || y > 18 )
		return ( -1 );

	return ( this->stones[x][y] );
}

bool	Goban::isDoubleThree( int player, int x, int y ) const
{
	int		pattern[5];
	int		match[2];
	int		i;
	int		nb_pattern;
	int		tmpX;
	int		tmpY;

	pattern[0] = 0;
	pattern[1] = 0;
	pattern[2] = player;
	pattern[3] = player;
	pattern[4] = 0;
	match[0] = 0;
	match[1] = 0;

	for (int a = -1; a <= 1; ++a)
	{
		for (int b = -1; b <= 1; ++b)
		{
			if ( (x + a < 0 && x + a >= 19) ||
				(y + b < 0 && y + b >= 19) ||
				(x - a < 0 && x - a >= 19) ||
				(y - b < 0 && y - b >= 19) )
				continue ;

			tmpX = x;
			tmpY = y;
			nb_pattern = 0;
			if ( this->playerHere(x - a, y - b) != 0
				|| this->playerHere(x + a, y + b) != 0 )
			{
				tmpX += a;
				tmpY += b;
				nb_pattern = 1;
			}

			i = 0;
			while ( i < 4 )
			{
				if ( pattern[i] != this->playerHere( tmpX - ( i * a ), tmpY - ( i * b ) ) )
					break ;
				i++;
			}
			if ( i == 4 )
				match[nb_pattern]++;
			if ( match[1] > 1 || ( match[0] > 0 && match[1] > 0 ) )
				return ( true );
		}
	}
	return ( false );
}

bool	Goban::isCaptureZone( int player, int x, int y ) const
{
	int		pattern[4];
	int		i;
	int		tmpX;
	int		tmpY;

	pattern[0] = player == 1 ? 2 : 1;
	pattern[1] = 0;
	pattern[2] = player;
	pattern[3] = pattern[0];

	for (int a = -1; a <= 1; ++a)
	{
		for (int b = -1; b <= 1; ++b)
		{
			if ( a == 0 && b == 0 )
				continue ;

			tmpX = x + a >= 0 && x + a < 19 ? x + a : x ;
			tmpY = y + b >= 0 && y + b < 19 ? y + b : y ;
			i = 0;
			while ( i < 4 )
			{
				if ( pattern[i] != this->playerHere( tmpX - ( i * a ), tmpY - ( i * b ) ) )
					break ;
				i++;
			}
			if ( i == 4 )
				return ( true );
		}
	}

	return ( false );
}

bool		Goban::canPlayHere( int player, int x, int y ) const
{
	if ( this->playerHere( x, y ) != 0 )
		return ( false );

	if ( this->isCaptureZone( player, x, y ) || this->isDoubleThree( player, x, y ) )
		return ( false );

	return ( true );
}

void	Goban::update()
{
	return ;
}

void	Goban::render(RenderEngine *render)
{
	double	x;
	double	y;
	double	diff;
	Color *color;

	color = new Color(0.8, 0.5, 0.3);
	x = -0.85;
	y = 0.85;
	diff = (0.85 * 2.0) / 18.0;
	render->draw_square(0, 0, 0.9, color);
	color->setColors( 0, 0, 0 );

	for ( double i = 0.0; i <= 19.0; i += 1.0 )
	{
		render->draw_line(x + (i * diff), y, x + (i * diff), -y, color);
	}

	x = -0.85;
	y = 0.85;
	for ( double i = 0.0; i <= 19.0; i += 1.0 )
	{
		render->draw_line(x, y - (i * diff), -x, y - (i * diff), color);
	}

	color->setColors( 0.0f, 0.0f, 0.0f );

	for (int i = 3; i < 16; i += 6)
	{
		y = 0.85 - diff * i;
		for (int j = 3; j < 16; j += 6)
		{
			x = -0.85 + diff * j;
			render->draw_circle(x, y, 0.01, color);
		}
	}

	delete color;
}

/*
** GETTER & SETTER
*/

int		**Goban::toIntArray( void ) const
{
	int		**result;

	result = new int *[19];

	for (int i = 0; i < 19; ++i)
	{
		result[i] = new int[19];
		for (int j = 0; j < 19; ++j)
		{
			result[i][j] = this->stones[i][j];
		}
	}

	return ( result );
}
