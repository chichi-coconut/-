#include "SnakeGame.h"

SnakeGame::SnakeGame() {
    srand(static_cast<unsigned>(time(0)));
    gameOver = false;
    paused = false;
}

void SnakeGame::HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void SnakeGame::GotoXY(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(consoleHandle, cursorPosition);
}

bool SnakeGame::IsFoodOnSnake(const Position& pos) {
    if (pos.x == snakeHead.x && pos.y == snakeHead.y) {
        return true;
    }
    for (auto part : snakeBody) {
        if (part.x == pos.x && part.y == pos.y) {
            return true;
        }
    }
    return false;
}

bool SnakeGame::IsFoodInCorner(const Position& pos) {
    return (pos.x == 0 && pos.y == 0) || (pos.x == 0 && pos.y == height - 1) ||
        (pos.x == width - 1 && pos.y == 0) || (pos.x == width - 1 && pos.y == height - 1);
}

void SnakeGame::GenerateFood() {
    do {
        food = { rand() % width, rand() % height };
    } while (IsFoodOnSnake(food) || IsFoodInCorner(food));
}

void SnakeGame::Setup(bool isFirstTime = false) {
    gameOver = false;
    paused = false;
    dir = RIGHT;
    snakeHead = { width / 2, height / 2 };
    snakeBody.clear();
    snakeBody.push_back(snakeHead);
    GenerateFood();
    score = 0;
    gameSpeed = 130;
    level = 1;
    if (!isFirstTime) {
        CountDown();
    }
}

void SnakeGame::Draw() {
    GotoXY(0, 0);
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";
            if (i == snakeHead.y && j == snakeHead.x)
                cout << "O";
            else if (i == food.y && j == food.x)
                cout << "X";
            else {
                bool isBodyPart = false;
                for (auto part : snakeBody) {
                    if (part.x == j && part.y == i) {
                        cout << "o";
                        isBodyPart = true;
                    }
                }
                if (!isBodyPart) cout << " ";
            }

            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    cout << "Score: " << score << "  Level: " << level << endl;
}

void SnakeGame::ShowLevelUp() {
    GotoXY(0, height + 2);
    cout << "Level Up! Now at Level " << level << "!";
    Sleep(500);
    GotoXY(0, height + 2);
    cout << "                           ";
}

void SnakeGame::CountDown() {
    for (int i = 3; i > 0; i--) {
        GotoXY(width / 2 - 1, height / 2);
        cout << i;
        Sleep(1000);
        GotoXY(width / 2 - 1, height / 2);
        cout << " ";
    }
}

void SnakeGame::PauseMenu() {
    GotoXY(0, height + 2);
    cout << "1. 繼續遊戲  2. 重新開始" << endl;
}

void SnakeGame::ClearPauseMenu() {
    GotoXY(0, height + 2);
    cout << "                         " << endl;
}

void SnakeGame::GameOverMenu() {
    GotoXY(0, height + 2);
    cout << "1. 重新開始  2. 結束程式" << endl;
}

void SnakeGame::ClearGameOverMenu() {
    GotoXY(0, height + 2);
    cout << "                         " << endl;
}

void SnakeGame::Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        case ' ':
            paused = true;
            PauseMenu();
            while (paused) {
                switch (_getch()) {
                case '1':
                    ClearPauseMenu();
                    paused = false;
                    CountDown();
                    break;
                case '2':
                    Setup();
                    ClearPauseMenu();
                    paused = false;
                    break;
                }
            }
            break;
        }
    }
}

void SnakeGame::Logic() {
    if (paused) return;

    Position prev = snakeHead;
    switch (dir) {
    case LEFT:
        snakeHead.x--;
        break;
    case RIGHT:
        snakeHead.x++;
        break;
    case UP:
        snakeHead.y--;
        break;
    case DOWN:
        snakeHead.y++;
        break;
    }

    if (snakeHead.x >= width || snakeHead.x < 0 || snakeHead.y >= height || snakeHead.y < 0) {
        gameOver = true;
    }

    for (auto part : snakeBody) {
        if (part.x == snakeHead.x && part.y == snakeHead.y) {
            gameOver = true;
        }
    }

    if (snakeHead.x == food.x && snakeHead.y == food.y) {
        score += 10;
        GenerateFood();
        snakeBody.push_back({ -1, -1 });

        if (score % 50 == 0) {
            gameSpeed -= 10;
            if (level < 10) {
                level++;
                ShowLevelUp();
            }
        }
    }

    for (int i = snakeBody.size() - 1; i > 0; i--) {
        snakeBody[i] = snakeBody[i - 1];
    }
    if (!snakeBody.empty()) snakeBody[0] = prev;
}

void SnakeGame::StartScreen() {
    system("cls");
    cout << "##############################" << endl;
    cout << "#                            #" << endl;
    cout << "#                            #" << endl;
    cout << "#                            #" << endl;
    cout << "#         貪食蛇遊戲         #" << endl;
    cout << "#                            #" << endl;
    cout << "#       請按任意鍵開始       #" << endl;
    cout << "#                            #" << endl;
    cout << "#    遊戲中按下空白鍵暫停    #" << endl;
    cout << "#                            #" << endl;
    cout << "#                            #" << endl;
    cout << "#                            #" << endl;
    cout << "#                            #" << endl;
    cout << "##############################" << endl;
    _getch();
}

bool SnakeGame::IsGameOver() {
    return gameOver;
}

int SnakeGame::GetGameSpeed() {
    return gameSpeed;
}
