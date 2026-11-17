# Долоо хоног 2: C++ ба game loop

**Зорилго:** C++ код машин код болж хувирахыг харах, raylib-ээр цонх нээж, дэлгэц дээр хөдөлдөг дүр зурах. Engine ашиглахгүй, бүгдийг өөрсдөө бичнэ.

## Алхмууд

| # | Хавтас | Юу сурах вэ |
|---|---|---|
| 0 | `00_compiler_explorer/` | C++ → assembly. [godbolt.org](https://godbolt.org) дээр `add.cpp`-г хуулж, `-O0` ба `-O2`-г харьцуул |
| 1 | `01_hello_cpp/` | Хувьсагч, нөхцөл, давталт, функц, `struct` |
| 2 | `02_window/` | `InitWindow`, game loop, `BeginDrawing` / `EndDrawing`, координат |
| 3 | `03_move/` | `IsKeyDown`, байрлал өөрчлөх, дэлгэцийн хязгаар |
| 4 | `04_delta_time/` | `GetFrameTime()`: FPS-ээс үл хамааран ижил хурд (1–4 товчоор FPS солино) |
| ★ | `../game/src/` | Улирлын тоглоом: `Player` struct, `UpdatePlayer`, `DrawPlayer`, debug (F1) |

## Game loop

```
while (цонх нээлттэй) {
    1. INPUT   — ямар товч дарагдсан бэ?
    2. UPDATE  — төлөвийг өөрчлөх (pos += vel * dt)
    3. DRAW    — бүгдийг шинээр зурах
}
```

## Гол ойлголтууд

- **Compiler**: C++ текстийг CPU-ийн ойлгох заавар (машин код) болгон хөрвүүлдэг програм.
- **Frame**: Game loop-ийн нэг эргэлт = дэлгэцийн нэг зураг.
- **FPS**: Секундэд хэдэн frame зурагддаг.
- **dt (delta time)**: Өмнөх frame-ээс хойш өнгөрсөн хугацаа (секунд). 60 FPS үед ≈ 0.0167.
- **зай = хурд × хугацаа** → `pos.x += speed * dt`

## Сорил (гэртээ)

1. ⭐ `config.h` дахь `PLAYER_SPEED`, өнгө, хэмжээг өөрчилж өөрийн дүрээ хий.
2. ⭐ Shift дарахад 2 дахин хурдан гүйдэг болго (`IsKeyDown(KEY_LEFT_SHIFT)`).
3. ⭐⭐ Тоглогч дэлгэцийн нэг талаас гараад нөгөө талаас гарч ирдэг (wrap-around) болго.
4. ⭐⭐ Тэнгэрт санамсаргүй байрлалтай 100 од зур (`GetRandomValue`, массив).
5. ⭐⭐⭐ Хурдыг шууд биш, аажмаар нэмэгдүүл (acceleration): `vel.x += accel * dt`, товч тавихад зогсох хүртэл удааширна (friction).

## Цааш судлах

- [Compiler Explorer](https://godbolt.org) — өөр код бичээд assembly-г нь хар
- [raylib cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html) — бүх функцийн жагсаалт
- [raylib examples](https://www.raylib.com/examples.html) — жишээ бүрийн кодыг хар
- [learncpp.com](https://www.learncpp.com/) — C++-ийг системтэй сурах
- "Fix Your Timestep!" (Glenn Fiedler) — game loop-ийн гүнзгий нийтлэл
