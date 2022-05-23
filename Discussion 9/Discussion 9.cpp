#include <iostream>
#include <map>
#include <vector>
#include <functional>

#include "Card.hpp"

using std::cout; using std::vector; using std::pair;

using FaceSuitPair = pair<ECE17::Faces, ECE17::Suits>;
using FSPList = vector<FaceSuitPair>;
using CardList = vector<ECE17::Card>;
using HandAnalyzer = double (*)(CardList);

// 1. Royal flush
// 2. Straight flush
// 3. Four of a kind
// 4. Full house
// 5. Flush
// 6. Straight
// 7. Three of a kind
// 8. Two pair
// 9. One Pair
// 10. High Card

void initializeHand(FSPList pairs, CardList& hand) {
    hand.clear();
    for (auto const& pair : pairs) {
        ECE17::Card newCard(pair.first, pair.second);
        hand.emplace_back(newCard);
    }
}

int main() {
    CardList hand;

    FSPList straightFlushPairs = {
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::six, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::seven, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::eight, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::nine, ECE17::Suits::clubs),
    };
    initializeHand(straightFlushPairs, hand);

    FSPList fullHousePairs = {
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::spades),
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::diamonds),
        FaceSuitPair(ECE17::Faces::nine, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::nine, ECE17::Suits::hearts),
    };
    initializeHand(fullHousePairs, hand);

    FSPList twoPairPairs = {
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::eight, ECE17::Suits::hearts),
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::hearts),
        FaceSuitPair(ECE17::Faces::eight, ECE17::Suits::diamonds),
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::spades),
    };
    initializeHand(twoPairPairs, hand);

    FSPList highCardPairs = {
        FaceSuitPair(ECE17::Faces::five, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::six, ECE17::Suits::diamonds),
        FaceSuitPair(ECE17::Faces::seven, ECE17::Suits::clubs),
        FaceSuitPair(ECE17::Faces::eight, ECE17::Suits::hearts),
        FaceSuitPair(ECE17::Faces::ace, ECE17::Suits::clubs),
    };
    initializeHand(twoPairPairs, hand);
}
