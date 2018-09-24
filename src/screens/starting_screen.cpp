/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/society_rhythm/screens/starting_screen.h"
#include <lambdacommon/system/system.h>

namespace society_rhythm
{
	StartingScreen::StartingScreen(Game *game) : game(game)
	{}

	void StartingScreen::init()
	{
		backgroundColor = lambdacommon::Color::COLOR_WHITE;
	}

	void StartingScreen::draw(ionicengine::Graphics *graphics)
	{
		Screen::draw(graphics);
		auto font = ionicengine::getFontManager()->getFont(SR_FONT_ROBOTO);
		auto text = warningFinished ? loading : warning;
		graphics->setColor(lambdacommon::Color::COLOR_BLACK);
		graphics->drawText(*font, ((width / 2) - (font->getTextLength(text) / 2)), ((height / 2) - (font->getHeight() / 2)), text);
		if (warningDisplay)
		{
			opacity -= 0.01f;
			if (opacity < 0.f)
				opacity = 0.f;
		}
		else if (warningFinished)
			opacity = 0.f;
		else
		{
			opacity += 0.01f;
			if (opacity > 1.f)
			{
				opacity = 1.f;
				warningFinished = true;
			}
		}
		graphics->setColor({0.f, 0.f, 0.f, opacity});
		graphics->drawQuad(0, 0, width, height);
	}

	void StartingScreen::update()
	{
		Screen::update();
		if (opacity <= 0.f)
		{
			counter++;
			if (counter == 250)
				warningDisplay = false;
		}
		if (warningFinished)
		{
			// Yes here we will load things because we're dumb
			SR_CHECK_IF_LOADED(game, ionicengine::texture::load(SR_MAIN_MENU_BACKGROUND_RES))
			//SR_CHECK_IF_LOADED(ionicengine::texture::load(SR_SLAUGHTERHOUSE_CONVEYOR_BELT_RES))
			game->changeScreen(SR_SCREEN_MAIN_MENU);
		}
	}
}