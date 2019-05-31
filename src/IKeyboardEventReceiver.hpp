#ifndef IKEYBOARDEVENTRECEIVER_HPP
#define IKEYBOARDEVENTRECEIVER_HPP

#include "KeyPressEvent.hpp"

class IKeyboardEventReceiver
{
public:
    virtual bool onKeyPress(KeyPressEvent& event) {return false;}
}; // IKeyboardEventReceiver

#endif // IKEYBOARDEVENTRECEIVER_HPP
