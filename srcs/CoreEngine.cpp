#include <CoreEngine.hpp>

CoreEngine::CoreEngine()
{
	this->render = new RenderEngine("Gomoku", 900, 600);
	this->game = new GameEngine();
}

CoreEngine::~CoreEngine()
{
	delete this->render;
}
void	CoreEngine::start(void)
{
	Player *p = new Player( 1 );

	std::cout << p->getPlayer() << std::endl;
	std::vector<IComponent *>	components;
	long double		timeF;

	while ( !glfwWindowShouldClose( this->render->getWin() ) )
	{
		this->startF = static_cast<long double>(clock());
		components = this->game->getComponents();

		for (size_t i = 0; i < components.size(); ++i)
		{
			components[i]->update();
		}
		this->test();

		for (size_t i = 0; i < components.size(); ++i)
		{
			components[i]->render(this->render);
		}

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
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	this->render->draw_square();
	this->render->draw_line();
	this->render->draw_circle();

	glfwSwapBuffers(this->render->getWin());
	glfwPollEvents();
}