#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;

class Button {

private:
	sf::Sprite rectangle;
	sf::Texture buttonTexture;
	sf::Music buttonSound;
	sf::Font buttonFont;
	sf::Text buttonText;
public:
	Button(float x, float y, string nameOfTexture);
	void setButtonScale(float xscale, float yscale);
	void moveButton(float x, float y);
	void setButtonMusic(string music, string font, string text);
	void setButtonMusic(string music);
	sf::Text getText();
	sf::Sprite getSprite();
	void useButton(sf::RenderWindow& window, sf::Event event);
	void drawButton(sf::RenderWindow& window);
};
#endif
