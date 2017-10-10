#include <SFML/Graphics.hpp>
#include "PlayerX.hpp"
#include <iostream>
#include <typeinfo>

PlayerX::PlayerX(std::string filename){
    if (!m_texture.loadFromFile(filename)) {
        std::cout << "Error when loading the texture";
    }
    for (int i = 0; i < 3;i++) {
        for (int j=0 ; j < 3 ; j++) {
            sf::Sprite sprite;
            sprite.setTexture(m_texture);
            sprite.setPosition(sf::Vector2f((j % 3)*275, (i % 3)*275));
            m_spriteStruct[i][j] = std::make_pair(sprite,false);
        }
    }

}

PlayerX::~PlayerX() {

}

void PlayerX::Render(sf::RenderWindow& l_window){
    for (int i=0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            if (m_spriteStruct[i][j].second) {
                l_window.draw(m_spriteStruct[i][j].first);
            }
        }
    }
}

bool PlayerX::Update(sf::Vector2i l_position, PlayerX& otherPlayer) {
    
    if (!m_spriteStruct[l_position.y][l_position.x].second and otherPlayer.CanIDraw(l_position.y,l_position.x)) {
        m_spriteStruct[l_position.y][l_position.x].second = true;
        return true;
    }
    return false;
}

bool PlayerX::CanIDraw(int row, int col) {
    return !m_spriteStruct[row][col].second;
}

void PlayerX::Restart(){
    for (int i=0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            m_spriteStruct[i][j].second = false;
        }
    }
}

bool PlayerX::IsWinner(){
    if (m_spriteStruct[0][0].second == true){
        if ((m_spriteStruct[0][1].second == true) and (m_spriteStruct[0][2].second == true)) {
            return true;
        } else if ((m_spriteStruct[1][0].second == true) and (m_spriteStruct[2][0].second == true)) {
            return true;
        } else if ((m_spriteStruct[1][1].second == true) and (m_spriteStruct[2][2].second == true)) {
            return true;
        }
    } else if (m_spriteStruct[0][1].second == true) {
        if ((m_spriteStruct[1][1].second == true)and (m_spriteStruct[2][1].second == true)) {
            return true;
        }
    } else if (m_spriteStruct[1][0].second == true) {
        if ((m_spriteStruct[1][1].second == true) and (m_spriteStruct[1][2].second == true)) {
            return true;
        }
    } else if (m_spriteStruct[2][2].second == true) {
        if ((m_spriteStruct[2][1].second == true) and (m_spriteStruct[2][0].second == true)) {
            return true;
        } else if ((m_spriteStruct[1][2].second == true) and (m_spriteStruct[0][2].second == true)) {
            return true;
        }
    } else if (m_spriteStruct[0][2].second == true) {
        if ((m_spriteStruct[1][1].second == true) and (m_spriteStruct[2][0].second == true)) {
            return true;
        }
    } else {
        return false;
    }
}