#pragma once
#include "IMap.h"
#include <random>

enum class EMapInitialization
{
	FromFile,
	Random
};

class Map : public IMap
{
private:
	std::vector<std::vector<ISquare*>> board;


public:
	Map(IPlayer* player1 , IPlayer* player2,EMapInitialization mapInitialization);

	// Inherited via IMap
	void Initialize(IPlayer* player1, IPlayer* player2) override;
	void ResetMap() override;
	std::pair<int, int> GetMapDimensions() const override;
	std::vector<std::vector<ISquare*>> getBoard() const override;

	ISquare* GetSquare(int x, int y) const override;
	bool IsDestructible(int x, int y) const override;
	bool IsPassable(int x, int y) const override;
	bool HasPowerUp(int x, int y) const override;
	bool HasBombOnSquare(std::pair<int, int> position) const override;

	std::vector<std::pair<int, int>> GetExplosionRange(int x, int y, int explosionRadius) const override;
	bool IsValidPosition(int x, int y) const override;

	void UpdateSquare(int x, int y, ISquare* newSquare) override;
	void PlaceBomb(int x, int y) override;
	void RemoveBomb(int x, int y) override;
	void AddPowerUp(int x, int y, ISquare* powerUp) override;
	void RemovePowerUp(int x, int y) override;

	void MovePlayer(IPlayer* player, EPlayerMovementType movementDir) override;

	void LoadFromFile(std::string filePath, IPlayer* player1, IPlayer* player2) override;

};

