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
	IBomb* GetBomb() const override;
	std::string GetImagePath() const override;



	void SetPlayer(IPlayer* player) override;
	void SetBomb(IBomb* bomb) override;
	void SetImagePath(std::string imagePath) override;
	void SetSquareType(ESquareType squareType) override;
	void RemovePlayer() override;
	bool BreakWall() override;
	void DropPowerUp() override;
	void ClearBomb() override;

	bool HasWall() const override;
	bool HasBomb() const override;
	bool HasBombExploded() const override;

private:

	bool ImageExist(const std::string& path);

	std::pair<int, int> position;
	IPlayer* player;
	IBomb* bomb;
	ESquareType squareType;
	std::string imagePath;

	//IPowerUp powerUp;
};

