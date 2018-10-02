/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_STARTING_SCREEN_H
#define SOCIETY_RHYTHM_STARTING_SCREEN_H

#include "../game.h"

namespace society_rhythm
{
	class StartingScreen : public ionicengine::Screen
	{
	private:
		Game *game;
		std::string loading = "Loading...";
		std::string warning = std::string("\t\t\t\t\t\t\t\tWARNING:\n")
										+ "This game is not suitable for children or those who are easily disturbed.";
		bool warningDisplay = true;
		int counter = 0;
		float opacity = 1.f;
		bool warningFinished = false;

	public:
		explicit StartingScreen(Game *game);

		void init() override;

		void draw(ionicengine::Graphics *graphics) override;

		void update() override;
	};
}

#endif //SOCIETY_RHYTHM_STARTING_SCREEN_H