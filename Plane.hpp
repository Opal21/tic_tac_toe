#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include "Move.hpp"

class Plane
{
public:
    [[nodiscard]] unsigned int get_size() const;
    [[nodiscard]] char get_sign_at(int k, int w) const;
    [[nodiscard]] bool is_full() const; // check if the game array is full
    [[nodiscard]] char who_won() const; // decide who won, possible outcomes: 'X', 'O', ' '
    [[nodiscard]] std::vector<Move> get_possible_moves(char player_color) const; 
    bool make_move(const Move& m);

    explicit Plane(unsigned int size);
    [[maybe_unused]] Plane(const Plane& ob);
    Plane(const Plane&& ob) noexcept ;
    Plane& operator = (const Plane& ob);
private:
    std::vector<std::vector<char>> data; // data[column][row]
    [[nodiscard]] static bool analyze_node(const Plane& plane, int col, int row) ;
    unsigned int size_;
};

std::ostream& operator << (std::ostream& stream, const Plane& plane);
std::ofstream& operator << (std::ofstream& stream, const Plane& plane);
std::ifstream& operator >> (std::ifstream& stream, Plane& plane);

#endif