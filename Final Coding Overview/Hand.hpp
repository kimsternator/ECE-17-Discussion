//
//  Hand.hpp
//  assignment2
//
//  Created by rick gessner on 10/6/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include "Card.hpp"
#include <deque>

namespace ECE17 {

	enum class HandRanks {
		unknown = 0, high_card, one_pair, two_pair, three_kind, odds, evens, straight,
		flush, full_house, four_kind, straight_flush, royal_flush
	};

	class Hand {
	public:
		Hand();
		Hand(const Hand& aCopy);
		~Hand();
		Hand& operator=(const Hand& aHand);
		bool  operator<(const Hand& aHand) const;
		bool  operator==(const Hand& aHand) const;

		bool    addCard(const Card& aCard);
		CardOpt discard(Faces aFace, Suits aSuit);

		bool    contains(const Card& aCard) const;
		size_t  count() const;

		HandRanks determineRank() const;
		Faces     highCard() const;

		//this will show a hand on the console...
		friend std::ostream& operator<<(std::ostream& anOutput, const Hand& aHand);

	protected:
		std::deque<Card> cards; //Deque required; DO NOT CHANGE!
	};


}

#endif /* Hand_hpp */