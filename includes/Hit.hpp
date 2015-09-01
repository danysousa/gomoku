#ifndef HIT_HPP
# define HIT_HPP

# include <Goban.hpp>

class Hit
{
	public:
		Hit ( int x, int y, int player, int score, Goban *goban );
		~Hit();

		Hit	operator=( Hit const & cpy );

		int		getX( void ) const;
		int		getY( void ) const;
		int		getPlayer( void ) const;
		int		getScore( void ) const;

	private:
		Hit( void );

		int			x;
		int			y;
		int			player;
		int			score;
		Goban		*stateAfter;

};

#endif