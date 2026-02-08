#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.h"
#include "Health.h"
#include "Map.h"

typedef enum {
    CLASS_WARRIOR,
    CLASS_MAGE,
    CLASS_ARCHER,
    CLASS_ROGUE,
    CLASS_ENEMY,
} CharacterClass;

typedef struct {
    unsigned int sprite;
    unsigned int x, y;
    unsigned int armor;
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
    Inventory inventory;
    Health health;
    CharacterClass class;
} Character;

Character* create_character(const char* name, CharacterClass class);
void take_damage(Character* character, int damage);
void use_mana(Character* character, int amount);
int is_alive(Character* character);
void heal_hp_character(Character* character, int amount);
void heal_mp_character(Character* character, int amount);
void block_damage(Character* character, int amount);
void show_status(const Character* character);
void gain_xp(Character* character, int xp_amount);
void level_up(Character* character);
void attack_target(Character* attacker, Character* target);
void destroy_character(Character* character);
Character* create_goblin();
Character* create_skeleton_mage();
Character* create_big_rat();
Character* create_slime();
Character* get_random_enemy(int player_level);
void clear_screen();
void start_battle(Character* player);
int get_choice();
void show_interface();
void game_started(Character* player);
void start_game(Character* player);

void character_move(Character *ent, Map *map, int ch);

void show_new_game();
void show_load_game();
void create_new_character();

#endif
