# Versiunea minimă de CMake necesară
cmake_minimum_required(VERSION 3.16)

# Numele proiectului tău
project(VerificatorPar VERSION 1.0.0 LANGUAGES CXX)

# Folosim standardul C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setări specifice Qt pentru a genera cod automat în fundal
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Căutăm biblioteca Qt6 pe sistemul tău
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Spunem din ce fișiere este creată aplicația
add_executable(VerificatorPar main.cpp)

# Legăm aplicația ta de biblioteca vizuală Qt
target_link_libraries(VerificatorPar PRIVATE Qt6::Widgets)