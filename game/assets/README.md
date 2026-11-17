# assets/ — таны зураг, дуу

Тоглоомын зураг (`.png`), дуу (`.wav`, `.ogg`), фонт зэргийг энд хийнэ.

Кодонд ингэж ачаална (`InitWindow`-ийн **дараа**):

```cpp
Texture2D hero = LoadTexture(ASSETS_DIR "hero.png");
Sound     jump = LoadSound(ASSETS_DIR "jump.wav");   // InitAudioDevice() хийсний дараа
```

`ASSETS_DIR`-г CMake автоматаар тохируулдаг. Тиймээс PowerShell, Visual Studio, Linux аль дээр ч, ямар хавтаснаас ажиллуулсан ч файл олдоно.
