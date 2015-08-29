#ifndef GOBAN_HPP
# define GOBAN_HPP
# include <IComponent.hpp>
# include <iostream>

class Goban : public IComponent
{
	public:
		Goban();
		virtual ~Goban();

		void render( RenderEngine * );
		void update( void );

};

#endif