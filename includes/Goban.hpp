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

		bool		canPlayHere( int player, int x, int y );

		int		**toIntArray( void ) const;

	private:
		int			stones[19][19];

		bool		isCaptureZone( int player, int x, int y );
		bool		isDoubleThree( int player, int x, int y );

};

#endif