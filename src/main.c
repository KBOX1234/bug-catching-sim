#include "bugs.h"
#include "raylib.h"
#include "render.h"
#include "tree.h"

#define MAX_COLUMNS 20

extern Camera camera;

int main(void){

    init_render();
    init_bugs();
    create_random_trees();

    while (!WindowShouldClose()){
        progress_time_of_day();
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) { getthebug(camera.target, camera.position); }
        render_main();
    }

    UnloadModel(tree_model);
    CloseWindow();


    return 0;
}
