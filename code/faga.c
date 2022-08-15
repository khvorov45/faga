#include <stdint.h>
#include "raylib.h"

typedef float f32;
typedef int32_t i32;

int
fagaMain(void) {
    InitWindow(1280, 720, "faga");

    Camera3D camera = {
        .position = (Vector3) {10.0f, 50.0f, 20.0f},
        .target = (Vector3) {0.0f, 0.0f, 0.0f},
        .up = (Vector3) {.y = 1.0f},
        .fovy = 45.0f,
        .projection = CAMERA_PERSPECTIVE,
    };

    Image imMap = LoadImage("cubicmap.png");
    // Texture2D cubicmap = LoadTextureFromImage(imMap);
    Mesh mesh = GenMeshCubicmap(imMap, (Vector3) {1.0f, 1.0f, 1.0f});
    Model model = LoadModelFromMesh(mesh);

    Texture2D texture = LoadTexture("cubicmap_atlas.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    // Color* mapPixels = LoadImageColors(imMap);
    UnloadImage(imMap);

    Vector3 mapPosition = {0.0f, 0.0f, 0.0f};

    // SetCameraMode(camera, CAMERA_FIRST_PERSON);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Vector3 oldCamPos = camera.position;
        //  UpdateCamera(&camera);

        // Vector2 playerPos = {camera.position.x, camera.position.z};
        // f32 playerRadius = 0.1f;

        // i32 playerCellX = (i32)(playerPos.x - mapPosition.x + 0.5f);
        // i32 playerCellY = (i32)(playerPos.y - mapPosition.z + 0.5f);

        BeginDrawing();
        {
            ClearBackground(BLACK);
            BeginMode3D(camera);
            DrawModel(model, mapPosition, 1.0f, WHITE);
            EndMode3D();
        }
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
