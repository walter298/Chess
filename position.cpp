#include "position.h"

void pos::printBoard(ty::Square board[8][8]) 
{
	for (int i = 1; i <= 8; i++) {
		std::cout << "  " << i << "  ";
	}

	std::cout << std::endl;

	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			std::cout << board[j][i].occupying_Piece.printedSelf;

			if (j == 7) {
				std::cout << " " << i + 1;
			}
		}
		std::cout << std::endl;
	}
}

void pos::setup(ty::Square board[8][8], std::vector<ty::Piece>& w_Pieces, std::vector<ty::Piece>& b_Pieces)
{
	//assign x and y coords
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			board[i][j].x = i;
			board[i][j].y = j;
		}
	}

	ty::Piece w_King, w_Queen, w_Rook1, w_Rook2, w_Knight1, w_Knight2, w_Bishop1, w_Bishop2;

	ty::Piece b_King, b_Queen, b_Rook1, b_Rook2, b_Knight1, b_Knight2, b_Bishop1, b_Bishop2;

	w_King = {ty::PieceType::king, 0, "|w K|", 4, 0, 1};
	w_Queen = {ty::PieceType::queen, 0, "|wQ1|", 3, 0, 2};
	w_Rook1 = {ty::PieceType::rook, 0, "|wr1|", 0, 0, 3};
	w_Rook2 = {ty::PieceType::rook, 0, "|wr2|", 7, 0, 4};
	w_Knight1 = {ty::PieceType::knight, 0, "|wN1|", 1, 0, 5};
	w_Knight2 = {ty::PieceType::knight, 0, "|wN2|", 6, 0, 6};
	w_Bishop1 = {ty::PieceType::bishop, 0, "|wb1|", 2, 0, 7};
	w_Bishop2 = {ty::PieceType::bishop, 0, "|wb2|", 5, 0, 8};

	b_King = {ty::PieceType::king, 1, "|b K|", 4, 7, 9};
	b_Queen = {ty::PieceType::queen, 1, "|bQ1|", 3, 7, 10};
	b_Rook1 = {ty::PieceType::rook, 1, "|br1|", 0, 7, 11};
	b_Rook2 = {ty::PieceType::rook, 1, "|br2|", 7, 7, 12};
	b_Knight1 = {ty::PieceType::knight, 1, "|bN1|", 1, 7, 13};
	b_Knight2 = {ty::PieceType::knight, 1, "|bN2|", 6, 7, 14};
	b_Bishop1 = {ty::PieceType::bishop, 1, "|bb1|", 2, 7, 15};
	b_Bishop2 = {ty::PieceType::bishop, 1, "|bb2|", 5, 7, 16};

	w_Pieces = {
		w_King, w_Queen, w_Rook1, w_Rook2, w_Knight1, w_Knight2, w_Bishop1, w_Bishop2
	};

	b_Pieces = {
		b_King, b_Queen, b_Rook1, b_Rook2, b_Knight1, b_Knight2, b_Bishop1, b_Bishop2
	};

	int w_ID = 17;
	int b_ID = 25;

	for (int i = 0; i <= 7; i++) {
		ty::Piece w_Pawn = { ty::PieceType::pawn, 0, "|w p|", i, 1, w_ID};
		ty::Piece b_Pawn = { ty::PieceType::pawn, 1, "|b p|", i, 6, b_ID};

		board[i][1].occupying_Piece = { w_Pawn.subtype, w_Pawn.color, w_Pawn.printedSelf, i, 1, w_ID };
		board[i][6].occupying_Piece = { b_Pawn.subtype, b_Pawn.color, b_Pawn.printedSelf, i, 6, b_ID };

		w_Pieces.push_back(w_Pawn);
		b_Pieces.push_back(b_Pawn);

		w_ID++;
		b_ID++;
	}

	board[4][0].occupying_Piece = { w_King.subtype, w_King.color, w_King.printedSelf, 4, 0, w_King.ID };
	board[3][0].occupying_Piece = { w_Queen.subtype, w_Queen.color, w_Queen.printedSelf, 3, 0, w_Queen.ID };
	board[0][0].occupying_Piece = { w_Rook1.subtype, w_Rook1.color, w_Rook1.printedSelf, 0, 0, w_Rook1.ID};
	board[7][0].occupying_Piece = { w_Rook2.subtype, w_Rook2.color, w_Rook2.printedSelf, 7, 0, w_Rook2.ID};
	board[1][0].occupying_Piece = { w_Knight1.subtype, w_Knight1.color, w_Knight1.printedSelf, 1, 0, w_Knight1.ID };
	board[6][0].occupying_Piece = { w_Knight2.subtype, w_Knight2.color, w_Knight2.printedSelf, 6, 0, w_Knight2.ID };
	board[2][0].occupying_Piece = { w_Bishop1.subtype, w_Bishop1.color, w_Bishop1.printedSelf, 2, 0, w_Bishop1.ID };
	board[5][0].occupying_Piece = { w_Bishop2.subtype, w_Bishop2.color, w_Bishop2.printedSelf, 5, 0, w_Bishop2.ID };

	board[4][7].occupying_Piece = { b_King.subtype, b_King.color, b_King.printedSelf, 4, 7, b_King.ID };
	board[3][7].occupying_Piece = { b_Queen.subtype, b_Queen.color, b_Queen.printedSelf, 3, 7, b_Queen.ID };
	board[0][7].occupying_Piece = { b_Rook1.subtype, b_Rook1.color, b_Rook1.printedSelf, 0, 7, b_Rook1.ID };
	board[7][7].occupying_Piece = { b_Rook2.subtype, b_Rook2.color, b_Rook2.printedSelf, 7, 7, b_Rook2.ID };
	board[1][7].occupying_Piece = { b_Knight1.subtype, b_Knight1.color, b_Knight1.printedSelf, 1, 7, b_Knight1.ID };
	board[6][7].occupying_Piece = { b_Knight2.subtype, b_Knight2.color, b_Knight2.printedSelf, 6, 7, b_Knight2.ID };
	board[2][7].occupying_Piece = { b_Bishop1.subtype, b_Bishop1.color, b_Bishop1.printedSelf, 2, 7, b_Bishop1.ID };
	board[5][7].occupying_Piece = { b_Bishop2.subtype, b_Bishop2.color, b_Bishop2.printedSelf, 5, 7, b_Bishop2.ID };
}

