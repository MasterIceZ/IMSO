#ifndef SOFAUTILS_H_INCLUDED
#define SOFAUTILS_H_INCLUDED

#include <iostream>
#include <utility>
#include <vector>

class ObstacleSet {
  public:
    std::vector<std::pair<double, double>> vertices;
    std::vector<std::pair<int, int>> edges;
    void read_input(std::istream &in);
};

class Sofa {
  public:
    std::vector<std::pair<double, double>> poly;
    void read_input(std::istream &in);
    bool translate_sofa(const ObstacleSet &obs,
                        std::pair<double, double> direction);
    bool rotate_sofa(const ObstacleSet &obs, std::pair<double, double> fulcrum,
                     double theta);
    double area();
};

#endif