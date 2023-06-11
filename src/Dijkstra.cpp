#include "include/Dijkstra.hpp"
#include <queue>
#include <algorithm>
#include <iostream>

#define INF 999

std::vector<char> Dijkstra::backprop(char begin, char eind) {
    std::vector<char> pad;
    Note* eindNote = kaart.getNote(eind);
    Note* beginNote = kaart.getNote(begin);
    Note* currentNode = kaart.getNote(eindNote->getId());
    while (currentNode != kaart.getNote(beginNote->getId())) {
        pad.push_back(currentNode->getPrenote());
        currentNode = kaart.getNote(currentNode->getPrenote());
    }
    std::reverse(pad.begin(), pad.end());
    pad.push_back(eind);
    return pad;
}


Dijkstra::Dijkstra(){
}

Dijkstra::Dijkstra(Kaart& kaart):
    kaart(kaart)
{}

std::pair<float, std::vector<char>> Dijkstra::korsteroute(char begin, char eind) {
    Note* beginNote = kaart.getNote(begin);
    for (auto& note : kaart.getNotes()) {
        note->setAfstand(INF);
        note->setPrenote('?');
    }
    beginNote->setAfstand(0);

    std::priority_queue<Note*, std::vector<Note*>, Vergelijker> mogelijkheden;
    mogelijkheden.push(beginNote);

    while (!mogelijkheden.empty()) {
        Note* besteBuur = mogelijkheden.top();
        mogelijkheden.pop();

        for (Bestemming& bestemming : besteBuur->Bestemmingen()) {
            Note* Buurnote = kaart.getNote(bestemming.getId());
            float tempAfstand = besteBuur->getAfstand() + bestemming.getPunten();

            if (tempAfstand < Buurnote->getAfstand()) {
                mogelijkheden.push(Buurnote);
                Buurnote->setAfstand(tempAfstand);
                Buurnote->setPrenote(besteBuur->getId());
            }
        }
    }

    return std::make_pair(kaart.getNote(eind)->getAfstand(), backprop(begin, eind));
}
    

