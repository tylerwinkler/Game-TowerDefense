#include "Tower.hpp"

#include "TextureManagerService.hpp"

Tower::Tower()
{
    m_sprite.setTexture(Services::textureManagerService.getService().get("./assets/tower.png"));
}

void Tower::update()
{

}

void Tower::render(RenderTarget& target)
{
    target.draw(m_sprite);
}
