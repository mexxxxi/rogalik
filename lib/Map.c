/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Map.c               *       Authors - mexxxxi                 *
 *          *    08.02.2026          *                                         *
*******************************************************************************/


#include "include/Map.h"

Map map_generation(void) {
    Map map;
    unsigned int count_rooms;

    srand(time(NULL));

    count_rooms = rand() % 5 + 5;

    return map;
}

static Room room_generation(void) {
    srand(time(NULL));
    
    Room room = {
            rand() % (SIZE_MAP_WIDTH - 32), 
            rand() % (SIZE_MAP_HEIGHT - 32),
            rand() % 15 + 5,
            rand() % 15 + 5,
            rand() % 4
    };

    return room;
}
