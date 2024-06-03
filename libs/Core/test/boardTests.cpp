#include "Core/board.h"
#include <gtest/gtest.h>

TEST(add_mark, AddMarkToEmptyCell) {
    // Проверка установки значения в пустую ячейку
    Board board1;
    Board board;
    for (int i = 1; i <= 9; ++i) {
        EXPECT_TRUE(board.add_mark(i, PLAYER_X));
    }
    for (int i = 1; i <= 9; ++i) {
        EXPECT_TRUE(board1.add_mark(i, PLAYER_O));
    }
    for (int i = 1; i <= 9; ++i) {
        EXPECT_EQ(PLAYER_X, board.get_mark(i));
    }
    for (int i = 1; i <= 9; ++i) {
        EXPECT_EQ(PLAYER_O, board1.get_mark(i));
    }
}

// Попытка поставить значение в занятую клетку
TEST(add_mark, AddMarkToOccupiedCell){
    Board board;
    for (int i = 1; i <= 9; ++i) {
        board.add_mark(i, PLAYER_X);

    }
    for (int i = 1; i <= 9; ++i) {
        EXPECT_FALSE(board.add_mark(i, PLAYER_O));
        EXPECT_EQ(board.get_mark(i), PLAYER_X);
    }

}

//    Позиция находится в допустимом диапазоне (1-9).
//    Позиция находится вне допустимого диапазона (меньше 1 или больше 9).
//    Проверить, что функция корректно возвращает значение из ячейки.

TEST(get_mark, PositionBetweenOneAndNine){
    Board board;
    for (int i = 1; i <= 4 ; ++i) {
        board.add_mark(i, PLAYER_X);
    }
    for (int i = 5; i <= 9 ; ++i) {
        board.add_mark(i, PLAYER_O);
    }
    for (int i = 1; i <= 4; ++i) {
        EXPECT_EQ(board.get_mark(i), PLAYER_X);
    }
    for (int i = 5; i <= 9; ++i) {
        EXPECT_EQ(board.get_mark(i), PLAYER_O);
    }
    for (int i = -10; i < 1; ++i) {
        EXPECT_EQ(board.get_mark(i), EMPTY);
    }
    for (int i = 10; i < 21; ++i) {
        EXPECT_EQ(board.get_mark(i), EMPTY);
    }
}

// Победа по строкам.
// Победа по столбцам.
// Победа по диагоналям.
// Отсутствие победителя (ничья или игра не завершена).
TEST(check_winners, WinOnRow){
    Board board;
    board.add_mark(4, PLAYER_O);
    board.add_mark(6, PLAYER_O);
    board.add_mark(9, PLAYER_O);
    board.add_mark(1, PLAYER_X);
    board.add_mark(2, PLAYER_X);
    board.add_mark(3, PLAYER_X);
    EXPECT_EQ(board.check_winner(), PLAYER_X);

    Board board1;
    board1.add_mark(1, PLAYER_O);
    board1.add_mark(7, PLAYER_O);
    board1.add_mark(9, PLAYER_O);
    board1.add_mark(4, PLAYER_X);
    board1.add_mark(5, PLAYER_X);
    board1.add_mark(6, PLAYER_X);
    EXPECT_EQ(board1.check_winner(), PLAYER_X);

    Board board2;
    board2.add_mark(1, PLAYER_O);
    board2.add_mark(4, PLAYER_O);
    board2.add_mark(6, PLAYER_O);
    board2.add_mark(7, PLAYER_X);
    board2.add_mark(8, PLAYER_X);
    board2.add_mark(9, PLAYER_X);
    EXPECT_EQ(board2.check_winner(), PLAYER_X);
}
TEST(check_winners, WinOnCol){
    Board board;
    board.add_mark(2, PLAYER_O);
    board.add_mark(3, PLAYER_O);
    board.add_mark(5, PLAYER_O);
    board.add_mark(1, PLAYER_X);
    board.add_mark(4, PLAYER_X);
    board.add_mark(7, PLAYER_X);
    EXPECT_EQ(board.check_winner(), PLAYER_X);

    Board board1;
    board1.add_mark(1, PLAYER_O);
    board1.add_mark(7, PLAYER_O);
    board1.add_mark(9, PLAYER_O);
    board1.add_mark(2, PLAYER_X);
    board1.add_mark(5, PLAYER_X);
    board1.add_mark(8, PLAYER_X);
    EXPECT_EQ(board1.check_winner(), PLAYER_X);

    Board board2;
    board2.add_mark(1, PLAYER_O);
    board2.add_mark(4, PLAYER_O);
    board2.add_mark(8, PLAYER_O);
    board2.add_mark(3, PLAYER_X);
    board2.add_mark(6, PLAYER_X);
    board2.add_mark(9, PLAYER_X);
    EXPECT_EQ(board2.check_winner(), PLAYER_X);
}
TEST(check_winners, WinOnDiag){
    Board board;
    board.add_mark(2, PLAYER_O);
    board.add_mark(4, PLAYER_O);
    board.add_mark(8, PLAYER_O);
    board.add_mark(1, PLAYER_X);
    board.add_mark(5, PLAYER_X);
    board.add_mark(9, PLAYER_X);
    EXPECT_EQ(board.check_winner(), PLAYER_X);

    Board board1;
    board1.add_mark(2, PLAYER_O);
    board1.add_mark(4, PLAYER_O);
    board1.add_mark(9, PLAYER_O);
    board1.add_mark(3, PLAYER_X);
    board1.add_mark(5, PLAYER_X);
    board1.add_mark(7, PLAYER_X);
    EXPECT_EQ(board1.check_winner(), PLAYER_X);

}

TEST(IsFull, CheckFullnessOfBoard){
    Board board;
    EXPECT_FALSE(board.isFull());

    // проверяет что full при всей заполненности
    Board board1;
    for (int i = 1; i <= 9; ++i) {
        board1.add_mark(i, PLAYER_X);
    }
    EXPECT_TRUE(board1.isFull());

    // проверяет что не полное, если есть какие-то элементы
    Board board2;
    board2.add_mark(2, PLAYER_X);
    board2.add_mark(4, PLAYER_O);
    EXPECT_FALSE(board2.isFull());


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}