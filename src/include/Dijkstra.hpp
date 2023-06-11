#pragma once
#include "Kaart.hpp"
#include "Vergelijker.hpp"
#include <string>

class Dijkstra{
private:
    Kaart kaart;
    std::vector<char> backprop(char begin, char eind);
public:
    Dijkstra();
    Dijkstra(Kaart& kaart);
    std::pair<float, std::vector<char>> korsteroute(char begin, char eind);
};