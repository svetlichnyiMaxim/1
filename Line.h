//
// Created by sch-57-d25 on 27.09.2023.
//

#ifndef HANOY_TOWER_LINE1_H
#define HANOY_TOWER_LINE1_H


#include "Position.h"

class Line {
private:
    unsigned char elements[8];

public:
    void display();

    void setElements(unsigned char *newElement);

    std::string toStr();

    bool isFilled();

    Line removeTopElement();

    Line addElement(int element);

    int topOneIndex();

    int topOne();

    bool isEmpty();

    Line addElement(unsigned char element);
};

#endif //HANOY_TOWER_LINE1_H
