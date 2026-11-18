#pragma once
#include "raylib.h"

// Нэг зоос
struct Coin {
    Vector2 pos;     // төв цэг
    bool    taken;   // авсан уу?
};

Coin MakeCoin(float x, float y);
void UpdateCoin(Coin& c, Rectangle playerBox);   // тоглогч хүрвэл авна
void DrawCoin(const Coin& c);
