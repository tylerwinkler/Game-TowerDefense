#include <cstdlib>
#include <ctime>

#include "Game.hpp"
#include "MainMenuState.hpp"
#include "TextureManagerService.hpp"
#include "WindowService.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    sf::RenderWindow* window = new sf::RenderWindow();
    window->create(sf::VideoMode(800, 600, 32), "td5");

    Services::windowService.setService(window);

    TextureManager* textureManager = new TextureManager();

    Services::textureManagerService.setService(textureManager);

    Game tdGame(new MainMenuState);
    tdGame.play();

    return tdGame.getStatus();
}
