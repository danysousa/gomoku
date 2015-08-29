#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP
# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <iostream>
# include <math.h>
# include <Color.hpp>

class RenderEngine
{
	public:
		RenderEngine(const char *, int, int);
		~RenderEngine();

		void		draw_square(float x, float y, float scale, Color * color);
		void		draw_circle(float x, float y, float scale, Color * color);
		void		draw_line(float xa, float ya, float xb, float yb, Color * color);

		GLFWwindow *getWin() const;

		static		int keyPressed[350];
		static		double cursorPos[2];
		static		double lastClick[2];
	private:
		GLFWwindow *win;
};

#endif