#include "TextureManager.hpp"

sf::Texture& TextureManager::get(const std::string& filename, bool attemptLoad)
{
    if (isLoaded(filename))
    {
        return m_textureMap.at(filename);
    }
    else
    {
        if (attemptLoad)
        {
            load(filename);
            return get(filename, false);
        }
        else
        {
            throw std::runtime_error("Texture: " + filename + " is not loaded.");
        }
    }
}

bool TextureManager::isLoaded(const std::string& filename)
{
    return m_textureMap.count(filename) != 0;
}

bool TextureManager::load(const std::string& filename)
{
    auto insertion = m_textureMap.insert(std::make_pair(filename, sf::Texture()));
    if (!insertion.second)
    {
        return false;
    }

    if (insertion.first->second.loadFromFile(filename))
    {
        return true;
    }
    else
    {
        m_textureMap.erase(insertion.first);
        return false;
    }
}

void TextureManager::unload(const std::string& filename)
{
    m_textureMap.erase(filename);
}
