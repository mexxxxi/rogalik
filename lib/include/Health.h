/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Health.h            *       Authors - mexxxxi                 *
 *          *    07.02.2026          *                                         *
*******************************************************************************/


#ifndef HEALTH_H
#define HEALTH_H


typedef struct {
    /* что-то */
} Buff;

typedef struct {
    unsigned int hp;
    unsigned int count_buffs;
    Buff *buffs;
} Health;


#endif /* HEALTH_H */
