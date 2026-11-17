// Алхам 4: Delta time — FPS-ээс үл хамааран ижил хурдтай хөдөлгөх
//
//   зай = хурд × хугацаа        (физикийн хичээлээс!)
//   pos += speed * dt           speed: пиксел/секунд, dt: энэ frame хэдэн секунд үргэлжилсэн
//
// 1-ээс 4 хүртэлх товчоор FPS-ийг сольж, хоёр бөмбөгийг харьцуул.

#include "raylib.h"

int main() {
    InitWindow(800, 450, "DP club - Week 2: Delta time");
    SetTargetFPS(60);

    float xFrame = 0.0f;   // frame-д тулгуурласан (буруу)
    float xDelta = 0.0f;   // dt-д тулгуурласан (зөв)
    const float speedPerFrame  = 4.0f;    // пиксел / frame
    const float speedPerSecond = 240.0f;  // пиксел / секунд  (= 4 × 60)
    int fps = 60;

    while (!WindowShouldClose()) {
        // INPUT: FPS солих
        if (IsKeyPressed(KEY_ONE))   { fps = 15;  SetTargetFPS(fps); }
        if (IsKeyPressed(KEY_TWO))   { fps = 30;  SetTargetFPS(fps); }
        if (IsKeyPressed(KEY_THREE)) { fps = 60;  SetTargetFPS(fps); }
        if (IsKeyPressed(KEY_FOUR))  { fps = 144; SetTargetFPS(fps); }

        // UPDATE
        float dt = GetFrameTime();         // өмнөх frame-ээс хойш өнгөрсөн секунд
        xFrame += speedPerFrame;
        xDelta += speedPerSecond * dt;
        if (xFrame > 800) xFrame = 0;
        if (xDelta > 800) xDelta = 0;

        // DRAW
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(TextFormat("Target FPS: %d  (keys 1-4)", fps), 10, 10, 20, DARKGRAY);
            DrawText(TextFormat("dt = %.4f s", dt), 10, 35, 20, GRAY);

            DrawText("per frame", 10, 140, 20, RED);
            DrawCircle((int)xFrame, 200, 20, RED);

            DrawText("per second (dt)", 10, 280, 20, DARKGREEN);
            DrawCircle((int)xDelta, 340, 20, DARKGREEN);
            DrawFPS(700, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
