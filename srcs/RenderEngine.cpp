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

void		RenderEngine::draw_square()
{
	glBegin( GL_POLYGON ) ;
		glVertex2f( -0.3F,-0.3F ) ;
		glVertex2f( -0.3F,0.3F ) ;
		glVertex2f( 0.3F,0.3F ) ;
		glVertex2f( 0.3F,-0.3F ) ;
	glEnd() ;
}

void		RenderEngine::draw_circle()
{
	glBegin( GL_POLYGON );
		for( int i =0; i <= 300; i++ )
		{
			double angle = 2 * M_PI * i / 300;
			double x = cos( angle ) / 100.0;
			double y = sin( angle ) / 100.0;
			glVertex2d( x, y );
		}
	glEnd();
}

void		RenderEngine::draw_line()
{
	glBegin(GL_LINE_LOOP);
		glVertex2d(-0.5,-0.5);
		glVertex2d(0.5,0.5);
	glEnd();
}

RenderEngine::~RenderEngine()
{
	glfwDestroyWindow( this->win );
	glfwTerminate();
}