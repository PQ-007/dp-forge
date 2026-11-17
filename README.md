# DP club

DP club-ийн бүх код энд байна. Улирлын турш нэг тоглоомыг C++ ба [raylib](https://www.raylib.com/) ашиглан эхнээс нь бүтээнэ.

```
dp-club/
├── CMakeLists.txt        # бүх төслийг build хийнэ (raylib-г автоматаар татна)
├── game/src/             # улирлын турш томрох тоглоом
└── week02/               # долоо хоног бүрийн жижиг жишээнүүд
```

## 1. Суулгах (нэг удаа)

| OS | Хэрэгтэй зүйл |
|---|---|
| **Windows** | [Visual Studio 2022 Community](https://visualstudio.microsoft.com/) ("Desktop development with C++" сонгоно) + [Git](https://git-scm.com/) |
| **macOS** | Terminal дээр `xcode-select --install`, дараа нь `brew install cmake` |
| **Linux (Ubuntu)** | `sudo apt install build-essential cmake git libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev` |
| **Linux (Fedora)** | `sudo dnf install gcc-c++ cmake git libX11-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel mesa-libGL-devel` |

Код засахад [VS Code](https://code.visualstudio.com/) + "C/C++" ба "CMake Tools" extension тохиромжтой.

## 2. Fork → clone

1. GitHub дээр энэ repo-г **Fork** хийнэ.
2. Өөрийн хуулбараа татна:
   ```bash
   git clone https://github.com/<ТАНЫ_НЭР>/dp-club.git
   cd dp-club
   git remote add upstream https://github.com/PQ-007/dp-club.git   # нэг удаа
   ```

## 3. Build ба ажиллуулах

```bash
cmake -S . -B build          # анх удаа raylib-г татна (1–2 минут)
cmake --build build
```

Ажиллуулах (Windows дээр `build\Debug\game.exe`):

```bash
./build/game          # тоглоом
./build/w02_window    # долоо хоног 2-ийн жишээнүүд
./build/w02_move
./build/w02_delta
```

## 4. Долоо хоног бүр

```bash
git pull upstream main     # багшийн шинэ кодыг татах
git add .
git commit -m "Нэмсэн зүйлээ бич"
git push                   # өөрийн fork руу илгээх
```

**Зөвлөгөө:** Өөрийн нэмэлтийг `game/src/my_*.cpp` гэх мэт тусдаа файлд бичвэл багшийн шинэчлэлтэй conflict бага гарна. `game/src/` доторх бүх `.cpp` файл автоматаар build-д орно.
