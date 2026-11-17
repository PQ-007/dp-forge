# Windows дээр суулгах заавар (VS Code)

Алхмуудыг **яг энэ дарааллаар** хий. Алхам бүрийн төгсгөлд **✅ шалгах** зүйл бий. Тэр харагдахгүй бол дараагийн алхам руу бүү ор, доорх "Түгээмэл асуудал"-ыг хар.

**Хэрэгтэй:** Windows 10 эсвэл 11 · интернет · ~10 GB сул зай · 1 цаг орчим (ихэнх нь татаж суулгах хугацаа)

---

## Хэсэг А · Гэртээ суулгах (нэг удаа)

### А1. GitHub бүртгэл

1. https://github.com/signup дээр бүртгүүлнэ.
2. Имэйлээ нээгээд GitHub-аас ирсэн **баталгаажуулах** линк дээр дар. Баталгаажуулаагүй бол fork хийж чадахгүй.

✅ https://github.com руу ороход баруун дээд буланд таны зураг/дүрс харагдана.

### А2. C++ compiler (Build Tools) — хамгийн удаан тул ЭХЭЛЖ эхлүүл

VS Code бол зөвхөн засварлагч. C++ кодыг машин код болгох **compiler** тусдаа хэрэгтэй.

1. Энэ линкээр татна: https://aka.ms/vs/17/release/vs_BuildTools.exe
2. Татсан `vs_BuildTools.exe`-г ажиллуулна. Асуувал **Yes** / **Continue**.
3. **Workloads** цонхонд **Desktop development with C++**-г чагтална.
4. Баруун талын жагсаалтад дараах хоёр чагттай эсэхийг шалга (ихэвчлэн анхнаасаа чагттай):
   - **MSVC … C++ x64/x86 build tools**
   - **Windows 11 SDK** (эсвэл Windows 10 SDK)
5. Баруун доод талын **Install** дарна. Хэдэн GB татна. **Хүлээж байх хооронд А3, А4, А5-ыг хий.**

✅ Төгсгөлд нь "Desktop development with C++" доор **Installed** гэж бичигдэнэ.

> ⚠️ "Visual Studio Installer" цонх **restart** хий гэвэл хий.

### А3. VS Code

1. https://code.visualstudio.com/ → **Download for Windows**.
2. Суулгахдаа бүх асуултад **Next**. **"Add to PATH"** чагттай байх ёстой (анхнаасаа чагттай).

✅ Start цэсэнд **Visual Studio Code** гарч ирнэ.

### А4. Git

> VS Code-оо **эхлээд** суулгасан байх ёстой (А3).

1. https://git-scm.com/download/win → **Click here to download** (64-bit).
2. Суулгахдаа **бүх цонхонд Next** дарна, **ганц цонхноос бусад нь:**
   - **"Choosing the default editor used by Git"** гэсэн цонхонд жагсаалтаас **"Use Visual Studio Code as Git's default editor"**-г сонгоно. (Анхдагч нь Vim бөгөөд түүнээс гарах аргыг мэдэхгүй бол гацна.)

✅ Сүүлийн цонхонд **Finish**.

### А5. CMake

1. https://cmake.org/download/ → **Binary distributions** хэсгээс **Windows x64 Installer** (`.msi`) татна.
2. Суулгахдаа **"Add CMake to the PATH environment variable"** (эсвэл "Add CMake to the system PATH for all users") **заавал чагтлагдсан** байх ёстой.

✅ **Finish**.

### А6. Компьютерээ RESTART хий

А2 (Build Tools) дууссаны дараа компьютерээ **заавал** унтрааж асаа. Тэгэхгүй бол шинэ програмууд олдохгүй.

### А7. Бүгд суусан эсэхийг шалгах

