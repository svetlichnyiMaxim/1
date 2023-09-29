#include <iostream>
#include "Line.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned char i[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Line line;
    line.setElements(i);
    line.display();
}