std::vector<ty::Square> pos::getSquaresInGivenDirection(ty::Square board[8][8], ty::Square square, int x, int y)
{
	std::vector<ty::Square> squares;

	int ox = x;
	int oy = y;

	while (pos::inBounds(square.x + x, square.y + y)) {
		if (board[square.x + x][square.y + y].occupying_Piece.color == square.occupying_Piece.color) {
			break;
		}
		if (board[square.x + x][square.y + y].occupying_Piece.color != -1) {
			squares.push_back(board[square.x + x][square.y + y]);
			break;
		}
		squares.push_back(board[square.x + x][square.y + y]);
		x += ox;
		y += oy;
	}

	return squares;
}

std::vector<ty::Square> pos::pawnSquares(ty::Square board[8][8], ty::Square pawnSquare, bool attacking)
{
	std::vector<ty::Square> pawnSquares;

	int x = pawnSquare.x, y = pawnSquare.y;

	int enemyColor, deltaY, row, enemyRow;

	if (pawnSquare.occupying_Piece.color == 0) {
		deltaY = 1;
		enemyColor = 1;
		row = 1;
		enemyRow = 4;
	} else {
		deltaY = -1;
		enemyColor = 0;
		row = 6;
		enemyRow = 3;
	}

	if (pos::inBounds(x + 1, y + deltaY)) {
		if (board[x + 1][y + deltaY].occupying_Piece.color == enemyColor) {
			pawnSquares.push_back(board[x + 1][y + deltaY]);
		}
	}

	if (pos::inBounds(x - 1, y + deltaY)) {
		if (board[x - 1][y + deltaY].occupying_Piece.color == enemyColor) {
			pawnSquares.push_back(board[x - 1][y + deltaY]);
		}
	}

	if (y == row && !attacking) {
		if (board[x][y + deltaY].occupying_Piece.subtype == ty::PieceType::blank &&
			board[x][y + (deltaY + deltaY)].occupying_Piece.subtype == ty::PieceType::blank &&
			y == row) {
			pawnSquares.push_back(board[x][y + (deltaY * 2)]);
		}
	}

	if (board[x][y + deltaY].occupying_Piece.subtype == ty::PieceType::blank && !attacking) {
		pawnSquares.push_back(board[x][y + deltaY]);
	}

	if (pos::inBounds(x + 1, y + deltaY)) {
		if (board[x + 1][y + deltaY].enPessant == 1) {
			pawnSquares.push_back(board[x + 1][y + deltaY]);
		}
	}

	if (pos::inBounds(x - 1, y + deltaY)) {
		if (board[x - 1][y + deltaY].enPessant == 1) {
			pawnSquares.push_back(board[x - 1][y + deltaY]);
		}
	}

	return pawnSquares;
}

