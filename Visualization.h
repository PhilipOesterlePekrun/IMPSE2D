#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Visualization
{
public:
	int windowWidth;
	int windowHeight;
	int framerate;
	int antiAliasingLevel;
	sf::Color baseColor; // == background color
	sf::Color secondaryColor;
	sf::Color defaultTextColor;
	sf::Font defaultFont;
	int defaultFontSize; // might delete if it does not make sense

	unsigned int currentFrame=0; // or use time, idk
	bool active=false; // active = window open
	bool paused=true;
	bool playOnLoop=false;

private:
	sf::RenderWindow renderWindow;
	int renderWindowDefaultPosX=50;
	int renderWindowDefaultPosY=50;
	

private:
	void drawBaseUI();

	inline sf::Vector2f posInXY(float posX, float posY){
		return sf::Vector2f(posX,windowHeight-posY);
	}
	sf::Text textConstructor(std::string textString, sf::Font *font, int fontSize, sf::Color fillColor, float posX, float posY);
public:
	Visualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize, int antiAliasingLevel); // (antiAliasingLevel = 0) == off
	bool activate();
	bool deactivate();
	bool play();
	bool pause();
	bool goToTime(double toTime); // go to nearest time

	void drawFrame();

	static inline void loadFont(sf::Font *fontObj, std::string filePath)
	{
		if(!fontObj->loadFromFile(filePath)){
			std::cout<<"ERROR: Cannot load font"<<"\n";
		}
	}
};