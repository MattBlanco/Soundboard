#include "button.h"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");



	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("cat.jpg"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	sprite.setScale(0.20, 0.20);
	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("contl.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Genghis Khan", font, 50);
	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("test.wav"))
		return EXIT_FAILURE;






	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Mouse::getPosition(window).x > sprite.getGlobalBounds().left 
				&& sf::Mouse::getPosition(window).x < (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) 
				&& sf::Mouse::getPosition(window).y > sprite.getGlobalBounds().top
				&& sf::Mouse::getPosition(window).y < (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height))
			{
               if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (music.getStatus() == sf::Music::Playing) {
							music.stop();
						}
						else {
							music.play();
						}
					}
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		//window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Draw the string
		window.draw(text);
		// Update the window
		window.display();
	}



	return EXIT_SUCCESS;
}