std::vector<ty::Square> pos::bishopSquares(ty::Square board[8][8], ty::Square bishopSquare)
{
	std::vector<ty::Square> bishopSquares;
	std::vector<std::vector<ty::Square>> directions;

	directions = {
		getSquaresInGivenDirection(board, bishopSquare, 1, 1),
		getSquaresInGivenDirection(board, bishopSquare, -1, -1),
		getSquaresInGivenDirection(board, bishopSquare, 1, -1),
		getSquaresInGivenDirection(board, bishopSquare, -1, 1),
	};

	for (std::vector<ty::Square> dir : directions) {
		for (ty::Square& square : dir) {
			bishopSquares.push_back(square);
		}
	}

	return bishopSquares;
}

ty::Square knightSquare(ty::Square board[8][8], int x, int y) {
	ty::Square errorSquare; //return this if x and y are out of bounds
	
	if (!pos::inBounds(x, y)) {
		return errorSquare;
	}

	return board[x][y];
}

std::vector<ty::Square> pos::knightSquares(ty::Square board[8][8], ty::Square square)
{
	std::vector<ty::Square> knightSquares;

	knightSquares = {
		knightSquare(board, square.x - 2, square.y + 1),
		knightSquare(board, square.x + 2, square.y + 1),
		knightSquare(board, square.x -2, square.y -1),
		knightSquare(board, square.x + 2, square.y - 1),

		knightSquare(board, square.x + 1, square.y + 2),
		knightSquare(board, square.x -1, square.y + 2),
		knightSquare(board, square.x + 1, square.y - 2),
		knightSquare(board, square.x - 1, square.y - 2)
	};

	for (unsigned int i = 0; i < knightSquares.size(); i++) {
		if (knightSquares[i].x == -1) {
			knightSquares.erase(knightSquares.begin() + i);
			i--;
			continue;
		}
		if (knightSquares[i].occupying_Piece.color == square.occupying_Piece.color) {
			knightSquares.erase(knightSquares.begin() + i);
			i--;
			continue;
		}
	}

	return knightSquares;
}

std::vector<ty::Square> pos::rookSquares(ty::Square board[8][8], ty::Square rookSquare) {
	std::vector<ty::Square> rookSquares;
	std::vector<std::vector<ty::Square>> directions;

	directions = {
		getSquaresInGivenDirection(board, rookSquare, 0, 1),
		getSquaresInGivenDirection(board, rookSquare, 0, -1),
		getSquaresInGivenDirection(board, rookSquare, 1, 0),
		getSquaresInGivenDirection(board, rookSquare, -1, 0),
	};

	for (std::vector<ty::Square> dir : directions) {
		for (ty::Square &square : dir) {
			rookSquares.push_back(square);
		}
	}

	return rookSquares;
}

