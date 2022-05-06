#ifndef AI
#define AI

#include <random>

#include "position.h"
#include "pawn.h"
#include "eval.h"

namespace ai 
{
	void chooseMove(ty::Position &pos, std::vector<ty::Piece> ai_Pieces, std::vector<ty::Piece> enemy_Pieces);
}

#endif
