#include <GameEngine.hpp>

GameEngine::GameEngine() : goban( new Goban() )
{
	return ;
}

GameEngine::~GameEngine()
{
	return ;
}

void		GameEngine::updateAll()
{
	this->goban->update();
}

void		GameEngine::renderAll( RenderEngine *render )
{
	this->goban->render(render);
}

std::vector<IComponent *>	GameEngine::getComponents( void ) const
{
	std::vector<IComponent *>	result;

	result.push_back( this->goban );

	return ( result );
}
