#include <vector>

std::vector<std::pair<int, int>> find_water(
    int N, int K, int M, std::vector<int> X, std::vector<int> Y,
    std::vector<int> S, std::vector<int> A, std::vector<int> B);

std::vector<std::pair<int, int>> place_water(int N, int K, std::vector<int> X,
                                             std::vector<int> Y,
                                             std::vector<int> S);
