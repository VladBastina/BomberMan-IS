#pragma once
#include "ISquare.h"
#include <fstream>

class Square : public ISquare
{
public:
	Square(std::pair<int,int>pos,IPlayer* player , ESquareType squareType , std::string imagePath);
	~Square() = default;

	// Inherited via ISquare
	std::pair<int, int> GetPosition() const override;
	bool HasPlayer() const override;
	ESquareType GetSquareType() const override;
	bool HasPowerUp() const override;
	IPlayer* GetPlayer() const override;
	std::string GetImagePath() const override;

	void SetPlayer(IPlayer* player) override;
	void RemovePlayer() override;
	bool BreakWall() override;
	void DropPowerUp() override;

	bool HasWall() const override;

private:

	bool ImageExist(const std::string& path);

	std::pair<int, int> position;
	IPlayer* player;
	ESquareType squareType;
	std::string imagePath;

	//IPowerUp powerUp;
};

