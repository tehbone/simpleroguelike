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

    TCODColor WALL_COLOR;
    TCODColor FLOOR_COLOR;
    int width;
    int height;

    std::vector<map_tile> tiles;

    void create_room(int x, int y, int width, int height);
    void create_horizontal_tunnel(int x1, int x2, int y);
    void create_vertical_tunnel(int x, int y1, int y2);

public:
    map(int width, int height)
        : width(width), height(height), WALL_COLOR(0, 0, 100),
          FLOOR_COLOR(50, 50, 150)
    {
        const map_tile model_tile = {
            .blocked = true,
            .block_sight = true,
        };

        tiles.reserve(height * width);
        tiles.assign(height * width, model_tile);
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

    static map generate(int width, int height);
};
#endif /* MAP_HPP_ */
