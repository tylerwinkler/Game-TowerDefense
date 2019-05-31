#ifndef TEXTURESERVICE_HPP
#define TEXTURESERVICE_HPP

#include "ServiceLocator.hpp"
#include "TextureManager.hpp"

namespace Services
{
    extern ServiceLocator<TextureManager> textureManagerService;
}

#endif // TEXTURESERVICE_HPP
