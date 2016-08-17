#include "Button.h"

Button::Button(float x, float y, string nameOfTexture)
{
	buttonTexture.loadFromFile(nameOfTexture);
	rectangle.setTexture(buttonTexture);
	rectangle.setPosition(x, y);
	buttonText.setPosition(x, y);
}


void Button::setButtonScale(float xscale, float yscale) 
{
	rectangle.setScale(xscale, yscale);
}

void Button::moveButton(float x, float y)
{
	rectangle.setPosition(x, y);
}


void Button::setButtonMusic(string music, string font, string text)
{
	buttonSound.openFromFile(music);
	buttonFont.loadFromFile(font);
	buttonText.setFont(buttonFont);
	buttonText.setScale(1, 1);
	buttonText.setString(text);
}

sf::Text Button::getText()
{
	return buttonText;
}

sf::Sprite Button::getSprite()
{
	return rectangle;
}

void Button::drawButton(sf::RenderWindow& window) 
{
	window.draw(rectangle);
	if (!buttonText.getString().isEmpty()) {
		window.draw(buttonText);
	}
}

void Button::useButton(sf::RenderWindow& window, sf::Event event) {
	if (sf::Mouse::getPosition(window).x > rectangle.getGlobalBounds().left
		&& sf::Mouse::getPosition(window).x < (rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width)
		&& sf::Mouse::getPosition(window).y > rectangle.getGlobalBounds().top
		&& sf::Mouse::getPosition(window).y < (rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
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
