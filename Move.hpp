struct Move
{
	int col; // column
	int row; // row
	char sign; // player_sign

	Move(int c, int r, char sign);
	Move();

    [[maybe_unused]] Move(const Move&);
	Move& operator = (const Move&);
};