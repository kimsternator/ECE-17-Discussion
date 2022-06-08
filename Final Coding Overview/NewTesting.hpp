#pragma once

#include "Hand.hpp"

using std::cout; using std::endl;

namespace ECE17 {
	class NewTesting {
	public:
		static Hand getHighCard() {
			Hand theHand;
			theHand.addCard(Card(Faces::two, Suits::hearts));
			theHand.addCard(Card(Faces::four, Suits::diamonds));
			theHand.addCard(Card(Faces::seven, Suits::spades));
			theHand.addCard(Card(Faces::nine, Suits::clubs));
			theHand.addCard(Card(Faces::jack, Suits::hearts));
			return theHand;
		}

		static Hand getOnePair() {
			Hand theHand;
			Faces theFace = static_cast<Faces>(2);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(theFace, Suits::diamonds));
			theHand.addCard(Card(Faces::six, Suits::spades));
			theHand.addCard(Card(Faces::nine, Suits::clubs));
			theHand.addCard(Card(Faces::ten, Suits::hearts));
			return theHand;
		}

		static Hand getOnePairJoker() {
			Hand theHand;
			Faces theFace = static_cast<Faces>(2);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			theHand.addCard(Card(Faces::six, Suits::spades));
			theHand.addCard(Card(Faces::nine, Suits::clubs));
			theHand.addCard(Card(Faces::ten, Suits::hearts));
			return theHand;
		}

