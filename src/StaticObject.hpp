#ifndef STATICOBJECT_HPP
#define STATICOBJECT_HPP

#include "SFML/System/Vector2.hpp"

#include "IRenderable.hpp"

class StaticObject : public IRenderable
{
public:
    StaticObject();

public:
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);

    virtual void render(RenderTarget& target) override;

private:
    sf::Vector2f m_position;
};

#endif // STATICOBJECT_HPP
