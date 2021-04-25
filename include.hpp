#ifndef PART2STEP2_HPP_
#define PART2STEP2_HPP_
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <tuple>
#include <ostream>
#include <stdbool.h>
#include <iomanip>
#include <limits.h>
#include <string.h>
using namespace std;

class algo {
    public:
        algo();
        ~algo();
        bool parcoursLargeur(std::vector<std::vector <int>>, int, int, std::vector<int>&);
        int fordFulkerson(std::vector<std::vector <int>>, int, int);
        std::vector<std::vector <int>> fillGraph(std::vector<std::vector <int>>);
        std::vector<std::vector <int>> matriceAdjacence(std::vector<std::vector<int>> matriceCapacite);
        std::vector<std::vector <int>> part2Step1;
        std::vector<std::vector <int>> part3Step1;
        std::vector<std::vector <int>> part3Step2;
        std::vector<std::vector <int>> part3Step3;
        std::vector<std::vector <int>> part3Step4;
        void dumpMatrix(std::vector<std::vector <int>> matrix);
};

#endif /* !PART2STEP2_HPP_ */