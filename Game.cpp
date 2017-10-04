#include "Game.hpp"
#include "World.hpp"
#include "PlayerX.hpp"

Game::Game() : m_window(), m_world(sf::Vector2u(800,800)), m_playerX("PlayerX.png"), m_playerO("PlayerO.png"), m_turn(1)
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

Window* Game::GetWindow(){ 
    return &m_window; 
}

void Game::HandleInput(){
    if (m_window.IsMousePressed()) {
        bool check;
        if (m_turn) {
            m_playerX.Update(sf::Mouse::getPosition(*m_window.GetRenderWindow()),m_playerO);
        } else {
            m_playerO.Update(sf::Mouse::getPosition(*m_window.GetRenderWindow()), m_playerX);
        }
        m_turn = 1 - m_turn;
        m_window.SetMousePressed(false);
    }
}

void Game::Update(){
	m_window.Update();
	float timestep = 1.0f / 15;
	if(m_elapsed >= timestep){
		m_elapsed -= timestep;
	}
}

void Game::Render(){
    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_playerX.Render(*m_window.GetRenderWindow());
    m_playerO.Render(*m_window.GetRenderWindow());
    // Rendering goes here
	m_window.EndDraw();
}