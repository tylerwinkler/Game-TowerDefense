#ifndef UI_HPP
#define UI_HPP

#include <memory>
#include <vector>

#include "SFML/Graphics/RenderTarget.hpp"

#include "IKeyboardEventReceiver.hpp"
#include "IMouseEventReceiver.hpp"

class UIElement;

class UI : public IMouseEventReceiver, IKeyboardEventReceiver
{
public:
    UI();

public:
    void add(std::unique_ptr<UIElement>& element);

    virtual bool onClick(ClickEvent& event) override;

    virtual bool onKeyPress(KeyPressEvent& event) override;

    void setSize(int width, int height);

    virtual void render(sf::RenderTarget& target);

private:
    int m_width;
    int m_height;

    std::vector<std::unique_ptr<UIElement>> m_children;

    UIElement* m_focusedChild;
}; // UI

#endif // UI_HPP
