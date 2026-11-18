# game/ дотор код бичих заавар

Энэ заавар: тоглоомын код хэрхэн зохион байгуулагдсан, **юуг хаана бичих**, шинэ зүйл нэмэхдээ **ямар дарааллаар** хийх вэ.

---

## 1. Тоглоомын код хэрхэн ажилладаг вэ

`game/src/` дотор 4 файл бий:

| Файл | Юу байдаг | Зүйрлэл |
|---|---|---|
| `main.cpp` | Game loop: бүх юмыг үүсгэж, секундэд 60 удаа шинэчилж, зурна | Тоглоомын зүрх |
| `config.h` | Бүх тоо нэг дор: дэлгэцийн хэмжээ, хурд, газрын өндөр | Тохиргооны цэс |
| `player.h` | Тоглогч гэж **юу** байгааг зарлана (`struct Player`, функцийн нэрс) | Рестораны цэс |
| `player.cpp` | Тоглогч **яаж** хөдөлж, зурагддагийг бичнэ | Гал тогоо |

`main.cpp` ийм бүтэцтэй:

```cpp
int main() {
    InitWindow(...);                         // 1 удаа: цонх нээх
    Player player = MakePlayer(...);         // 1 удаа: юмсаа ҮҮСГЭХ

    while (!WindowShouldClose()) {           // секундэд 60 удаа:
        float dt = GetFrameTime();

        // 1) INPUT   — товч шалгах
        // 2) UPDATE  — тоог өөрчлөх:  UpdatePlayer(player, dt);
        // 3) DRAW    — зурах:          DrawWorld(); DrawPlayer(player);
    }
    CloseWindow();
}
```

> **Алтан дүрэм:** UPDATE хэсэгт зурахгүй. DRAW хэсэгт тоо өөрчлөхгүй.

---

## 2. Юуг хаана бичих вэ?

| Хийх зүйл | Файл | Хаана |
|---|---|---|
| Хурд, хэмжээ, өнгө өөрчлөх | `config.h` | Тоог нь солино |
| Тоглогчийн хөдөлгөөн | `player.cpp` | `UpdatePlayer()` дотор |
| Тоглогчийн дүр төрх | `player.cpp` | `DrawPlayer()` дотор |
| Тэнгэр, газар, арын зураг | `main.cpp` | `DrawWorld()` дотор |
| Товч дарахад нэг удаа юм хийх | `main.cpp` | `// 1) INPUT` хэсэгт |
| **ШИНЭ зүйл** (зоос, дайсан, сум…) | `my_xxx.h` + `my_xxx.cpp` | Шинэ файл → `main.cpp`-д холбоно |

Шинэ `.cpp` файл `game/src/` дотор үүсгэхэд **автоматаар** build-д орно. `CMakeLists.txt`-г засах хэрэггүй.

---

## 3. Шинэ зүйл нэмэх дараалал

Ямар ч шинэ зүйлийг (зоос, дайсан, сум) **яг энэ дарааллаар** нэмнэ:

| # | Алхам | Хаана | Асуулт |
|---|---|---|---|
| 0 | **Нэг өгүүлбэрээр бич** | Цаасан дээр | Юу хийх вэ? «Тоглогч зоосонд хүрвэл зоос алга болно» |
| 1 | **Тоо** | `config.h` | Ямар хэмжээ, хурд хэрэгтэй вэ? |
| 2 | **Цэс** | `my_xxx.h` | Юуг санах вэ (`struct`)? Ямар функц хэрэгтэй вэ? |
| 3 | **Гал тогоо** | `my_xxx.cpp` | `Make…` → `Draw…` → `Update…` |
| 4 | **Холбох** | `main.cpp` | `#include` → loop-ийн өмнө үүсгэх → UPDATE → DRAW |
| 5 | **Build + турших** | F7, Shift+F5 | Ажиллаж байна уу? |
| 6 | **Хадгалах** | Терминал | `git add .` → `git commit` → `git push` |

**Гурван зөвлөгөө:**
- **Эхлээд `Draw`.** Дэлгэцэн дээр харагдаж байгаа эсэхийг эхлээд шалга, дараа нь хөдөлгө.
- **Жижиг алхам → build.** 20 мөр бичээд дараа нь build хийвэл алдааг олоход хэцүү. 3–5 мөр бичээд build хий.
- **Өөрийн файлыг `my_` эхтэй нэрлэ** (`my_coin.cpp`). Хэнийх нь гэдэг тодорхой.

---

## 4. Жишээ А: нар (1 мөр)

`main.cpp` → `DrawWorld()` функц. Тэнгэр зурдаг мөрийн **дараа** нэм:

```cpp
static void DrawWorld() {
    DrawRectangleGradientV(0, 0, SCREEN_W, (int)GROUND_Y, ...);   // тэнгэр
    DrawCircle(820, 90, 40, YELLOW);                               // ← НАР (шинэ)
    ...
}
```

