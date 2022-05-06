#include "pawn.h"

void pw::promote(ty::Square board[8][8], std::vector<ty::Piece>& pieces, int promotedPieceType)
{
	ty::Piece promotedPiece;
	ty::PieceType type = ty::PieceType::blank;
	std::string newPrintedSelf = "|   |";

	int color, row;

	if (pieces[0].color == 0) {
		color = 0, row = 7;
	} else {
		color = 1, row = 0;
	}

	for (unsigned int i = 0; i < pieces.size(); i++) {
		if (pieces[i].y == row && pieces[i].subtype == ty::PieceType::pawn) {
			if (pieces[0].color == 0) {
				switch (promotedPieceType) {
				case 0:
					type = ty::PieceType::rook;
					newPrintedSelf = "|pWR|";
					break;
				case 1:
					type = ty::PieceType::bishop;
					newPrintedSelf = "|pWB|";
					break;
				case 2:
					type = ty::PieceType::knight;
					newPrintedSelf = "|pWN|";
					break;
				case 3:
					type = ty::PieceType::queen;
					newPrintedSelf = "|pWQ|";
					break;
				}
			} else {
				switch (promotedPieceType) {
				case 0:
					type = ty::PieceType::rook;
					newPrintedSelf = "|pBR|";
					break;
				case 1:
					type = ty::PieceType::bishop;
					newPrintedSelf = "|pBB|";
					break;
				case 2:
					type = ty::PieceType::knight;
					newPrintedSelf = "|pBN|";
					break;
				case 3:
					type = ty::PieceType::queen;
					newPrintedSelf = "|pBQ|";
					break;
				}
			}

			promotedPiece = { type, color, newPrintedSelf, pieces[i].x, pieces[i].y, pieces[i].ID };

			board[pieces[i].x][pieces[i].y].occupying_Piece = { type, color, newPrintedSelf, pieces[i].x, pieces[i].y, pieces[i].ID };

			pieces.erase(pieces.begin() + i);
			pieces.push_back(promotedPiece);

			break;
		}
	}
}