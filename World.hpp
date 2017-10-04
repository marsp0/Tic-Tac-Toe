#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class World{
public:
	World(sf::Vector2u l_windowSize);
	~World();

    int GetBlockSize();

    void Update();
    
    void Render(sf::RenderWindow& l_window);
    
private:

	int m_blockSize;
    sf::RectangleShape m_bounds[4];
    sf::Vector2u m_windowSize;
};