# Долоо хоног 2: алхам алхмаар жишээнүүд
add_executable(w02_hello 01_hello_cpp/main.cpp)        # raylib хэрэггүй
dp_raylib_app(w02_window 02_window/main.cpp)
dp_raylib_app(w02_move   03_move/main.cpp)
dp_raylib_app(w02_delta  04_delta_time/main.cpp)
