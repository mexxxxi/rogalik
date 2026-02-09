/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Inventory.c         *       Authors - mexxxxi                 *
 *          *    08.02.2026          *                                         *
*******************************************************************************/


#include "include/Inventory.h"

Inventory new_inventory(void) {
    Item item = {"", ITEM_TYPE_VOID, ITEM_CLASS_VOID};

    Inventory inv = {SIZE_INVENTORY, NULL, item, item};
    inv.data = (Item *)malloc(sizeof(Item) * SIZE_INVENTORY);

    return inv;
}

void inventory_sort(Inventory *inv) {
    unsigned int i, j;
    for (i = 0; i < SIZE_INVENTORY - 1; i++) {
        int flag = 0;

        for (j = 0; j < SIZE_INVENTORY - i - 1; j++) {
            if (inv->data[j].type < inv->data[j+1].type) {
                Item temp = inv->data[j];
                inv->data[j] = inv->data[j+1];
                inv->data[j+1] = temp;
                flag = 1;
            }
        }
        
        if (!flag) break;
    }
}

void inventory_add_item(Inventory *inv, Item item) {
    if (inv->size >= SIZE_INVENTORY)
        return;

    inventory_sort(inv);

    inv->data[inv->size] = item;
    inv->size++;
}
