#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>

Button::Button(sf::String l_title , sf::Vector2f l_size, sf::Color l_color, sf::Vector2f l_position) {
    Setup(l_title, l_size, l_color, l_position);
}
Button::~Button() {

}

void Button::Update(sf::Vector2i l_mousePosition){
    std::cout << 456 << std::endl;
}

void Button::Render(sf::RenderWindow& l_window){
    l_window.draw(m_background);
    l_window.draw(m_text);
}

void Button::Setup(sf::String l_title, sf::Vector2f l_size, sf::Color l_color, sf::Vector2f l_position) {
    //text options 
    m_font.loadFromFile("Arial.ttf");
    m_text.setFont(m_font);
    m_text.setColor(sf::Color::White);
    m_text.setString(l_title);
    m_text.setPosition(l_position.x + l_size.x/2 - m_text.getLocalBounds().width/2, l_position.y + l_size.y/2 - m_text.getLocalBounds().height);
    m_background.setSize(l_size);
    m_background.setFillColor(l_color);
    m_background.setPosition(l_position);
}