#pragma once
#include "IMap.h"

class Map : public IMap
{
public:
	Map();

	// Inherited via IMap
	void Initialize() override;
	void ResetMap() override;
	std::pair<int, int> GetMapDimensions() const override;

	ISquare* GetSquare(int x, int y) const override;
	bool IsDestructible(int x, int y) const override;
	bool IsPassable(int x, int y) const override;
	bool HasBomb(int x, int y) const override;
	bool HasPowerUp(int x, int y) const override;

	std::vector<std::pair<int, int>> GetAllDestructibleSquares() const override;
	std::vector<std::pair<int, int>> GetExplosionRange(int x, int y, int explosionRadius) const override;
	bool IsValidPosition(int x, int y) const override;

	void UpdateSquare(int x, int y, ISquare* newSquare) override;
	void PlaceBomb(int x, int y) override;
	void RemoveBomb(int x, int y) override;
	void AddPowerUp(int x, int y, ISquare* powerUp) override;
	void RemovePowerUp(int x, int y) override;

	void PrintMap() const override;
	std::string ExportMapAsString() const override;
	
private:
	std::vector<std::vector<ISquare*>> board;
};

