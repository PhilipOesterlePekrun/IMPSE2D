#include "Visualization.h"

void Visualization::drawBaseUI()
{
	// pause bar and symbol
	{
		sf::RectangleShape playPauseLoopBar(sf::Vector2f(400, 100));
		playPauseLoopBar.setPosition(posInXY(windowWidth/2-200, 200));
		playPauseLoopBar.setFillColor(sf::Color(100, 100, 100));
		renderWindow.draw(playPauseLoopBar);
		if(paused)
		{
			sf::RectangleShape pauseL(sf::Vector2f(10, 80));
			pauseL.setPosition(posInXY(windowWidth/2-5-20, 200-10));
			pauseL.setFillColor(sf::Color(0,0,0));
			renderWindow.draw(pauseL);
			sf::RectangleShape pauseR(sf::Vector2f(10, 80));
			pauseR.setPosition(posInXY(windowWidth/2-5+20, 200-10));
			pauseR.setFillColor(sf::Color(0,0,0));
			renderWindow.draw(pauseR);
		}
		else
		{
			sf::ConvexShape playTriangle;
			playTriangle.setFillColor(sf::Color(0,0,0));
			playTriangle.setPointCount(3);
			playTriangle.setPoint(0, posInXY(windowWidth/2+20, 200-50));
			playTriangle.setPoint(1, posInXY(windowWidth/2-20, 200-10));
			playTriangle.setPoint(2, posInXY(windowWidth/2-20, 200-90));
			renderWindow.draw(playTriangle);
		}
	}

	// window time and frame count
	{
		std::string descString="Window:";
		std::string frameCountString="current frame = "+std::to_string(currentFrame);
		std::string timeString="t = "+std::to_string(currentTime().asSeconds())+"s";
		sf::Text descText=textConstructor(descString, &defaultFont, 14, defaultTextColor, windowWidth/2-200, 200);
		sf::Text frameCountText=textConstructor(frameCountString, &defaultFont, 12, defaultTextColor, windowWidth/2-180, 200-12);
		sf::Text timeText=textConstructor(timeString, &defaultFont, 12, defaultTextColor, windowWidth/2-180, 200-24);
		renderWindow.draw(descText);
		renderWindow.draw(frameCountText);
		renderWindow.draw(timeText);
	}
}

sf::Text Visualization::textConstructor(std::string textString, sf::Font *font, int fontSize, sf::Color fillColor, float posX, float posY) // NOTE: Already in my XY coordinate system
{
	sf::Text textObj;
	textObj.setFont(*font);
	textObj.setString(textString);
	textObj.setCharacterSize(fontSize);
	textObj.setFillColor(fillColor);
	textObj.setPosition(posInXY(posX, posY));
	return textObj;
}


// CONSTRUCTORS
Visualization::Visualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize){
	this->windowWidth=windowWidth;
	this->windowHeight=windowHeight;
	this->framerate=framerate;
	this->baseColor=baseColor;
	this->secondaryColor=secondaryColor;
	this->defaultTextColor=defaultTextColor;
	this->defaultFont=*defaultFont;
	this->defaultFontSize=defaultFontSize;

	maxTime=sf::Time(sf::seconds(5));
}
Visualization::Visualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize, int antiAliasingLevel) :
	Visualization(windowWidth, windowHeight, framerate, baseColor, secondaryColor, defaultTextColor, defaultFont, defaultFontSize)
{
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
	renderWindow.setPosition(renderWindowPos);
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

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			if(!pDown) paused=!paused;
			pDown=true;
		}
		else
		{
			pDown=false;
		}

		if(!paused){
			currentFrame++;
		}

		renderWindow.clear(baseColor);
		drawBaseUI();
		// drawSimulation of currentFrame
		renderWindow.display();
	}
}