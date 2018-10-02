/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_INGAME_SCREEN_H
#define SOCIETY_RHYTHM_INGAME_SCREEN_H

#include "../game.h"

namespace society_rhythm
{
	class InGameScreen : public ionicengine::Screen
	{
	private:
		Game *game;
		bool timeToUpdate;
		int updates;

	public:
		explicit InGameScreen(Game *game);

		void init() override;

		void draw(ionicengine::Graphics *graphics) override;

		void update() override;
	};
}

#endif //SOCIETY_RHYTHM_INGAME_SCREEN_H