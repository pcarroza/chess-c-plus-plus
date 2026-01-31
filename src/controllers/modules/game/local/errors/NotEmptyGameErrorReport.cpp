#include "controllers/modules/game/local/errors/NotEmptyGameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    NotEmptyGameErrorReport::NotEmptyGameErrorReport() 
        : GameErrorReport("The origin coordinate is empty.") {}
}
