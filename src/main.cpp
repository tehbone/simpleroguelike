/*
 * Copyright 2019 Tabari Alexander
 */
#include <libtcod/libtcod.hpp>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 50;
const int LIMIT_FPS = 20;

int player_x = SCREEN_WIDTH / 2;
int player_y = SCREEN_HEIGHT / 2;

static bool handle_keys()
{
    TCODConsole::waitForKeypress(true);
    if (TCODConsole::isKeyPressed(TCODK_ESCAPE))
        return true;
    if (TCODConsole::isKeyPressed(TCODK_UP))
        player_y--;
    else if (TCODConsole::isKeyPressed(TCODK_DOWN))
        player_y++;
    else if (TCODConsole::isKeyPressed(TCODK_LEFT))
        player_x--;
    else if (TCODConsole::isKeyPressed(TCODK_RIGHT))
        player_x++;
    return false;
}

/**
 * The main function.
 * @param argc Count of arguments
 * @param argv The arguments. Currently unused.
 *
 * @return 0
 */
int main(int argc, char *argv[])
{
    // "Use" the arguments.
    (void)argc;
    (void)argv;
    TCODConsole console(SCREEN_WIDTH, SCREEN_HEIGHT);

    TCODConsole::setCustomFont("arial10x10.png",
        TCOD_FONT_TYPE_GREYSCALE | TCOD_FONT_LAYOUT_TCOD);
    TCODConsole::initRoot(SCREEN_WIDTH, SCREEN_HEIGHT, "SimpleRogueLike", false,
        TCOD_RENDERER_SDL2);
    TCODSystem::setFps(0); // not real time
    while (!TCODConsole::isWindowClosed()) {
        console.setDefaultForeground(TCODColor::white);
        console.putChar(player_x, player_y, '@', TCOD_BKGND_NONE);
        TCODConsole::blit(&console, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
            TCODConsole::root, 0, 0);
        TCODConsole::flush();
        // Clear the player's old position
        console.putChar(player_x, player_y, ' ', TCOD_BKGND_NONE);
        if (handle_keys())
            break;
    }

    return 0;
}
