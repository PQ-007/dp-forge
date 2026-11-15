// Алхам 2: raylib-ээр цонх нээж, зураг зурах
// Game loop-ийн 3 хэсэг:  1) Input  2) Update  3) Draw

#include "raylib.h"

int main() {
    InitWindow(800, 450, "DP club - Week 2: Window");
    SetTargetFPS(60);   // секундэд 60 удаа давтана

    int frameCount = 0;

    // ===== GAME LOOP =====
    // Цонхыг хаах (X эсвэл ESC) хүртэл давтагдана
    while (!WindowShouldClose()) {
        // 1) INPUT  - энд хараахан юу ч алга
        // 2) UPDATE - тоглоомын төлөвийг өөрчлөх
        frameCount++;

        // 3) DRAW   - дэлгэцийг шинээр зурах
        BeginDrawing();
            ClearBackground(RAYWHITE);   // өмнөх frame-ийг арилгах

            DrawText("Hello, DP club!", 250, 180, 40, DARKBLUE);
            DrawText(TextFormat("Frame: %d", frameCount), 10, 10, 20, GRAY);

            DrawRectangle(100, 300, 120, 60, ORANGE);   // x, y, өргөн, өндөр
            DrawCircle(600, 330, 40, RED);              // төвийн x, y, радиус
            DrawLine(0, 400, 800, 400, DARKGRAY);       // газар

            DrawFPS(700, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Туршаад үз:
//  - SetTargetFPS(60)-г 5 болгоод юу өөрчлөгдөхийг ажигла.
//  - ClearBackground мөрийг устгавал юу болох вэ? Яагаад?
//  - Координат (0,0) нь дэлгэцийн аль буланд байна вэ?
