#include "Grid.h"

Grid::Grid(unsigned int p_sizeX, unsigned int& p_screenWidth, unsigned int& p_screenHeight)
{
	m_gridSize.x = p_sizeX;
	m_tileSize = p_screenWidth / p_sizeX;
	m_gridSize.y = p_screenHeight / m_tileSize;

	m_numOfTiles = m_gridSize.x * m_gridSize.y;

	std::cout << m_numOfTiles << std::endl;

	m_tiles = new Tile[m_numOfTiles];

	float x = 0;
	float y = 0;

	for (int i = 0; i < m_numOfTiles; i++)
	{
		if (i % m_gridSize.x == 0 && i >= m_gridSize.x)
		{
			x = 0;
			y += m_tileSize;
		}

		m_tiles[i].m_position = sf::Vector2f(x, y);

		m_tiles[i].m_rectangle.setSize(sf::Vector2f(m_tileSize, m_tileSize));
		m_tiles[i].m_rectangle.setPosition(x, y);
		m_tiles[i].m_rectangle.setFillColor(sf::Color::Black);

		x += m_tileSize;
	}

	colorRow(13, sf::Color::Magenta);
	colorRow(7, sf::Color::Magenta);
	
	for (int i = 6; i > 1; i--)
	{
		colorRow(i, sf::Color::Blue);
	}

	colorRow(1, sf::Color::Green);

	
	for (int i = 2; i < m_gridSize.x; i += 3)
	{
		m_tiles[convertIndex(i, 1)].m_rectangle.setFillColor(sf::Color::Blue);
		/*m_grassRect.erase(m_grassRect.begin() + i);*/
		m_waterRect.push_back(&m_tiles[convertIndex(i, 1)].m_rectangle);
	}

	for (int i = 0; i < m_gridSize.x; i++)
	{
		if(m_tiles[convertIndex(i, 1)].m_rectangle.getFillColor() == sf::Color::Green)
			m_grassRect.push_back(&m_tiles[convertIndex(i, 1)].m_rectangle);
	}

	std::cout << m_gridSize.x << ", " << m_gridSize.y << std::endl;
}

Grid::~Grid()
{

}

void Grid::draw(sf::RenderTarget& target) const
{
	for (int i = 0; i < m_numOfTiles; i++)
	{
		target.draw(m_tiles[i].m_rectangle);
	}
}

sf::Vector2f Grid::getPosByIndex(int x, int y)
{
	return m_tiles[convertIndex(x, y)].m_position;
}

int Grid::convertIndex(int x, int y)
{
	return y * m_gridSize.x + x;
}

sf::Vector2f Grid::getMidPoint()
{
	return m_tiles[((m_gridSize.x * m_gridSize.y) / 2) - 1].m_position;
}

int Grid::getTileSize()
{
	return m_tileSize;
}

sf::Vector2f Grid::getBottomRowPos()
{
	return m_tiles[(m_gridSize.y - 1) * m_gridSize.x].m_position;
}

sf::Vector2i Grid::getGridSize()
{
	return m_gridSize;
}

void Grid::colorRow(int p_row, sf::Color p_color)
{
	int index = convertIndex(0, p_row);

	for (int i = 0; i < m_gridSize.x; i++)
	{
		m_tiles[index].m_rectangle.setFillColor(p_color);
		index++;
	}
}

std::vector<sf::RectangleShape*> Grid::getGrassRect()
{
	return m_grassRect;
}

std::vector<sf::RectangleShape*> Grid::getWaterRect()
{
	return m_waterRect;
}

