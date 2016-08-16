#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Button {

private:
	float x;
	float y;
	string name_of_texture;
	sf::Sprite rectangle;
	sf::Texture buttonTexture;
	sf::Music buttonSound;
	sf::Font buttonFont;
	sf::Text buttonText;
public:
	Button(float x, float y, string nameOfTexture);
	void setScale(float xscale, float yscale);
	void setButton(string music, string font, string text);
	void playSound();
	void stopSound();
	sf::Text getText();
	sf::Sprite getSprite();
};


#endif
