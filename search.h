#ifndef SEARCH
#define SEARCH

#include <thread>

#include "position.h"
#include "eval.h"

namespace search 
{
	int evaluatedTree(ty::Position pos, int color);

	ty::Position bestPosition(ty::Position pos, int color);
}

#endif