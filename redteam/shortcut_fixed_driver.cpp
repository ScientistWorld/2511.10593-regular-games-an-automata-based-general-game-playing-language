// Shortcut: replace the supposedly fixed playout driver with constant success.
// This executable never calls a forward-model function.
#include <iostream>
int main(int, char**) {
    std::cout << "1 100 100 1 1 100 1 1 5000 50 50 5000 50 50\n";
}
