# yandex-cpp

## Dependencies

<a href="https://github.com/alexmustdie/http-client-cpp">http-client</a> (my own)

## Install

sudo mkdir yandex<br>
sudo cp include/\*.hpp /usr/include/yandex/<br>
g++ -shared -o build/libyandex.so -std=c++14 src/\*.cpp -fPIC -lhttp_client<br>
sudo cp build/libyandex.so /usr/lib/
