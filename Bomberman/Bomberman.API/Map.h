#pragma once
#include "IMap.h"

class Map : public IMap
{
public:
	Map();
	// Inherited via IMap
	std::vector<std::vector<ISquare*>> GetState() override;
private:

	void BuildConfig() override;

private:
	std::vector<std::vector<ISquare*>> board;
};

