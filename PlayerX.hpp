#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class PlayerX {
public:
    PlayerX(std::string string);
    ~PlayerX();
    void Render(sf::RenderWindow& l_window);
    bool Update(sf::Vector2i l_position, PlayerX& otherPlayer);
    bool CanIDraw(int row, int col);
private:
    sf::Texture m_texture;
    std::pair<sf::Sprite, bool> m_spriteStruct[3][3];
};