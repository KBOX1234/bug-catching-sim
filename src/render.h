#ifndef RENDER_H
#define RENDER_H

#include <raylib.h>


Camera3D camera;

Vector3* PLAYER_POS;

void init_render(){
    InitWindow(1280, 720, "stim sim");

    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();

    SetTargetFPS(60);
}

void render_main(){
    UpdateCamera(&camera, CAMERA_THIRD_PERSON);
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);


                    DrawCube(camera.target, 0.5f, 0.5f, 0.5f, PURPLE);
                    DrawCubeWires(camera.target, 0.5f, 0.5f, 0.5f, DARKPURPLE);

            EndMode3D();

            // Draw info boxes

        EndDrawing();
}

#endif // !RENDER_H
