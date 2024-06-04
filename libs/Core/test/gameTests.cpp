#include "Core/game.h"
#include <gtest/gtest.h>

TEST(GameTest, InitialPlayerIsX){
    Game game;
    EXPECT_EQ(game.get_current_player(), PLAYER_X);
}

TEST(GameTest, SwitchPlayerXtoO) {
    Game game;
    game.set_current_player(PLAYER_X);
    game.switch_player();
    EXPECT_EQ(game.get_current_player(), PLAYER_X);
}