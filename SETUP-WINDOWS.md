# Windows дээр суулгах заавар

Энэ зааврыг **нэг удаа** хийнэ. Visual Studio том (хэдэн GB) тул клубээс өмнө гэртээ суулгаж ирээрэй.

**Хэрэгтэй зүйл:** Windows 10 эсвэл 11, интернет, ~10 GB сул зай, GitHub бүртгэл (байхгүй бол https://github.com/signup дээр үүсгэ).

---

## 1. Visual Studio суулгах

1. https://visualstudio.microsoft.com/ руу ороод **Visual Studio Community** (үнэгүй) татна.
2. Installer нээгдэхэд **Workloads** хэсгээс **Desktop development with C++**-г чагтална.
3. Баруун талын жагсаалтад **C++ CMake tools for Windows** чагттай эсэхийг шалга (ихэвчлэн анхнаасаа чагттай байдаг).
4. **Install** дараад дуустал хүлээнэ.

> ⚠️ **Visual Studio** (нил ягаан нь) хэрэгтэй. **Visual Studio Code** (цэнхэр нь биш!)

## 2. Git суулгах

https://git-scm.com/download/win хаягаас татаж суулгана. Бүх асуултад **Next** дарахад болно.

## 3. Терминал нээх

Start цэснээс **Developer PowerShell for VS** гэж хайгаад нээнэ. Энэ бол compiler болон CMake бэлэн байгаа тусгай терминал. **Цаашдын бүх командыг энд бичнэ.**

Бүх зүйл суусан эсэхийг шалгах:

```powershell
git --version
cmake --version
```

Хоёулаа хувилбарын дугаар хэвлэвэл бэлэн.

Git-д нэрээ таниулах (нэг удаа):

```powershell
git config --global user.name "Таны Нэр"
git config --global user.email "github-д-бүртгүүлсэн@имэйл.com"
```

## 4. Fork → clone

1. https://github.com/PQ-007/dp-forge руу ороод баруун дээд талын **Fork** → **Create fork** дарна.
2. Терминал дээр (`<ТАНЫ_НЭР>`-ийн оронд өөрийн GitHub нэрийг бич):

```powershell
mkdir C:\dp
cd C:\dp
git clone https://github.com/<ТАНЫ_НЭР>/dp-forge.git
cd dp-forge
git remote add upstream https://github.com/PQ-007/dp-forge.git
```

## 5. Build хийх

```powershell
cmake -S . -B build
cmake --build build
```

Анх удаа raylib-г интернетээс татдаг тул хэдэн минут болно. Жоохон удна дараа нь гайгүй хурдан ажиллана.

## 6. Ажиллуулах

```powershell
.\build\Debug\w02_hello.exe     # терминал дээр текст хэвлэнэ
.\build\Debug\w02_window.exe    # цонх нээгдэнэ
.\build\Debug\w02_move.exe
.\build\Debug\w02_delta.exe
.\build\Debug\game.exe          # улирлын тоглоом
```

Цонхыг **ESC** дарж хаана.

## 7. Visual Studio дээр код засах

1. Visual Studio нээгээд **Open a local folder** → `C:\dp\dp-forge` сонгоно.
2. Visual Studio `CMakeLists.txt`-г өөрөө таньж тохируулна. Доод талын **Output** цонхонд CMake дуустал хүлээ.
3. Дээд талын ногоон ▶ товчны дэргэдэх жагсаалтаас (**Select Startup Item**) `game.exe`-г сонгоно.
4. **F5** дарж ажиллуулна.

Кодоо засаад дахин **F5** дарахад автоматаар build хийгээд ажиллуулна.

## 8. Долоо хоног бүр

```powershell
git pull upstream main          # багшийн шинэ кодыг татах
cmake --build build
git add .
git commit -m "Нэмсэн зүйлээ бич"
git push                        # өөрийн fork руу илгээх
```

Анх удаа `git push` хийхэд GitHub-д нэвтрэх цонх гарна. Нэвтрээд зөвшөөрөл (**Authorize**) өгнө.

---

## Түгээмэл асуудал

| Алдаа | Шийдэл |
|---|---|
| `cmake` / `git` `is not recognized` | Энгийн PowerShell биш, **Developer PowerShell for VS** нээ. Git саяхан суулгасан бол терминалаа хаагаад дахин нээ. |
| `No CMAKE_CXX_COMPILER could be found` | **Visual Studio Installer** → **Modify** → **Desktop development with C++** чагтлаад суулга. Дараа нь `build` хавтсаа устгаад (доорх команд) дахин build хий. |
| raylib татахад алдаа гарсан | Интернетээ шалга. `build` хавтсаа устгаад дахин оролд. |
| `LNK1168: cannot open ...exe for writing` | Програм ажиллаж байна. Цонхыг хаагаад дахин build хий. |
| `.exe` олдохгүй | `build\Debug\` дотор байгаа. Build амжилттай болсон эсэхийг шалга. |
| `git commit` хийхэд `Please tell me who you are` | 3-р алхмын `git config` хоёр командыг ажиллуул. |
| `'upstream' does not appear to be a git repository` | 4-р алхмын `git remote add upstream ...` командыг ажиллуул. |

`build` хавтсыг устгах:

```powershell
Remove-Item build -Recurse -Force
```

Шийдэгдэхгүй бол алдааны мессежийг бүтнээр нь хуулж багшдаа илгээ.
