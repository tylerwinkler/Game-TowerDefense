template <class T>
QuadTree<T>::QuadTree()
{
    m_quadrants = nullptr;
    m_depth = 0;
    m_bounds = sf::FloatRect(0, 0, 800, 600);
}

template <class T>
bool QuadTree<T>::insert(T& object)
{
    if (!objectFits(object))
    {
        return false;
    }

    if (quadrantsExist())
    {
        if (insertIntoQuadrants(object))
        {
            return true;
        }

        m_children.push_back(object);
        return true;
    }

    if (!isFull())
    {
        m_children.push_back(object);
        return true;
    }
    else
    {
        if (isTooDeep())
        {
            m_children.push_back(object);
            return true;
        }
        else
        {
            createQuadrants();
            redistributeChildren();

            return insert(object);
        }
    }
}

template <class T>
void QuadTree<T>::createQuadrants()
{
    m_quadrants = new QuadTree<T>[4];

    sf::FloatRect topRightRect(m_bounds.left + m_bounds.width / 2, m_bounds.top, m_bounds.width / 2, m_bounds.height / 2);

    sf::FloatRect topLeftRect(m_bounds.left, m_bounds.top, m_bounds.width / 2, m_bounds.height / 2);

    sf::FloatRect bottomLeftRect(m_bounds.left, m_bounds.top + m_bounds.height / 2, m_bounds.width / 2, m_bounds.height / 2);

    sf::FloatRect bottomRightRect(m_bounds.left + m_bounds.width / 2, m_bounds.top + m_bounds.height / 2, m_bounds.width / 2, m_bounds.height / 2);

    m_quadrants[Quadrant::TopRight].m_bounds = topRightRect;
    m_quadrants[Quadrant::TopRight].m_depth = m_depth + 1;

    m_quadrants[Quadrant::TopLeft].m_bounds = topLeftRect;
    m_quadrants[Quadrant::TopLeft].m_depth = m_depth + 1;

    m_quadrants[Quadrant::BottomLeft].m_bounds = bottomLeftRect;
    m_quadrants[Quadrant::BottomLeft].m_depth = m_depth + 1;

    m_quadrants[Quadrant::BottomRight].m_bounds = bottomRightRect;
    m_quadrants[Quadrant::BottomRight].m_depth = m_depth + 1;
}

template <class T>
bool QuadTree<T>::isFull()
{
    const int MaxChildren = 10;

    return m_children.size() >= MaxChildren;
}

template <class T>
bool QuadTree<T>::objectFits(T& object)
{
    return m_bounds.contains(object->getBounds().left, object->getBounds().top)
    && m_bounds.contains(object->getBounds().left + object->getBounds().width, object->getBounds().top)
    && m_bounds.contains(object->getBounds().left + object->getBounds().width, object->getBounds().top + object->getBounds().height)
    && m_bounds.contains(object->getBounds().left, object->getBounds().top + object->getBounds().height);
}

template <class T>
bool QuadTree<T>::isTooDeep()
{
    const int MaxDepth = 4;

    return m_depth >= MaxDepth;
}

template <class T>
void QuadTree<T>::redistributeChildren()
{
    std::vector<T> objects;
    for (auto& child : m_children)
    {
        objects.push_back(child);
    }

    m_children.clear();

    for (auto& object : objects)
    {
        insert(object);
    }
}

template <class T>
bool QuadTree<T>::quadrantsExist()
{
    return m_quadrants != nullptr;
}

template <class T>
bool QuadTree<T>::insertIntoQuadrants(T& object)
{
    if (m_quadrants[Quadrant::TopRight].insert(object))
    {
        return true;
    }
    if (m_quadrants[Quadrant::TopLeft].insert(object))
    {
        return true;
    }
    if (m_quadrants[Quadrant::BottomLeft].insert(object))
    {
        return true;
    }
    if (m_quadrants[Quadrant::BottomRight].insert(object))
    {
        return true;
    }

    return false;
}

