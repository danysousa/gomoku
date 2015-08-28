#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP
# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <iostream>

class RenderEngine
{
	public:
		RenderEngine(const char *, int, int);
		~RenderEngine();
		GLFWwindow *getWin() const;

	private:
		GLFWwindow *win;
};

#endif