#include "Core/game.h"
#include <gtest/gtest.h>

TEST(GameTest, InitialPlayerIsX){
    Game game;
    EXPECT_EQ(game.get_current_player(), PLAYER_X);
}