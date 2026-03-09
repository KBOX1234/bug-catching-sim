#ifndef RENDER_H
#define RENDER_H

#include <raylib.h>
#include "bugs.h"
#include "tree.h"

#define DAY_PROGRESSION 0.001

Camera3D camera;

Vector3* PLAYER_POS;

float time_of_day = 0;

bool DAY = true;

Color TIME_CYCLE;


void init_render(){
    InitWindow(1280, 720, "stim sim");

    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    PLAYER_POS = &camera.target;

    DisableCursor();

    SetTargetFPS(60);

    TIME_CYCLE = WHITE;
}

void draw_bugs(){
    for(int i = 0; i < BUG_COUNT; i++){
        if(bugsList[i].didyagetit) continue;
        DrawCube(bugsList[i].pos, 1, 1, 1, BLUE);
    }
}

void draw_trees(){
    for(int i = 0; i < TREE_COUNT; i++){
        DrawModel(tree_model, trees[i].pos, 1, TIME_CYCLE);
    }
}

void progress_time_of_day(){
    if(DAY == false){
        time_of_day = time_of_day + DAY_PROGRESSION;
        if(time_of_day > 0.9) DAY = true;
    }
    if(DAY == true){
        time_of_day = time_of_day - DAY_PROGRESSION;
        if(time_of_day < 0.1) DAY = false;
    }

    TIME_CYCLE.r = 255 - (time_of_day * 255);
    TIME_CYCLE.g = 255 - (time_of_day * 255);
    TIME_CYCLE.b = 255 - (time_of_day * 128);
}

void render_main(){
    UpdateCamera(&camera, CAMERA_THIRD_PERSON);
        BeginDrawing();

            ClearBackground(TIME_CYCLE);

            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, TIME_CYCLE);


                    DrawCube(camera.target, 0.5f, 0.5f, 0.5f, RED);
                    DrawCubeWires(camera.target, 0.5f, 0.5f, 0.5f, GREEN);

                    draw_bugs();
                    draw_trees();

            EndMode3D();

            // Draw info boxes

        EndDrawing();
}

#endif // !RENDER_H
