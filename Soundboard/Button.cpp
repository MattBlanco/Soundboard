#include "Button.h"

Button::Button(float x, float y, string name_of_texture)
{

	rectangle.setPosition(x, y);
	buttonTexture.loadFromFile(name_of_texture);
	rectangle.setTexture(buttonTexture);
}

void Button::setScale(float xscale, float yscale) 
{
	rectangle.setScale(xscale, yscale);
}


void Button::setButton(string music, string font, string text)
{
	buttonSound.openFromFile(music);
	buttonFont.loadFromFile(font);
	buttonText.setFont(buttonFont);
	buttonText.setScale(5, 5);
	buttonText.setString(text);
}

void Button::playSound()
{
	buttonSound.play();
}

void Button::stopSound()
{
	buttonSound.stop();
}

sf::Text Button::getText()
{
	return buttonText;
}

sf::Sprite Button::getSprite()
{
	return rectangle;
}

