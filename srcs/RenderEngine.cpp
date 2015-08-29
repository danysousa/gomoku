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

RenderEngine::~RenderEngine()
{
	glfwDestroyWindow( this->win );
	glfwTerminate();
}