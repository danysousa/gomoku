#ifndef GOBAN_HPP
# define GOBAN_HPP
# include <IComponent.hpp>
# include <iostream>
# include <vector>

class Goban : public IComponent
{
	public:
		Goban();
		Goban( Goban const & cpy );
		Goban( int **goban );
		virtual ~Goban();

		Goban	&operator=( Goban const & cpy );

		void	render( RenderEngine * );
		void	update( void );
		void	addStone( int x, int y, int player );
		void	deleteStone( int x, int y );
		int		playerHere( int x, int y ) const;

		bool	canPlayHere( int player, int x, int y ) const;

		int		**toIntArray( void ) const;
		int		getCapturedStones( void ) const;
		std::vector<int *>	const &getLastDeletedStones( void ) const;

	private:
		int					stones[19][19];
		std::vector<int *>	lastDeletedStones;

		bool	isCaptureZone( int player, int x, int y ) const;
		bool	isDoubleThree( int player, int x, int y ) const;
		void	checkCapture( int x, int y, int player );

};

#endif