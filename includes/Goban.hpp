#ifndef GOBAN_HPP
# define GOBAN_HPP
# include <IComponent.hpp>
# include <iostream>

class Goban : public IComponent
{
	public:
		Goban();
		virtual ~Goban();

		void	render( RenderEngine * );
		void	update( void );
		void	addStone( int x, int y, int player );
		void	deleteStone( int x, int y );
		int		playerHere( int x, int y );

	private:
		int		stones[19][19];
};

#endif