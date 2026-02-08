/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Map.h               *       Authors - mexxxxi                 *
 *          *    08.02.2026          *                                         *
*******************************************************************************/


#ifndef MAP_H
#define MAP_H


#define SIZE_MAP_WIDTH      64
#define SIZE_MAP_HEIGHT     64

#define SIZE_SCREEN_WIDTH   64
#define SIZE_SCREEN_HEIGHT  24

#include <stdlib.h>
#include <time.h>

typedef enum {
    DIRECTION_TOP,
    DIRECTION_BOTTOM,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} Direction;

typedef struct {
    unsigned int x, y;
    unsigned int width;
    unsigned int height;
    Direction    direction_door;
} Room;

typedef struct {
    unsigned int width;
    unsigned int height;
    int        **data;
} Map;

Map map_generation(void);

Room room_generation(void);


#endif /* MAP_H */
