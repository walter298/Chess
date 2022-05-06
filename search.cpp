#include "search.h"

int search::evaluatedTree(ty::Position pos, int color)
{
	return 0;
}

ty::Position search::bestPosition(ty::Position pos, int color)
{
	ty::Position bestPos;

	std::vector<ty::Piece> friendlies, enemies;

	if (color == 0) {
		friendlies = pos.w_Pieces;
		enemies = pos.b_Pieces;
	} else {
		friendlies = pos.b_Pieces;
		enemies = pos.w_Pieces;
	}

	std::vector<ty::Position> positions = pos::possible_Positions(pos, friendlies, enemies);

	std::thread threads(evaluatedTree);

	return bestPos;
}