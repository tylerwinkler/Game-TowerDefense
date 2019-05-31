#include "StaticObject.hpp"

#include "SFML/Graphics/Sprite.hpp"

#include "TextureManagerService.hpp"

namespace
{
    sf::Sprite spr;
}

StaticObject::StaticObject()
{
    if (!Services::textureManagerService.getService().isLoaded("./assets/rock.png"))
    {
        Services::textureManagerService.getService().load("./assets/rock.png");
    }
    spr.setTexture(Services::textureManagerService.getService().get("./assets/rock.png"));
}

sf::Vector2f StaticObject::getPosition()
{
    return m_position;
}

void StaticObject::setPosition(sf::Vector2f position)
{
    m_position = position;

    spr.setPosition(m_position);
}

void StaticObject::render(RenderTarget& target)
{
    target.draw(spr);
}
