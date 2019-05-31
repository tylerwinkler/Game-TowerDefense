#ifndef ISTATE_HPP
#define ISTATE_HPP

#include "SFML/Graphics/RenderTarget.hpp"

#include "SFML/Window/Keyboard.hpp"

using RenderTarget = sf::RenderTarget;

class IState
{
    friend class Game;

private:
    virtual bool initialize(){return true;}

    virtual void update() = 0;

    virtual void render(RenderTarget& target) = 0;

    virtual void onClick(int x, int y, int button, bool pressed) {}
    virtual void onKey(sf::Keyboard::Key key, bool control, bool alt, bool shift, bool system, bool pressed) {}
}; // IState

#endif // ISTATE_HPP
