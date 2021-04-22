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
        bool parcoursLargeur(std::vector<std::vector <int>>, int, int, std::vector<int>);
        int fordFulkerson(std::vector<std::vector <int>>, int, int);
        std::vector<std::vector <int>> grapheEtCapacites;
        std::vector<std::vector <int>> fillGraph(std::vector<std::vector <int>>);
};

#endif /* !PART2STEP2_HPP_ */