#include "Button.h"

/********************
Function: Button(float x, float y, string nameOfTexture)

Constructor for the button class

Arguments: x position, y position, and the file name of a texture as a string ("cat.jpg")
*********************/
Button::Button(float x, float y, string nameOfTexture)
{
	buttonTexture.loadFromFile(nameOfTexture);
	rectangle.setTexture(buttonTexture);
	rectangle.setPosition(x, y);
	buttonText.setPosition(x, y);
}

/********************
Function: setButtonScale(float xscale, float yscale) 

Readjusts the scale of the button

Uses 1 as 100% and 0 as 0%

Returns: void
*********************/
void Button::setButtonScale(float xscale, float yscale) 
{
	rectangle.setScale(xscale, yscale);
}


/********************
Function: moveButton(float xscale, float yscale)

Moves the button to a new location

Returns: void
*********************/
void Button::moveButton(float x, float y)
{
	rectangle.setPosition(x, y);
}


/********************
Function: setButtonMusic(string music, string font, string text)

Sets the button music through a .wav file and assigns a font and text to the button

Returns: void
*********************/
void Button::setButtonMusic(string music, string font, string text)
{
	buttonSound.openFromFile(music);
	buttonFont.loadFromFile(font);
	buttonText.setFont(buttonFont);
	buttonText.setScale(1, 1);
	buttonText.setString(text);
}


/********************
Function: setButtonMusic(string music)

Sets the button music only. Useful if your texture already describes the button

Returns: void
*********************/
void Button::setButtonMusic(string music)
{
	buttonSound.openFromFile(music);
}

/********************
Function: drawButton(sf::RenderWindow& window)

Draws the button onto the window passed into the function

Returns: void
*********************/
void Button::drawButton(sf::RenderWindow& window) 
{
	window.draw(rectangle);
	if (!buttonText.getString().isEmpty()) {
		window.draw(buttonText);
	}
}


/********************
Function: useButton(sf::RenderWindow& window, sf::Event event)

Provides logic for the button's music by checking if the mouse is over the button when it is clicked
Uses an event object to poll for the user's mouse behavior
Returns: void
*********************/
void Button::useButton(sf::RenderWindow& window, sf::Event event) {
	//Checks if the mouse is within the button's coordinates
	if (sf::Mouse::getPosition(window).x > rectangle.getGlobalBounds().left
		&& sf::Mouse::getPosition(window).x < (rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width)
		&& sf::Mouse::getPosition(window).y > rectangle.getGlobalBounds().top
		&& sf::Mouse::getPosition(window).y < (rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height))
	{
		//Checks if the user is clicking the button
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//If the button's music is already playing, turn off button.
				//Otherwise turn on the button
				if (buttonSound.getStatus() == sf::Music::Playing) {
					buttonSound.stop();
				}
				else {
					buttonSound.play();
				}
			}
		}
	}
}