std::vector<ty::Square> pos::queenSquares(ty::Square board[8][8], ty::Square queenSquare) 
{
	std::vector<ty::Square> queenSquares;
	std::vector <std::vector<ty::Square>> directions;

	directions = {
		getSquaresInGivenDirection(board, queenSquare, 1, 1),
		getSquaresInGivenDirection(board, queenSquare, 1, 0),
		getSquaresInGivenDirection(board, queenSquare, 1, -1),
		getSquaresInGivenDirection(board, queenSquare, -1, 1),
		getSquaresInGivenDirection(board, queenSquare, -1, 0),
		getSquaresInGivenDirection(board, queenSquare, -1, -1),
		getSquaresInGivenDirection(board, queenSquare, 0, 1),
		getSquaresInGivenDirection(board, queenSquare, 0, -1),
	};

	for (std::vector<ty::Square> dir : directions) {
		for (ty::Square &squares : dir) {
			queenSquares.push_back(squares);
		}
	}

	return queenSquares;
}

std::vector<ty::Square> pos::kingSquares(ty::Square board[8][8], ty::Square kingSquare)
{
	std::vector<ty::Square> kingSquares;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!pos::inBounds(kingSquare.x + i, kingSquare.y + j)) {
				continue;
			}
			//erase own square
			if (kingSquare.x + i == kingSquare.x && kingSquare.y + j == kingSquare.y) {
				continue;
			}
			if (board[kingSquare.x + i][kingSquare.y + j].occupying_Piece.color == kingSquare.occupying_Piece.color) {
				continue;
			}
			kingSquares.push_back(board[i + kingSquare.x][j + kingSquare.y]);
		}
	}
	return kingSquares;
}

std::vector<ty::Square> pos::squaresForPiece(ty::Square board[8][8], ty::Square square, bool pawnPush)
{
	std::vector <ty::Square> errorSquares; //defaultly return this

	switch (square.occupying_Piece.subtype) {
	case ty::PieceType::king:
		return pos::kingSquares(board, square);
		break;
	case ty::PieceType::queen:
		return pos::queenSquares(board, square);
		break;
	case ty::PieceType::rook:
		return pos::rookSquares(board, square);
		break;
	case ty::PieceType::knight:
		return pos::knightSquares(board, square);
		break;
	case ty::PieceType::bishop:
		return pos::bishopSquares(board, square);
		break;
	case ty::PieceType::pawn:
		return pos::pawnSquares(board, square, pawnPush);
		break;
	default:
		return errorSquares;
		break;
	}
}

bool pos::inBounds(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
		return true;
	}

	return false;
}

void pos::duplicatePosition(ty::Position &oldPos, ty::Position &newPos)
{
	newPos.wK_RookMoved = oldPos.wK_RookMoved;
	newPos.wQ_RookMoved = oldPos.wQ_RookMoved;
	newPos.w_Castled = newPos.w_Castled;

	newPos.bK_RookMoved = oldPos.bK_RookMoved;
	newPos.bQ_RookMoved = oldPos.bQ_RookMoved;
	newPos.b_Castled = oldPos.b_Castled;

	newPos.w_Pieces = oldPos.w_Pieces;
	newPos.b_Pieces = oldPos.b_Pieces;

	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			newPos.board[i][j].x = i;
			newPos.board[i][j].y = j;
			newPos.board[i][j].occupying_Piece = oldPos.board[i][j].occupying_Piece;
			newPos.board[i][j].enPessant = oldPos.board[i][j].enPessant;
		}
	}
}

