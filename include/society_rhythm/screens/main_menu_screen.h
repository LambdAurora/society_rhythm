/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_MAIN_MENU_SCREEN_H
#define SOCIETY_RHYTHM_MAIN_MENU_SCREEN_H

#include "../game.h"

namespace society_rhythm
{
	class MainMenuScreen : public ionicengine::Screen
	{
	private:
		Game *game;
		uint32_t buttonsWidth = 150;
		int x = 0, y = 0;
		int centeredComponentsCount = 3;

	public:
		MainMenuScreen(Game *game);

		void init() override;

		void draw(ionicengine::Graphics *graphics) override;

		void update() override;
	};
}

#endif //SOCIETY_RHYTHM_MAIN_MENU_SCREEN_H
