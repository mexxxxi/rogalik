
#include "include/character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start_battle(Character* player) {
    Character* enemy = create_random_enemy(player->level);

    printf("═══════════════════════════════════════\n");
    printf("           БОЙ НАЧАЛСЯ!               \n");
    printf("═══════════════════════════════════════\n");
    printf(" %-12s    vs    %-12s \n", player->name, enemy->name);
    printf("═══════════════════════════════════════\n\n");

    while(is_alive(player) && is_alive(enemy)) {
        printf("════════════════════════════════════════\n");
        printf(" 1. Атаковать     2. Лечение (30 HP)    \n");
        printf("════════════════════════════════════════\n");
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
        printf("\n════════════════════════════════════════\n");
        printf("                ПОБЕДА!                 \n");
        printf("════════════════════════════════════════\n\n");

        int xp_reward = enemy->level * 50;
        int old_level = player->level;
        gain_xp(player, xp_reward);

        printf("════════════════════════════════════════\n");
        printf(" Получено опыта: %-25d \n", xp_reward);
        printf("────────────────────────────────────────\n");
        printf(" Опыт: %4d/%4d   Уровень: %2d        \n",
               player->experience, player->level * 100, player->level);
        printf("════════════════════════════════════════\n");

        if(player->level > old_level) {
            printf("\n════════════════════════════════════════\n");
            printf("         УРОВЕНЬ ПОВЫШЕН!              \n");
            printf("   %2d → %2d                            \n",
                   old_level, player->level);
            printf("════════════════════════════════════════\n");
        }
    } else {
        printf("\n════════════════════════════════════════\n");
        printf("               ПОРАЖЕНИЕ!               \n");
        printf("────────────────────────────────────────\n");
        printf("   Ваш герой пал в бою...               \n");
        printf("════════════════════════════════════════\n");
    }

    printf("\nНажмите Enter для возврата в подземелье...");
    wait_enter();

    destroy_character(enemy);
}
