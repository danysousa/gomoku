#include <Computer.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Computer::Computer( void )
{
	this->player = 1;
}

Computer::Computer( int player ) : Player( player )
{

}

Computer::Computer( Computer const & cpy ) : Player( player )
{
	*this = cpy;
}

Computer::~Computer( void )
{

}

/*
** OPERATOR
*/
Computer Computer::operator=( Computer const & cpy )
{
	this->player = cpy.getPlayer();
	this->captured = cpy.getCaptured();
	return ( *this );
}

/*
** METHOD
*/
Hit		*Computer::simulate( Goban *goban, std::vector<Stones *> *canMove, std::vector<Stones *> *stones )
{
	std::vector<Hit *>		hits;
	std::vector<Stones *>	tmp;
	Hit						*tmpHit;
	int						tmpScore;
	int						bestScore;

	for (size_t i = 0; i < canMove->size(); ++i)
	{
		hits.push_back( new Hit( canMove->at(i)->getX(), canMove->at(i)->getY(), this->player, *goban) );
		stones->push_back( new Stones( canMove->at(i)->getX(), canMove->at(i)->getY(), this->player ) );
		findFreeMove( hits.at(hits.size() - 1)->getStateAfter(), stones, &tmp, this->player == 2 ? 1 : 2 );
		std::cout << hits.at(hits.size() - 1)->getStateAfter().playerHere(canMove->at(i)->getX(), canMove->at(i)->getY()) << " == " << this->player << std::endl;
		std::cout << canMove->at(i)->getX() << ", " << canMove->at(i)->getY() << " :" << std::endl;
		for (size_t j = 0; j < tmp.size(); ++j)
		{
			tmpHit = new Hit( tmp.at(j)->getX(), tmp.at(j)->getY(), tmp.at(j)->getPlayer(), hits.at(hits.size() - 1)->getStateAfter() );
			tmpHit->setScore( this->score( tmpHit->getStateAfter(), this->player ) );
			std::cout << "\t    XY => (" << tmpHit->getX() << ", " << tmpHit->getY() << ") --- Score : " << tmpHit->getScore() << std::endl;
			hits.at(hits.size() - 1)->addPossibility( tmpHit );
		}

		delete stones->at(stones->size() - 1);
		stones->pop_back();
		for (size_t i = 0; i < tmp.size(); ++i)
			delete tmp.at(i);

		tmp.erase(tmp.begin(), tmp.end());
	}

	for (size_t i = 0; i < hits.size(); ++i)
	{
		tmpScore = hits.at( i )->getMinScore();
		if ( i == 0 || tmpScore > bestScore )
		{
			bestScore = tmpScore;
			tmpHit = hits.at( i );
		}
	}

	return ( tmpHit );
}

Stones		*Computer::play( Goban *goban, std::vector<Stones *> stones )
{
	Hit		*hit;

	std::vector<Stones *> *canMove = new std::vector<Stones *>;
	this->findFreeMove( *goban, &stones, canMove, this->player );
	hit = this->simulate( goban, canMove, &stones );

	std::cout << "\n\n\n" << std::endl;
	return ( new Stones( hit->getX(), hit->getY(), this->player ) );
}

int			Computer::scoreAlignement( int **goban, int axeX, int axeY, int x, int y ) const
{
	int		i;
	int		a;
	int		b;
	int		*result;

	result = new int[2];
	result[1] = 0;
	i = 1;
	a = x + axeX * i;
	b = y + axeY * i;
	while ( a >= 0 && a < 19 && b >= 0 && b < 19 && goban[a][b] == goban[x][y] )
	{
		// goban[a][b] = - goban[x][y];
		i++;
		a = x + (axeX * i);
		b = y + (axeY * i);
	}

	if (a >= 0 && a < 19 && b >= 0 && b < 19 && goban[a][b] == 0 )
		result[1]++;

	result[0] = i;
	i = 1;
	a = x - axeX * i;
	b = y - axeY * i;
	while ( a >= 0 && a < 19 && b >= 0 && b < 19 && goban[a][b] == goban[x][y] )
	{
		// goban[a][b] = - goban[x][y];
		i++;
		a = x - (axeX * i);
		b = y - (axeY * i);
	}

	result[0] = result[0] + (i - 1);
	if ( result[0] >= 5 )
		return ( 10000 );
	// std::cout << "{POK} -----> " << result[0] << std::endl;
	if (a >= 0 && a < 19 && b >= 0 && b < 19 && goban[a][b] == 0 )
		result[1]++;

	result[1] = result[1] == 0 ? 0 : ( result[0] * ( result[0] * (result[1] - 1) ) );

	return (result[1]);
}


int			Computer::score( Goban const &goban, int player ) const
{
	int		score;
	int		**tmp;
	int		inc;

	tmp = goban.toIntArray();

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if ( tmp[i][j] <= 0 )
				continue ;
			inc = tmp[i][j] == player ? 1 : -1;
			for (int a = -1; a <= 0; ++a)
			{
				for (int b = -1; b <= 1; ++b)
				{
					if ( a == 0 && b == 0 )
						break ;
					score = score + ( this->scoreAlignement(tmp, a, b, i, j) * inc );
				}
			}
		}
	}

	for (int i = 0; i < 19; ++i)
		delete [] tmp[i];
	delete [] tmp;

	return ( score );
}

void	Computer::findFreeMove( Goban const &goban, std::vector<Stones *> *stones, std::vector<Stones *> *canMove, int nbplayer )
{
	int		j = 0;
	int		x;
	int		y;

	for ( unsigned int i = 0; i < stones->size(); ++i)
	{
		x = stones->at(i)->getX();
		y = stones->at(i)->getY();
		for ( int a = -1; a <= 1; a++ )
		{
			for ( int b = -1; b <= 1; b++ )
			{
				if ( goban.playerHere( x - a, y - b ) == 0 )
				{
					if ( checkMoveExist( x - a, y - b, canMove ) == 0 && goban.canPlayHere( nbplayer, x - a, y - b ) )
					{
						j++;
						canMove->push_back( new Stones( x - a, y - b, nbplayer ) );
					}
				}
			}
		}
	}

	this->numberFreeMove = j;
}

int			Computer::checkMoveExist(int x, int y, std::vector<Stones *> *canMove)
{
	for ( unsigned int i = 0; i < canMove->size(); ++i )
	{
		if ( canMove->at(i)->getX() == x && canMove->at(i)->getY() == y )
			return (1);
	}
	return (0);
}

/*
** GETTER & SETTER
*/
