#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <vector>

#include "SFML/Graphics/Rect.hpp"

template <class T>
class QuadTree
{
    friend class QuadTreeRenderer;

public:
    // Initializes m_quadrants as a nullptr
    QuadTree<T>();

public:
    // Returns true if the object has been successfully added to the QuadTree
    bool insert(T& object);

private:
    enum Quadrant {TopRight, TopLeft, BottomLeft, BottomRight};

private:
    // Creates the four children quadrant QuadTrees
    void createQuadrants();

    // Returns true if this quad is at capacity
    bool isFull();

    // Returns true if an object will fit in this QuadTree
    bool objectFits(T& object);

    // Returns true if the QuadTree cannot subdivide deeper
    bool isTooDeep();

    // Redistributes children amongst quadrants
    void redistributeChildren();

    // Returns true if quadrants exist
    bool quadrantsExist();

    // Attempts to insert object into a quadrant
    bool insertIntoQuadrants(T& object);

private:
    QuadTree<T>* m_quadrants;
    std::vector<T> m_children;
    sf::FloatRect m_bounds;
    int m_depth;
}; // QuadTree

#include "QuadTree.tpp"

#endif // QUADTREE_HPP
