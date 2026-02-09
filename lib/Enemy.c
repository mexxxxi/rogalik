
#include "include/character.h"
#include <stdlib.h>
#include <time.h>

Character* create_goblin(int player_level);
Character* create_skeleton_mage(int player_level);
Character* create_big_rat(int player_level);
Character* create_slime(int player_level);

Character* create_random_enemy(int player_level) {
    int monster_type = rand() % 4;
    
    switch(monster_type) {
        case 0:
            return create_goblin(player_level);
        case 1:
            return create_skeleton_mage(player_level);
        case 2:
            return create_big_rat(player_level);
        case 3:
            return create_slime(player_level);
        default:
            return create_goblin(player_level);
    }
}
