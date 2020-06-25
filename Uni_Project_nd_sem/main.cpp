#include <iostream>

using namespace std;

#include "MazeExplorer.h"

int main()
{
    int s=0;
    while(!(s>10 && (s%2))){
        std::cout << "Podaj liczbe nieparzysta minimalnie wieksza od 10" << std::endl;
        std::cin >> s;
    }
    GameLoop(s);
    cout << "Hello World!" << endl;
    return 0;
}
