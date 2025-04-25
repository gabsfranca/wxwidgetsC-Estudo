pra compilar tem que usar o seguinte comando:

g++ -o LeitorDeRedesNeurais src/*.cpp src/app/*.cpp src/ui/*.cpp src/core/*.cpp `wx-config --cxxflags --libs` -std=c++17