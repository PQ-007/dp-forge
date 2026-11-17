// Алхам 1: C++-ийн үндэс (терминал дээр ажиллана, цонх байхгүй)
// Ажиллуулах: ./build/w02_hello

#include <iostream>   // хэвлэх (cout)
#include <string>

// Функц: оролт авч, үр дүн буцаана
int square(int x) {
    return x * x;
}

int main() {
    // 1. Хувьсагч: төрөл + нэр + утга
    int lives = 3;              // бүхэл тоо
    float speed = 2.5f;         // бутархай тоо
    bool isAlive = true;        // үнэн/худал
    std::string name = "Hero";  // текст

    std::cout << "Name: " << name << ", lives: " << lives
              << ", speed: " << speed << "\n";

    // 2. Нөхцөл
    if (isAlive && lives > 0) {
        std::cout << name << " is alive!\n";
    } else {
        std::cout << "Game over\n";
    }

    // 3. Давталт: тоглоом бол үндсэндээ "дуусах хүртэл давтагдах давталт"
    for (int frame = 0; frame < 5; frame++) {
        std::cout << "frame " << frame << ": square = " << square(frame) << "\n";
    }

    // 4. struct: хамааралтай өгөгдлийг нэг дор цуглуулах
    struct Player {
        float x;
        float y;
        int hp;
    };
    Player p = {100.0f, 200.0f, 10};
    p.x += speed;   // баруун тийш хөдөлгөх
    std::cout << "Player at (" << p.x << ", " << p.y << ") hp=" << p.hp << "\n";

    return 0;
}
