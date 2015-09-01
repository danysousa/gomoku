#ifndef HIT_HPP
# define HIT_HPP

# include <Goban.hpp>
# include <vector>

class Hit
{
	public:
		Hit ( int x, int y, int player, Goban const &goban );
		~Hit();

		Hit	&operator=( Hit const & cpy );

		int		getX( void ) const;
		int		getY( void ) const;
		int		getPlayer( void ) const;
		Goban	const &getStateAfter( void ) const;
		int		getScore( void ) const;
		void	setScore( int );

		int		getMinScore( void );
		void	addPossibility( Hit *elem );
		void	linkScoreToPossibility( int pos, int score );

	private:
		Hit( void );

		int					x;
		int					y;
		int					player;
		int					score;
		Goban				stateAfter;
		std::vector<Hit *>	possibility;
};

#endif