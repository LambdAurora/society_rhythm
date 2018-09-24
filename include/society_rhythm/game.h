/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_GAME_H
#define SOCIETY_RHYTHM_GAME_H

#include "constants.h"
#include <ionicengine/graphics/screen.h>

namespace society_rhythm
{
	class Game
	{
	private:
		ionicengine::ScreenManager screens{};
		ionicengine::Window window{nullptr};
		lambdacommon::ResourceName currentScreen = SR_SCREEN_STARTING;

	public:
		void init();

		void shutdown();

		const ionicengine::ScreenManager &getScreens() const;

		const ionicengine::Window &getWindow() const;

		const lambdacommon::ResourceName &getCurrentScreen() const;

		void changeScreen(const lambdacommon::ResourceName& name);

		void updateRichPresence() const;
	};
}

#endif //SOCIETY_RHYTHM_GAME_H