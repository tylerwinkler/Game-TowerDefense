#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "IState.hpp"
#include "Tower.hpp"
#include "UI.hpp"

#include "QuadTree.hpp"
#include "debug/QuadTreeRenderer.hpp"
#include "UIElement.hpp"

class MainMenuState : public IState
{
private:
    virtual bool initialize() override;

    virtual void update() override;

    virtual void render(RenderTarget& target) override;

    virtual void onClick(int x, int y, int button, bool pressed) override;

    virtual void onKey(sf::Keyboard::Key key, bool control, bool alt, bool shift, bool system, bool pressed) override;

    void spawnBox(int x, int y, int w, int h);

    virtual void createUI(int width, int height);

private:
    Tower m_tower;
    UI m_ui;

    QuadTree<UIElement*> m_test;
    QuadTreeRenderer m_testRenderer;
};

#endif // MAINMENUSTATE_HPP
