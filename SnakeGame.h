#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class SnakeGame {
public:
    SnakeGame();
    void HideCursor();
    void GotoXY(int x, int y);
    void Setup(bool isFirstTime);
    void Draw();
    void ShowLevelUp();
    void CountDown();
    void PauseMenu();
    void ClearPauseMenu();
    void GameOverMenu();
    void ClearGameOverMenu();
    void Input();
    void Logic();
    void StartScreen();
    bool IsGameOver();
    int GetGameSpeed();

private:
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;

    struct Position {
        int x, y;
    };

    const int width = 40;
    const int height = 20;
    Position snakeHead;
    vector<Position> snakeBody;
    Position food;
    bool gameOver;
    bool paused;
    int score;
    int gameSpeed;
    int level;

    bool IsFoodOnSnake(const Position& pos);
    bool IsFoodInCorner(const Position& pos);
    void GenerateFood();
};

#endif
