# DP club

Энэ repo бол **таны өөрийн тоглоомын суурь**. Fork хийсэн мөчөөс эхлэн `game/` хавтас бол **таных**: ямар тоглоом хийхээ өөрөө шийднэ.

Багш долоо хоног бүр шинэ жишээ (`lessons/`) болон шинэ барилгын блок (`engine/`) нэмнэ. Та тэдгээрийг өөрийн тоглоомдоо холбож, улирлын төгсгөлд game jam-д өөрийн тоглоомтойгоо орно. Хэрэгсэл: C++ ба [raylib](https://www.raylib.com/).

Бүтэн хөтөлбөр: <https://bright-starship-8e8a16.netlify.app/>

## Бүтэц

```
dp-forge/
├── lessons/           БАГШ  долоо хоног бүрийн жишээ: уншиж, ажиллуулж, хуулж ав
│   └── week02/              C++ ба game loop
├── engine/            БАГШ  тоглоомын суурь блокууд (3-р долоо хоногоос)
├── game/              ★ ТА  таны тоглоом
│   ├── src/                 код (main.cpp, player.cpp, config.h …)
│   └── assets/              зураг, дуу
├── bots/                    8-р долоо хоногийн тэмцээн
├── CMakeLists.txt     БАГШ  бүгдийг build хийнэ (raylib-г автоматаар татна)
└── SETUP-WINDOWS.md         Windows дээр суулгах заавар
```

## Дүрэм

1. **Зөвхөн `game/` дотор код бич** (8-р долоо хоногоос `bots/my_bot.cpp` ч гэсэн).
2. **`lessons/`, `engine/`, `CMakeLists.txt`-г бүү засаарай.** Өөрчлөх хэрэгтэй бол файлыг `game/src/` руу хуулж аваад тэнд засна. Тэгвэл багшийн шинэчлэлийг татахад conflict хэзээ ч гарахгүй.
3. **`game/src/` дотор шинэ `.cpp` файл, дэд хавтас** үүсгэж болно. Бүгд автоматаар build-д орно.
4. **Зураг, дууг `game/assets/`-д** хийгээд `LoadTexture(ASSETS_DIR "hero.png")` гэж ачаална.

## 1. Суулгах (нэг удаа)

| OS | Хэрэгтэй зүйл |
|---|---|
| **Windows** | [Visual Studio Community](https://visualstudio.microsoft.com/) ("Desktop development with C++" сонгоно) + [Git](https://git-scm.com/). Дэлгэрэнгүй алхам: **[SETUP-WINDOWS.md](SETUP-WINDOWS.md)** |
| **macOS** | Terminal дээр `xcode-select --install`, дараа нь `brew install cmake` |
| **Linux (Ubuntu)** | `sudo apt install build-essential cmake git libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev` |
| **Linux (Fedora)** | `sudo dnf install gcc-c++ cmake git libX11-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel mesa-libGL-devel` |

## 2. Fork → clone

1. GitHub дээр энэ repo-г **Fork** хийнэ.
2. Өөрийн хуулбараа татна:
   ```bash
   git clone https://github.com/<ТАНЫ_НЭР>/dp-forge.git
   cd dp-forge
   git remote add upstream https://github.com/PQ-007/dp-forge.git   # нэг удаа
   ```

## 3. Build ба ажиллуулах

```bash
cmake -S . -B build          # анх удаа raylib-г татна (хэдэн минут)
cmake --build build
```

Ажиллуулах (Windows дээр `.\build\Debug\game.exe` гэх мэт):

```bash
./build/game          # таны тоглоом
./build/w02_hello     # долоо хоног 2-ийн жишээнүүд
./build/w02_window
./build/w02_move
./build/w02_delta
```

## 4. Долоо хоног бүр

```bash
git pull upstream main     # багшийн шинэ жишээ, блокуудыг татах
cmake --build build
git add .
git commit -m "Нэмсэн зүйлээ бич"
git push                   # өөрийн fork руу илгээх
```

## Долоо хоногууд

| # | Сэдэв | Хуудас |
|---|---|---|
| 2 | C++ ба game loop | [lessons/week02](lessons/week02/README.md) |
