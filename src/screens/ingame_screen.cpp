/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/society_rhythm/screens/ingame_screen.h"

namespace society_rhythm
{
	InGameScreen::InGameScreen(Game *game) : game(game)
	{}

	void InGameScreen::init()
	{
		updates = 0;
	}

	void InGameScreen::draw(ionicengine::Graphics *graphics)
	{
		Screen::draw(graphics);
		auto font = ionicengine::getFontManager()->getFont(SR_FONT_ROBOTO);
		auto text = "Updates: " + std::to_string(updates);
		graphics->setColor(lambdacommon::Color::COLOR_WHITE);
		graphics->drawText(*font, ((width / 2) - (font->getTextLength(text) / 2)),
						   ((height / 2) - (font->getHeight() / 2)), text);
	}

	void InGameScreen::update()
	{
		Screen::update();
		if (timeToUpdate)
			updates++;
		timeToUpdate = !timeToUpdate;
	}
}