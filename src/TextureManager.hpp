#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <string>

#include "SFML/Graphics/Texture.hpp"

class TextureManager
{
public:
    sf::Texture& get(const std::string& filename, bool attemptLoad = true);

    bool isLoaded(const std::string& filename);

    bool load(const std::string& filename);

    void unload(const std::string& filename);

private:
    std::map<std::string, sf::Texture> m_textureMap;
}; // TextureManager

#endif // TEXTUREMANAGER_HPP
