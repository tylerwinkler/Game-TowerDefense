#ifndef IMOUSEEVENTRECEIVER_HPP
#define IMOUSEEVENTRECEIVER_HPP

#include "ClickEvent.hpp"

class IMouseEventReceiver
{
    // Should return true if the event has been handled by the receiver, and false otherwise
    virtual bool onClick(ClickEvent& event) {return false;}
}; // IMouseEventReceiver

#endif // IMOUSEEVENTRECEIVER_HPP
