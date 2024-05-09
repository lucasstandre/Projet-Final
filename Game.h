#pragma once
class Game
{
private:

public:
    Game();
    ~Game();
    void play();
    void intialize();
    void save(string characterSaveFile);
    void showMenu();
    void showScore();
    void showHelp();
    void miniGame();


};
