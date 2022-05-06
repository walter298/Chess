#ifndef TYPES
#define TYPES

#include <vector>

namespace ty {
	enum class PieceType {
		king = 300,
		queen = 9,
		knight = 3,
		bishop = 4,
		rook = 5,
		pawn = 1,
		blank = 0
	};

	class Piece {
	public:
		PieceType subtype = PieceType::blank;

		int color = -1;

		std::string printedSelf = "|   |";

		int x = -1;
		int y = -1;

		int ID = 0;
	};

	class Square {
	public:
		Piece occupying_Piece;

		int x = -1;
		int y = -1;

		bool equals (Square& square) {
			if (this->x == square.x && this->y == square.y) {
				return true;
			} else {
				return false;
			}
		}

		int enPessant = 0;
	};
	
	class Position {
	public:
		bool wQ_RookMoved = false;
		bool wK_RookMoved = false;
		bool w_Castled = false;

		bool bQ_RookMoved = false;
		bool bK_RookMoved = false;
		bool b_Castled = false;

		bool castled(int color) {
			if (color == 0) {
				return this->w_Castled;
			} else {
				return this->b_Castled;
			}
		}

		bool qRookMoved(int color) {
			if (color == 0) {
				return this->wQ_RookMoved;
			} else {
				return this->bQ_RookMoved;
			}
		}

		bool kRookMoved(int color) {
			if (color == 0) {
				return this->wK_RookMoved;
			} else {
				return this->bK_RookMoved;
			}
		}

		std::vector<ty::Piece> w_Pieces, b_Pieces;

		Square board[8][8];

		int evaluation = 0;
	};
}

#endif
