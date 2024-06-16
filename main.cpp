#include "SnakeGame.h"

int main() {
    SnakeGame game;
    game.HideCursor();
    game.StartScreen();
    game.Setup(true);

    while (true) {
        while (!game.IsGameOver()) {
            game.Draw();
            game.Input();
            game.Logic();
            Sleep(game.GetGameSpeed());
        }

        game.GameOverMenu();
        while (game.IsGameOver()) {
            switch (_getch()) {
            case '1':
                game.Setup(false);
                game.ClearGameOverMenu();
                break;
            case '2':
                game.ClearGameOverMenu();
                return 0;
            }
        }
    }

    return 0;
}
