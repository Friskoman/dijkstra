#include "src/include/Kaart.hpp"
#include "src/include/Dijkstra.hpp"
#include "src/include/Rit.hpp"
#include "src/include/Reis.hpp"
#include "src/include/Vlucht.hpp"

#include <iostream>
#include <utility>

int main() {
    Kaart kaart = Kaart();

    // Create new nodes
    Note noteA('A');
    Note noteB('B');
    Note noteC('C');
    Note noteD('D');
    Note noteE('E');
    Note noteF('F');
    Note noteG('G');
    Note noteH('H');
    Note noteI('I');

    // Set destinations for each node
    Rit AB('B', 4);
    Rit AE('E', 3);
    std::vector<Bestemming> A = {AB, AE};
    noteA.setBestemmingen(A);

    Rit BA('A', 4);
    Rit BC('C', 4);
    Rit BD('D', 3);
    std::vector<Bestemming> B = {BA, BC, BD};
    noteB.setBestemmingen(B);

    Rit CB('B', 4);
    Rit CD('D', 3);
    std::vector<Bestemming> C = {CB, CD};
    noteC.setBestemmingen(C);

    Rit DB('B', 3);
    Rit DC('C', 3);
    Rit DG('G', 5);
    Rit DH('H', 3);
    std::vector<Bestemming> D = {DB, DC, DG, DH};
    noteD.setBestemmingen(D);

    Rit EA('A', 3);
    Rit EF('F', 3);
    Rit EI('I', 4);
    std::vector<Bestemming> E = {EA, EF, EI};
    noteE.setBestemmingen(E);

    Rit FE('E', 3);
    Rit FG('G', 2);
    std::vector<Bestemming> F = {FE, FG};
    noteF.setBestemmingen(F);

    Rit GD('D', 5);
    Rit GF('F', 2);
    Rit GI('I', 2);
    std::vector<Bestemming> G = {GD, GF, GI};
    noteG.setBestemmingen(G);

    Rit HD('D', 3);
    Rit HI('I', 2);
    std::vector<Bestemming> H = {HD, HI};
    noteH.setBestemmingen(H);

    Rit IE('E', 4);
    Rit IG('G', 2);
    Rit IH('H', 2);
    std::vector<Bestemming> I = {IE,IG,IH};
    noteI.setBestemmingen(I);

    std::vector<Note*> allNodes = {&noteA, &noteB, &noteC, &noteD, &noteE, &noteF, &noteG, &noteH, &noteI};
    kaart.setNotes(allNodes);

    Dijkstra dijkstra = Dijkstra(kaart);
    std::pair<float, std::vector<char>> korstepad = dijkstra.korsteroute('C', 'F');

    std::cout << "De route is: " << std::get<0>(korstepad) << " Route:";
    for (char nodeId : std::get<1>(korstepad)) {
        std::cout << ' ' << nodeId;
    }
    std::cout << '.' << std::endl;

    return 0;
}
