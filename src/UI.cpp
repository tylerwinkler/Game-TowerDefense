#include "UI.hpp"

#include "UIElement.hpp"

UI::UI()
{
    m_focusedChild = nullptr;
}

void UI::add(std::unique_ptr<UIElement>& element)
{
    m_children.push_back(std::move(element));
}

bool UI::onClick(ClickEvent& event)
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

bool UI::onKeyPress(KeyPressEvent& event)
{
    if (m_focusedChild != nullptr)
    {
        return m_focusedChild->onKeyPress(event);
    }
    return false;
}

void UI::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
}

void UI::render(sf::RenderTarget& target)
{
    for (auto& child : m_children)
    {
        child->render(target);
    }
}
