#ifndef UIELEMENT_HPP
#define UIELEMENT_HPP

#include <memory>
#include <vector>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include "IKeyboardEventReceiver.hpp"
#include "IMouseEventReceiver.hpp"

class UIElement : public IMouseEventReceiver, IKeyboardEventReceiver
{
public:
    virtual bool onClick(ClickEvent& event) override;

    virtual bool onKeyPress(KeyPressEvent& event) override;

    const sf::FloatRect& getBounds();

    // Does nothing, but subclasses are not forced to implement any rendering
    virtual void render(sf::RenderTarget& target);

protected:
    public:
    void setBounds(sf::FloatRect& rect);

private:
    std::vector<std::unique_ptr<UIElement>> m_children;

    sf::FloatRect m_bounds;

    UIElement* m_focusedChild;
}; // UIElement

#endif // UIELEMENT_HPP
