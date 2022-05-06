#include "eval.h"

ty::Position ev::highestRatedPosition(std::vector<ty::Position> positions, int color)
{
	std::vector<int> ratings;

	int lowestRated = 0, highestRated = 0, lowestIndex = 0, highestIndex = 0;

	for (ty::Position& i : positions) {
		ratings.push_back(ev::evaluation(i, i.w_Pieces, i.b_Pieces));
	}

	//get highest and lowest position
	for (unsigned int i = 0; i < ratings.size(); i++) {
		if (ratings[i] > highestRated) {
			ratings[i] = highestRated;
			highestIndex = i;
		} else if (ratings[i] < lowestRated) {
			lowestRated = ratings[i];
			lowestIndex = i;
		}
	}

	if (color == 0) {
		return positions[highestIndex];
	}
	else {
		return positions[lowestIndex];
	}
}


int ev::getMaterialCount(std::vector<ty::Piece> pieces, std::vector<ty::Piece> enemy_Pieces)
{
	int enemyCount = 0, friendlyCount = 0, total = 0;

	for (ty::Piece i : pieces) {
		friendlyCount += static_cast<int>(i.subtype);
	}
	for (ty::Piece i : enemy_Pieces) {
		enemyCount += static_cast<int>(i.subtype);
	}

	total = friendlyCount - enemyCount;

	return total;
}

int ev::getAttackCount(ty::Position pos, std::vector<ty::Piece> pieces, std::vector<ty::Piece> enemy_Pieces)
{
	int friendlyAttackCount = 0, enemyAttackCount = 0;

	std::vector<int> attackedFriendlyPieceRatings, attackedEnemyPieceRatings;

	for (ty::Piece& i : enemy_Pieces) {
		if (pos::isPieceThreatened(pos.board, pos.board[i.x][i.y], pieces, enemy_Pieces)) {
			attackedEnemyPieceRatings.push_back(static_cast<int>(i.subtype));
		}
	}
	for (ty::Piece& i : pieces) {
		if (pos::isPieceThreatened(pos.board, pos.board[i.x][i.y], enemy_Pieces, pieces)) {
			attackedFriendlyPieceRatings.push_back(static_cast<int>(i.subtype));
		}
	}

	int currentHighestRating = 0;

	for (int i : attackedEnemyPieceRatings) {
		if (i > currentHighestRating) {
			currentHighestRating = i;
		}

		friendlyAttackCount += i;
	}

	currentHighestRating = 0;

	for (int i : attackedFriendlyPieceRatings) {
		if (i > currentHighestRating) {
			currentHighestRating = i;
		}

		enemyAttackCount += i;
	}

	return friendlyAttackCount - enemyAttackCount;
}

int ev::evaluation(ty::Position pos, std::vector<ty::Piece> friendlies, std::vector<ty::Piece> enemies)
{
	int totalEval = 0;

	int friendlyMaterialCount, attackedPieces;

	friendlyMaterialCount = ev::getMaterialCount(friendlies, enemies);
	attackedPieces = ev::getAttackCount(pos, friendlies, enemies);

	totalEval += friendlyMaterialCount;
	totalEval += attackedPieces;

	return totalEval;
}