1. VS Code нээнэ.
2. Дээд цэснээс **Terminal → New Terminal** (эсвэл `` Ctrl+` ``). Доор терминал нээгдэнэ.
3. Дараах гурвыг нэг нэгээр нь бичиж Enter дарна:
   ```powershell
   git --version
   cmake --version
   code --version
   ```

✅ Гурвуулаа хувилбарын дугаар хэвлэнэ (жишээ нь `git version 2.47.1.windows.1`).

### А8. VS Code extension

1. VS Code дээр `Ctrl+Shift+X` (Extensions).
2. Хайх хэсэгт **C/C++ Extension Pack** гэж бичнэ.
3. **Microsoft**-ийн гаргасныг сонгоод **Install**. (Дотроо **C/C++** болон **CMake Tools** орсон.)

✅ Зүүн талын хэсэгт **CMake** (гурвалжин) дүрс гарч ирнэ.

### А9. Git-ийн тохиргоо (нэг удаа)

VS Code-ийн терминалд **нэг нэгээр нь** бичнэ (`Таны Нэр`, имэйлийг өөрийнхөөрөө соль):

```powershell
git config --global user.name "Таны Нэр"
git config --global user.email "github-д-бүртгүүлсэн@имэйл.com"
git config --global pull.rebase false
git config --global core.editor "code --wait"
```

Сүүлийн хоёр мөр долоо хоног бүр `git pull` хийхэд гацахаас сэргийлнэ.

✅ `git config --global --list` гэж бичихэд дээрх 4 тохиргоо харагдана.

**Хэсэг А дууслаа! Хичээл дээр Хэсэг Б-г хамтдаа хийнэ.**

---

## Хэсэг Б · Repo-гоо авах ба ажиллуулах

### Б1. Fork

1. GitHub-д нэвтэрсэн байдлаар https://github.com/PQ-007/dp-forge руу орно.
2. Баруун дээд талын **Fork** товч → **Create fork**.

✅ Хаягийн мөрөнд `github.com/ТАНЫ_НЭР/dp-forge` гэж харагдана.

### Б2. Clone

VS Code-ийн терминалд **нэг нэгээр нь** бичнэ (`ТАНЫ_НЭР` = таны GitHub нэр):

```powershell
mkdir C:\dp
cd C:\dp
git clone https://github.com/ТАНЫ_НЭР/dp-forge.git
cd dp-forge
git remote add upstream https://github.com/PQ-007/dp-forge.git
git remote -v
```

✅ `git remote -v` дөрвөн мөр хэвлэнэ: хоёр нь `origin … ТАНЫ_НЭР/dp-forge`, хоёр нь `upstream … PQ-007/dp-forge`.

> 💡 Яагаад `C:\dp`? Замд кирилл үсэг, хоосон зай, OneDrive байхгүй бол асуудал гарахгүй.

### Б3. Хавтсаа VS Code-оор нээх

1. **File → Open Folder…** → `C:\dp\dp-forge` → **Select Folder**.
2. "Do you trust the authors…?" гэж асуувал → **Yes, I trust the authors**.
3. "CMake Tools would like to configure IntelliSense…" гэвэл → **Allow**.

✅ Зүүн талын Explorer-т `game`, `lessons`, `CMakeLists.txt` … харагдана.

### Б4. Kit сонгох (compiler-ээ заах)

1. `Ctrl+Shift+P` дарж, **CMake: Select a Kit** гэж бичээд Enter.
2. Жагсаалтаас **Visual Studio Build Tools 2022 Release - amd64**-г сонгоно.
   - Жагсаалтад байхгүй бол **[Scan for kits]**-г сонгоод, дахин 1-р алхмыг хий.

✅ Доод мөрөнд (status bar) эсвэл CMake хэсэгт сонгосон kit-ийн нэр харагдана.

### Б5. Configure (`cmake -S . -B build`-тэй адил)

1. `Ctrl+Shift+P` → **CMake: Configure**.
2. Доор **Output** цонх нээгдэж мөрүүд гүйнэ. Анх удаа raylib-г интернетээс татдаг тул **хэдэн минут** болно.

✅ Output-ийн төгсгөлд `Configuring done` ба `Generating done` гэж гарна.

### Б6. Build (`cmake --build build`-тэй адил)

1. `Ctrl+Shift+P` → **CMake: Build** (эсвэл **F7**).

✅ Output-ийн төгсгөлд `Build finished with exit code 0`.

### Б7. Ажиллуулах

1. `Ctrl+Shift+P` → **CMake: Set Launch/Debug Target** → **game** сонгоно.
2. `Ctrl+Shift+P` → **CMake: Run Without Debugging** (эсвэл **Shift+F5**).

✅ Тоглоомын цонх нээгдэж, A/D-ээр дүр хөдөлнө. **ESC** дарж хаана.

Бусад жишээг (`w02_hello`, `w02_window`, `w02_move`, `w02_delta`) мөн 1-р алхмаар сонгоод ажиллуулна. `w02_hello`-ийн гаралт доорх **Terminal** хэсэгт гарна.

> ⚠️ **VS Code-ийн баруун дээд буланд гарах ▶ товчийг (Run C/C++ File) бүү дар.** Тэр ганц файлыг compile хийх гэж оролдоод алдаа өгнө. Үргэлж **Shift+F5** эсвэл **CMake: Run Without Debugging** ашигла.

### Б8. Анхны өөрчлөлт → commit → push

1. `game/src/config.h`-г нээгээд `PLAYER_SPEED`-ийг `300.0f` → `600.0f` болгоод **Ctrl+S**.
2. **Shift+F5** (автоматаар build хийгээд ажиллуулна). Дүр хурдан болсон уу?
3. Терминалд:
   ```powershell
   git status
   git add .
   git commit -m "Миний анхны өөрчлөлт"
   git push
   ```
4. Анх push хийхэд **GitHub-д нэвтрэх цонх** гарна → **Sign in with your browser** → хөтөч дээр **Authorize** дарна.

✅ GitHub дээр өөрийн fork-оо (`github.com/ТАНЫ_НЭР/dp-forge`) refresh хийхэд "Миний анхны өөрчлөлт" commit харагдана.

---

## Долоо хоног бүр

```powershell
git pull --no-edit upstream main     # багшийн шинэ код
```
Дараа нь **F7** (build) → **Shift+F5** (ажиллуулах). Өөрчлөлт хийсний дараа:
```powershell
git add .
git commit -m "Юу хийснээ бич"
git push
```

---

## SSH key хэрэгтэй юу?

**Үгүй.** Бид `https://` хаягаар clone хийдэг. Push хийхэд Git өөрөө хөтчөөр GitHub-д нэвтрүүлнэ (Б8).

---

## Түгээмэл асуудал

| Юу болсон | Шийдэл |
|---|---|
| `git` / `cmake` / `code` **is not recognized** | Компьютерээ restart хий. Дахиад гарвал тухайн програмыг дахин суулгаж, **PATH** сонголтыг чагтал (А3, А5). |
| **CMake: Select a Kit** дээр Visual Studio байхгүй | **[Scan for kits]** сонго. Байхгүй хэвээр бол Start → **Visual Studio Installer** → **Modify** → **Desktop development with C++** чагтлаад суулга, restart. |
| Configure дээр `No CMAKE_CXX_COMPILER could be found` | Дээрхтэй адил: Build Tools-ийн C++ workload суугаагүй. |
| raylib татахад алдаа / интернет тасарсан | Интернетээ шалга → `Ctrl+Shift+P` → **CMake: Delete Cache and Reconfigure**. |
| `Does not match the generator used previously` | `Ctrl+Shift+P` → **CMake: Delete Cache and Reconfigure**. (Терминалаас `cmake` бүү ажиллуул, зөвхөн CMake командууд.) |
| `LNK1168: cannot open …exe for writing` | Тоглоом ажиллаж байна. Цонхыг нь хаагаад дахин build хий. |
| `#include "raylib.h"` доор улаан зураас | Б5 (Configure)-ыг хийгээгүй. Configure хийгээд хэсэг хүлээ. |
| ▶ дарахад `cl.exe` / `g++` алдаа | Буруу товч. **Shift+F5** ашигла (Б7). |
| `Please tell me who you are` | А9-ийн `git config` командуудыг ажиллуул. |
| `fatal: Need to specify how to reconcile divergent branches` | `git config --global pull.rebase false` гээд дахин `git pull --no-edit upstream main`. |
| `git pull` хийхэд VS Code-д `MERGE_MSG` таб нээгдэж гацсан | Тэр табыг хаа (`Ctrl+W`). Цаашид `--no-edit` нэмж бич. |
| `Permission denied` / `403` push хийхэд | Багшийн repo руу push хийж байна. `git remote -v`-ээр `origin` нь **таны** fork мөн эсэхийг шалга. |
| `'upstream' does not appear to be a git repository` | Б2-ын `git remote add upstream …` командыг ажиллуул. |
| `CONFLICT` гэж гарсан | Багшдаа үзүүл. (Зөвхөн `game/` дотор код бичвэл гарахгүй.) |

Шийдэгдэхгүй бол алдааны мессежийг **бүтнээр нь** хуулж багшдаа илгээ.
