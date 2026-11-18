#include "my_coin.h"
#include "config.h"

Coin MakeCoin(float x, float y) {
    Coin c;
    c.pos   = { x, y };
    c.taken = false;
    return c;
}

void UpdateCoin(Coin& c, Rectangle playerBox) {
    if (c.taken) return;                                  // аль хэдийн авсан
    if (CheckCollisionCircleRec(c.pos, COIN_R, playerBox)) {
        c.taken = true;                                   // хүрлээ!
    }
}

void DrawCoin(const Coin& c) {
    if (c.taken) return;                                  // авсан бол зурахгүй
    DrawCircleV(c.pos, COIN_R, GOLD);
    DrawCircleLines((int)c.pos.x, (int)c.pos.y, COIN_R, ORANGE);
}
