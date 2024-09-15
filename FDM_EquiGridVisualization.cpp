#include "Visualization.h"
#include "FDM_EquiGridVisualization.h"

void FDM_EquiGridVisualization::defaultGridSizing()
{
	double ppmHorizontal=windowWidth/(sim.xBounds[1]-sim.xBounds[0]);
	double ppmVertical=windowHeight/(sim.yBounds[1]-sim.yBounds[0]);
	pixelsPerMeter=std::min(ppmHorizontal, ppmVertical);
}
void FDM_EquiGridVisualization::drawBaseUI()
{
	{
		Visualization::drawBaseUI();
		std::string descString="Simulation Information:";
		sf::Text desctext=textConstructor(descString, &defaultFont, 18, defaultTextColor, 50, windowHeight-50);
		renderWindow.draw(desctext);
	}
}

// CONSTRUCTORS
FDM_EquiGridVisualization::FDM_EquiGridVisualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize,
	Simulation_FDM_ChorinsProj_Viscous_Unsteady sim)
	: Visualization(windowWidth, windowHeight, framerate, baseColor, secondaryColor, defaultTextColor, defaultFont, defaultFontSize)
{
	if(sim.simHasRun) this->sim=sim;
}
FDM_EquiGridVisualization::FDM_EquiGridVisualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize, int antiAliasingLevel,
	Simulation_FDM_ChorinsProj_Viscous_Unsteady sim)
	: Visualization(windowWidth, windowHeight, framerate, baseColor, secondaryColor, defaultTextColor, defaultFont, defaultFontSize, antiAliasingLevel)
{
	if(sim.simHasRun) this->sim=sim;
}

void FDM_EquiGridVisualization::drawFrame()
{
	Visualization::drawFrame();
}