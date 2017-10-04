#pragma once
#include "Window.hpp"
#include "World.hpp"
#include "PlayerX.hpp"


class Game{
public:
    Game();
    
	~Game();

    void HandleInput();
    
    void Update();
    
	void Render();

    sf::Time GetElapsed();
    
	void RestartClock();

    Window* GetWindow();
    
private:

    Window m_window;
    World m_world;
    PlayerX m_playerX;
    PlayerX m_playerO;
	sf::Clock m_clock;
    float m_elapsed;
    int m_turn;

};