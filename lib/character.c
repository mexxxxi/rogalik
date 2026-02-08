#include "include/character.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct {
    int max_hp;
    int max_mp;
    int attack;
    int defense;
    const char* class_name;
}ClassInfo;


static const ClassInfo class_data[] = {
    //WARRIOR
    {200, 0, 30, 10, "Воин"},
    //MAGE
    {100, 200, 10, 0, "Маг"},
    //ARCHER
    {150, 50, 20, 5, "Лучник"},
    //ROGUE
    {120, 70, 30, 5, "Разбойник"},
    //ENEMY
    {0, 0, 0, 0, "Существо"},
};

Character* create_character(const char* name, CharacterClass class) {
    Character* character = malloc(sizeof(Character));
    if(!character) {
        printf("error");
        return NULL;
    }
    strncpy(character->name, name, 49);
    character->name[49] = '\0';
    character->is_enemy = 0;
    character->class = class;
    character->max_heat_point = class_data[class].max_hp;
    character->heat_point = character->max_heat_point;
    character->max_mana_point = class_data[class].max_mp;
    character->mana_point = character->max_mana_point;
    character->attack = class_data[class].attack;
    character->defense = class_data[class].defense;
    character->level = 1;
    character->experience = 0;
    printf("Персонаж '%s' создан! Класс: %s\n",
            character->name, class_data[class].class_name);

    return character;
}

Character* create_goblin() {
    Character* goblin = create_character("Гоблин", CLASS_ENEMY);
    goblin->is_enemy = 1;
    goblin->max_heat_point = 100;
    goblin->heat_point = goblin->max_heat_point;
    goblin->max_mana_point = 0;
    goblin->mana_point = goblin->max_mana_point;
    goblin->attack = 30;
    goblin->defense = 0;
    goblin->level = 1;
    return goblin;
}

Character* create_skeleton_mage() {
    Character* skeleton = create_character("Скелет-маг", CLASS_ENEMY);
    skeleton->is_enemy = 1;
    skeleton->max_heat_point = 50;
    skeleton->heat_point = skeleton->max_heat_point;
    skeleton->max_mana_point = 100;
    skeleton->mana_point = skeleton->max_mana_point;
    skeleton->attack = 10;
    skeleton->defense = 0;
    skeleton->level = 1;
    return skeleton;
}

Character* create_big_rat() {
    Character* rat = create_character("Гиганская крыса", CLASS_ENEMY);
    rat->is_enemy = 1;
    rat->max_heat_point = 70;
    rat->heat_point = rat->max_heat_point;
    rat->max_mana_point = 30;
    rat->mana_point = rat->max_mana_point;
    rat->attack = 20;
    rat->defense = 0;
    rat->level = 1;
    return rat;
}

Character* create_slime() {
    Character* slime = create_character("Сгусток слизи", CLASS_ENEMY);
    slime->is_enemy = 1;
    slime->max_heat_point = 50;
    slime->heat_point = slime->max_heat_point;
    slime->max_mana_point = 50;
    slime->mana_point = slime->max_mana_point;
    slime->attack = 15;
    slime->defense = 0;
    slime->level = 1;
    return slime;
}


void take_damage(Character* character, int damage) {
    if(!character || damage <= 0) return;

    int actual_damage = damage - character->defense;
    if(actual_damage < 1) actual_damage = 1;
    
    character->heat_point -= actual_damage;
    
    if(character->heat_point < 0) character->heat_point = 0;
    if(character->heat_point == 0) {
        printf("%s Погиб...\n", character->name);
    } else {
        printf("%s получает %d урона! Осталось HP: %d/%d\n",
               character->name, actual_damage, 
               character->heat_point, 
               character->max_heat_point);
    }
}

void use_mana(Character* character, int amount) {
    if(!character || amount <= 0) return;
    if(character->mana_point >= amount) {
        character->mana_point -= amount;
        printf("%s потратил %d маны Осталось MP: %d/%d\n",
        character->name, amount, character->mana_point,
        character->max_mana_point);
    }else {
        printf("Недостаточно маны!");
    }
}

int is_alive(Character* character) {
    if(!character) return 0;
    return character->heat_point > 0;
}

void heal_hp_character(Character* character, int amount) {
    if (!character || amount <= 0) return;
    int old_hp = character->heat_point;
    character->heat_point += amount;
    if(character->heat_point > character->max_heat_point) {
        character->heat_point = character->max_heat_point;
    }
    printf("%s Восстанавливает %d HP. Текущее HP: %d/%d\n",
    character->name, character->heat_point - old_hp, character->heat_point, character->max_heat_point);
}

void heal_mp_character(Character* character, int amount) {
    if(!character || amount <= 0) return;
    int old_mana = character->mana_point; 
    character->mana_point += amount;
    if(character->mana_point > character->max_mana_point) {
            character->mana_point = character->max_mana_point;
    }  
    printf("%s Восстанавливает %d MP. Текущее MP: %d/%d\n",
        character->name, character->mana_point - old_mana, 
        character->mana_point, character->max_mana_point);
}



void gain_xp(Character* character, int xp_amount) {
    if (!character || xp_amount <= 0) return;
    character->experience += xp_amount;
    printf("%s Получает %d опыта! Всего: %d/%d\n",
        character->name, xp_amount, character->experience, character->level * 100);
        while(character->experience >= character->level * 100) {
            level_up(character);
        }
}

void level_up(Character* character) {
    if(!character) return;

    int needed_xp = character->level * 100;
    character->experience -= needed_xp;
    character->level++;

    switch(character->class) {
        case CLASS_WARRIOR:
            character->max_heat_point += 50;
            character->attack += 20;
            character->defense += 5;
            break;
        case CLASS_MAGE:
            character->max_heat_point += 20;
            character->max_mana_point += 50;
            character->attack += 5;
            character->defense += 1;
            break;
        case CLASS_ARCHER:
            character->max_heat_point += 25;
            character->max_mana_point += 20;
            character->attack += 10;
            character->defense += 2;
            break;
        case CLASS_ROGUE:
            character->max_heat_point += 30;
            character->max_mana_point += 30;
            character->attack += 15;
            character->defense += 1;
            break;
    }
    character->heat_point = character->max_heat_point;
    character->mana_point = character->max_mana_point;
    printf("%s Достиг уровня %d\n", character->name, character->level);
}

void attack_target(Character* attacker, Character* target) {
    printf("%s атакует %s...",attacker->name, target->name);
    int damage = attacker->attack;
    take_damage(target, damage);
    if(!is_alive(target)) {
        int xp_reward = target->level * 50;
        gain_xp(attacker, xp_reward);
    }
}

void destroy_character(Character* character) {
    if(character) {
        free(character);
    }
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");      
    #else
        system("clear");    
    #endif
} 

