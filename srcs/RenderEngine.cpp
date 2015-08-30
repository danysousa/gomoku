#include <RenderEngine.hpp>

int RenderEngine::keyPressed[350];
double RenderEngine::cursorPos[2];
double RenderEngine::lastClick[3];

static void error_callback( int error, const char* description )
{
	std::cout << error << " : " << description << std::endl;
}
static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key > 0 && action == GLFW_PRESS)
		RenderEngine::keyPressed[key] = 1;
	else if (key > 0 && action == GLFW_RELEASE)
		RenderEngine::keyPressed[key] = 0;
}

static void cursor_callback(GLFWwindow* window, double x, double y)
{
	RenderEngine::cursorPos[0] = (x / 450) - 1;
	RenderEngine::cursorPos[1] = - ((y / 450) - 1);
}

void button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		RenderEngine::lastClick[0] = RenderEngine::cursorPos[0];
		RenderEngine::lastClick[1] = RenderEngine::cursorPos[1];
		RenderEngine::lastClick[2] = 1.0;
	}
}


RenderEngine::RenderEngine(const char *winName, int winX, int winY)
{
	glfwSetErrorCallback(error_callback);
	if ( !glfwInit() )
		exit(EXIT_FAILURE);
	glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
	this->win = glfwCreateWindow(winX, winY, winName, NULL, NULL);
	if ( !this->win )
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->win);
	glfwSwapInterval(1);
	for (int i = 0; i < 350; ++i)
		RenderEngine::keyPressed[i] = 0;
	RenderEngine::cursorPos[0] = 0.0;
	RenderEngine::cursorPos[1] = 0.0;
	RenderEngine::lastClick[0] = 0.0;
	RenderEngine::lastClick[1] = 0.0;
	RenderEngine::lastClick[2] = 0.0;

	glfwSetKeyCallback(this->win, key_callback);
	glfwSetCursorPosCallback(this->win, cursor_callback);
	glfwSetMouseButtonCallback(this->win, button_callback);
}

GLFWwindow *RenderEngine::getWin() const
{
	return ( this->win );
}

void		RenderEngine::draw_square(float x, float y, float scale, Color *color)
{
	glColor3f(color->getRed(), color->getGreen(), color->getBlue());
	glBegin( GL_POLYGON );
		glVertex2f( x - scale, y - scale );
		glVertex2f( x - scale, y + scale );
		glVertex2f( x + scale, y + scale );
		glVertex2f( x + scale, y - scale );
	glEnd();
}

void		RenderEngine::draw_circle(float x, float y, float scale, Color *color)
{
	double angle;
	double a;
	double b;

	glColor3f(color->getRed(), color->getGreen(), color->getBlue());
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

void		RenderEngine::draw_line(float xa, float ya, float xb, float yb, Color *color)
{
	glColor3f(color->getRed(), color->getGreen(), color->getBlue());
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