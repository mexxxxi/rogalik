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
    {300, 50, 22, 18, "Воин"},
    //MAGE
    {140, 300, 26, 4, "Маг"},
    //ARCHER
    {200, 100, 24, 10, "Лучник"},
    //ROGUE
    {180, 120, 30, 8, "Разбойник"},
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

Character* create_goblin(int player_level) {
    Character* goblin = create_character("Гоблин", CLASS_ENEMY);
    goblin->is_enemy = 1;
    
    int base_hp = 85;
    int base_atk = 22;
    int base_def = 4;
    
    goblin->max_heat_point = base_hp + (player_level - 1) * 15;
    goblin->heat_point = goblin->max_heat_point;
    goblin->max_mana_point = 0;
    goblin->mana_point = goblin->max_mana_point;
    goblin->attack = base_atk + (player_level - 1) * 3;
    goblin->defense = base_def + (player_level - 1) * 1;
    goblin->level = player_level;  
    return goblin;
}

Character* create_skeleton_mage(int player_level) {
    Character* skeleton = create_character("Скелет-маг", CLASS_ENEMY);
    skeleton->is_enemy = 1;
    
    int base_hp = 60;
    int base_mp = 120;
    int base_atk = 26;
    int base_def = 0;
    
    skeleton->max_heat_point = base_hp + (player_level - 1) * 10;
    skeleton->heat_point = skeleton->max_heat_point;
    skeleton->max_mana_point = base_mp + (player_level - 1) * 20;
    skeleton->mana_point = skeleton->max_mana_point;
    skeleton->attack = base_atk + (player_level - 1) * 4;  
    skeleton->defense = base_def + (player_level - 1) * 0; 
    skeleton->level = player_level;
    return skeleton;
}

Character* create_big_rat(int player_level) {
    Character* rat = create_character("Гигантская крыса", CLASS_ENEMY);
    rat->is_enemy = 1;
    
    int base_hp = 75;
    int base_atk = 20;
    int base_def = 3;
    
    rat->max_heat_point = base_hp + (player_level - 1) * 12;
    rat->heat_point = rat->max_heat_point;
    rat->max_mana_point = 0;
    rat->mana_point = rat->max_mana_point;
    rat->attack = base_atk + (player_level - 1) * 3;
    rat->defense = base_def + (player_level - 1) * 1;
    rat->level = player_level;
    return rat;
}

Character* create_slime(int player_level) {
    Character* slime = create_character("Сгусток слизи", CLASS_ENEMY);
    slime->is_enemy = 1;
    
    int base_hp = 100;
    int base_atk = 15;
    int base_def = 6;
    
    slime->max_heat_point = base_hp + (player_level - 1) * 18;
    slime->heat_point = slime->max_heat_point;
    slime->max_mana_point = 0;
    slime->mana_point = slime->max_mana_point;
    slime->attack = base_atk + (player_level - 1) * 2;  
    slime->defense = base_def + (player_level - 1) * 2; 
    slime->level = player_level;
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
            character->max_heat_point += 30;
            character->attack += 8;
            character->defense += 4;
            break;
        case CLASS_MAGE:
            character->max_heat_point += 15;
            character->max_mana_point += 40;
            character->attack += 12;
            character->defense += 1;
            break;
        case CLASS_ARCHER:
            character->max_heat_point += 20;
            character->max_mana_point += 15;
            character->attack += 10;
            character->defense += 2;
            break;
        case CLASS_ROGUE:
            character->max_heat_point += 22;
            character->max_mana_point += 20;
            character->attack += 14;
            character->defense += 1;
            break;
    }
    character->heat_point = character->max_heat_point;
    character->mana_point = character->max_mana_point;
}

void attack_target(Character* attacker, Character* target) {
    printf("%s атакует %s...",attacker->name, target->name);
    int damage = attacker->attack;
    take_damage(target, damage);
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

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

