#ifndef GAME_ERROR_TYPE_HPP
#define GAME_ERROR_TYPE_HPP

namespace controllers::modules::game::local::errors
{
    enum class GameErrorType
    {
        NOT_EMPTY,
        REPEATED_COORDINATE,
        NOT_PROPERTY
    };
}

#endif