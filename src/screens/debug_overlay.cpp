/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/society_rhythm/screens/debug_overlay.h"

namespace society_rhythm
{
	DebugOverlay::DebugOverlay(Game *game) : game(game)
	{}

	void DebugOverlay::init()
	{
	}

	void DebugOverlay::draw(ionicengine::Graphics *graphics)
	{
		Overlay::draw(graphics);
		auto font = *ionicengine::getFontManager()->getFont(SR_FONT_ROBOTO);
		auto fpsText = "FPS: " + std::to_string(game->getScreens().getFPS());
		auto currentScreenText = "Current screen: '" + game->getCurrentScreen().toString() + "'";
		graphics->setColor({0.f, 0.f, 0.f , .25f});
		graphics->drawQuad(2, 1, font.getTextLength(fpsText), font.getHeight() + 1);
		graphics->drawQuad(2, 3 + font.getHeight(), font.getTextLength(currentScreenText), font.getHeight() + 1);
		graphics->setColor(lambdacommon::Color::COLOR_WHITE);
		graphics->drawText(font, 2, 4, fpsText);
		graphics->drawText(font, 2, 6 + font.getHeight(), currentScreenText);
	}

	void DebugOverlay::update()
	{
		Overlay::update();
	}
}