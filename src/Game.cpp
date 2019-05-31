#include "Game.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#include "SFML/Window/Event.hpp"

#include "IState.hpp"
#include "WindowService.hpp"

Game::Game() : Game(nullptr)
{
}

Game::Game(IState* initState)
{
    m_playing = true;
    m_status = 0;

    m_currentState = initState;
    m_nextState = nullptr;
}

void Game::play()
{
    if (m_currentState == nullptr || !m_currentState->initialize())
    {
        m_playing = false;
    }

    while (m_playing)
    {
        processEvents();
        update();
        render();
    }
}

void Game::play(IState* initState)
{
    m_currentState = initState;

    play();
}

void Game::processEvents()
{
    sf::Event event;
    while (Services::windowService.getService().pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_playing = false;
            break;
        case sf::Event::KeyPressed:
            m_currentState->onKey(event.key.code, event.key.control, event.key.alt, event.key.shift, event.key.system, true);
            break;
        case sf::Event::KeyReleased:
            m_currentState->onKey(event.key.code, event.key.control, event.key.alt, event.key.shift, event.key.system, false);
            break;
        case sf::Event::MouseButtonPressed:
            m_currentState->onClick(event.mouseButton.x, event.mouseButton.y, event.mouseButton.button, true);
            break;
        case sf::Event::MouseButtonReleased:
            m_currentState->onClick(event.mouseButton.x, event.mouseButton.y, event.mouseButton.button, false);
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    if (m_currentState != nullptr)
    {
        m_currentState->update();
    }
}

void Game::render()
{
    Services::windowService.getService().clear();

    if (m_currentState != nullptr)
    {
        m_currentState->render(Services::windowService.getService());
    }

    Services::windowService.getService().display();
}

int Game::getStatus()
{
    return m_status;
}

void Game::setStatus(int status)
{
    m_status = status;
}