**Shift+F5** → тэнгэрт нар гарна. Дараалал чухал: тэнгэрийн **өмнө** зурвал тэнгэр нарыг дарж харагдахгүй.

---

## 5. Жишээ Б: зоос (бүтэн дараалал)

**Алхам 0.** «Газар дээр зоос байна. Тоглогч хүрвэл зоос алга болно.»

### Алхам 1 · `config.h` — тоо

Файлын төгсгөлд нэм:

```cpp
constexpr float COIN_R = 12.0f;          // зоосны радиус (пиксел)
```

### Алхам 2 · `my_coin.h` — цэс (шинэ файл)

`game/src/my_coin.h` үүсгэ:

```cpp
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
```

### Алхам 3 · `my_coin.cpp` — гал тогоо (шинэ файл)

`game/src/my_coin.cpp` үүсгэ:

```cpp
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
```

### Алхам 4 · `main.cpp` — холбох (4 газар)

**① Дээр нь** `#include`:

```cpp
#include "player.h"
#include "my_coin.h"                                      // ← шинэ
```

**② Loop-ийн өмнө** үүсгэх:

```cpp
Player player = MakePlayer(SCREEN_W / 2.0f, GROUND_Y);
bool showDebug = true;
Coin coin = MakeCoin(200, GROUND_Y - 30);                 // ← шинэ
```

**③ DRAW хэсэгт** зурах (тоглогчийн **өмнө**, тэгвэл тоглогч дээр нь харагдана):

```cpp
DrawWorld();
DrawCoin(coin);                                           // ← шинэ
DrawPlayer(player);
```

👉 **Энд нэг build хий (Shift+F5).** Зоос газар дээр харагдаж байна уу? Тийм бол үргэлжлүүл.

**④ UPDATE хэсэгт** шинэчлэх:

```cpp
UpdatePlayer(player, dt);
Rectangle box = { player.pos.x - PLAYER_W / 2, player.pos.y - PLAYER_H, PLAYER_W, PLAYER_H };
UpdateCoin(coin, box);                                    // ← шинэ
```

`box` бол тоглогчийн биеийг тойрсон тэгш өнцөгт. raylib-ийн `CheckCollisionCircleRec` тойрог (зоос) ба тэгш өнцөгт (тоглогч) хүрч байгаа эсэхийг шалгана.

### Алхам 5 · Турших

**Shift+F5** → **A** дарж зүүн тийш алх → зоосонд хүрэхэд алга болно. 🎉

### Алхам 6 · Хадгалах

```powershell
git add .
git commit -m "Зоос нэмэв"
git push
```

---

## 6. Дараа нь өөрөө хий

- ⭐ **Оноо:** `int score = 0;` (loop-ийн өмнө). Зоос авахад нэм. DRAW-д `DrawText(TextFormat("Score: %d", score), 16, 120, 20, GOLD);`
- ⭐⭐ **Олон зоос:** `Coin coins[5];` → `for` давталтаар үүсгэж, шинэчилж, зурна.
- ⭐⭐⭐ **Дахин гарч ирэх:** авсан зоосыг `GetRandomValue(50, 900)` x байрлалд дахин гаргах.

## 7. Гэрийн даалгаврын зөвлөмж (шийдэл биш!)

- **Shift гүйлт:** `player.cpp` → `UpdatePlayer()` → `// 2) Хурд тооцох` хэсэг. `IsKeyDown(KEY_LEFT_SHIFT)` үнэн бол хурдыг 2 дахин.
- **Wrap-around:** `player.cpp` → `UpdatePlayer()` → `// 4) Дэлгэцийн хязгаар` хэсэг. Хязгаарт **тулгах** биш, нөгөө тал руу **шилжүүл**.

---

## 8. Алдаа гарвал

| Алдаа | Утга | Шийдэл |
|---|---|---|
| `expected ';'` | Цэг таслал мартсан | Заасан мөрийн **өмнөх** мөрийн төгсгөлийг шалга |
| `'Coin' was not declared` / `undeclared identifier` | `#include` мартсан эсвэл нэр буруу | `#include "my_coin.h"` байгаа эсэх, үсгийг шалга |
| `undefined reference to 'DrawCoin'` | `.h`-д зарласан, `.cpp`-д бичээгүй | `my_coin.cpp`-д функцийн бие байгаа эсэх |
| `no member named 'postion'` | struct-ийн талбарын нэр буруу | `.h` дахь нэртэй яг ижил бич |
| Build амжилттай, гэхдээ юу ч харагдахгүй | Draw дуудаагүй эсвэл буруу дараалал | DRAW хэсэгт дуудсан уу? Тэнгэрийн **дараа** зурсан уу? |

Алдааны мессежийн **эхний** мөрийг уншаад, файлын нэр ба мөрийн дугаарыг хар. Ихэнхдээ асуудал тэр мөрөнд эсвэл яг өмнөх мөрөнд байдаг.
