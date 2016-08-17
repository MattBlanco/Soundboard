#include "button.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Soundboard window");


	Button genghis(20, 20, "cat.jpg");
	genghis.setButtonScale(0.2, 0.2);
	genghis.setButtonMusic("test.wav", "contl.ttf", "genghis khan");

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			genghis.useButton(window, event);
			if (event.type == sf::Event::Closed)
				window.close();
		}
		genghis.drawButton(window);
		window.display();
	}
}