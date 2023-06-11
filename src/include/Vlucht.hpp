#pragma once
#include "Bestemming.hpp"

class Vlucht: public Bestemming{
public:
    Vlucht();
    Vlucht(char id, float prijs);
};