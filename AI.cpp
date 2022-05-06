#include "AI.h"

void ai::chooseMove(ty::Position &pos, std::vector<ty::Piece> ai_Pieces, std::vector<ty::Piece> enemy_Pieces)
{
    std::vector<ty::Position> possible_Positions = pos::possible_Positions(pos, ai_Pieces, enemy_Pieces);
    
    size_t numberOfPositions = possible_Positions.size();

    if (numberOfPositions == 0) {
        if (pos::isAttacked(pos, pos.board[ai_Pieces[0].x][ai_Pieces[0].y], enemy_Pieces)) {
            std::cout << "it is checkmate!\n";
            exit(0);
        }
        else {
            std::cout << "it is a stalemate\n";
            exit(0);
        }
    }

    ty::Position newPos = ev::highestRatedPosition(possible_Positions, ai_Pieces[0].color);

    pos::duplicatePosition(newPos, pos);
}
