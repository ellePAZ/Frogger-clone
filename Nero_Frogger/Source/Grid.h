#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Grid
{
	struct Tile
	{
		sf::Vector2f m_position = sf::Vector2f(0, 0);
		sf::RectangleShape m_rectangle;
	};

	Tile* m_tiles;
	std::vector<sf::RectangleShape*> m_grassRect;
	std::vector<sf::RectangleShape*> m_waterRect;

	sf::Vector2i m_gridSize;
	int m_tileSize;

	int m_numOfTiles;

public:
	Grid(unsigned int p_sizeX, unsigned int& p_screenWidth, unsigned int& p_screenHeight);
	~Grid();

	void draw(sf::RenderTarget& target) const;
	
	sf::Vector2f getPosByIndex(int x, int y);
	int convertIndex(int x, int y);

	sf::Vector2f getMidPoint();
	sf::Vector2f getBottomRowPos();
	int getTileSize();

	sf::Vector2i getGridSize();

	void colorRow(int, sf::Color);

	std::vector<sf::RectangleShape*> getGrassRect();
	std::vector<sf::RectangleShape*> getWaterRect();

};