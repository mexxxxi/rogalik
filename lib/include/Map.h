/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Map.h               *       Authors - mexxxxi                 *
 *          *    08.02.2026          *                                         *
*******************************************************************************/


#ifndef MAP_H
#define MAP_H


#define SIZE_MAP_WIDTH   64
#define SIZE_MAP_HEIGHT  64

#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    int        **data;
} Map;

Map map_generation(void);


#endif /* MAP_H */
