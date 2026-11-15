#include "player.h"
#include "config.h"
#include <cmath>

Player MakePlayer(float x, float y) {
    Player p;
    p.pos      = { x, y };
    p.vel      = { 0.0f, 0.0f };
    p.facing   = 1;
    p.walkTime = 0.0f;
    return p;
}

void UpdatePlayer(Player& p, float dt) {
    // 1) INPUT -> хүссэн чиглэл
    float dir = 0.0f;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) dir += 1.0f;
    if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) dir -= 1.0f;

    // 2) Хурд тооцох
    p.vel.x = dir * PLAYER_SPEED;
    if (dir != 0.0f) p.facing = (dir > 0) ? 1 : -1;

    // 3) Байрлал шинэчлэх:  зай = хурд × хугацаа
    p.pos.x += p.vel.x * dt;

    // 4) Дэлгэцийн хязгаар
    float half = PLAYER_W / 2.0f;
    if (p.pos.x < half)            p.pos.x = half;
    if (p.pos.x > SCREEN_W - half) p.pos.x = SCREEN_W - half;

    // Алхах анимэйшн: хөдөлж байвал цаг урагшилна
    if (dir != 0.0f) p.walkTime += dt;
    else             p.walkTime  = 0.0f;
}

void DrawPlayer(const Player& p) {
    // Алхахад бага зэрэг дээш доош хөдөлнө (sin долгион)
    float bob = std::fabs(std::sin(p.walkTime * 12.0f)) * 4.0f;

    Rectangle body = {
        p.pos.x - PLAYER_W / 2.0f,
        p.pos.y - PLAYER_H - bob,
        PLAYER_W,
        PLAYER_H
    };
    DrawRectangleRounded(body, 0.3f, 6, SKYBLUE);
    DrawRectangleRoundedLinesEx(body, 0.3f, 6, 2.0f, DARKBLUE);

    // Нүд: харж буй зүг рүүгээ шилжинэ
    float eyeX = p.pos.x + p.facing * 8.0f;
    float eyeY = body.y + 18.0f;
    DrawCircle((int)(eyeX - 6), (int)eyeY, 5, WHITE);
    DrawCircle((int)(eyeX + 6), (int)eyeY, 5, WHITE);
    DrawCircle((int)(eyeX - 6 + p.facing * 2), (int)eyeY, 2, BLACK);
    DrawCircle((int)(eyeX + 6 + p.facing * 2), (int)eyeY, 2, BLACK);
}
