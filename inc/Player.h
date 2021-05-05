#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H


class Player
{
public:
    Player();
    bool MyTurn();

    void PlaceSign();

    char get_sign();
    void set_sign(char new_sign);
private:
    char sign{};
};


#endif //TIC_TAC_TOE_PLAYER_H
