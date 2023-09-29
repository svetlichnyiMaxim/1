//
// Created by sch-57-d25 on 29.09.2023.
//
using namespace std;

#ifndef HANOY_TOWER_POSITION_H
#define HANOY_TOWER_POSITION_H

#include <utility>
#include <string>
#include <vector>
#include "Line.h"

class Position {
private:
    unsigned char startLine;
    Line pos[3];
public:

    pair<vector<Position>, int> startSolving(int depth);

    std::__cxx11::basic_string<char> toStr();

    void display();

    bool hasWon();

    std::vector<pair < int, int>> possibleMove();

    pair<vector<Position>, int> generateMoves(int depth, int originalDepth);

    std::vector<Position> generateMoves();

    Position applyMove(pair<int, int> move);
};

#endif //HANOY_TOWER_POSITION_H
