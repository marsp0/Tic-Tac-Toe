#pragma once

#include <SFML/Graphics.hpp>

class Button {

public:
    Button(sf::String l_title , sf::Vector2f l_size, sf::Color l_color, sf::Vector2f l_position);
    ~Button();

    void Render(sf::RenderWindow& l_window);
    
    void Setup(sf::String l_title, sf::Vector2f l_size, sf::Color l_color, sf::Vector2f l_position);

    sf::FloatRect getGlobalBounds();

private:

    sf::Text m_text;
    sf::Font m_font;
    sf::RectangleShape m_background;

};