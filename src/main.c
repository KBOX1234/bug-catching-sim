#include "raylib.h"
#include "render.h"

#define MAX_COLUMNS 20


int main(void){

    init_render();

    while (!WindowShouldClose()){
        render_main();
    }

    CloseWindow();


    return 0;
}
