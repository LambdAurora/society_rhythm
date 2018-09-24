/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_CONSTANTS_H
#define SOCIETY_RHYTHM_CONSTANTS_H

#include <lambdacommon/resources.h>

#define SR_SCREEN_STARTING lambdacommon::ResourceName("society_rhythm:screens/starting")
#define SR_SCREEN_MAIN_MENU lambdacommon::ResourceName("society_rhythm:screens/main_menu")
#define SR_SCREEN_OPTIONS lambdacommon::ResourceName("society_rhythm:screens/options")
#define SR_SCREEN_CREDITS lambdacommon::ResourceName("society_rhyhtm:screens/credits")
#define SR_SCREEN_INGAME lambdacommon::ResourceName("society_rhythm:screens/ingame")

#define SR_DEBUG_OVERLAY lambdacommon::ResourceName("society_rhythm:screens/overlays/debug")

#define SR_FONT_ROBOTO lambdacommon::ResourceName("google:fonts/roboto")

#define SR_MAIN_MENU_BACKGROUND_RES lambdacommon::ResourceName("society_rhythm:textures/main_menu_background")
#define SR_SLAUGHTERHOUSE_CONVEYOR_BELT_RES lambdacommon::ResourceName("society_rhythm:textures/conveyor_belt/slaughter_house")

#define SR_CHECK_IF_LOADED(game, x) if (!x) { game->shutdown(); exit(1); }

#endif //SOCIETY_RHYTHM_CONSTANTS_H
