#ifndef STONES_HPP
# define STONES_HPP
# include <IComponent.hpp>
# include <iostream>

class Stones : public IComponent
{
	public:
		Stones( void );
		Stones ( int x, int y, int player );
		virtual ~Stones();

		Stones	operator=( Stones const & cpy );

		void render( RenderEngine * );
		void update( void );

		int		getX( void ) const;
		int		getY( void ) const;
		int		getPlayer( void ) const;

		bool	win;

	private:
		int		x;
		int		y;
		int		player;
};

#endif