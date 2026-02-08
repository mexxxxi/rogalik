/*******************************************************************************
 *          *    project - rogalik   *                                         *
 *          *    Item.h              *       Authors - mexxxxi                 *
 *          *    07.02.2026          *                                         *
*******************************************************************************/


#ifndef ITEM_H
#define ITEM_H


#include <stdarg.h>
#include <string.h>

typedef struct {
    unsigned int damage;
} Weapon;

typedef enum {
    CLOTHES_TYPE_HEAD,
    CLOTHES_TYPE_BODY,
    CLOTHES_TYPE_LEGS
} ClothesType;

typedef struct {
    ClothesType  type;
    unsigned int armor;
} Clothes;

typedef struct {
    /* это зелье */
} Potion;

typedef enum {
    ITEM_TYPE_VOID,
    ITEM_TYPE_WEAPON,
    ITEM_TYPE_CLOTHES,
    ITEM_TYPE_POTION
} ItemType;

typedef enum {
    ITEM_CLASS_VOID,
    ITEM_CLASS_WARRIOR,
    ITEM_CLASS_MAGE,
    ITEM_CLASS_ARCHER,
    ITEM_CLASS_ROGUE
} ItemClass;

typedef union {
    Weapon  weapon;
    Clothes clothes;
} ItemInfo;

typedef struct {
    char      name[64];
    ItemType  type;
    ItemClass class;
    ItemInfo  info;
} Item;


Item new_item(char *name, ItemType type, ItemClass class, ...);

Weapon  new_item_weapon(unsigned int damage);
Clothes new_item_clothes(ClothesType type, unsigned int armor);


#endif /* ITEM_H */

