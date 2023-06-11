#pragma once
#include "Note.hpp"

struct Vergelijker
{
bool operator()(const Note* lhs, const Note* rhs) const{
    return lhs->getAfstand() > rhs->getAfstand();
}
};
