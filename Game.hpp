#pragma once
#include "World.hpp"
#include "PlayerX.hpp"
#include "Menu.hpp"
#include <SFML/Graphics.hpp>


class Game{
public:
    Game();
    
	~Game();

    void HandleInput();
    
    void Update();
    
	void Render();

    sf::Time GetElapsed();
    
	void RestartClock();

    sf::RenderWindow* GetWindow();

    void Run();

    void ProcessEvents();
    
private:

    sf::RenderWindow m_window;
    World m_world;
    PlayerX m_playerX;
    PlayerX m_playerO;
    sf::Clock m_clock;
    int m_currentState;
    float m_elapsed;
    int m_turn;
    Menu m_menu;
};