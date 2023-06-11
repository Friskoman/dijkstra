#include "include/catch.hpp"
#include <iostream>

#include "../src/include/Kaart.hpp"
#include "../src/include/Dijkstra.hpp"
#include "../src/include/Rit.hpp"
#include "../src/include/Reis.hpp"
#include "../src/include/Vlucht.hpp"

TEST_CASE("Shortest path exists", "Dijkstra::korsteroute") {
    // Create the map and nodes
    Kaart kaart = Kaart();
    Note noteA('A');
    Note noteB('B');
    Note noteC('C');
    Note noteD('D');
    Note noteE('E');
    Note noteF('F');

    // Set destinations for each node
    Rit AB('B', 4);
    std::vector<Bestemming> A = {AB};
    noteA.setBestemmingen(A);

    Rit BA('A', 4);
    Rit BC('C', 2);
    std::vector<Bestemming> B = {BA, BC};
    noteB.setBestemmingen(B);

    Rit CB('B', 2);
    Rit CF('F', 5);
    Rit CD('D', 3);
    std::vector<Bestemming> C = {CB, CD, CF};
    noteC.setBestemmingen(C);

    Rit DC('C', 3);
    Rit DF('F', 1);
    Rit DE('E', 1);
    std::vector<Bestemming> D = {DC, DF};
    noteD.setBestemmingen(D);

    Rit ED('D', 1);
    Rit EF('F', 1);
    std::vector<Bestemming> E = {ED};
    noteE.setBestemmingen(E);

    Rit FE('E', 1);
    Rit FC('C', 5);
    std::vector<Bestemming> F = {FE};
    noteF.setBestemmingen(F);

    // Set all nodes in the map
    std::vector<Note*> allNodes = {&noteA, &noteB, &noteC, &noteD, &noteE, &noteF};
    kaart.setNotes(allNodes);

    // Perform Dijkstra's algorithm and check the result
    Dijkstra dijkstra = Dijkstra(kaart);
    std::pair<float, std::vector<char>> korstepad = dijkstra.korsteroute('A', 'F');

    // Check if the shortest path is correct
    REQUIRE(std::get<0>(korstepad) == 10.0f);
    REQUIRE(std::get<1>(korstepad) == std::vector<char>{'A', 'B', 'C', 'D', 'F'});

    // Display the path taken
    std::cout << "Shortest path: ";
    for (char nodeId : std::get<1>(korstepad)) {
        std::cout << nodeId << " -> ";
    }
}

TEST_CASE("Shortest path doesn't exist", "Dijkstra::korsteroute") {
    // Create the map and nodes
    Kaart kaart = Kaart();
    Note noteA('A');
    Note noteB('B');
    Note noteC('C');
    Note noteD('D');
    Note noteE('E');
    Note noteF('F');

    // Set destinations for each node
    Rit AB('B', 4);
    std::vector<Bestemming> A = {AB};
    noteA.setBestemmingen(A);

    Rit BA('A', 4);
    Rit BC('C', 2);
    std::vector<Bestemming> B = {BA, BC};
    noteB.setBestemmingen(B);

    Rit CB('B', 2);
    std::vector<Bestemming> C = {CB};
    noteC.setBestemmingen(C);

    Rit DC('C', 3);
    std::vector<Bestemming> D = {DC};
    noteD.setBestemmingen(D);

    // Set all nodes in the map
       std::vector<Note*> allNodes = {&noteA, &noteB, &noteC, &noteD};
    kaart.setNotes(allNodes);

    // Perform Dijkstra's algorithm and check the result
    Dijkstra dijkstra = Dijkstra(kaart);
    std::pair<float, std::vector<char>> korstepad = dijkstra.korsteroute('A', 'F');

    // Check if the shortest path is not found
    REQUIRE(std::get<0>(korstepad) == std::numeric_limits<float>::infinity());
    REQUIRE(std::get<1>(korstepad).empty());

    // Display the path taken (should be empty)
    std::cout << "Shortest path: No path found" << std::endl;
}

TEST_CASE("Empty map", "Dijkstra::korsteroute") {
    // Create an empty map
    Kaart kaart = Kaart();

    // Perform Dijkstra's algorithm and check the result
    Dijkstra dijkstra = Dijkstra(kaart);
    std::pair<float, std::vector<char>> korstepad = dijkstra.korsteroute('A', 'F');

    // Check if the shortest path is not found
    REQUIRE(std::get<0>(korstepad) == std::numeric_limits<float>::infinity());
    REQUIRE(std::get<1>(korstepad).empty());
}
