#include "game.h"

ty::Position mainPos;

void game::playerPromote(ty::Position &pos, int color)
{
	int row;
	char colorChar;

	std::vector<ty::Piece> pieces;

	if (color == 0) {
		row = 7;
		pieces = pos.w_Pieces;
		colorChar = 'w';
	} else {
		row = 0;
		pieces = pos.b_Pieces;
		colorChar = 'b';
	}

	bool finishedPromoting = false;

	for (int i = 0; i <= 7; i++) {
		if (finishedPromoting) {
			break;
		}
		if (pos.board[i][row].occupying_Piece.subtype == ty::PieceType::pawn) {
			ty::PieceType type;
			char input;
			std::string name;

			int pieceIndex = -1;

			for (unsigned int i = 0; i < pieces.size(); i++) {
				if (pieces[i].x == i && pieces[i].y == row) {
					pieceIndex = i;
					break;
				}
			}

			std::cout << "what would you like to promote your piece to?\n";
			std::cout << "q: queen.\n";
			std::cout << "n: knight.\n";
			std::cout << "b: bishop.\n";
			std::cout << "r: rook\n";

			while (true) {
				std::cin >> input;

				if (input != 'q' && input != 'n' && input != 'b' && input != 'r') {
					std::cout << "not a valid input.\n";
				} else {
					break;
				}
			}

			switch (input) {
			case 'q':
				name = { 'p', colorChar, 'Q' };
				type = ty::PieceType::queen;
				break;
			case 'n': 
				name = { 'p', colorChar, 'N' };
				type = ty::PieceType::knight;
				break;
			case 'b':
				name = { 'p', colorChar, 'B' };
				type = ty::PieceType::bishop;
				break;
			case 'r':
				name = { 'p', colorChar, 'R' };
				type = ty::PieceType::rook;
				break;
			}

			if (color == 0) {
				pos.w_Pieces[pieceIndex] = { type, color, name, i, row, pos.w_Pieces[pieceIndex].ID };
			} else {
				pos.b_Pieces[pieceIndex] = { type, color, name, i, row, pos.w_Pieces[pieceIndex].ID };
			}

			finishedPromoting = true;
		}
	}
}

void game::getPlayerInput(int color)
{
	std::vector<ty::Position> possible_Positions;
	ty::Position inputtedPos;

	int x1, y1, x2, y2;

	if (color == 0) {
		possible_Positions = pos::possible_Positions(mainPos, mainPos.w_Pieces, mainPos.b_Pieces);
	} else {
		possible_Positions = pos::possible_Positions(mainPos, mainPos.b_Pieces, mainPos.w_Pieces);
	}

	pos::printBoard(mainPos.board);

	while (true) {
		std::cout << "type in the x and y coords for the piece you want to move\n";

		std::cin >> x1;
		std::cin >> y1;

		x1--;
		y1--;

		if (!pos::inBounds(x1, y1)) {
			std::cout << "Error: please numbers between 1 and 8.\n";
			continue;
		}

		if (mainPos.board[x1][y1].occupying_Piece.color != color) {
			std::cout << "Error: invalid piece\n";
			continue;
		}

		std::cout << "now type in the x and y coords for that piece to go to.\n";
		std::cin >> x2;
		std::cin >> y2;

		x2--;
		y2--;

		if (!pos::inBounds(x2, y2)) {
			std::cout << "Error: please numbers between 1 and 8.\n";
			continue;
		}

		bool validSquare = false;

		for (ty::Position &i : possible_Positions) {
			if (i.board[x2][y2].occupying_Piece.ID == mainPos.board[x1][y1].occupying_Piece.ID) {
				validSquare = true;
				pos::duplicatePosition(i, inputtedPos);
				break;
			}
		}

		if (!validSquare) {
			std::cout << "Error: piece cannot move to that square\n";
			continue;
		}

		break;
	}

	pos::duplicatePosition(inputtedPos, mainPos);

	game::playerPromote(mainPos, color);

	pos::printBoard(mainPos.board);
	
}

void game::play()
{
	pos::setup(mainPos.board, mainPos.w_Pieces, mainPos.b_Pieces);

	int color = 0;

	std::cout << "Type in your color of choice. 0 to be white, 1 to be black.\n";

	std::cin >> color;

	if (color == 0) {
		while (true) {
			getPlayerInput(color);
			std::cout << std::endl;
			ai::chooseMove(mainPos, mainPos.b_Pieces, mainPos.w_Pieces);
		}
	} else {
		while (true) {
			ai::chooseMove(mainPos, mainPos.w_Pieces, mainPos.b_Pieces);
			std::cout << std::endl;
			getPlayerInput(color);
		}
	}
}