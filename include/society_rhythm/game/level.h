/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef SOCIETY_RHYTHM_LEVEL_H
#define SOCIETY_RHYTHM_LEVEL_H

#include "../game.h"
#include <ionicengine/graphics/animation.h>
#include <nlohmann/json.hpp>

namespace society_rhythm
{
	class Level
	{
	private:
		lambdacommon::ResourceName &resourceName;
		nlohmann::json json;
		int state = 0;
		std::vector<ionicengine::BitmapAnimation> staticAnimations;

	public:
		lambdacommon::Color getBackgroundColor() const;

		void start();

		void render(ionicengine::Graphics *graphics);

		void update();
	};
}

#endif //SOCIETY_RHYTHM_LEVEL_H