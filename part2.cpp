#include "include.hpp"

algo::algo()
{
    //premiere matrice d'adjacence graphe et capacité
    this->part2Step1 = {
        {0, 50, 70, 40, 0, 0, 0},
        {0, 0, 0, 0, 60, 0, 0},
        {0, 0, 0, 0, 40, 50, 0},
        {0, 0, 0, 0, 0, 30, 0},
        {0, 0, 0, 0, 0, 0, 80},
        {0, 0, 0, 0, 0, 0, 70},
        {0, 0, 0, 0, 0, 0, 0},
    };
    //matrice d'adjacence etape 1 partie 3 (l'unité de flot correspond à une unité de chocolat)
    this->part3Step1 = {
        {0, INT_MAX, INT_MAX, INT_MAX, 0},
		{0, 0, 0, 0, 20},
		{0, 0, 0, 0, 7},
		{0, 0, 0, 0, 5},
		{0, 0, 0, 0, 0}
    };
    //matrice d'adjacence etape 2 partie 3 
    this->part3Step2 = {
        {0, 25, 10, 8, 0},
		{0, 0, 0, 0, 20},
		{0, 0, 0, 0, 7},
		{0, 0, 0, 0, 5},
		{0, 0, 0, 0, 0}
    };
    //matrice d'adjacence etape 3 partie 3
    this->part3Step3 = {
        {0, 25, 10, 8, 0},
		{0, 0, 8, 12, 30},
		{0, 8, 0, 3, 7},
		{0, 12, 3, 0, 5},
		{0, 0, 0, 0, 0}
    };
    //matrice d'adjacence etape 4 partie 3 
    this->part3Step4 = {
        {0, 25, 15, 10, 5, 5, 8, 0},
		{0, 0, 15, 10, 0, 10, 0, 14},
		{0, 0, 0, 0, 5, 0, 5, 19},
		{0, 4, 0, 0, 8, 10, 0, 3},
		{0, 0, 8, 0, 0, 0, 5, 10},
		{0, 4, 0, 10, 0, 0, 7, 7},
		{0, 0, 7, 0, 5, 0, 0, 5},
		{0, 0, 0, 0, 0, 0, 0, 0}
    };
}

algo::~algo()
{
}


//fonction qui va parcourir en largeur de s vers t pour trouver le chemin ameliorant,
//la fonction renvoie true si un chemin ameliorant a été trouvé sinon false.
bool algo::parcoursLargeur(std::vector<std::vector <int>> grapheEtCapacites, int s, int t, std::vector<int>&cheminAmeliorant)
{
    bool sommetVisite[8] = {false, false, false, false, false, false, false, false};
    std::queue<int> file;
    file.push(s);
    sommetVisite[s] = true;
    int u;
    cheminAmeliorant[s] = -1;

    while (!file.empty()) {
        u = file.front();
        file.pop();
        for (int v = 0; v < grapheEtCapacites.size(); v++) {
            if (!sommetVisite[v] && grapheEtCapacites[u][v] != 0) {
                file.push(v);
                cheminAmeliorant[v] = u;
                sommetVisite[v] = true;
            }
        }
    }
    return (sommetVisite[t]);
}

// algorithme de fordFulkerson qui determine le flot maximal
int algo::fordFulkerson(std::vector<std::vector <int>> grapheEtCapacites, int s, int t)
{
    int u, v = 0;
    std::vector<std::vector <int>>grapheResiduel = grapheEtCapacites;
    std::vector<int>cheminAmeliorant(grapheEtCapacites.size(), -1);
    int max_flow = 0;
    int ameliorationFlot = 0;

    while(this->parcoursLargeur(grapheResiduel, s, t, cheminAmeliorant)) {
        ameliorationFlot = INT_MAX;
        for (v = t; v != s; v = cheminAmeliorant[v]) {
            u = cheminAmeliorant[v];
            ameliorationFlot  = min(ameliorationFlot, grapheResiduel[u][v]);
        }
        for (v = t; v != s; v = cheminAmeliorant[v]) {
            u = cheminAmeliorant[v];
            grapheResiduel[u][v] -= ameliorationFlot;
            grapheResiduel[v][u] += ameliorationFlot;
        }
        max_flow += ameliorationFlot;
    }
    return max_flow;
}

//fonction qui affiche une matrice en sortie
void algo::dumpMatrix(std::vector<std::vector <int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " / ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//fonction principale, pour executer l'algorithme de fordFulkerson,
//il suffit de changer le premier et le dernier paramètre par les matrices contenues dans la classe
//idem pour afficher la matrice
int main(void)
{
    algo parcour;
    int flotMax = parcour.fordFulkerson(parcour.part3Step4, 0, parcour.part3Step4.size() -1);

    parcour.dumpMatrix(parcour.part3Step4);
    std::cout << "Le flot max est de " << flotMax << std::endl;
    return 0;
}