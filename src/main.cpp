/*
 * Copyright 2019 Tabari Alexander
 */
#include <libtcod/libtcod.hpp>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 50;
const int LIMIT_FPS = 20;

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

    TCODConsole::setCustomFont("arial10x10.png",
        TCOD_FONT_TYPE_GREYSCALE | TCOD_FONT_LAYOUT_TCOD);
    TCODConsole::initRoot(SCREEN_WIDTH, SCREEN_HEIGHT, "SimpleRogueLike", false,
        TCOD_RENDERER_SDL2);
    TCODSystem::setFps(LIMIT_FPS);
    while (!TCODConsole::isWindowClosed()) {
        TCODConsole::root->setDefaultForeground(TCODColor::white);
        TCODConsole::root->putChar(1, 1, '@', TCOD_BKGND_NONE);
        TCODConsole::flush();
    }

    return 0;
}
