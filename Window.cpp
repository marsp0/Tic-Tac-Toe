#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include <iostream>

Window::Window() : m_windowSize(800,800), m_isDone(false) {
		// can i pass literal values to create method ? its ok
		m_window.create({m_windowSize.x,m_windowSize.y,32},"Tic Tac Toe", sf::Style::Default);
}
    
Window::~Window() {
	m_window.close();
}

void Window::BeginDraw(){
    m_window.clear(sf::Color::White);
}
    
void Window::EndDraw(){
    m_window.display();
}

void Window::Update(){
    sf::Event event;
	while(m_window.pollEvent(event)){
		if(event.type == sf::Event::Closed){ m_isDone = true; 
		} else if (event.type == sf::Event::EventType::MouseButtonPressed) {
			m_isMousePressed = true;
		}
	}
}

bool Window::IsDone() {
    return m_isDone;
}
    
sf::RenderWindow* Window::GetRenderWindow(){
	return &m_window;
}

void Window::Draw(sf::Drawable& l_drawable){

}

bool Window::IsMousePressed() {
	return m_isMousePressed;
}

void Window::SetMousePressed(bool val) {
	m_isMousePressed = val;
}
