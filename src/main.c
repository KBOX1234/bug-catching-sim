#include "bugs.h"
#include "raylib.h"
#include "render.h"
#include "tree.h"

#define MAX_COLUMNS 20


int main(void){

    init_bugs();
    init_render();
    create_random_trees();

    while (!WindowShouldClose()){
        progress_time_of_day();
        render_main();
    }

    UnloadModel(tree_model);
    CloseWindow();


    return 0;
}
