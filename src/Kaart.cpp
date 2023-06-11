#include "include/Kaart.hpp"

Kaart::Kaart() {}

Kaart::Kaart(std::vector<Note*>& notes) : notes(notes) {}

const std::vector<Note*>& Kaart::getNotes() const {
    return notes;
}

void Kaart::setNotes(const std::vector<Note*>& notes_) {
    this->notes = notes_;
}

void Kaart::addNotes(Note* note) {
    this->notes.push_back(note);
}

Note* Kaart::getNote(char id) const {
    for (auto& note : notes) {
        if (note->getId() == id) {
            return note;
        }
    }
    return nullptr;
}