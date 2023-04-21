#ifndef TEST_TILEMAP_H
#define TEST_TILEMAP_H

#include "test_sprite_exp.h"
#include <vector>


class test_tilemap
{
    public:
        test_tilemap();
        virtual ~test_tilemap();


        std::vector<std::vector<test_sprite_exp>> tilemap;


    protected:

    private:
};

#endif // TEST_TILEMAP_H
