#include "functions.c"

void (*flist[]) (char param_key[], char param_value[], char answer[]) = {
    home, 
    square, 
    cube, 
    helloworld, 
    pingpong, 
    prime,
    fibonacci
};
