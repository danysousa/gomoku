#include <RenderEngine.hpp>

static void error_callback( int error, const char* description )
{
	std::cout << error << " : " << description << std::endl;
}
static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

RenderEngine::RenderEngine(const char *winName, int winX, int winY)
{
	glfwSetErrorCallback(error_callback);
	if ( !glfwInit() )
		exit(EXIT_FAILURE);
	this->win = glfwCreateWindow(winX, winY, winName, NULL, NULL);
	if ( !this->win )
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->win);
	glfwSwapInterval(1);
	glfwSetKeyCallback(this->win, key_callback);
}

GLFWwindow *RenderEngine::getWin() const
{
	return ( this->win );
}

void		RenderEngine::draw_square(float x, float y, float scale)
{
	glBegin( GL_POLYGON );
		glVertex2f( x - scale, y - scale );
		glVertex2f( x - scale, y + scale );
		glVertex2f( x + scale, y + scale );
		glVertex2f( x + scale, y - scale );
	glEnd();
}

void		RenderEngine::draw_circle(float x, float y, float scale)
{
	double angle;
	double a;
	double b;

	glBegin( GL_POLYGON );
		for( int i = 0; i <= (280 * scale) + 20; i++ )
		{
			angle = 2 * M_PI * i / ((280 * scale) + 20);
			a = cos( angle );
			b = sin( angle );
			glVertex2d( x + a * scale , y + b * scale );
		}
	glEnd();
}

void		RenderEngine::draw_line(float xa, float ya, float xb, float yb)
{
	glBegin(GL_LINE_LOOP);
		glVertex2d(xa, ya);
		glVertex2d(xb, yb);
	glEnd();
}

RenderEngine::~RenderEngine()
{
	glfwDestroyWindow( this->win );
	glfwTerminate();
}