#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Visualization
{
public:
	sf::Vector2i renderWindowPos=sf::Vector2i(50, 50); // default, but you can change it from externally so you can open multiple simulation windows perfectly next to eachother
	int windowWidth;
	int windowHeight;
	int framerate;
	int antiAliasingLevel=0;
	sf::Color baseColor; // == background color
	sf::Color secondaryColor;
	sf::Color defaultTextColor;
	sf::Font defaultFont;
	int defaultFontSize; // might delete if it does not make sense

	unsigned int currentFrame=0; // or use time, idk
	bool active=false; // active = window open
	bool paused=true;
	bool playOnLoop=false;

protected:
	sf::RenderWindow renderWindow;

	sf::Time maxTime; // or maxFrame idk; in any case, it is taken from simulation in the constructor for everything except the Visualization base class
	

protected:
	virtual void drawBaseUI();

	inline sf::Vector2f posInXY(float posX, float posY){
		return sf::Vector2f(posX,windowHeight-posY);
	}
	sf::Text textConstructor(std::string textString, sf::Font *font, int fontSize, sf::Color fillColor, float posX, float posY);

	inline const sf::Time currentTime(){
		return sf::Time(sf::seconds((float)currentFrame/framerate));
	}
public:
	// CONSTRUCTORS
	inline Visualization(){}; // default constructor
	Visualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize);
	Visualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize, int antiAliasingLevel); // (antiAliasingLevel = 0) == off

	bool activate();
	bool deactivate();
	bool play();
	bool pause();
	bool goToTime(double toTime); // go to nearest time

	bool pDown=false;
	virtual void drawFrame();

	static inline void loadFont(sf::Font *fontObj, std::string filePath)
	{
		if(!fontObj->loadFromFile(filePath)){
			std::cout<<"ERROR: Cannot load font"<<"\n";
		}
	}
};