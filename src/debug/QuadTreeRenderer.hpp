#ifndef QUADTREERENDERER_HPP
#define QUADTREERENDERER_HPP

#include <map>

#include "SFML/Graphics/RenderTarget.hpp"

#include "../QuadTree.hpp"
#include "../UIElement.hpp"

class QuadTreeRenderer
{
public:
    void render(QuadTree<UIElement*>& quad, sf::RenderTarget& target);

    void print(QuadTree<UIElement*>& quad);

private:
    std::map<int, int> count(QuadTree<UIElement*>& quad);
};

#endif // QUADTREERENDERER_HPP
