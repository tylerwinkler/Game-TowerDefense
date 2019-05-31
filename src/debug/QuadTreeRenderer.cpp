#include "QuadTreeRenderer.hpp"

#include <iostream>

#include "SFML/Graphics/RectangleShape.hpp"

void QuadTreeRenderer::render(QuadTree<UIElement*>& quad, sf::RenderTarget& target)
{
    for (auto& child : quad.m_children)
    {
        sf::RectangleShape childR;
        childR.setPosition(sf::Vector2f(child->getBounds().left, child->getBounds().top));
        childR.setSize(sf::Vector2f(child->getBounds().width, child->getBounds().height));
        childR.setFillColor(sf::Color(255 - 50 * quad.m_depth, 255 - 50 * quad.m_depth, 255 - 50 * quad.m_depth, 255));

        target.draw(childR);
    }

    sf::RectangleShape rect;
    rect.setPosition(quad.m_bounds.left, quad.m_bounds.top);
    rect.setSize(sf::Vector2f(quad.m_bounds.width, quad.m_bounds.height));

    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color(255 - 50 * quad.m_depth, 0, 0, 255));
    rect.setOutlineThickness(1.f);

    target.draw(rect);

    if (quad.m_quadrants != nullptr)
    {
        render(quad.m_quadrants[0], target);
        render(quad.m_quadrants[1], target);
        render(quad.m_quadrants[2], target);
        render(quad.m_quadrants[3], target);
    }
}

void QuadTreeRenderer::print(QuadTree<UIElement*>& quad)
{
    std::map<int, int> levelTotals;

    std::cout << "Quad [depth]=" << quad.m_depth << " [children]=" << quad.m_children.size() << "\n";

    if (quad.m_quadrants == nullptr)
    {
        print(quad.m_quadrants[0]);
        print(quad.m_quadrants[1]);
        print(quad.m_quadrants[2]);
        print(quad.m_quadrants[3]);
    }
}
