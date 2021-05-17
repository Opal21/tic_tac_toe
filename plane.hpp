#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>
#include <iostream>

struct Move
{
	int col; // column
	int row; // row
	char sign; // player_sign
	
	Move(int c, int r, char sign);
	Move(const Move& ob);
	Move(const Move&& ob) noexcept ;
};

class Plane
{
public:
    [[nodiscard]] unsigned int get_size() const;
    [[nodiscard]] char get_sign_at(int k, int w) const;
    [[nodiscard]] bool is_full() const; // check if the game array is full
    [[nodiscard]] char who_won() const; // decide who won, possible outcomes: 'X', 'O', ' '
    [[nodiscard]] std::vector<Move> evaluate(char player_color) const; // evaluate
    bool make_move(const Move& m);

    explicit Plane(unsigned int size);
    Plane(const Plane& ob);
    Plane(const Plane&& ob) noexcept ;
    Plane& operator = (const Plane& ob);
private:
    std::vector<std::vector<char>> data; // data[column][row]
    unsigned int size_;
};

std::ostream& operator << (std::ostream& stream, const Plane& plane);

#endif