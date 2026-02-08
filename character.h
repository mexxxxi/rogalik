
#ifndef CHARACTER_H
#define CHARACTER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    CLASS_WARRIOR,
    CLASS_MAGE,
    CLASS_ARCHER,
    CLASS_ROGUE,
} CharacterClass;

typedef struct {
    char name[50];
    int heat_point;
    int max_heat_point;
    int mana_point;
    int max_mana_point;
    int attack;
    int defense;
    int level;
    int experience;
    int is_enemy;
    CharacterClass class;
} Character;

Character* create_character(const char* name, CharacterClass class);
void take_damage(Character* character, int damage);
void use_mana(Character* character, int amount);
int  is_alive(Character* character);
void heal_hp_character(Character* character, int amount);
void heal_mp_character(Character* character, int amount);
void block_damage(Character* character, int amount);
void show_status(const Character* character);
void gain_xp(Character* character, int xp_amount);
void level_up(Character* character);
void attack_target(Character* attacker, Character* target);
void destroy_character(Character* character);



#endif


