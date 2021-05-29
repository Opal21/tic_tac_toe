//
// Created by marci on 29/05/2021.
//

#ifndef TIC_TAC_TOE_GAME_HPP
#define TIC_TAC_TOE_GAME_HPP


#include "plane.hpp"
#include "user.hpp"

class Game {
private:
    Plane plane;
    User* players[2]{}; // two players - we can put Player or Bot inside
    char l_sign{};
    Game() = delete;
    Game(const Game &game) = delete;
    Game(const Game &&game) = delete ;
    Game& operator = (const Game& game) = delete;
public:
    Game(int size, int x_player_mode, int o_player_mode); // player_mode=0-human, other-computer
    ~Game();
    [[nodiscard]] bool is_finished() const; // check if game is finished
    [[nodiscard]] Plane last_plane() const;
    [[nodiscard]] char last_sign() const;
    bool forward();
    bool save(std::string filename) const; // save current state of game to file
    bool load(std::string filename); // load state of game from file
};


#endif //TIC_TAC_TOE_GAME_HPP
