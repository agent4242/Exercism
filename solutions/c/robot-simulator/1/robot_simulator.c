#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robert;
    robot_position_t pos;
    pos.x = x;
    pos.y = y;
    robert.position = pos;
    robert.direction = direction;

    return robert;
}

void robot_move(robot_status_t *robot, const char *commands){
    int i;

    for (i=0; i < (int) strlen(commands); i++) {

        switch(commands[i]) {
            case 'R': 
                if (robot->direction == DIRECTION_WEST) {
                    robot->direction = DIRECTION_NORTH;
                } else {
                    robot->direction++;
                }
                break;
            case 'L':
                if (robot->direction == DIRECTION_NORTH) {
                    robot->direction = DIRECTION_WEST;
                } else {
                    robot->direction--;
                }
                break;
            case 'A':
                switch(robot->direction) {
                    case DIRECTION_NORTH:
                        robot->position.y++;
                        break;
                    case DIRECTION_EAST:
                        robot->position.x++;
                        break;
                    case DIRECTION_SOUTH:
                        robot->position.y--;
                        break;
                    case DIRECTION_WEST:
                        robot->position.x--;
                        break;
                    default: break;
                }
        }
        
    }

    
}