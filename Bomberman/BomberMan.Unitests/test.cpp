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

TEST(GameTest, GameOver) {
    IGame* game = new Game();
    EXPECT_FALSE(game->isOver());
    game->SetGameOver();
    EXPECT_TRUE(game->isOver());
}

class MockGameListener : public IGameListener {
public:
    MOCK_METHOD(void, OnKeyPressed, (), (override));
};

TEST(GameTest, AddRemoveGameListener) {
    Game game;
    MockGameListener listener1, listener2;
    EXPECT_TRUE(game.addGameListener(&listener1));
    EXPECT_TRUE(game.addGameListener(&listener2));
    EXPECT_TRUE(game.removeGameListener(&listener1));
    EXPECT_FALSE(game.removeGameListener(&listener1));
    EXPECT_TRUE(game.removeGameListener(&listener2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

