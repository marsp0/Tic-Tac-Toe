#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window{
public:
    Window();
    
	~Window();

    void BeginDraw();
    
	void EndDraw();

    void Update();
    
    bool IsDone();
    
    sf::RenderWindow* GetRenderWindow();

    void Draw(sf::Drawable& l_drawable);

    bool IsMousePressed();

    void SetMousePressed(bool val);
    
private:

    bool m_isDone;
    bool m_isMousePressed;
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
};