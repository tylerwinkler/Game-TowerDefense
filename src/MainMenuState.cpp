#include "MainMenuState.hpp"

#include "SFML/Graphics/RectangleShape.hpp"

#include "StaticObject.hpp"
#include "WindowService.hpp"

namespace
{
    sf::RectangleShape r;
    StaticObject* so = nullptr;
}

bool MainMenuState::initialize()
{
    sf::RenderTarget& target = Services::windowService.getService();

    createUI(target.getSize().x, target.getSize().y);

    r.setSize(sf::Vector2f(target.getSize().x - 30, target.getSize().y - 30));
    r.setPosition(sf::Vector2f(15, 15));

    so = new StaticObject();
    so->setPosition(sf::Vector2f(125, 15));

    return true;
}

void MainMenuState::update()
{

}

void MainMenuState::render(RenderTarget& target)
{
    target.draw(r);
    so->render(target);
    m_tower.render(target);
    m_testRenderer.render(m_test, target);
}

void MainMenuState::onClick(int x, int y, int button, bool pressed)
{
    ClickEvent e;
    e.x = x;
    e.y = y;
    e.button = button;
    e.pressed = pressed;

    if (m_ui.onClick(e))
    {
        return;
    }

    if (pressed)
    {
        return;
    }

    if (button == 0)
    {
        spawnBox(x - 16, y - 16, 32, 32);
    }
    else
    {
        for (int i = 0; i < 10000; ++i)
        {
            spawnBox(rand() % 800, rand() % 600, rand() % 64 + 1, rand() % 64 + 1);
        }
    }
}

void MainMenuState::onKey(sf::Keyboard::Key key, bool control, bool alt, bool shift, bool system, bool pressed)
{
    if (key == sf::Keyboard::A && !pressed)
    {
        spawnBox(rand() % 800, rand() % 600, rand() % 64 + 1, rand() % 64 + 1);
    }
    else if (key == sf::Keyboard::S && !pressed)
    {
        for (int i = 0; i < 10000; ++i)
        {
            spawnBox(rand() % 800, rand() % 600, rand() % 64 + 1, rand() % 64 + 1);
        }
    }
}

void MainMenuState::spawnBox(int x, int y, int w, int h)
{
    UIElement* leakyElement = new UIElement();

    sf::FloatRect r(x, y, w, h);
    leakyElement->setBounds(r);

    m_test.insert(leakyElement);
}

void MainMenuState::createUI(int width, int height)
{
    m_ui.setSize(width, height);
}
