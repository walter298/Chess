#ifndef EVAL
#define EVAL

#include <map>

#include "position.h"

namespace ev 
{
	int getMaterialCount(std::vector<ty::Piece> pieces, std::vector<ty::Piece> enemy_Pieces);

	int getAttackCount(ty::Position pos, std::vector<ty::Piece> pieces, std::vector<ty::Piece> enemy_Pieces);

	int evaluation(ty::Position pos, std::vector<ty::Piece> friendlies, std::vector<ty::Piece> enemies);

	ty::Position highestRatedPosition(std::vector<ty::Position> positions, int color);
}

#endif