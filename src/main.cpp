/*
 * Copyright 2019 Tabari Alexander
 */
#include <functional>
#include <list>
#include <libtcod/libtcod.hpp>

#include "entity.hpp"
#include "map.hpp"

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 50;
const int LIMIT_FPS = 20;

static bool handle_keys(entity &player, map &m)
{
    int dx = 0;
    int dy = 0;
    TCODConsole::waitForKeypress(true);
    if (TCODConsole::isKeyPressed(TCODK_ESCAPE))
        return true;
    if (TCODConsole::isKeyPressed(TCODK_UP))
        dy = -1;
    else if (TCODConsole::isKeyPressed(TCODK_DOWN))
        dy = 1;
    if (TCODConsole::isKeyPressed(TCODK_LEFT))
        dx = -1;
    else if (TCODConsole::isKeyPressed(TCODK_RIGHT))
        dx = 1;

    player.move(dx, dy, m);
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

    std::list<std::reference_wrapper<entity>> entities;
    entity player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, '@', TCODColor::white);
    entity npc(SCREEN_WIDTH/2 - 5, SCREEN_HEIGHT/2, '@', TCODColor::yellow);
    map level(80, 45);
    TCODConsole console(SCREEN_WIDTH, SCREEN_HEIGHT);

    entities.push_back(player);
    entities.push_back(npc);

    TCODConsole::setCustomFont("arial10x10.png",
        TCOD_FONT_TYPE_GREYSCALE | TCOD_FONT_LAYOUT_TCOD);
    TCODConsole::initRoot(SCREEN_WIDTH, SCREEN_HEIGHT, "SimpleRogueLike", false,
        TCOD_RENDERER_SDL2);
    TCODSystem::setFps(0); // not real time
    while (!TCODConsole::isWindowClosed()) {
        level.draw(console);
        for (entity &ent: entities)
            ent.draw(console);

        TCODConsole::blit(&console, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
            TCODConsole::root, 0, 0);
        TCODConsole::flush();
        // Clear the player's old position
        for (entity &ent: entities)
            ent.clear(console);

        if (handle_keys(player, level))
            break;
    }

    return 0;
}
