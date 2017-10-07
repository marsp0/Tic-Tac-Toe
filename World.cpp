#include <SFML/Graphics.hpp>
#include "World.hpp"
#include <iostream>
#include <vector>

World::World(sf::Vector2u l_window) : m_windowSize(l_window), m_blockSize(25) {
    for (int i=0; i < 4 ; i++) {
        m_bounds[i].setFillColor(sf::Color(135,206,250));
        if ( i < 2 ) {
            m_bounds[i].setSize(sf::Vector2f(25,800));
            m_bounds[i].setPosition(sf::Vector2f( (250+i*275) , 0 ));
        } else {
            int multiplier = i-2;
            m_bounds[i].setSize(sf::Vector2f(800,25));
            m_bounds[i].setPosition(sf::Vector2f(0, (250+multiplier*275)));
        }
    }
}

World::~World() {

}

int World::GetBlockSize() {
    return m_blockSize;
}

void World::Render(sf::RenderWindow& l_window) {
    for (int i=0 ; i < 4; i++) {
        l_window.draw(m_bounds[i]);
    }
}

void World::Update() {

}