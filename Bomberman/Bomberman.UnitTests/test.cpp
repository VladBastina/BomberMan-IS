#include "pch.h"

TEST(GameTest, MovePlayer) {
    Game* game = new Game();
    IPlayer* player1 = game->GetPlayer1();

    // Move Up
    game->MovePlayer(player1, EPlayerMovementType::Up);
    EXPECT_EQ(player1->GetPosition().first, 1);
    EXPECT_EQ(player1->GetPosition().second, 1);

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // Move Down
    game->MovePlayer(player1, EPlayerMovementType::Down);
    EXPECT_EQ(player1->GetPosition().first, 2);
    EXPECT_EQ(player1->GetPosition().second, 1);

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // Move Left
    game->MovePlayer(player1, EPlayerMovementType::Left);
    EXPECT_EQ(player1->GetPosition().first, 2);
    EXPECT_EQ(player1->GetPosition().second, 1);

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // Move Right
    game->MovePlayer(player1, EPlayerMovementType::Right);
    EXPECT_EQ(player1->GetPosition().first, 2);
    EXPECT_EQ(player1->GetPosition().second, 2);

    delete game;
}
