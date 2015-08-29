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

		void		draw_square(float x, float y, float scale);
		void		draw_circle(float x, float y, float scale);
		void		draw_line(float xa, float ya, float xb, float yb);

		GLFWwindow *getWin() const;

	private:
		GLFWwindow *win;
};

#endif