#include "controllers/modules/game/local/errors/RepeatedCoordinateGameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    RepeatedCoordinateGameErrorReport::RepeatedCoordinateGameErrorReport() 
        : GameErrorReport("The origin and destination coordinates are the same.") {}
}
