/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/society_rhythm/screens/main_menu_screen.h"

namespace society_rhythm
{
	MainMenuScreen::MainMenuScreen(Game *game) : game(game)
	{}

	void MainMenuScreen::init()
	{
		x = (width / 2) - (buttonsWidth / 2);
		y = (height / 2) - (((24 + 2) * centeredComponentsCount) / 2);
		auto playButton = new ionicengine::GuiButton(x, y + 2, buttonsWidth, 24, "Play");
		playButton->setFont(ionicengine::getFontManager()->getFont(SR_FONT_ROBOTO));
		components.push_back(playButton);
		auto creditsButton = new ionicengine::GuiButton(x, y + playButton->height + 7, buttonsWidth, 24, "Credits");
		creditsButton->setFont(ionicengine::getFontManager()->getFont(SR_FONT_ROBOTO));
		components.push_back(creditsButton);
		auto quitButton = new ionicengine::GuiButton(x, y + playButton->height + 7 + creditsButton->height + 5, buttonsWidth, 24, "Quit");
		quitButton->setClickListener([](ionicengine::Window &window) { window.setShouldClose(true); });
		quitButton->setFont(ionicengine::getFontManager()->getFont(SR_FONT_ROBOTO));
		components.push_back(quitButton);
	}

	void MainMenuScreen::draw(ionicengine::Graphics *graphics)
	{
		graphics->drawImage(SR_MAIN_MENU_BACKGROUND_RES, 0, 0, width, height);
		graphics->setColor({0.f, 0.f, 0.f, .25f});
		graphics->drawQuad(x - 10, y - 8, buttonsWidth + 20, static_cast<uint32_t>((24 + 5) * centeredComponentsCount) + 16);
		Screen::draw(graphics);
	}

	void MainMenuScreen::update()
	{
		Screen::update();
	}
}