#ifndef IRENDERABLE_HPP
#define IRENDERABLE_HPP

#include "SFML/Graphics/RenderTarget.hpp"

using RenderTarget = sf::RenderTarget;

class IRenderable
{
    virtual void render(RenderTarget& target){}
};

#endif // IRENDERABLE_HPP
