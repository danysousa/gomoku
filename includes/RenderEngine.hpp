#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP
# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <iostream>
# include <math.h>

class RenderEngine
{
	public:
		RenderEngine(const char *, int, int);
		~RenderEngine();

		void		draw_square();
		void		draw_circle();
		void		draw_line();

		GLFWwindow *getWin() const;

	private:
		GLFWwindow *win;
};

#endif