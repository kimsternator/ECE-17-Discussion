#include <iostream>

#include "OldTesting.hpp"
#include "NewTesting.hpp"

int main() {
    ECE17::OldTesting::oldTests();
}


/* Example (NOT THE REAL FINAL)
Hand is now variable size at least 5 but in the range of 5 - 8 cards
kHandSize = 5 + (rand() % 4);

Choose cards you want to discard and after discarding/receiving new cards, 
remove cards from your hand until you have 5 total.

New Card Face + Suit
Face::Joker, Suit::Joker
The face and suit belong on 4 total cards, these are like wildcards meaning
they can count as any card/suit.

New Hands:
1) Evens
2) Odds

New Rankings
1. Royal flush
2. Straight flush
4. Four of a kind
5. Full house
6. Flush
7. Straight
8. Evens
9. Odds
10. Three of a kind
11. Two pair
12. One Pair
13. High Card
*/