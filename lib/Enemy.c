
#include "include/character.h"
#include <stdlib.h>
#include <time.h>

Character* get_random_enemy(int player_level) {
    int r = rand() % 4;
    
    switch(r) {
        case 0: return create_goblin();
        case 1: return create_skeleton_mage();
        case 2: return create_big_rat();
        case 3: return create_slime();
        default: return create_goblin();
    }
}
