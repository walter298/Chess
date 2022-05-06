#ifndef GAME
#define GAME

#include "AI.h"

namespace game {
	void playerPromote(ty::Position &pos, int color);
	void getPlayerInput(int color);
	void play();
}

#endif