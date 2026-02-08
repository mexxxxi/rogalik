/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Inventory.h         *       Authors - mexxxxi                 *
 *          *    07.02.2026          *                                         *
*******************************************************************************/


#ifndef INVENTORY_H
#define INVENTORY_H


#define SIZE_INVENTORY 24 

#include <stdlib.h>
#include <stddef.h>

#include "Item.h"

typedef struct {
    unsigned int size;
    Item *data;
    Item  weapon_slot;
    Item  clothes_slot;
} Inventory;


Inventory new_inventory(void);

void inventory_sort(Inventory *inv);
void inventory_add_item(Inventory *inv, Item item);
void inventory_remove_item(Inventory *inv);
Item inventory_get_item(Inventory *inv);


#endif /* INVENTORY_H */
