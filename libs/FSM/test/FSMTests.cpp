#include "FSM/FSM.h"
#include <gtest/gtest.h>

class FSMToggleTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    void SetUp() override {
        fsm.register_state("on", onState);
        fsm.register_state("off", offState);
    }

    FSM fsm;

    State onState = State{
            .enter = [] {},
            .update = [] {},
            .exit = [] {}
    };

    State offState = State{
            .enter = [] {},
            .update = [] {},
            .exit = [] {}
    };
};

TEST_P(FSMToggleTest, ChangeStateTest) {
    auto param = GetParam();

    fsm.change(param.first);
    EXPECT_EQ(fsm.current_state, param.first);

    fsm.change(param.second);
    EXPECT_EQ(fsm.current_state, param.second);
}

TEST_P(FSMToggleTest, HasStateTest) {
    auto param = GetParam();

    EXPECT_TRUE(fsm.has_state(param.first));
    EXPECT_TRUE(fsm.has_state(param.second));
    EXPECT_FALSE(fsm.has_state("undefined_state"));
}

INSTANTIATE_TEST_SUITE_P(
        FSMTests,
        FSMToggleTest,
        ::testing::Values(
                std::make_pair("on", "off"),
                std::make_pair("off", "on")
        )
);


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}