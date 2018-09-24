/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of Society Rhythm.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../include/society_rhythm/game.h"
#include "../include/society_rhythm/screens/debug_overlay.h"
#include "../include/society_rhythm/screens/starting_screen.h"
#include "../include/society_rhythm/screens/main_menu_screen.h"

#include <ionicengine/ionicengine.h>
#include <discord_rpc.h>
#include <iostream>

namespace society_rhythm
{
	void Game::init()
	{
		ionicengine::IonicOptions ionicOptions;
		ionicOptions.debug = true;
		if (!ionicengine::init(ionicOptions))
			exit(1);

		ionicengine::WindowOptions options;
		options.context_version_major = 3;
		options.context_version_minor = 3;
		options.opengl_profile = GLFW_OPENGL_CORE_PROFILE;
#ifdef LAMBDA_MAC_OSX
		options.opengl_forward_compat = true;
#endif
		window = ionicengine::window::createWindow(u8"Society Rhythm", 800, 600, options);
		window.requestContext();
		window.initContext();

		auto font = ionicengine::getFontManager()->loadFont(SR_FONT_ROBOTO, std::string{"Roboto.ttf"}, 14);
		if (!font)
		{
			shutdown();
			exit(1);
		}

		screens.registerOverlay(SR_DEBUG_OVERLAY, new DebugOverlay(this));
		screens.addActiveOverlay(SR_DEBUG_OVERLAY);

		screens.registerScreen(SR_SCREEN_STARTING, new StartingScreen(this));
		screens.registerScreen(SR_SCREEN_MAIN_MENU, new MainMenuScreen(this));
		changeScreen(SR_SCREEN_STARTING);

		ionicengine::getGraphicsManager()->init();

		screens.attachWindow(window);

		DiscordEventHandlers handlers{};
		handlers.ready = [](const DiscordUser *request)
		{
			std::cout << "[DiscordRPC] Discord Rich Presence is ready." << std::endl;
		};
		handlers.errored = [](int errorCode, const char *message)
		{
			std::cout << "[DiscordRPC][Error " << std::to_string(errorCode) << "] " << message << std::endl;
		};
		handlers.disconnected = [](int errorCode, const char *message)
		{
			std::cout << "[DiscordRPC][Disconnected " << std::to_string(errorCode) << "] " << message << std::endl;
		};
		handlers.joinGame = [](const char *joinSecret) {};
		handlers.spectateGame = [](const char *spectateSecret) {};
		handlers.joinRequest = [](const DiscordUser *request) {};

		Discord_Initialize("492038277302452244", &handlers, 0, nullptr);

		screens.startLoop();
	}

	void Game::shutdown()
	{
		Discord_Shutdown();
		ionicengine::shutdown();
	}

	const ionicengine::ScreenManager &Game::getScreens() const
	{
		return screens;
	}

	const ionicengine::Window &Game::getWindow() const
	{
		return window;
	}

	const lambdacommon::ResourceName &Game::getCurrentScreen() const
	{
		return currentScreen;
	}

	void Game::changeScreen(const lambdacommon::ResourceName &name)
	{
		currentScreen = name;
		screens.setActiveScreen(name);
		updateRichPresence();
	}

	void Game::updateRichPresence() const
	{
		DiscordRichPresence discordPresence{nullptr};
		if (currentScreen == SR_SCREEN_MAIN_MENU)
		{
			discordPresence.state = "In main menu.";
			discordPresence.details = "";
		}
		else if (currentScreen == SR_SCREEN_INGAME)
		{
			discordPresence.state = "Playing";
			discordPresence.details = "";
			//discordPresence.startTimestamp = 1507665886;
			//discordPresence.endTimestamp = 1600000000;
		}
		else
		{
			discordPresence.state = "/shrug";
			discordPresence.details = "We do not have details for this";
		}
		//discordPresence.largeImageText = "";
		//discordPresence.smallImageText = "";
		discordPresence.instance = false;
		Discord_UpdatePresence(&discordPresence);
	}
}