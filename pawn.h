#ifndef PAWN
#define PAWN

#include <random>
#include <windows.h>

#include "types.h"

namespace pw 
{
	void promote(ty::Square board[8][8], std::vector<ty::Piece>& pieces, int promotedPieceType);
}

#endif