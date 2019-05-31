#ifndef GAME_HPP
#define GAME_HPP

class IState;

class Game
{
public:
    Game();
    Game(IState* initState);

    void play();
    void play(IState* initState);

    int getStatus();
    void setStatus(int status);

private:
    void update();
    void processEvents();
    void render();

private:
    bool m_playing;
    int m_status;

    IState* m_currentState;
    IState* m_nextState;
}; // Game

#endif // GAME_HPP
