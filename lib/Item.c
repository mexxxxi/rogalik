/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Item.c              *       Authors - mexxxxi                 *
 *          *    08.02.2026          *                                         *
*******************************************************************************/


#include "include/Item.h"

Item new_item(char *name, ItemType type, ItemClass class, ...) {
    Item item = {.type = type, .class = class};
    strncpy(item.name, name, 63);
    item.name[63] = '\0';
    
    if (type != ITEM_TYPE_VOID) {
        va_list start;
        va_start(start, class);

        switch (type) {
            case ITEM_TYPE_WEAPON:
                item.info.weapon = va_arg(start, Weapon);
                break;
            case ITEM_TYPE_CLOTHES:
                item.info.clothes = va_arg(start, Clothes);
                break;
        }
        va_end(start);
    }

    return item;
}

Weapon new_item_weapon(unsigned int damage) {
    Weapon w = {damage};

    return w;
}

Clothes new_item_clothes(ClothesType type, unsigned int armor) {
    Clothes c = {type, armor};

    return c;
}
