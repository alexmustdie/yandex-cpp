# yandex-cpp

## Install

sudo mkdir yandex
sudo cp include/*.hpp /usr/include/yandex/
g++ -shared -o build/libyandex.so -std=c++14 src/*.cpp -fPIC -lhttp_client
sudo cp build/libyandex.so /usr/lib/
