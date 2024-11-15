#pragma once
#include"ISquare.h"

class IMap {
	virtual std::vector<std::vector<ISquare*>> GetState() = 0;
};
