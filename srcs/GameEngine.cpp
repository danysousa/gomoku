#include <GameEngine.hpp>

GameEngine::GameEngine() : goban( new Goban() ), stones(new Stones(14, 5) )
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
	this->stones->render(render);
}

std::vector<IComponent *>	GameEngine::getComponents( void ) const
{
	std::vector<IComponent *>	result;

	result.push_back( this->goban );
	result.push_back( this->stones );

	return ( result );
}
