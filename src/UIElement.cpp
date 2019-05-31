#include "UIElement.hpp"

bool UIElement::onClick(ClickEvent& event)
{
    for (auto& child : m_children)
    {
        if (child->onClick(event))
        {
            m_focusedChild = child.get();
            return true;
        }
    }
    return false;
}

bool UIElement::onKeyPress(KeyPressEvent& event)
{
    if (m_focusedChild != nullptr)
    {
        return m_focusedChild->onKeyPress(event);
    }
    return false;
}

const sf::FloatRect& UIElement::getBounds()
{
    return m_bounds;
}

void UIElement::setBounds(sf::FloatRect& rect)
{
    m_bounds = rect;
}

void UIElement::render(sf::RenderTarget& target)
{

}
