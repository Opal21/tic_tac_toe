#include <iostream>
#include "inc/Player.h"
#include "inc/Bot.h"
#include "inc/Plane.h"
#include "inc/User.h"

int main()
{
    std::string action, player1_type, player2_type;
    Plane plane;

    while (true)
    {
        std::cout << "Input command: " << std::endl;
        std::cin >> action >> player1_type >> player2_type;
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
    }
    return 0;
}
