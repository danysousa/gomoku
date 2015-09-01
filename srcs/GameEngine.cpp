#include <GameEngine.hpp>

GameEngine::GameEngine() : goban( new Goban() ), currentPlayer(1)
{
	this->stones = new std::vector<Stones *>;
	this->players[0] = new Player(1);
	this->computer = new Computer(2);

	this->players[1] = this->computer;


	return ;
}

GameEngine::~GameEngine()
{
	return ;
}

void		GameEngine::updateAll()
{
	int		tmp;
	if ( this->currentPlayer == 2 && this->computer )
	{
		this->stones->push_back( this->computer->play( this->goban, *(this->stones) ) );
		tmp = this->stones->size() - 1;
		this->goban->addStone( this->stones->at(tmp)->getX(), this->stones->at(tmp)->getY(), 2 );
		this->currentPlayer = 1;
		return ;
	}

	this->goban->update();
	if ( RenderEngine::lastClick[2] > 0.0 )
		this->addPlayerStone(RenderEngine::lastClick[0], RenderEngine::lastClick[1]);

	for (size_t i = 0; i < this->stones->size(); ++i)
		this->stones->at(i)->update();
}

void		GameEngine::addPlayerStone( double x, double y )
{
	float	tmp;
	int	a;
	int	b;

	RenderEngine::lastClick[2] = 0.0;

	if ( x < -0.9 || x > 0.9 || y < -0.9 || y > 0.9 )
		return ;

	tmp = (2 * 0.85) / 18;
	a = round(( x + 0.85 ) / tmp);
	b = round(( -y + 0.85 ) / tmp);

	if ( !this->goban->canPlayHere( this->currentPlayer, a, b ) )
		return ;

	this->stones->push_back( new Stones( a, b, this->currentPlayer ) );
	this->goban->addStone( a, b, this->currentPlayer );
	this->currentPlayer = this->currentPlayer == 1 ? 2 : 1;
	this->checkCapture();
	this->checkWin();
}

void		GameEngine::deleteStone(int x, int y)
{
	int		pos = 0;

	for (std::vector<Stones *>::iterator i = this->stones->begin(); i != this->stones->end(); ++i)
	{
		if ( this->stones->at(pos)->getX() == x && this->stones->at(pos)->getY() == y )
		{
			this->goban->deleteStone(x, y);
			delete this->stones->at(pos);
			this->stones->erase(i);
			return ;
		}
		pos++;
	}
}

void		GameEngine::checkWin()
{
	int		currentPlayer;

	currentPlayer =  this->stones->back()->getPlayer();

	if ( checkAlignement( -1, -1, 1, 1, this->stones->back() ) >= 5
		|| checkAlignement( -1, 0, 1, 0, this->stones->back() ) >= 5
		|| checkAlignement( 0, -1, 0, 1, this->stones->back() ) >= 5
		|| checkAlignement( -1, 1, 1, -1, this->stones->back() ) >= 5 )
	{
		std::cout << "Player " << currentPlayer << " Win ! " << std::endl;
		exit(0);
	}
}

int		GameEngine::checkAlignement( int axeX1, int axeY1, int axeX2, int axeY2, Stones *lastStone )
{
	int		j;
	int		i;
	int		x;
	int		y;

	x = lastStone->getX();
	y = lastStone->getY();
	i = 0;
	while (  this->goban->playerHere( x + axeX1 * i, y + axeY1 * i ) == lastStone->getPlayer() )
		i++;
	if (i >= 5)
		return (i);
	j = i;
	i = 1;
	while (  this->goban->playerHere( x + axeX2 * i, y + axeY2 * i ) == lastStone->getPlayer() )
		i++;
	j = j + (i - 1);

	return (j);
}

void		GameEngine::checkCapture()
{
	int		enemy;
	int		x;
	int		y;

	enemy = this->stones->back()->getPlayer() == 1 ? 2 : 1;
	x = this->stones->back()->getX();
	y = this->stones->back()->getY();

	for (int a = -1; a <= 1; ++a)
	{
		for (int b = -1; b <= 1; ++b)
		{
			if ( this->goban->playerHere(x + a, y + b) == enemy &&
				this->goban->playerHere(x + 2 * a, y + 2 * b) == enemy &&
				this->goban->playerHere(x + 3 * a, y + 3 * b) == this->stones->back()->getPlayer() )
			{
				this->players[this->stones->back()->getPlayer() - 1]->addCaptureCount( 2 );
				this->deleteStone(x + a, y + b);
				this->deleteStone(x + 2 * a, y + 2 * b);
			}
		}
	}
}

void		GameEngine::renderAll( RenderEngine *render )
{
	this->goban->render(render);

	for (size_t i = 0; i < this->stones->size(); ++i)
		this->stones->at(i)->render(render);
}

