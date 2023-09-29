#include <bits/stdc++.h>
#include <cstring>
#include "Line.h"
#include "Position.h"
#include "main.h"

using namespace std;

pair<vector<Position>, int> Position::startSolving(int depth) {
    return generateMoves(depth, depth);
}

string Position::toStr() {
    string str = reinterpret_cast<const char *>(startLine);
    for (Line it: pos) {
        str += it.toStr();
    }
    return str;
}

void Position::display() {
    for (Line it: pos) {
        it.display();
        cout << endl;
    }
}

bool Position::hasWon() {
    for (int index = 0; index < 3; index++) {
        if (index != startLine && pos[index].isFilled()) {
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> Position::possibleMove() {
    vector<pair<int, int>> list;
    for (int index = 0; index < 3; index++) {
        Line it = pos[index];
        if (!it.isEmpty())
            for (int index1 = 0; index1 < 3; index1++) {
                Line it1 = pos[index1];
                if (it.topOne() > it1.topOne() || it.isEmpty()) {
                    list.push_back(pair(index1, index));
                }
            }
    }
    return list;
}

pair<vector<Position>, int> Position::generateMoves(int depth, int originalDepth) {
    int currentDepth = originalDepth - depth + 1;
    // no need to continue investigation if we can't improve depth score
    if (depth == 1) {
        for (Position it: generateMoves()) {
            if (it.hasWon()) {
                pair<vector<Position>, int> returnVec1;
                returnVec1.first.push_back(it);
                returnVec1.second = currentDepth;
                return returnVec1;
            }
        }
        // if we weren't able to find a solution, what's the point of returning it?
        return {};
    }

    vector<pair<vector<Position>, int>> list;
    for (Position it: generateMoves()) {
        if (it.hasWon()) {
            vector<pair<pos, currentDepth>> returnVec1;
            returnVec1.pushBack(pair(pos, currentDepth));
            return returnVec1;
        }
        // Adds all moving sequences
        for (pair<vector<Position>, int> it: pos.generateMoves(depth - 1, originalDepth)) {
            if (!it.first.empty()) {
                list.push_back(it);
            }
        }
    }
    int minDepth = 10000;
    vector<Position> bestChoice;
    for (pair<vector<Position>, int> it: list) {
        if (!it.first.empty()) {
            if (it.second < minDepth) {
                vector<Position> listToCopy = it.first;
                memcpy(&bestChoice, &listToCopy, it.first.size());
            }
        }
    }
    // fallback option
    return {};
}

vector<Position> Position::generateMoves() {
    string str = toStr();
// if this pos was stored, we can use it's cached version, saves a lot of time
    if (occuredPositions.count(str) != 0) {
        return occuredPositions[str];
    }
    vector<Position> generatedList;

    for (pair<int, int> it: possibleMove()) {
        generatedList.push_back(applyMove(it));
    }
// Stores positions with it's generatedMoves
    occuredPositions[str] = generatedList;
    return generatedList;
}

Position Position::applyMove(pair<int, int> move) {
    int lineToRemove = move.first;
    int lineToAdd = move.second;
    int elementToMove = pos[lineToRemove].topOne();
    Line copy[3] = pos.toMutableList();
    copy[lineToRemove] = copy[lineToRemove].removeTopElement();
    copy[lineToAdd] = copy[lineToAdd].addElement(elementToMove);
    Position newPos;
    newPos.startLine = startLine;
    newPos.pos = copy;
    return newPos;
}