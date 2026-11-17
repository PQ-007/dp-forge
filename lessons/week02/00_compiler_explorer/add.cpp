// Compiler Explorer демо: https://godbolt.org
// 1) Энэ кодыг зүүн талд хуулж тавина.
// 2) Compiler: x86-64 gcc (эсвэл clang) сонгоно.
// 3) Баруун талд гарсан assembly-г харна.
// 4) Compiler options хэсэгт -O0, дараа нь -O2 гэж бичээд ялгааг харьцуул.

int add(int a, int b) {
    return a + b;          // -O2 үед ганц "lea" заавар болно
}

int square(int x) {
    return x * x;          // "imul" заавар
}

int sum_to(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;        // -O2 үед compiler давталтыг томьёо болгож магадгүй!
    }
    return total;
}

// Асуулт: Долоо хоног 1-д угсарсан ADDER, ALU чинь
// энэ "add" зааврыг яг яаж гүйцэтгэдэг вэ?
