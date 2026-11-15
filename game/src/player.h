#pragma once
#include "raylib.h"

// Тоглогчийн бүх төлөв нэг struct-д
struct Player {
    Vector2 pos;        // хөлийн доод төв цэг
    Vector2 vel;        // хурд (пиксел/секунд). Долоо хоног 3-д үсрэлтэд хэрэглэнэ
    int     facing;     // 1 = баруун, -1 = зүүн
    float   walkTime;   // алхах анимэйшнд зориулсан цаг
};

Player MakePlayer(float x, float y);
void   UpdatePlayer(Player& p, float dt);   // & = эх хувийг нь өөрчилнө (хуулбар биш)
void   DrawPlayer(const Player& p);
