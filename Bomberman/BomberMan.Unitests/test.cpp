#include "pch.h"

TEST(GameTest, MovePlayer1) {
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

TEST(GameTest, MovePlayer2) {
    Game* game = new Game();
    IPlayer* player2 = game->GetPlayer2();

    // Move Up
    game->MovePlayer(player2, EPlayerMovementType::Up);
    EXPECT_EQ(player2->GetPosition().first, 11);
    EXPECT_EQ(player2->GetPosition().second, 12);

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // Move Down
    game->MovePlayer(player2, EPlayerMovementType::Down);
    EXPECT_EQ(player2->GetPosition().first, 12);
    EXPECT_EQ(player2->GetPosition().second, 12);

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // Move Left
    game->MovePlayer(player2, EPlayerMovementType::Left);
    EXPECT_EQ(player2->GetPosition().first, 12);
    EXPECT_EQ(player2->GetPosition().second, 11);

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // Move Right
    game->MovePlayer(player2, EPlayerMovementType::Right);
    EXPECT_EQ(player2->GetPosition().first, 12);
    EXPECT_EQ(player2->GetPosition().second, 12);

    delete game;
}

TEST(GameTest, GameOver) {
    IGame* game = new Game();
    EXPECT_FALSE(game->isOver());
    game->SetGameOver();
    EXPECT_TRUE(game->isOver());
    delete game;
}

class MockGameListener : public IGameListener {
public:
    MOCK_METHOD(void, OnKeyPressed, (), (override));
};

TEST(GameTest, AddRemoveGameListener) {
    IGame* game = new Game();
    MockGameListener listener1, listener2;
    EXPECT_TRUE(game->addGameListener(&listener1));
    EXPECT_TRUE(game->addGameListener(&listener2));
    EXPECT_TRUE(game->removeGameListener(&listener1));
    EXPECT_FALSE(game->removeGameListener(&listener1));
    EXPECT_TRUE(game->removeGameListener(&listener2));
    delete game;
}

TEST(GameTest, ListenerCallTest)
{
    IGame* game = new Game();
    MockGameListener* listener = new MockGameListener();

    EXPECT_CALL(*listener, OnKeyPressed).Times(1);

    game->addGameListener(listener);
    game->MovePlayer(game->GetPlayer1(), EPlayerMovementType::Down);   
    
    delete game;
}

TEST(GameTest, ExplosionDestroyTest)
{

}

TEST(GameTest, ExplosionPlayerTest)
{

}

TEST(GameTest, FireTest)
{

}

TEST(GameTest, FirePlayerTest)
{

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

