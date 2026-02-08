/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Entity.h            *       Authors - mexxxxi                 *
 *          *    07.02.2026          *                                         *
*******************************************************************************/

#ifndef ENTITY_H
#define ENTITY_H

#include "Inventory.h"
#include "Health.h"


typedef enum {
    ENTITY_CLASS_WARRIOR,
    ENTITY_CLASS_MAGE,
    ENTITY_CLASS_ARCHER,
    ENTITY_CLASS_ROGUE
} EntityClass;

typedef struct {
    unsigned int sprite;
    unsigned int x, y;
    unsigned int armor;
    
    Inventory inventory;
    Health    health;
} Entity;


Entity new_entity(void);


#endif /* ENTITY_H */
