#pragma once
#include"ISquare.h"

class IMap {
public:
	virtual std::vector<std::vector<ISquare*>> GetState() = 0;

	virtual ~IMap() = default;

protected:
	virtual void BuildConfig() = 0;
};
