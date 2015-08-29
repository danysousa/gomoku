#include <CoreEngine.hpp>

CoreEngine::CoreEngine()
{
	this->render = new RenderEngine("Gomoku", 900, 900);
	this->game = new GameEngine();
}

CoreEngine::~CoreEngine()
{
	delete this->render;
}
void	CoreEngine::start(void)
{
	std::vector<IComponent *>	components;
	long double		timeF;

	while ( !glfwWindowShouldClose( this->render->getWin() ) )
	{
		this->startF = static_cast<long double>(clock());

		this->game->updateAll();
		glClear(GL_COLOR_BUFFER_BIT);

		// this->test();

		this->game->renderAll( this->render );

		glfwSwapBuffers(this->render->getWin());
		glfwPollEvents();
		timeF = (static_cast<long double>(clock()) - this->startF) / CLOCKS_PER_SEC;
		if ( timeF < (1.0 / 30.0) )
			usleep( ((1.0 / 30.0) - timeF) * 1000000 );
	}
}

void	CoreEngine::test(void)
{
	float ratio;
	int width, height;
	glfwGetFramebufferSize(this->render->getWin(), &width, &height);
	ratio = width / (float) height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Color *color = new Color(0.5, 0.5, 0.0);
	this->render->draw_circle(0,0, 0.02, color);
	delete color;
	color = new Color(0.0, 0.5, 0.5);

	this->render->draw_square(-0.5,-0.5,0.02, color);
	delete color;
	color = new Color(0.2, 0.2, 0.9);

	this->render->draw_line(-0.4, -0.4, 0.4, 0.4, color);

	delete color;
	glfwSwapBuffers(this->render->getWin());
	glfwPollEvents();
}