/*
 * Copyright 2019 Tabari Alexander
 */
#include <algorithm>
#include <utility>
#include "map.hpp"

void map::create_room(int x, int y, int w, int h)
{
    for (auto j = y; j <= y + h; ++j) {
        for (auto i = x; i <= x + w; ++i) {
            tiles[j*width + i].blocked = false;
            tiles[j*width + i].block_sight = false;
        }
    }
}

void map::create_horizontal_tunnel(int x1, int x2, int y)
{
    int end = std::max(x1, x2);
    for (auto i = std::min(x1, x2); i <= end; ++i) {
        tiles[y*width + i].blocked = false;
        tiles[y*width + i].block_sight = false;
    }
}
void map::create_vertical_tunnel(int x, int y1, int y2)
{
    int end = std::max(y1, y2);
    for (auto i = std::min(y1, y2); i <= end; ++i) {
        tiles[i*width + x].blocked = false;
        tiles[i*width + x].block_sight = false;
    }
}
map map::generate(int width, int height)
{
    map new_map(width, height);
    new_map.create_room(20, 15, 10, 15);
    new_map.create_room(50, 15, 10, 15);
    new_map.create_horizontal_tunnel(25, 55, 23);
    return std::move(new_map);
}
