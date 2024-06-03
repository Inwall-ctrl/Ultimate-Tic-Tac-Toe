#ifndef __Core__
#define __Core__

#include <map>
#include <functional>
#include <stdexcept>
#include <string>

class State {
public:
    std::function<void()> enter;
    std::function<void()> update;
    std::function<void()> exit;
};

class FSM {
public:
    std::string current_state;
    std::map<std::string, State> states;

    FSM();

    void update();

    void register_state(const std::string& name, const State& state);

    void unregister(const std::string& name);

    bool has_state(const std::string& name) const;

    State change(const std::string& state_name);
};


#endif
