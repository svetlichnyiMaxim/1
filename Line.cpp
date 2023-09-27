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
    Line newLine;
    newLine.setElements(elements);
    newLine[topOneIndex()] = 0;
    return newLine;
}

Line Line::addElement(byte element) {
    // we don't check if there is any space left, cause there are n elements and size of tower we want to move
    // and element to move is n-1 at max
    Line copy;
    int additionalIndex = (topOne() == 0) ? 0: -1;
    copy[topOneIndex()+additionalIndex] = element;
    return copy;
}

bool Line::isEmpty() {
    return elements.last() == 0.toByte()
}

int Line::topOne() {
    // we use the fact, that they are always sorted like this 0, 1, 2, 3, 4...
    elements.forEachIndexed
    {
        index, i->
        if (i != 0.toByte() || index == 7) return i.toInt()
    }
    // This never happens
    throw IllegalStateException()
}

int Line::topOneIndex() {
    // we use the fact, that they are always sorted like this 0, 1, 2, 3, 4...
    for (int index: elements.size()) {
        if (elements[index] != 0.toByte() || index == 7) return index;
    }
    // This never happens
    throw;
}
/*
class Line1 {
public:
    Line(unsigned char string[8]) {
        Line c1 = Line(nullptr);
        memcpy(c1.elements, string, 8);
    }


};
*/