#include <iostream>
#include "inc/Player.h"
#include "inc/Bot.h"
#include "inc/Plane.h"
#include "inc/User.h"

int main()
{
    std::string action, player1_type, player2_type;
    bool endGame;
    Plane plane;

    while (true)
    {
        std::cout << "Input command: " << std::endl;
        std::cin >> action >> player1_type >> player2_type;
        // Chciałbym żeby player1_type i player2_type były opcjonalne
        if (action == "start")
        {
            if (player1_type == "user")
            {
                Player user1;
                break;
            }
            else if (player1_type == "bot")
            {
                Bot user1;
                break;
            }
            else
            {
                std::cout << "Wrong command!" << std::endl;
            }

            if (player2_type == "user")
            {
                Player user2;
                break;
            }
            else if (player2_type == "bot")
            {
                Bot user2;
                break;
            }
            else
            {
                std::cout << "Wrong command!" << std::endl;
            }
        }
        else if (action == "exit")
        {
            endGame = true;
            break;
        }
    }

    plane.PrintPlane();

    if (not endGame)
    {
        while (true)
        {
            user1.MakeMove();
            plane.PrintPlane();
            char winner1 = plane.DecideWinner();
            switch (winner1)
            {
                case 'X':
                    std::cout << "X has won!" << std::endl;
                    plane.someoneWon = true;
                    break;
                case 'O':
                    std::cout << "O has won!" << std::endl;
                    plane.someoneWon = true;
                    break;
                case 'D':
                    if (plane.IsFull())
                    {
                        std::cout << "Draw!" << std::endl;
                        plane.someoneWon = true;
                        break;
                    }
                    break;
                default:
                    std::cout << "error" << std::endl;
            }
            user2.MakeMove();
            plane.PrintPlane();
            char winner2 = plane.DecideWinner();
            switch (winner2)
            {
                case 'X':
                    std::cout << "X has won!" << std::endl;
                    plane.someoneWon = true;
                    break;
                case 'O':
                    std::cout << "O has won!" << std::endl;
                    plane.someoneWon = true;
                    break;
                case 'D':
                    if (plane.IsFull())
                    {
                        std::cout << "Draw!" << std::endl;
                        plane.someoneWon = true;
                        break;
                    }
                    break;
                default:
                    std::cout << "error" << std::endl;
            }
        }
    }

    return 0;
}
