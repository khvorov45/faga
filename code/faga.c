#include "raylib.h"

typedef float f32;

int
fagaMain(void) {
    InitWindow(800, 450, "raylib [core] example - basic window");

    Camera3D camera = {
        .position = (Vector3) {.y = 10.0f, .z = 10.0f},
        .target = (Vector3) {0},
        .up = (Vector3) {.y = 1.0f},
        .fovy = 45.0f,
        .projection = CAMERA_PERSPECTIVE,
    };

    Vector3 cubePosition = {0};
    f32 cubeDim = 2.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        DrawCube(cubePosition, cubeDim, cubeDim, cubeDim, RED);
        DrawCubeWires(cubePosition, cubeDim, cubeDim, cubeDim, MAROON);
        DrawGrid(10, 1.0f);
        EndMode3D();
        EndDrawing();
    }

    return 0;
}

#if PLATFORM_WINDOWS

typedef void* HINSTANCE;
typedef char* LPSTR;

int
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    fagaMain();
}

#endif  // PLATFORM_WINDOWS
