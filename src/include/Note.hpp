#pragma once
#include <vector>
#include "Bestemming.hpp"



class Note{
    private:
    char id;
    std::vector<Bestemming> bestemmingen;
    float afstand;
    char prenote;

    public:
    Note(char id);
    Note(char id, std::vector<Bestemming>& bestemmingen);

    std::vector<Bestemming> Bestemmingen() const { return bestemmingen; }
    void setBestemmingen(std::vector<Bestemming> &bestemmingen) { this->bestemmingen = bestemmingen; }
    void addBestemmingen(Bestemming& bestemming);

    char getId() const { return id; }

    float getAfstand() const { return afstand; }
    void setAfstand(float afstand) { this->afstand = afstand; }

    char getPrenote() const { return prenote; }
    void setPrenote(char prenote) { this->prenote = prenote; }

    friend bool operator== (const Note& lhs, const Note* rhs);
    
};
