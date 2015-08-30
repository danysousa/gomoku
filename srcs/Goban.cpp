#include <Goban.hpp>

Goban::Goban()
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			this->stones[i][j] = 0;
	}
}

Goban::~Goban()
{

}

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

int		Goban::playerHere( int x, int y )
{
	if ( x < 0 || x > 18 || y < 0 || y > 18 )
		return ( -1 );

	return ( this->stones[x][y] );
}

bool	Goban::isCaptureZone( int player, int x, int y )
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
				if ( pattern[i] != this->stones[tmpX - ( i * a )][tmpY - ( i * b )] )
					break ;
				i++;
			}
			if ( i == 4 )
				return ( true );
		}
	}

	return ( false );
}

bool		Goban::canPlayHere( int player, int x, int y )
{
	if ( this->playerHere( x, y ) != 0 )
		return ( false );

	if ( this->isCaptureZone( player, x, y ) )
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