#include "button.h"

int main()
{
	//create a new window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Soundboard window");

	//create buttons with different sounds
	//The origin (0,0) is the top left corner of the window, there are no negative coordinates
	
	//This button is longer to demonstrate being able to stop a sound
	Button genghis(0, 0, "cat.jpg");
	genghis.setButtonScale(0.2, 0.2);
	genghis.setButtonMusic("test.wav", "contl.ttf", "genghis khan");

	Button powerup(300, 0, "powerup.png");
	powerup.setButtonScale(1, 1);
	powerup.setButtonMusic("smw_power-up.wav");

	Button oneup(600, 0, "oneup.jpg");
	oneup.setButtonScale(0.2, 0.2);
	oneup.setButtonMusic("smw_1-up.wav");

	Button ring(0, 300, "ring.png");
	ring.setButtonScale(1, 1);
	ring.setButtonMusic("ring.wav");

	//Creating a background for the soundboard
	sf::Texture texture;
	texture.loadFromFile("geo.jpg");

	//Create a new sprite (rectangle with a texture)
	sf::Sprite sprite(texture);
	sprite.setScale(1, 1);



	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			//enable logic to control buttons
			genghis.useButton(window, event);
			powerup.useButton(window, event);
			oneup.useButton(window, event);
			ring.useButton(window, event);

			//end program if window is closed
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//displays the window
		window.display();

		//draw the background
		window.draw(sprite);

		//draws the buttons onto the window
		genghis.drawButton(window);
		powerup.drawButton(window);
		oneup.drawButton(window);
		ring.drawButton(window);
	}
}