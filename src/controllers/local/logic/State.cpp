#include "controllers/local/logic/State.hpp"

namespace controllers::local::logic
{
    State::State(StateBuilder *stateBuilder) : stateBuilder(stateBuilder)
    {
    }

    State *State::initialize()
    {
        assert(false && "initialize() not implemented");
        return nullptr;
    }

    State *State::begin()
    {
        assert(false && "begin() not implemented");
        return nullptr;
    }

    State *State::finalize()
    {
        assert(false && "finalize() not implemented");
        return nullptr;
    }

    State *State::end()
    {
        assert(false && "end() not implemented");
        return nullptr;
    }
}
