/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_DEBUG_OVERLAY_H
#define SOCIETY_RHYTHM_DEBUG_OVERLAY_H

#include "../game.h"

namespace society_rhythm
{
	class DebugOverlay : public ionicengine::Overlay
	{
	private:
		Game *game;

	public:
		explicit DebugOverlay(Game *game);

		void init() override;

		void draw(ionicengine::Graphics *graphics) override;

		void update() override;
	};
}

#endif //SOCIETY_RHYTHM_DEBUG_OVERLAY_H