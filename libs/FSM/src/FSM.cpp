#include "FSM/FSM.h"

FSM::FSM() = default;

void FSM::update() {
    if(!current_state.empty() && states[current_state].update != nullptr) {
        states[current_state].update();
    } else {
        throw std::runtime_error("Update() called on FSM without an active state");
    }
}

void FSM::register_state(const std::string& name, const State& state) {
    states[name] = state;
}

void FSM::unregister(const std::string& name) {
    states.erase(name);
}

bool FSM::has_state(const std::string& name) const {
    return states.find(name) != states.end();
}

State FSM::change(const std::string& state_name) {
    if(!current_state.empty() && states[current_state].exit != nullptr) {
        states[current_state].exit();
    }

    if(!has_state(state_name)) {
        throw std::runtime_error("Error: FSM object is attempting to switch to an invalid / undefined state: " + state_name);
    }

    current_state = state_name;

    if(!current_state.empty() && states[current_state].enter != nullptr) {
        states[current_state].enter();
    }

    return states[current_state];
}