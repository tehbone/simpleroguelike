/*
 * Copyright 2019 Tabari Alexander
 */
#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include <libtcod/libtcod.hpp>

class entity {
    char symbol;
    int x;
    int y;
    TCODColor color;

public:
    entity(int x, int y, char symbol, TCODColor color = TCODColor::white)
        : x(x), y(y), symbol(symbol), color(color)
    {
    }

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    void draw(TCODConsole &con)
    {
        con.setDefaultForeground(color);
        con.putChar(x, y, symbol, TCOD_BKGND_NONE);
    }

    void clear(TCODConsole &con)
    {
        con.putChar(x, y, ' ', TCOD_BKGND_NONE);
    }
};
#endif
