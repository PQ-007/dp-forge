// DP club тоглоом — Долоо хоног 2: game loop + хөдөлгөөн
// Энэ тоглоом улирлын турш долоо хоног бүр томорно:
//   W2: цонх, game loop, хөдөлгөөн, delta time   <- одоо энд
//   W3: үсрэлт, таталцал, мөргөлдөөн
//   W4: амь, inventory, хадгалах файл
//
// ЗӨВЛӨГӨӨ: Өөрийн кодоо my_*.cpp гэх мэт тусдаа файлд бичвэл
// багшийн шинэчлэлтэй conflict бага гарна.

#include "raylib.h"
#include "config.h"
#include "player.h"
#include "my_coin.h"                                      // a) зоосны цэс

static void DrawWorld() {
    // Тэнгэр -> газар
    DrawRectangleGradientV(0, 0, SCREEN_W, (int)GROUND_Y, Color{ 30, 30, 60, 255 }, Color{ 90, 70, 140, 255 });
    DrawRectangle(0, (int)GROUND_Y, SCREEN_W, SCREEN_H - (int)GROUND_Y, Color{ 60, 45, 35, 255 });
    DrawRectangle(0, (int)GROUND_Y, SCREEN_W, 8, Color{ 80, 170, 80, 255 });
}

static void DrawDebug(const Player& p, float dt) {
    DrawRectangle(8, 8, 260, 100, Fade(BLACK, 0.5f));
    DrawText(TextFormat("FPS: %d", GetFPS()),               16, 16, 18, LIME);
    DrawText(TextFormat("dt: %.4f s", dt),                   16, 38, 18, RAYWHITE);
    DrawText(TextFormat("pos: (%.0f, %.0f)", p.pos.x, p.pos.y), 16, 60, 18, RAYWHITE);
    DrawText(TextFormat("vel.x: %.0f px/s", p.vel.x),        16, 82, 18, RAYWHITE);
}

int main() {
    InitWindow(SCREEN_W, SCREEN_H, "DP club game");
    SetTargetFPS(TARGET_FPS);

    Player player = MakePlayer(SCREEN_W / 2.0f, GROUND_Y);
    bool showDebug = true;
    Coin coin = MakeCoin(200, GROUND_Y - 30);             // b) loop-ийн өмнө 1 удаа үүсгэнэ

    // ===== GAME LOOP =====
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // 1) INPUT (ерөнхий)
        if (IsKeyPressed(KEY_F1)) showDebug = !showDebug;

        // 2) UPDATE
        UpdatePlayer(player, dt);
        Rectangle box = {                                 // d) тоглогчийн биеийг тойрсон тэгш өнцөгт
            player.pos.x - PLAYER_W / 2,  // зүүн
            player.pos.y - PLAYER_H,      // дээд
            PLAYER_W, PLAYER_H            // өргөн, өндөр
        };
        UpdateCoin(coin, box);

        // 3) DRAW
        BeginDrawing();
            ClearBackground(BLACK);
            DrawWorld();
            DrawCoin(coin);                               // c) тоглогчийн өмнө зурна
            DrawPlayer(player);
            if (showDebug) DrawDebug(player, dt);
            DrawText("A/D or arrows: move   F1: debug", 16, SCREEN_H - 30, 18, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
