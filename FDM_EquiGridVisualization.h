#pragma once
#include "Simulation_FDM_ChorinsProj_Viscous_Unsteady.h"
class FDM_EquiGridVisualization : public Visualization
{
public:
	double pixelsPerMeter; // default: fill screen in at least one direction (maybe also with a certain gap/bezel)
	sf::Vector2f originLocation=sf::Vector2f(0,0); // origin = bottom left corner; [pixels]
private:
	Simulation_FDM_ChorinsProj_Viscous_Unsteady sim;

	sf::Vector2f*gridVertexPositions;

private:
	void defaultGridSizing();
	void drawBaseUI() override;
public:
	// CONSTRUCTORS
	inline FDM_EquiGridVisualization(){}; // default constructor
	FDM_EquiGridVisualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize,
		Simulation_FDM_ChorinsProj_Viscous_Unsteady sim);
	FDM_EquiGridVisualization(int windowWidth, int windowHeight, int framerate, sf::Color baseColor, sf::Color secondaryColor, sf::Color defaultTextColor, sf::Font *defaultFont, int defaultFontSize, int antiAliasingLevel,
		Simulation_FDM_ChorinsProj_Viscous_Unsteady sim);

	void drawFrame() override;
};