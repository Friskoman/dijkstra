#pragma once
#include "Note.hpp"


class Kaart{
    private:
    std::vector<Note*> notes;

    public:
    Kaart();
    Kaart(std::vector<Note*>& notes);

    const std::vector<Note*>& getNotes() const;
    void setNotes(const std::vector<Note*>& notes_);
    void addNotes(Note* note);

    Note* getNote(char id) const;
    
};