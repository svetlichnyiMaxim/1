#include <bits/stdc++.h>
#include <cstring>
#include "Line.h"

using namespace std;


void Line::setElements(unsigned char newElement[8]) {
    memcpy(elements, newElement, 8);
}

void Line::display() {
    for (int value: elements) {
        if (value != 0) {
            cout << value << " ";
        } else {
            cout << "  ";
        }
    }
}

string Line::toStr() {
    string stringBuilder = "";
    for (char it: elements) {
        stringBuilder += it;
    }
    return stringBuilder;
}

bool Line::isFilled() {
    return elements[0] != '0';
}

Line Line::removeTopElement() {
    unsigned char elements1[8];
    elements1[topOneIndex()] = 0;
    Line newLine;
    newLine.setElements(elements1);
    return newLine;
}

Line Line::addElement(unsigned char element) {
    // we don't check if there is any space left, cause there are n elements and size of tower we want to move
    // and element to move is n-1 at max
    unsigned char elements1[8];
    memcpy(elements1, elements, 8);
    int additionalIndex = (topOne() == 0) ? 0 : -1;
    elements1[topOneIndex() + additionalIndex] = element;
    Line copy;
    copy.setElements(elements1);
    return copy;
}

bool Line::isEmpty() {
    return elements[7] == 0;
}

int Line::topOne() {
    // we use the fact, that they are always sorted like this 0, 1, 2, 3, 4...
    for (int index = 0; index < 8; index++) {
        if (elements[index] != 0 || index == 7) return elements[index];
    }
    // This never happens
    throw;
}

int Line::topOneIndex() {
    // we use the fact, that they are always sorted like this 0, 1, 2, 3, 4...
    for (int index = 0; index < 8; index++) {
        if (elements[index] != 0 || index == 7) return index;
    }
    // This never happens
    throw;
}