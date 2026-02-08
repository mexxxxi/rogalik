#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/character.h"

int get_choice() {
    int choice;
    scanf("%d", &choice);
    while(getchar() != '\n');
    return choice;
}

void show_interface() {
    clear_screen();
    printf("║════════════════════════════════════════║\n");
    printf("║==========Подземелья и драконы==========║\n");
    printf("║════════════════════════════════════════║\n");
    printf("║            1. Новая игра               ║\n");
    printf("║            2. Загрузить игру           ║\n");
    printf("║            3. Выйти из игры            ║\n");
    printf("║════════════════════════════════════════║\n");

    int choice = get_choice();

    switch(choice) {
        case 1: 
            show_new_game();
            break;
        case 2:
            show_load_game();
            break;
        case 3:
             exit(0);
    }
}

void show_new_game() {
    clear_screen();
    printf("║════════════════════════════════════════║\n");
    printf("║==========Подземелья и драконы==========║\n");
    printf("║════════════════════════════════════════║\n");
    printf("║         1. Создать персонажа           ║\n");
    printf("║         2. Выйти в меню                ║\n");
    printf("║════════════════════════════════════════║\n");

    int choice = get_choice();
    switch(choice) {
        case 1:
            create_new_character();
            break;
        case 2:
            show_interface();
    }
}

void create_new_character() {
    clear_screen();
    char name[50];
    printf("Введите имя: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("║════════════════════════════════════════║\n");
    printf("║==========Подземелья и драконы==========║\n");
    printf("║════════════════════════════════════════║\n");
    printf("║         1. Класс Воин                  ║\n");
    printf("║         2. Класс Маг                   ║\n");
    printf("║         3. Класс Лучник                ║\n");
    printf("║         4. Класс Разбойник             ║\n");
    printf("║         5. Выйти                       ║\n");
    printf("║════════════════════════════════════════║\n");

    int choice = get_choice();

    CharacterClass class;

    switch(choice) {
        case 1:
            class = CLASS_WARRIOR;
            break;
        case 2: 
            class = CLASS_MAGE;
            break;
        case 3:
            class = CLASS_ARCHER;
            break;
        case 4:
            class = CLASS_ROGUE;
            break;
        case 5:
            show_new_game();
            return;
    }

    Character* player = create_character(name, class);
    start_game(player);
}

void start_game(Character* player) {
    clear_screen();
    printf("║════════════════════════════════════════║\n");
    printf("║==========Подземелья и драконы==========║\n");
    printf("║════════════════════════════════════════║\n");
    printf("║         1. Войти в подземелье          ║\n");
    printf("║         2. Статистика Персонажа        ║\n");
    printf("║         3. Выход                       ║\n");
    printf("║════════════════════════════════════════║\n");

    int choice = get_choice();
   
    switch(choice) {
        case 1:
            game_started(player);
            break;
        case 2:
            clear_screen();
            show_status(player);
            printf("\nНажмите Enter для возврата в меню...");
            getchar();  
            start_game(player); 
            break;
        case 3:
            destroy_character(player);  
            show_interface();
            return;
    }
}



void show_load_game() {
    clear_screen();
    printf("Загрузка не реализована\n");
    show_interface();
}

void show_status(const Character* character) {
    clear_screen();
    if(!character) return;
      const char* class_names[] = {"Воин", "Маг", "Лучник", "Разбойник"};
    printf("\n=== Статистика персонажа ===\n");
    printf("Имя: %s\n", character->name);
    printf("Класс: %s\n", class_names[character->class]);
    printf("Уровень: %d\n", character->level);
    printf("HP: %d/%d\n", character->heat_point, character->max_heat_point);
    printf("MP: %d/%d\n", character->mana_point, character->max_mana_point);
    printf("Атака: %d\n", character->attack);
    printf("Защита: %d\n", character->defense);
    printf("Опыт: %d/%d\n", character->experience, character->level * 100);
    printf("============================\n");
}


void game_started(Character* player) {
    clear_screen();
    while(is_alive(player)) {
        printf("║════════════════════════════════════════║\n");
        printf("║==========Подземелья и драконы==========║\n");
        printf("║════════════════════════════════════════║\n");
        printf("║         1. Продвигаться дальше         ║\n");
        printf("║         2. Статистика Персонажа        ║\n");
        printf("║         3. Выход                       ║\n");
        printf("║════════════════════════════════════════║\n");

        int choice = get_choice();
    
        switch(choice) {
            case 1:
                if(rand() % 100 < 30) {
                    printf("На вас напал монстр!\n");
                    printf("Нажмите Enter для продолжения боя...");
                    getchar();
                    
                    clear_screen();
                    start_battle(player);
                } else {
                    printf("Вы безопасно продвинулись дальше...\n");
                    printf("Нажмите Enter...");
                    getchar();
                }
                break;
            case 2:
                clear_screen();
                show_status(player);
                printf("\nНажмите Enter для возврата...");
                getchar();  
                break;      
            case 3:
                destroy_character(player);
                show_interface();
                return;
        }
    }
}





















