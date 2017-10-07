#pragma once

#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Menu {
public:
    Menu();
    ~Menu();

    void Update(sf::Vector2i l_mousePosition);

    void Render(sf::RenderWindow& l_window);

private:

    sf::Text m_text;
    sf::Font m_font;
    sf::RectangleShape m_background;
    
    Button m_newGame;
    Button m_closeGame;

};