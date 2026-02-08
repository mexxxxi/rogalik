
#include "include/character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start_battle(Character* player) {
    int enemy_type = rand() % 4;
    Character* enemy;
    
    switch(enemy_type) {
        case 0: enemy = create_goblin(); break;
        case 1: enemy = create_skeleton_mage(); break;
        case 2: enemy = create_big_rat(); break;
        case 3: enemy = create_slime(); break;
    }
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║            БОЙ НАЧАЛСЯ!                ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ %-20s vs %-20s                         ║\n", 
              player->name, enemy->name);
    printf("╚════════════════════════════════════════╝\n");
    

    while(is_alive(player) && is_alive(enemy)) {
        printf("╔════════════════════════════════════════╗\n");
        printf("║ 1. Атаковать     2. Лечение (30 HP)    ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Ваш ход: ");
        int battle_choice = get_choice();
        
        if(battle_choice == 1) {
            attack_target(player, enemy);
        } else {
            heal_hp_character(player, 30);
        }
        if(is_alive(enemy)) {
            attack_target(enemy, player);
        }
    }
    
    if(is_alive(player)) {
        printf("╔════════════════════════════════════════╗\n");
        printf("║            ПОБЕДА!                     ║\n");
        printf("╠════════════════════════════════════════╣\n");
        
        int xp_reward = enemy->level * 50;
        gain_xp(player, xp_reward);
        printf("╔════════════════════════════════════════╗\n");
        printf("║ Получено опыта: %-25d                  ║\n", xp_reward);
        printf("╚════════════════════════════════════════╝\n");
    } else {
        printf("╔════════════════════════════════════════╗\n");
        printf("║           ПОРАЖЕНИЕ!                   ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║   Ваш герой пал в бою...               ║\n");
        printf("╚════════════════════════════════════════╝\n");
    }
    
    destroy_character(enemy);
}
