#include "Core/ultimateboard.h" // Make sure this path is correct for your project
#include <gtest/gtest.h>

// add_mark
TEST(UltimateBoard, AddMark){
    UltimateBoard board;
    EXPECT_TRUE(board.add_mark(1,1,PLAYER_X));
}
TEST(UltimateBoard, AddMarkInvalidMini){
    UltimateBoard board;
    EXPECT_FALSE(board.add_mark(10,1,PLAYER_X));
}
TEST(UltimateBoard, AddMarkInvalidCell){
    UltimateBoard board;
    EXPECT_FALSE(board.add_mark(1,10,PLAYER_X));
}
TEST(UltimateBoard, AddMarkToMarked){
    UltimateBoard board;
    board.add_mark(1,1, PLAYER_O);
    EXPECT_FALSE(board.add_mark(1,1, PLAYER_X));
}
TEST(UltimateBoard, AddMarkMultipleValid){
    UltimateBoard board;
    EXPECT_TRUE(board.add_mark(1,1, PLAYER_X));
    EXPECT_TRUE(board.add_mark(1,2, PLAYER_O));
    EXPECT_TRUE(board.add_mark(2,1, PLAYER_X));
    EXPECT_TRUE(board.add_mark(3,9, PLAYER_O));
}

// check_winner
TEST(UltimateBoard, CheckWinnerRow){
    UltimateBoard board;
    board.add_mark(1,1,PLAYER_X);
    board.add_mark(1,2,PLAYER_X);
    board.add_mark(1,3,PLAYER_X);

    board.add_mark(2,1,PLAYER_X);
    board.add_mark(2,2,PLAYER_X);
    board.add_mark(2,3,PLAYER_X);

    board.add_mark(3,1,PLAYER_X);
    board.add_mark(3,2,PLAYER_X);
    board.add_mark(3,3,PLAYER_X);

    EXPECT_TRUE(board.check_ultimate_winner(PLAYER_X));


}
TEST(UltimateBoard, CheckWinnerCol){
    UltimateBoard board;
    board.add_mark(1,1,PLAYER_O);
    board.add_mark(1,4,PLAYER_O);
    board.add_mark(1,7,PLAYER_O);

    board.add_mark(4,1,PLAYER_O);
    board.add_mark(4,4,PLAYER_O);
    board.add_mark(4,7,PLAYER_O);

    board.add_mark(7,1,PLAYER_O);
    board.add_mark(7,4,PLAYER_O);
    board.add_mark(7,7,PLAYER_O);

    EXPECT_TRUE(board.check_ultimate_winner(PLAYER_O));


}
TEST(UltimateBoardTest, CheckUltimateWinnerDiagonal1) {
    UltimateBoard board;

    board.add_mark(1, 1, PLAYER_X);
    board.add_mark(1, 2, PLAYER_X);
    board.add_mark(1, 3, PLAYER_X);

    board.add_mark(5, 1, PLAYER_X);
    board.add_mark(5, 2, PLAYER_X);
    board.add_mark(5, 3, PLAYER_X);

    board.add_mark(9, 1, PLAYER_X);
    board.add_mark(9, 2, PLAYER_X);
    board.add_mark(9, 3, PLAYER_X);

    EXPECT_TRUE(board.check_ultimate_winner(PLAYER_X));
}
TEST(UltimateBoardTest, CheckUltimateWinnerDiagonal2) {
    UltimateBoard board;

    board.add_mark(3, 1, PLAYER_O);
    board.add_mark(3, 2, PLAYER_O);
    board.add_mark(3, 3, PLAYER_O);

    board.add_mark(5, 4, PLAYER_O);
    board.add_mark(5, 5, PLAYER_O);
    board.add_mark(5, 6, PLAYER_O);

    board.add_mark(7, 7, PLAYER_O);
    board.add_mark(7, 8, PLAYER_O);
    board.add_mark(7, 9, PLAYER_O);

    EXPECT_TRUE(board.check_ultimate_winner(PLAYER_O));
}
TEST(UltimateBoardTest, CheckNoWinner) {
    UltimateBoard board;

    board.add_mark(1, 1, PLAYER_X);
    board.add_mark(1, 2, PLAYER_O);
    board.add_mark(1, 3, PLAYER_X);

    board.add_mark(2, 1, PLAYER_X);
    board.add_mark(2, 2, PLAYER_X);
    board.add_mark(2, 3, PLAYER_O);

    board.add_mark(3, 1, PLAYER_O);
    board.add_mark(3, 2, PLAYER_X);
    board.add_mark(3, 3, PLAYER_O);

    EXPECT_FALSE(board.check_ultimate_winner(PLAYER_X));
    EXPECT_FALSE(board.check_ultimate_winner(PLAYER_O));
}

TEST(UltimateBoardTest, CheckUltimateFullWhenFull) {
    UltimateBoard board;

    for (int mini_pos = 1; mini_pos <= 9; ++mini_pos) {
        for (int cell_pos = 1; cell_pos <= 9; ++cell_pos) {
            board.add_mark(mini_pos, cell_pos, PLAYER_X);
        }
    }

    EXPECT_TRUE(board.is_ultimate_full());
}
TEST(UltimateBoardTest, CheckUltimateFullWhenNotFull) {
    UltimateBoard board;

    for (int mini_pos = 1; mini_pos <= 8; ++mini_pos) {
        for (int cell_pos = 1; cell_pos <= 9; ++cell_pos) {
            board.add_mark(mini_pos, cell_pos, PLAYER_X);
        }
    }

    EXPECT_FALSE(board.is_ultimate_full());
}
TEST(UltimateBoardTest, CheckUltimateFullWhenEmpty) {
    UltimateBoard board;

    EXPECT_FALSE(board.is_ultimate_full());
}
