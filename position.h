#ifndef POSITION
#define POSITION

#include <iostream>
#include <vector>

#include "types.h"
#include "pawn.h"

namespace pos 
{
	void setup(ty::Square board[8][8], std::vector<ty::Piece>& w_Pieces, std::vector<ty::Piece>& b_Pieces);

	void printBoard(ty::Square board[8][8]);

	std::vector<ty::Square> getSquaresInGivenDirection(ty::Square board[8][8], ty::Square square, int x, int y);

	std::vector<ty::Square> pawnSquares(ty::Square board[8][8], ty::Square pawnSquare, bool attacking);
	std::vector<ty::Square> bishopSquares(ty::Square board[8][8], ty::Square bishopSquare);
	std::vector<ty::Square> knightSquares(ty::Square board[8][8], ty::Square knightSquare);
	std::vector<ty::Square> rookSquares(ty::Square board[8][8], ty::Square rookSquare);
	std::vector<ty::Square> queenSquares(ty::Square board[8][8], ty::Square queenSquare);
	std::vector<ty::Square> kingSquares(ty::Square board[8][8], ty::Square kingSquare);
	std::vector<ty::Square> squaresForPiece(ty::Square board[8][8], ty::Square square, bool pawnPush);

	bool inBounds(int x, int y);

	void duplicatePosition(ty::Position &oldPos, ty::Position &newPos);

	std::vector<std::vector<ty::Square>> possible_Moves(ty::Position &pos, std::vector<ty::Piece> pieces, bool pawnPush);
	std::vector<ty::Position> possible_Positions(ty::Position &pos, std::vector<ty::Piece> pieces, std::vector<ty::Piece> enemy_Pieces);

	bool isAttacked(ty::Position pos, ty::Square square, std::vector<ty::Piece> enemy_Pieces);

	void checkCastlingPrivelages(ty::Position &pos, int color);

	ty::Position castledPosition(ty::Position pos, int rookX, int color);

	std::vector<ty::Piece> getAttackers(ty::Square board[8][8], ty::Square square, std::vector<ty::Piece> enemy_Pieces);

	bool isPieceThreatened(ty::Square board[8][8], ty::Square square, std::vector<ty::Piece> enemy_Pieces, std::vector<ty::Piece> friendly_Pieces);
}

#endif
