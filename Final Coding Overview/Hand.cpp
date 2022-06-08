//
//  Hand.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Hand.hpp"
#include "HandRankUtil.hpp"
#include <algorithm>
#include <map>

namespace ECE17 {

	using CardCountMap = std::map<Faces, size_t>;

	Hand::Hand() {
	}

	Hand::Hand(const Hand& aCopy) {
		*this = aCopy;
	}

	Hand::~Hand() {}

	Hand& Hand::operator=(const Hand& aCopy) {
		cards = aCopy.cards;
		return *this;
	}

	bool Hand::operator<(const Hand& aHand) const {
		HandRanks theRank = determineRank();
		HandRanks theOtherRank = aHand.determineRank();

		if (theRank == theOtherRank) {
			return HandRankUtil::getHighCard(cards, theRank) < HandRankUtil::getHighCard(aHand.cards, theOtherRank);
		}
		return theRank < theOtherRank;
	}

	bool Hand::operator==(const Hand& aHand) const {
		return (int)determineRank() == (int)aHand.determineRank();
	}

	bool Hand::addCard(const Card& aCard) {
		cards.emplace_back(aCard);
		return true;
	}

	CardOpt Hand::discard(Faces aFace, Suits aSuit) {
		auto result = std::find_if(cards.begin(), cards.end(), [aFace, aSuit](const Card& aCard) {
			return aCard.getFace() == aFace && aCard.getSuit() == aSuit;
		});
		// Not Found
		if (result == cards.end()) {
			return std::nullopt;
		}

		CardOpt theReturn(*result);
		cards.erase(result);
		return theReturn;
	}

	size_t Hand::count() const {
		return cards.size();
	}

	bool Hand::contains(const Card& aCard) const {
		auto result = std::find_if(cards.begin(), cards.end(), [aCard](const Card& anotherCard) {
			return aCard == anotherCard;
		});
		return result != cards.end();
	}

	std::ostream& operator<<(std::ostream& anOutput, const Hand& aHand) {
		for (auto theCard : aHand.cards) {
			anOutput << theCard << " ";
		}
		return anOutput;
	}

	//what is the highest card in the hand?
	Faces Hand::highCard() const {
		Faces theMax = Faces::two;
		for (auto const& card : cards) {
			if ((int)card.getFace() > (int)theMax) {
				theMax = card.getFace();
			}
		}
		return theMax;
	}

	HandRanks Hand::determineRank() const {
		return HandRankUtil::dispatch(cards);
	}
}