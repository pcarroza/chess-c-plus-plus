#include "controllers/modules/game/local/errors/NotPropertyGameErrorReport.hpp"

namespace controllers::modules::game::local::errors
{
    NotPropertyGameErrorReport::NotPropertyGameErrorReport() 
        : GameErrorReport("The piece at the origin does not belong to the current player.") {}
}
