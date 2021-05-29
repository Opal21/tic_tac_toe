#pragma once

struct Move
{
	int col; // column
	int row; // row
	char sign; // player_sign

	Move(int c, int r, char sign);
	Move();
	Move(const Move&);
	Move(const Move&&);
	Move& operator = (const Move&);
};
