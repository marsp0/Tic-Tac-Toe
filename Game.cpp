#include "Game.hpp"
#include "World.hpp"
#include "PlayerX.hpp"
#include <iostream>

Game::Game() : m_window(sf::VideoMode(800,800,32),"Tic Tac Toe", sf::Style::Default ),m_world(sf::Vector2u(800,800)), m_playerX("PlayerX.png"), m_playerO("PlayerO.png"), m_turn(1)
{
    m_clock.restart();
    // WHY?
	srand(time(nullptr));
    m_elapsed = 0.0f;
}

Game::~Game(){}

sf::Time Game::GetElapsed(){ 
    return m_clock.getElapsedTime(); 
}
void Game::RestartClock(){ 
    m_elapsed += m_clock.restart().asSeconds(); 
}

sf::RenderWindow* Game::GetWindow(){ 
    return &m_window; 
}

void Game::HandleInput(){
    bool check;
    if (m_turn) {
        m_playerX.Update(sf::Mouse::getPosition(*GetWindow()),m_playerO);
    } else {
        m_playerO.Update(sf::Mouse::getPosition(*GetWindow()), m_playerX);
    }
    m_turn = 1 - m_turn;
}

void Game::ProcessEvents() {
    sf::Event event;
	while(m_window.pollEvent(event)){
		if(event.type == sf::Event::Closed) { 
            m_window.close();
            break;
		} else if (event.type == sf::Event::EventType::MouseButtonPressed) {
            HandleInput();
		}
	}
}

void Game::Update(){
	float timestep = 1.0f / 15;
	if(m_elapsed >= timestep){
		m_elapsed -= timestep;
	}
}

void Game::Render(){
    m_window.clear(sf::Color::White);
    m_world.Render(*GetWindow());
    m_playerX.Render(*GetWindow());
    m_playerO.Render(*GetWindow());
    // Rendering goes here
	m_window.display();
}

void Game::Run(){
    // The main game loop
    // While the window is open we :
    // 1. Check for input from the players
    // 2. Update the state of the game
    // 3. Render the changes
    // 4. Restart the clock - Not really needed in tic tac toe
    while (m_window.isOpen()){
        // game loop here
        ProcessEvents();
        Update();
        Render();
        RestartClock();
    }
}