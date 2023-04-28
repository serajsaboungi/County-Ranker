#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using std::cout;
using std::string;
using std::vector;
using std::pair;

class County
{
    float score;
    int index;
    string name;
    string state;
    vector<float> pop;
    vector<float> age;
    vector<float> ethnic;
    pair<float, float> income;
    pair<float, float> edu;

public:
    County(int index, string name, string state, vector<float> pop, vector<float> age, pair<float, float> edu,
           vector<float> ethc, pair<int, int> inc);


    void calculateRank(vector<pair<float, int>>& input, int ethcIndex);

    bool operator<(const County& rhs) const;
    bool operator<=(const County& rhs) const;
    bool operator>(const County& rhs) const;

    void display();
    void displayAttributes();
    void printName();
    void printPop();
    void printAge();
    void printEdu();
    void printEthc();
    void printInc();
    void printAll();
};


