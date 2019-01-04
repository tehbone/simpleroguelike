/*
 * Copyright 2019 Tabari Alexander
 */
#ifndef MAP_HPP_
#define MAP_HPP_
#include <optional>
#include <vector>

#include <libtcod/libtcod.hpp>

class map {
    struct map_tile {
        bool blocked;
        std::optional<bool> block_sight;
    };

    const TCODColor WALL_COLOR;
    const TCODColor FLOOR_COLOR;
    const int width;
    const int height;

    std::vector<map_tile> tiles;

public:
    map(int width, int height)
        : width(width), height(height), WALL_COLOR(0, 0, 100),
          FLOOR_COLOR(50, 50, 150)
    {
        tiles.reserve(height * width);
        // this is not the right location, but whatever.
        tiles[22*width + 30].blocked = true;
        tiles[22*width + 30].block_sight = true;
        tiles[22*width + 50].blocked = true;
        tiles[22*width + 50].block_sight= true;
    }

    bool blocked(int x, int y) const
    {
        return tiles[y*width + x].blocked;
    }

    void draw(TCODConsole &console)
    {
        for (auto j = 0; j < height; ++j)
            for (auto i = 0; i < width; ++i)
                if (tiles[j*width + i].block_sight.value_or(false))
                    console.setCharBackground(i, j, WALL_COLOR, TCOD_BKGND_SET);
                else
                    console.setCharBackground(i, j, FLOOR_COLOR, TCOD_BKGND_SET);
    }
};
#endif /* MAP_HPP_ */
