#include "Card.h"
#include <string>
using namespace std;

Card::Card() {
    suit = 0; rank = 0;
}

Card::Card(int s, int r) {
    suit = s; rank = r;
}

string Card::to_string() const {
    string suit_strings[] = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
    string rank_strings[] = {"Joker", "Ace", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "Jack", "Queen",
                                   "King"};

    if (rank == 0) {
        return rank_strings[rank];
    }

    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::operator==(const Card& c2) const {
    return (rank == c2.rank && suit == c2.suit);
}

bool Card::operator>(const Card& c2) const {
    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;

    if (rank == 1 && c2.rank != 1) return true;
    if (c2.rank == 1 && rank != 1) return true;

    // if suits are equal, check ranks
    if (rank > c2.rank) return true;
    if (rank < c2.rank) return false;
    // this last statement can be omitted without changing the
    // behavior of the function, but making it arguably less readable

    // if ranks are equal too, 1st card is not greater than the 2nd
    return false;
}

bool Card::operator<=(const Card& c2) const {
    return !(*this > c2);
}

bool Card::operator<(const Card& c2) const {
    return *this <= c2 && !(*this == c2);
}

bool Card::operator>=(const Card& c2) const {
    return !(*this < c2);
}

