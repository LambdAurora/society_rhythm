/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/society_rhythm/game/level.h"

namespace society_rhythm
{
	lambdacommon::Color Level::getBackgroundColor() const
	{
		if (json)
		{
			auto backgroundJson = json["background"];
			if (backgroundJson)
				return lambdacommon::color::fromHex(backgroundJson.get<std::string>());
		}
		return lambdacommon::Color::COLOR_BLACK;
	}

	void Level::start()
	{
		state = 0;
	}

	void Level::render(ionicengine::Graphics *graphics)
	{
		graphics->setColor(getBackgroundColor());
		graphics->drawQuad(0, 0, graphics->getWidth(), graphics->getHeight());
		for (auto &sA : staticAnimations)
			sA.render(graphics);
	}

	void Level::update()
	{

	}
}