		static Hand getTwoPair() {
			Hand theHand;
			static Faces theFaces[] = { Faces::two, Faces::four };
			Faces theFace = static_cast<Faces>(theFaces[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(theFace, Suits::clubs));
			theHand.addCard(Card(Faces::six, Suits::spades));
			theHand.addCard(Card(Faces::six, Suits::diamonds));
			theHand.addCard(Card(Faces::queen, Suits::hearts));
			return theHand;
		}

		static Hand getThreeOfAKind() {
			Hand theHand;
			static int theFaces[] = { 4,6 };
			Faces theFace = static_cast<Faces>(theFaces[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(theFace, Suits::diamonds));
			theHand.addCard(Card(theFace, Suits::spades));
			theHand.addCard(Card(Faces::eight, Suits::clubs));
			theHand.addCard(Card(Faces::ten, Suits::clubs));
			return theHand;
		}

		static Hand getThreeOfAKindJoker() {
			Hand theHand;
			static Faces theFaces2[] = { Faces::eight, Faces::ten };
			Faces theFace = static_cast<Faces>(theFaces2[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(theFace, Suits::diamonds));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			theHand.addCard(Card(Faces::three, Suits::spades));
			theHand.addCard(Card(Faces::queen, Suits::diamonds));
			return theHand;
		}

		static Hand getEven() {
			Hand theHand;
			theHand.addCard(Card(Faces::two, Suits::hearts));
			theHand.addCard(Card(Faces::four, Suits::diamonds));
			theHand.addCard(Card(Faces::six, Suits::spades));
			theHand.addCard(Card(Faces::ten, Suits::spades));
			theHand.addCard(Card(Faces::eight, Suits::diamonds));
			return theHand;
		}

		static Hand getEvenJoker() {
			Hand theHand;
			theHand.addCard(Card(Faces::two, Suits::hearts));
			theHand.addCard(Card(Faces::four, Suits::diamonds));
			theHand.addCard(Card(Faces::six, Suits::spades));
			theHand.addCard(Card(Faces::ten, Suits::spades));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			return theHand;
		}

		static Hand getOdd() {
			Hand theHand;
			theHand.addCard(Card(Faces::three, Suits::hearts));
			theHand.addCard(Card(Faces::nine, Suits::diamonds));
			theHand.addCard(Card(Faces::five, Suits::spades));
			theHand.addCard(Card(Faces::jack, Suits::spades));
			theHand.addCard(Card(Faces::three, Suits::diamonds));
			return theHand;
		}

		static Hand getOddJoker() {
			Hand theHand;
			theHand.addCard(Card(Faces::three, Suits::hearts));
			theHand.addCard(Card(Faces::nine, Suits::diamonds));
			theHand.addCard(Card(Faces::five, Suits::spades));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			theHand.addCard(Card(Faces::three, Suits::diamonds));
			return theHand;
		}

		static Hand getStraight() {
			Hand theHand;
			theHand.addCard(Card(Faces::three, Suits::diamonds));
			theHand.addCard(Card(Faces::four, Suits::diamonds));
			theHand.addCard(Card(Faces::five, Suits::hearts));
			theHand.addCard(Card(Faces::six, Suits::clubs));
			theHand.addCard(Card(Faces::seven, Suits::spades));
			return theHand;
		}

		static Hand getStraightJoker() {
			Hand theHand;
			theHand.addCard(Card(Faces::three, Suits::diamonds));
			theHand.addCard(Card(Faces::four, Suits::diamonds));
			theHand.addCard(Card(Faces::five, Suits::hearts));
			theHand.addCard(Card(Faces::six, Suits::clubs));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			return theHand;
		}

		static Hand getFlush(Suits aSuit = Suits::clubs) {
			Hand theHand;
			theHand.addCard(Card(Faces::two, aSuit));
			theHand.addCard(Card(Faces::five, aSuit));
			theHand.addCard(Card(Faces::eight, aSuit));
			theHand.addCard(Card(Faces::jack, aSuit));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			return theHand;
		}

		static Hand getFullHouse(Faces aFace) {
			Hand theHand;
			static Faces theFaces[] = { Faces::two, Faces::four };
			Faces theFace = static_cast<Faces>(theFaces[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::clubs));
			theHand.addCard(Card(theFace, Suits::spades));
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(aFace, Suits::clubs));
			theHand.addCard(Card(aFace, Suits::hearts));
			return theHand;
		}

		static Hand getFullHouseJoker(Faces aFace) {
			Hand theHand;
			static Faces theFaces[] = { Faces::two, Faces::four };
			Faces theFace = static_cast<Faces>(theFaces[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::clubs));
			theHand.addCard(Card(theFace, Suits::spades));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			theHand.addCard(Card(aFace, Suits::clubs));
			theHand.addCard(Card(aFace, Suits::hearts));
			return theHand;
		}

		static Hand getFourOfAKind() {
			Hand theHand;
			static int theFaces[] = { 6,10 };
			Faces theFace = static_cast<Faces>(theFaces[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(theFace, Suits::diamonds));
			theHand.addCard(Card(theFace, Suits::spades));
			theHand.addCard(Card(theFace, Suits::clubs));
			theHand.addCard(Card(Faces::king, Suits::hearts));
			return theHand;
		}

		static Hand getFourOfAKindJoker() {
			Hand theHand;
			static int theFaces[] = { 6,10 };
			Faces theFace = static_cast<Faces>(theFaces[rand() % 2]);
			theHand.addCard(Card(theFace, Suits::hearts));
			theHand.addCard(Card(theFace, Suits::diamonds));
			theHand.addCard(Card(theFace, Suits::spades));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			theHand.addCard(Card(Faces::king, Suits::hearts));
			return theHand;
		}

		static Hand getStraightFlush() {
			Hand theHand;
			theHand.addCard(Card(Faces::three, Suits::hearts));
			theHand.addCard(Card(Faces::four, Suits::hearts));
			theHand.addCard(Card(Faces::five, Suits::hearts));
			theHand.addCard(Card(Faces::six, Suits::hearts));
			theHand.addCard(Card(Faces::seven, Suits::hearts));
			return theHand;
		}

		static Hand getStraightFlushJoker() {
			Hand theHand;
			theHand.addCard(Card(Faces::three, Suits::hearts));
			theHand.addCard(Card(Faces::four, Suits::hearts));
			theHand.addCard(Card(Faces::five, Suits::hearts));
			theHand.addCard(Card(Faces::six, Suits::hearts));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			return theHand;
		}

		static Hand getRoyalFlush() {
			Hand theHand;
			theHand.addCard(Card(Faces::ten, Suits::hearts));
			theHand.addCard(Card(Faces::jack, Suits::hearts));
			theHand.addCard(Card(Faces::queen, Suits::hearts));
			theHand.addCard(Card(Faces::king, Suits::hearts));
			theHand.addCard(Card(Faces::ace, Suits::hearts));
			return theHand;
		}

		static Hand getRoyalFlushJoker() {
			Hand theHand;
			theHand.addCard(Card(Faces::ten, Suits::hearts));
			theHand.addCard(Card(Faces::jack, Suits::hearts));
			theHand.addCard(Card(Faces::queen, Suits::hearts));
			theHand.addCard(Card(Faces::king, Suits::hearts));
			theHand.addCard(Card(Faces::joker, Suits::joker));
			return theHand;
		}

		static bool newTests() {
			bool theResult = true;

			if (getRoyalFlush().determineRank() != HandRanks::royal_flush &&
				getRoyalFlushJoker().determineRank() != HandRanks::royal_flush) {
				theResult = false;
				cout << "Error on Royal Flush" << endl;
			}

			if (getStraightFlush().determineRank() != HandRanks::straight_flush &&
				getStraightFlushJoker().determineRank() != HandRanks::straight_flush) {
				theResult = false;
				cout << "Error on Straight Flush" << endl;
			}

			if (getFourOfAKind().determineRank() != HandRanks::four_kind &&
				getFourOfAKindJoker().determineRank() != HandRanks::four_kind) {
				theResult = false;
				cout << "Error on Four of a Kind" << endl;
			}

			if (getFullHouse(Faces::five).determineRank() != HandRanks::full_house &&
				getFullHouseJoker().determineRank() != HandRanks::full_house) {
				theResult = false;
				cout << "Error on Full House" << endl;
			}

			if (getStraight().determineRank() != HandRanks::straight &&
				getStraightJoker().determineRank() != HandRanks::straight) {
				theResult = false;
				cout << "Error on Straight" << endl;
			}

			if (getFlush().determineRank() != HandRanks::flush &&
				getFlushJoker().determineRank() != HandRanks::flush) {
				theResult = false;
				cout << "Error on Flush" << endl;
			}

			if (getEven().determineRank() != HandRanks::even &&
				getEvenJoker().determineRank() != HandRanks::even) {
				theResult = false;
				cout << "Error on Even" << endl;
			}

			if (getOdd().determineRank() != HandRanks::odd &&
				getOddJoker().determineRank() != HandRanks::odd) {
				theResult = false;
				cout << "Error on Odd" << endl;
			}

			if (getThreeOfAKind().determineRank() != HandRanks::three_kind &&
				getThreeOfAKindJoker().determineRank() != HandRanks::three_kind) {
				theResult = false;
				cout << "Error on Three of a Kind" << endl;
			}

			if (getTwoPair().determineRank() != HandRanks::two_pair) {
				theResult = false;
				cout << "Error on Two Pair" << endl;
			}

			if (getOnePair().determineRank() != HandRanks::one_pair &&
				getOnePairJoker().determineRank() != HandRanks::one_pair) {
				theResult = false;
				cout << "Error on One Pair" << endl;
			}

			if (getHighCard().determineRank() != HandRanks::high_card) {
				theResult = false;
				cout << "Error on High Card" << endl;
			}

			cout << "********************" << endl;
			cout << "* All Tests " << (theResult ? "Passed" : "Failed") << " * " << endl;
			cout << "********************" << endl;

			return theResult;
		}

	};
}