#ifndef UIBUTTON_HPP
#define UIBUTTON_HPP

#include "UIElement.hpp"

class UIButton : public UIElement
{
public:


private:
    std::vector<IMouseEventReceiver*> m_mouseListeners;
}; // UIButton

#endif // UIBUTTON_HPP
