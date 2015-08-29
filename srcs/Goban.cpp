#include <Goban.hpp>

Goban::Goban()
{

}

Goban::~Goban()
{

}

void	Goban::update()
{
	// std::cout << "GO";
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
	diff = (0.85 * 2.0) / 17.0;

	render->draw_square(0, 0, 0.9, color);
	delete color;

	color = new Color(0, 0, 0);
	for ( double i = 0.0; i < 19.0; i += 1.0 )
	{
		render->draw_line(x + (i * diff), y, x + (i * diff), -y, color);
	}

	x = -0.85;
	y = 0.85;
	for ( double i = 0.0; i < 19.0; i += 1.0 )
	{
		render->draw_line(x, y - (i * diff), -x, y - (i * diff), color);
	}

	delete color;
}