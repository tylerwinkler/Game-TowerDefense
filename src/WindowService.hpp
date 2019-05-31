#ifndef WINDOWSERVICE_HPP
#define WINDOWSERVICE_HPP

#include "SFML/Graphics/RenderWindow.hpp"

#include "ServiceLocator.hpp"

using RenderWindow = sf::RenderWindow;

namespace Services
{
    extern ServiceLocator<RenderWindow> windowService;
}

#endif // WINDOWSERVICE_HPP