std::vector<std::vector<ty::Square>> pos::possible_Moves(ty::Position &pos, std::vector<ty::Piece> pieces, bool pawnPush) 
{
	std::vector<std::vector<ty::Square>> squares;

	for (ty::Piece &i : pieces) {
		squares.push_back(pos::squaresForPiece(pos.board, pos.board[i.x][i.y], pawnPush));
	}

	return squares;
}

std::vector<ty::Position> pos::possible_Positions(ty::Position &pos, std::vector<ty::Piece> pieces, std::vector<ty::Piece> enemy_Pieces)
{
	std::vector<ty::Position> positions;

	ty::Position newPos;

	std::vector<std::vector<ty::Square>> possible_Moves = pos::possible_Moves(pos, pieces, false);

	if (!pos.castled(pieces[0].color)) {
		pos::checkCastlingPrivelages(pos, pieces[0].color);

		if (!pos.castled(pieces[0].color)) {
			ty::Position
				queensideCastledPos = pos::castledPosition(pos, 0, pieces[0].color),
				kingsideCastledPos = pos::castledPosition(pos, 7, pieces[0].color);

			if (queensideCastledPos.castled(pieces[0].color)) {
				positions.push_back(queensideCastledPos);
			}
			if (kingsideCastledPos.castled(pieces[0].color)) {
				positions.push_back(kingsideCastledPos);
			}
		}
	}

	for (int i = 0; i <= 7; i++) {
		if (pos.board[i][5].enPessant == 2) {
			pos.board[i][5].enPessant = 0;
		}
		else if (pos.board[i][5].enPessant == 1) {
			pos.board[i][5].enPessant++;
		}

		if (pos.board[i][2].enPessant == 2) {
			pos.board[i][2].enPessant = 0;
		}
		else if (pos.board[i][2].enPessant == 1) {
			pos.board[i][2].enPessant++;
		}
	}

	for (unsigned int i = 0; i < possible_Moves.size(); i++) {

		for (unsigned int j = 0; j < possible_Moves[i].size(); j++) {
			pos::duplicatePosition(pos, newPos);

			std::vector<ty::Piece> future_Enemy_Pieces = enemy_Pieces;

			int x = possible_Moves[i][j].x, y = possible_Moves[i][j].y;

			newPos.board[pieces[i].x][pieces[i].y].occupying_Piece = { ty::PieceType::blank, -1, "|   |", -1, -1, -1 };

			//check to see if pawn jumped 2 squares, 
			//then give en pessant to that square ahead of it if true
			if (pieces[i].subtype == ty::PieceType::pawn) {
				int jumpLength = pieces[i].y - y;

				int deltaY = 1;

				if (jumpLength < 0) {
					jumpLength = jumpLength * -1;
					deltaY = -1;
				}

				if (jumpLength == 2) {
					newPos.board[x][y + deltaY].enPessant = 1;
				}

				int eX, eY;

				//check if piece has done the en pessant
				if (newPos.board[x][y].enPessant == 2) {
					for (unsigned int z = 0; z < future_Enemy_Pieces.size(); z++) {
						eX = future_Enemy_Pieces[z].x, eY = future_Enemy_Pieces[z].y;

						if (newPos.board[eX][eY].equals(newPos.board[x][y + deltaY])) {
							newPos.board[eX][eY].occupying_Piece = { ty::PieceType::blank, -1, "|   |", -1, -1, -1 };
							future_Enemy_Pieces.erase(future_Enemy_Pieces.begin() + z);
						}
					}
				}
			} 

			for (unsigned int z = 0; z < future_Enemy_Pieces.size(); z++) {
				if (future_Enemy_Pieces[z].ID == newPos.board[x][y].occupying_Piece.ID) {
					future_Enemy_Pieces.erase(future_Enemy_Pieces.begin() + z);
					z--;
				}
			} 

			if (pieces[0].color == 0) {
				newPos.b_Pieces = future_Enemy_Pieces;
			} else {
				newPos.w_Pieces = future_Enemy_Pieces;
			}

			newPos.board[x][y].occupying_Piece = { pieces[i].subtype, pieces[i].color, pieces[i].printedSelf, x, y, pieces[i].ID };

			if (pieces[0].color == 0) {
				newPos.w_Pieces[i].x = x;
				newPos.w_Pieces[i].y = y;
			} else {
				newPos.b_Pieces[i].x = x;
				newPos.b_Pieces[i].y = y;
			}

			if (pieces[0].color == 0) {
				for (int z = 0; z <= 3; z++) {
					pw::promote(newPos.board, newPos.w_Pieces, z);
				}
			} else {
				for (int z = 0; z <= 3; z++) {
					pw::promote(newPos.board, newPos.b_Pieces, z);
				}
			}

			positions.push_back(newPos);
		}
	}

	std::vector<ty::Piece> friendlies, enemies;

	for (unsigned int i = 0; i < positions.size(); i++) {
		if (pieces[0].color == 0) {
			friendlies = positions[i].w_Pieces;
			enemies = positions[i].b_Pieces;
		} else {
			friendlies = positions[i].b_Pieces;
			enemies = positions[i].w_Pieces; 
		}

		if (pos::isAttacked(positions[i], positions[i].board[friendlies[0].x][friendlies[0].y], enemies)) {
			positions.erase(positions.begin() + i);
			i--;
		}
	}

	return positions;
}

