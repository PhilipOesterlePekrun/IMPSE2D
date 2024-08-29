#include "Visualization.h"

void Visualization::drawBaseUI()
{
	renderWindow.draw(textConstructor("Testing", &defaultFont, 24, defaultTextColor, 500, 500));
}

sf::Text Visualization::textConstructor(std::string textString, sf::Font *font, int fontSize, sf::Color fillColor, float posX, float posY)
{
	sf::Text textObj;
	textObj.setFont(*font);
	textObj.setString(textString);
	textObj.setCharacterSize(fontSize);
	textObj.setFillColor(fillColor);
	textObj.setPosition(posInXY(posX, posY));
	return textObj;
}


Visualization::Visualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize, int antiAliasingLevel)
{
	this->windowWidth=windowWidth;
	this->windowHeight=windowHeight;
	this->framerate=framerate;
	this->baseColor=baseColor;
	this->secondaryColor=secondaryColor;
	this->defaultTextColor=defaultTextColor;
	this->defaultFont=*defaultFont;
	this->defaultFontSize=defaultFontSize;
	this->antiAliasingLevel=antiAliasingLevel;
}
bool Visualization::activate()
{
	if(renderWindow.isOpen())
	{
		return 0;
	}

	active=true;
	renderWindow.create(sf::VideoMode(windowWidth, windowHeight), "Simulation Base");
	renderWindow.setPosition(sf::Vector2i(renderWindowDefaultPosX, renderWindowDefaultPosY));
	renderWindow.setFramerateLimit(framerate);
	return 1;
}
bool Visualization::deactivate()
{
	active=false;
	renderWindow.close();
	return 1;
}
bool Visualization::play()
{
	if(!renderWindow.isOpen())
	{
		return 0;
	}

	paused=false;
	return 1;
}
bool Visualization::pause()
{
	if(!renderWindow.isOpen())
	{
		return 0;
	}

	paused=true;
	return 1;
}
bool Visualization::goToTime(double toTime) // go to nearest time
{
	if(!renderWindow.isOpen())
	{
		return 0;
	}

	return 1;
}

void Visualization::drawFrame()
{
	if(renderWindow.isOpen())
	{
		sf::Event event;
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				deactivate();
			}
		}

		renderWindow.clear(baseColor);
		drawBaseUI();
		renderWindow.display();
	}
}