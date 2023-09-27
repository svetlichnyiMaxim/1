//
// Created by sch-57-d25 on 27.09.2023.
//

#ifndef HANOY_TOWER_LINE1_H
#define HANOY_TOWER_LINE1_H


class Line {
    unsigned char elements[8];

public:
    void display();
    void setElements(unsigned char *newElement);
    std::string toStr();

    bool isFilled();

    Line removeTopElement();

    Line addElement(int element);

    Line addElement(std::byte element);
};

struct Time {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
};
#endif //HANOY_TOWER_LINE1_H
