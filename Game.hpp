#pragma once
#include "World.hpp"
#include "PlayerX.hpp"
#include "Menu.hpp"
#include "AI.hpp"
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

    void RestartGame();

    void CloseGame();

    std::vector<int> ComputerMove();

    int maxSearch(int l_board[3][3]);

    int minSearch(int l_board[3][3]);

    int Score(int l_board[3][3]);

    int CheckWin(int l_board[3][3], int player);

    bool GameOver(int l_board[3][3]);
    
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
    std::vector < std::vector <int> > m_board;
    bool m_isAI;
    AI m_bot;
};