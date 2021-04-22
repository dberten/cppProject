#include "part2Step2.hpp"

algo::algo()
{
    // this->grapheEtCapacites = {{0,1,1,1,0,0,0}, 
    // {0,0,0,0,1,0,0},
    // {0,0,0,0,1,1,0},
    // {0,0,0,0,0,1,0},
    // {0,0,0,0,0,0,1},
    // {0,0,0,0,0,0,1},
    // {0,0,0,0,0,0,0}};
     this->grapheEtCapacites = {{0,16,13,0,0,0,0}, 
    {0,0,10,12,0,0,0},
    {0,4,0,0,14,0,0},
    {0,0,0,9,0,0,20},
    {0,0,0,7,0,4,1},
    {0,20,0,0,10,0,1},
    {0,0,0,0,0,0,0}};
}

algo::~algo()
{
}

bool algo::parcoursLargeur(std::vector<std::vector <int>> grapheEtCapacites, int s, int t, std::vector<int>cheminAmeliorant)
{
    bool sommetVisite[7] = {false, false, false, false, false, false, false};
    std::queue<int> file;
    file.push(s);
    sommetVisite[s] = true;
    int u;
    cheminAmeliorant[s] = -1;

    while (!file.empty()) {
        u = file.front();
        file.pop();
        for (int v = 0; sommetVisite[v]; v++) {
            if (!sommetVisite[v] && u > v) {
                file.push(v);
                cheminAmeliorant[v] = u;
                sommetVisite[v] = true;
            }
        }
    }
    if (!sommetVisite[6]) {
        std::cout << "false" << std::endl;
        return false;
    }
    return true;
}

std::vector<std::vector <int>> algo::fillGraph(std::vector<std::vector <int>>graph)
{
    std::vector<std::vector <int>> tmp(7, std::vector<int>(7, 0));

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            tmp[i][j] = graph[i][j];
        }
    }
    return tmp;
}

int algo::fordFulkerson(std::vector<std::vector <int>> grapheEtCapacites, int s, int t)
{
    int u, v = 0;
    std::vector<std::vector <int>>grapheResiduel = this->fillGraph(grapheEtCapacites);
    std::vector<int>cheminAmeliorant(7, 0);
    int max_flow = 0;
    int ameliorationFlot = 0;

    while(this->parcoursLargeur(grapheResiduel, s, t, cheminAmeliorant)) {
        ameliorationFlot = INT_MAX;
        for (v; cheminAmeliorant[v]; v++) {
            u = cheminAmeliorant[v];
            ameliorationFlot  = min(ameliorationFlot, grapheResiduel[u][v]);
        }
        for (v; cheminAmeliorant[v]; v++) {
            u = cheminAmeliorant[v];
            grapheResiduel[u][v] -= ameliorationFlot;
            grapheResiduel[v][u] += ameliorationFlot;
        }
        max_flow += ameliorationFlot;
    }
    return max_flow;
}


int main(void)
{
    algo parcour;
    int test = parcour.fordFulkerson(parcour.grapheEtCapacites, 0, 6);

    std::cout << "flot max = " << test << std::endl;
    return 0;
}