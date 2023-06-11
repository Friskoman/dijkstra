#include "include/Note.hpp"

#define INF 999

Note::Note(char id):
    id(id),
    bestemmingen({}),
    afstand(INF),
    prenote('?')
{}

Note::Note(char id, std::vector<Bestemming>& bestemmingen):
    id(id),
    bestemmingen(bestemmingen),
    afstand(INF),
    prenote('?')
{}

void Note::addBestemmingen(Bestemming& bestemming){
    this->bestemmingen.push_back(bestemming);
}


bool operator==(const Note& lhs, const Note* rhs){
    if(lhs.getAfstand() == rhs->getAfstand() && lhs.getId() == rhs->getId() && lhs.getPrenote() == rhs->getPrenote()){
        return true;
    }
    return false;
}