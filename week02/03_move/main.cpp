// Алхам 3: Гараар хөдөлдөг дүр
// Сум товч / WASD-аар хөдөлгөнө.

#include "raylib.h"

int main() {
    const int screenW = 800;
    const int screenH = 450;
    InitWindow(screenW, screenH, "DP club - Week 2: Move");
    SetTargetFPS(60);

    // Дүрийн төлөв (state)
    Vector2 pos = { screenW / 2.0f, screenH / 2.0f };
    float speed = 4.0f;      // нэг frame-д хэдэн пиксел
    float radius = 20.0f;

    while (!WindowShouldClose()) {
        // 1) INPUT + 2) UPDATE
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) pos.x += speed;
        if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) pos.x -= speed;
        if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) pos.y += speed;   // y доошоо өснө!
        if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) pos.y -= speed;

        // Дэлгэцээс гарахгүй байлгах
        if (pos.x < radius)           pos.x = radius;
        if (pos.x > screenW - radius) pos.x = screenW - radius;
        if (pos.y < radius)           pos.y = radius;
        if (pos.y > screenH - radius) pos.y = screenH - radius;

        // 3) DRAW
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(pos, radius, MAROON);
            DrawText("Arrow keys / WASD", 10, 10, 20, DARKGRAY);
            DrawText(TextFormat("x=%.0f  y=%.0f", pos.x, pos.y), 10, 35, 20, GRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// АСУУДАЛ: speed нь "нэг frame-д 4 пиксел".
// Компьютер 30 FPS-тэй бол удаан, 144 FPS-тэй бол хурдан хөдөлнө!
// Шийдэл -> 04_delta_time