bool pos::isAttacked(ty::Position pos, ty::Square square, std::vector<ty::Piece> enemy_Pieces)
{
	std::vector<std::vector<ty::Square>> enemy_Squares = pos::possible_Moves(pos, enemy_Pieces, true);

	for (unsigned int i = 0; i < enemy_Squares.size(); i++) {
		for (unsigned int j = 0; j < enemy_Squares[i].size(); j++) {
			if (enemy_Squares[i][j].equals(square)) {
				return true;
			}
		}
	}

	return false;
}

void pos::checkCastlingPrivelages(ty::Position& pos, int color)
{
	ty::Piece king, kRook, qRook;

	std::vector<ty::Piece> pieces;

	int y;

	int rookCount = 0;

	int rook1 = -1, rook2 = -1;

	if (color == 0) {
		pieces = pos.w_Pieces;
		y = 0;
	}
	else {
		pieces = pos.b_Pieces;
		y = 7;
	}

	if (pos.board[0][y].occupying_Piece.subtype != ty::PieceType::rook) {
		if (color == 0) {
			pos.wQ_RookMoved = true;
		}
		else {
			pos.bQ_RookMoved = true;
		}
	}

	if (pos.board[7][y].occupying_Piece.subtype != ty::PieceType::rook) {
		if (color == 0) {
			pos.wK_RookMoved = true;
		}
		else {
			pos.bK_RookMoved = true;
		}

		if (pos.board[4][y].occupying_Piece.subtype != ty::PieceType::king) {
			if (color == 0) {
				pos.w_Castled = true;
			}
			else {
				pos.b_Castled = true;
			}
		}

		if (color == 0) {
			if (pos.wK_RookMoved && pos.wQ_RookMoved) {
				pos.w_Castled = true;
			}
		}
		else {
			if (pos.bK_RookMoved && pos.bQ_RookMoved) {
				pos.b_Castled = true;
			}
		}
	}
}

