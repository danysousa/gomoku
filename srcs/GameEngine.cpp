#include <GameEngine.hpp>

int GameEngine::counterWin = 0;

GameEngine::GameEngine() : goban( new Goban() ), currentPlayer(1), win(false)
{
	this->stones = new std::vector<Stones *>;
	this->players[0] = new Player(1);
	this->computer = new Computer(2);

	this->players[1] = this->computer;

	return ;
}

GameEngine::GameEngine( char numberPlayer ) : goban( new Goban() ), currentPlayer(1), win(false), estimation(NULL)
{
	this->stones = new std::vector<Stones *>;

	if ( numberPlayer == '1' )
	{
		this->nbPlayer = 1;
		this->players[0] = new Player(1);
		this->computer = new Computer(2);
		this->players[1] = this->computer;
	}
	else
	{
		this->nbPlayer = 2;
		this->players[0] = new Player(1);
		this->players[1] = new Player(2);
		this->computer = new Computer(1);
	}

	return ;
}

GameEngine::~GameEngine()
{
	return ;
}

void		GameEngine::updateAll()
{
	int		tmp;
	if ( this->win == true )
		return ;
	if ( this->currentPlayer == 2 && this->nbPlayer == 1 )
	{
		this->stones->push_back( this->computer->play( this->goban, *(this->stones) ) );
		tmp = this->stones->size() - 1;
		this->goban->addStone( this->stones->at(tmp)->getX(), this->stones->at(tmp)->getY(), 2 );
		this->computer->addEnemyCaptureCount( this->goban->getCapturedStones() );
		this->checkCapture();
		this->checkWin();
		this->currentPlayer = 1;

		return ;
	}
	else if ( this->nbPlayer == 2 && this->estimation == NULL && this->stones->size() > 0 )
	{
		this->computer->setPlayer( this->currentPlayer );
		this->estimation = this->computer->play( this->goban, *(this->stones) );
		this->estimation->setSimulation(true);
	}

	this->goban->update();
	if ( RenderEngine::lastClick[2] > 0.0 )
		this->addPlayerStone( RenderEngine::lastClick[0], RenderEngine::lastClick[1] );

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
	if ( this->estimation != NULL )
	{
		delete this->estimation;
		this->estimation = NULL;
	}

	this->goban->addStone( a, b, this->currentPlayer );
	this->checkCapture();
	this->currentPlayer = this->currentPlayer == 1 ? 2 : 1;
	this->checkWin();
}

void		GameEngine::checkCapture()
{
	std::vector<int *> const		& captured = this->goban->getLastDeletedStones();

	this->players[this->currentPlayer - 1]->addCaptureCount( this->goban->getCapturedStones() );
	for (size_t i = 0; i < captured.size(); ++i)
		this->deleteStone( captured.at(i)[0], captured.at(i)[1] );

	if ( this->players[this->currentPlayer - 1]->getCaptured() >= 10 )
	{
		std::cout << "Player " << currentPlayer << " Win by capture! " << std::endl;
		this->win = true;
		this->stones->at(this->stones->size() - 1)->win = true;
	}

	return ;
}

void		GameEngine::deleteStone(int x, int y)
{
	int		pos = 0;

	for (std::vector<Stones *>::iterator i = this->stones->begin(); i != this->stones->end(); ++i)
	{
		if ( this->stones->at(pos)->getX() == x && this->stones->at(pos)->getY() == y )
		{
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
		if ( this->checkCounterWin() == 0 )
		{
			std::cout << "Player " << currentPlayer << " Win ! " << std::endl;
			this->win = true;
			this->stones->at(this->stones->size() - 1)->win = true;
		}
	}
}

int			GameEngine::checkCounterWin()
{
	int		nbCurrentPlayer;
	int		stoneEnemy;
	int		stoneCurrentPlayer;
	int		x;
	int		y;
	Player	*enemy;
	Player	*currentPlayer;

	nbCurrentPlayer = this->stones->back()->getPlayer();
	currentPlayer = nbCurrentPlayer == this->players[0]->getPlayer() ? this->players[0] : this->players[1];
	enemy = nbCurrentPlayer == this->players[0]->getPlayer() ? this->players[1] : this->players[0];

	if ( enemy->getCaptured() == 8 && GameEngine::counterWin == 0 )
	{
		for ( unsigned int i = 0; i < stones->size(); ++i)
		{
			x = this->stones->at(i)->getX();
			y = this->stones->at(i)->getY();
			for ( int a = -1; a <= 1; a++ )
			{
				for ( int b = -1; b <= 1; b++ )
				{
					if ( this->goban->playerHere( x - a, y - b ) == 0 )
					{
						stoneEnemy = 0;
						stoneCurrentPlayer = 0;
						for ( int c = 0; c < 2; ++c )
						{
							if ( this->goban->playerHere( x + a * c, y + b * c ) == enemy->getPlayer() )
								stoneEnemy++;
						}
						if ( stoneEnemy == 2 && this->goban->playerHere( x + a * 3, y + b * 3 ) == currentPlayer->getPlayer() )
							stoneCurrentPlayer++;
						if ( stoneEnemy == 2 && stoneCurrentPlayer == 1 )
						{
							GameEngine::counterWin = 1;
							return (1);
						}
					}
				}
			}
		}
	}

	return (0);
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

void		GameEngine::renderAll( RenderEngine *render )
{
	this->goban->render(render);

	for (size_t i = 0; i < this->stones->size(); ++i)
		this->stones->at(i)->render(render);
	if ( this->estimation != NULL )
		this->estimation->render(render);

}

