#ifndef TOWER_HPP
#define TOWER_HPP

#include "SFML/Graphics/Sprite.hpp"

#include "Entity.hpp"
#include "IRenderable.hpp"

class Tower : public Entity, IRenderable
{
public:
    Tower();

    virtual void update() override;

    virtual void render(RenderTarget& target) override;

private:
    // Times per second that the tower will shoot
    int m_fireRate;

    sf::Sprite m_sprite;
}; // Tower

#endif // TOWER_HPP