ty::Position pos::castledPosition(ty::Position pos, int rookX, int color) {
	ty::Position castledPos;
	pos::duplicatePosition(pos, castledPos);

	std::vector<ty::Piece> pieces, enemy_Pieces;

	int row;

	int rookIndex = 0;

	if (color == 0) {
		pieces = pos.w_Pieces;
		enemy_Pieces = pos.b_Pieces;
		
		row = 0;
	} else {
		pieces = pos.b_Pieces;
		enemy_Pieces = pos.w_Pieces;

		row = 7;
	}

	if (pos::isAttacked(pos, pos.board[pieces[0].x][pieces[0].y], enemy_Pieces)) {
		return castledPos;
	}

	int deltaX = 0;

	if (rookX == 0) {
		if (pos.qRookMoved(color)) {
			return castledPos;
		}

		deltaX = 1;
	} else if (rookX == 7) {
		if (pos.kRookMoved(color)) {
			return castledPos;
		}

		deltaX = -1;
	}

	for (unsigned int i = 0; i < pieces.size(); i++) {
		if (pieces[i].subtype == ty::PieceType::rook &&
			pieces[i].x == rookX && pieces[i].y == row) 
		{
			rookIndex = i;
		}
	}

	int i = rookX + deltaX;

	while (true) {
		if (i == 4) {
			break;
		}
		if (castledPos.board[i][row].occupying_Piece.subtype != ty::PieceType::blank ||
			pos::isAttacked(castledPos, castledPos.board[i][row], enemy_Pieces)) 
		{
			return castledPos;
		}

		i += deltaX;
	}

	castledPos.board[4 - (deltaX * 2)][row].occupying_Piece = { ty::PieceType::king, color, pieces[0].printedSelf, 4 + (deltaX * 2), row, pieces[0].ID };
	castledPos.board[4 - deltaX][row].occupying_Piece = { ty::PieceType::rook, color, pieces[rookIndex].printedSelf, 4 + deltaX, row, pieces[rookIndex].ID };

	castledPos.board[4][row].occupying_Piece = { ty::PieceType::blank, -1, "|   |", -1, -1, -1 };
	castledPos.board[rookX][row].occupying_Piece = { ty::PieceType::blank, -1, "|   |", -1, -1, -1 };

	if (color == 0) {
		castledPos.w_Pieces[0].x = 4 + (deltaX * 2);
		castledPos.w_Pieces[rookIndex].x = 4 + deltaX;
	} else {
		castledPos.b_Pieces[0].x = 4 + (deltaX * 2);
		castledPos.b_Pieces[rookIndex].x = 4 + deltaX;
	}

	if (color == 0) {
		castledPos.w_Castled = true;
	} else {
		castledPos.b_Castled = true;
	}

	return castledPos;
}

std::vector<ty::Piece> pos::getAttackers(ty::Square board[8][8], ty::Square square, std::vector<ty::Piece> enemy_Pieces)
{
	std::vector<ty::Piece> pieces;

	std::vector<ty::Square> squares;

	for (ty::Piece& i : enemy_Pieces) {
		squares = pos::squaresForPiece(board, board[i.x][i.y], true);

		for (ty::Square& s : squares) {
			if (s.equals(square)) {
				pieces.push_back(i);
				break;
			}
		}
	}

	return pieces;
}

bool pos::isPieceThreatened(ty::Square board[8][8], ty::Square square, std::vector<ty::Piece> enemy_Pieces, std::vector<ty::Piece> friendly_Pieces) 
{
	std::vector<ty::Piece> defenders = pos::getAttackers(board, square, friendly_Pieces);
	std::vector<ty::Piece> attackers = pos::getAttackers(board, square, enemy_Pieces);

	if (attackers.size() == 0) {
		return false;
	}

	//if piece is attacked and undefended
	if (defenders.size() == 0 && attackers.size() > 0) {
		return true;
	}

	//check if piece of lesser value is attacking it
	for (ty::Piece i : attackers) {
		if (static_cast<int>(i.subtype) < static_cast<int>(square.occupying_Piece.subtype)) {
			return true;
		}
	}

	std::vector<int> enemyRatings, defenderRatings, sortedEnemyRatings, sortedDefenderRatings;

	int lowestRating = 0, highestRating = 0;

	for (ty::Piece& i : attackers) {
		enemyRatings.push_back(static_cast<int>(i.subtype));
	}

	for (ty::Piece& i : attackers) {
		defenderRatings.push_back(static_cast<int>(i.subtype));
	}

	if (attackers.size() > defenders.size()) {
		return true;
	}

	return false;
}