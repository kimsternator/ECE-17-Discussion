#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "Hand.hpp"

using std::string; using std::deque; using std::map; using std::vector;
using std::pair;

using CardDeque = deque<ECE17::Card>;
using FaceCountElement = pair< ECE17::Faces, size_t>;
using FaceCount = map<ECE17::Faces, size_t>;
using FaceVector = vector<ECE17::Faces>;
using HandAnalyzer = bool (*)(CardDeque const&);
using HandAnalyzerSm = ECE17::HandRanks (*)(CardDeque const&);
using AssociativeDispatch = map<ECE17::HandRanks, HandAnalyzer>;
using AssociativeDispatchSm = map<ECE17::HandRanks, HandAnalyzerSm>;


namespace ECE17 {
	class HandRankUtil {
	public:
		/*
		Joker Card
		1) Split our hand apart from any Joker x
		2) Evaluate what we have based on what cards we have
			a) based on what # of jokers we have increase the value of our hand
		Assumptions:
		(for time) assume only 1 joker in hand is possible

		10. Three of a kind = > Four of a Kind
		11. Two pair = > full house
		12. One Pair = > Three of kind, { dependent: Evens, Odds }
		13. High Card = > One Pair, { dependent: straight, flush, Evens, Odds }
		*/
		static bool CheckEven(CardDeque const& cards) {
			bool theResult = true;
			for (auto& card : cards) {
				if ((int) card.getFace() % 2) {
					theResult = false;
				}
			}
			return theResult;
		}

		static bool CheckOdd(CardDeque const& cards) {
			bool theResult = true;
			for (auto& card : cards) {
				if (!((int) card.getFace() % 2)) {
					theResult = false;
				}
			}
			return theResult;
		}

		static bool CheckFlush(CardDeque const& cards) {
			if (cards.empty()) {
				return false;
			}

			Suits theSuit = cards.begin()->getSuit();
			for (auto const& card : cards) {
				if (card.getSuit() != theSuit) {
					return false;
				}
			}

			return true;
		}

		static bool CheckStraightJoker(CardDeque const& cards) {
			bool flag = false;
			CardDeque copy(cards);
			std::sort(copy.begin(), copy.end(), [](const Card& aLeft, const Card& aRight) {
				return (int) aLeft.getFace() < (int) aRight.getFace();
			});
			for (size_t i = 0; i < copy.size() - 1; i++) {
				if ((int) copy[i].getFace() - (int) copy[i + 1].getFace() != -1) {
					if (!flag && (int) copy[i].getFace() - (int) copy[i + 1].getFace() != -2) {
						flag = true;
					} else {
						return false;
					}
				}
			}
			return true;
		}

		static HandRanks SmHighCard(CardDeque const& cards) {
			if (CheckStraightJoker(cards) && CheckFlush(cards)) {
				return HandRanks::straight_flush;
			}
			if (CheckStraightJoker(cards)) {
				return HandRanks::straight;
			}
			if (CheckFlush(cards)) {
				return HandRanks::flush;
			}
			if (CheckEven(cards)) {
				return HandRanks::evens;
			}
			if (CheckOdd(cards)) {
				return HandRanks::odds;
			}
			return HandRanks::one_pair;
		}

		static HandRanks SmOnePair(CardDeque const& cards) {
			if (CheckEven(cards)) {
				return HandRanks::evens;
			} 
			if (CheckOdd(cards)) {
				return HandRanks::odds;
			}
			return HandRanks::three_kind;
		}

		static HandRanks SmTwoPair(CardDeque const& cards) {
			return HandRanks::full_house;
		}

		static HandRanks SmThreeKind(CardDeque const& cards) {
			return HandRanks::four_kind;
		}

		static HandRanks determineSmallerHandRank(CardDeque const& cards) {
			static AssociativeDispatchSm SmAD = {
				{HandRanks::three_kind, SmThreeKind},
				{HandRanks::two_pair, SmTwoPair},
				{HandRanks::one_pair, SmOnePair},
				{HandRanks::high_card, SmHighCard},
			};

			HandRanks theMaxHand = HandRanks::high_card;

			for (int i = (int) HandRanks::high_card; i != (int) HandRanks::three_kind + 1; i++) {
				HandRanks currentRank = static_cast<HandRanks>(i);
				currentRank = SmAD[currentRank](cards);
				if ((int) currentRank > (int) theMaxHand) {
					theMaxHand = currentRank;
				}
			}

			return theMaxHand;
		}

		static CardDeque getCards(CardDeque const& cards) {
			CardDeque result;
			for (auto const& card : cards) {
				if (card.getFace() == Faces::joker || card.getSuit() == Suits::joker) {
					continue;
				}
				result.push_back(Card(card));
			}
			return result;
		}

		static CardDeque getJokerCards(CardDeque const& cards) {
			CardDeque result;
			for (auto const& card : cards) {
				if (card.getFace() != Faces::joker && card.getSuit() != Suits::joker) {
					continue;
				}
				result.push_back(Card(card));
			}
			return result;
		}

		static HandRanks evaluate(CardDeque const& cards) {
			CardDeque temp1 = getCards(cards); // get the non joker cards
			CardDeque temp2 = getJokerCards(cards); // get the joker cards + probably want to count jokers

			if (temp2.empty()) {
				return dispatch(cards);
			}

			return determineSmallerHandRank(temp1);
		}


		static bool allRoyals(CardDeque const& cards) {
			static FaceVector royals = {
				Faces::ten, Faces::jack, Faces::queen, Faces::king, Faces::ace,
			};

			for (auto const& card : cards) {
				if (std::find(royals.begin(), royals.end(), card.getFace()) == royals.end()) {
					return false;
				}
			}

			return true;
		}

		static FaceCount countFaces(CardDeque const& cards) {
			FaceCount theCount;
			for (auto const& card : cards) {
				theCount[card.getFace()]++;
			}
			return theCount;
		}

		static size_t checkPairNum(CardDeque const& cards, size_t pairSize) {
			FaceCount theCount = countFaces(cards);
			return std::count_if(theCount.begin(), theCount.end(), [&pairSize](const FaceCountElement& aPair) {
				return aPair.second == pairSize;
			});
		}

		static bool CheckOnePair(CardDeque const& cards) {
			return checkPairNum(cards, 2) == 1;
		}

		static bool CheckTwoPair(CardDeque const& cards) {
			return checkPairNum(cards, 2) == 2;
		}

		static bool CheckThreeKind(CardDeque const& cards) {
			return checkPairNum(cards, 3) == 1;
		}

		static bool CheckStraight(CardDeque const& cards) {
			CardDeque copy(cards);
			std::sort(copy.begin(), copy.end(), [](const Card& aLeft, const Card& aRight) {
				return (int) aLeft.getFace() < (int) aRight.getFace();
			});
			for (size_t i = 0; i < copy.size() - 1; i++) {
				if ((int) copy[i].getFace() - (int) copy[i + 1].getFace() != -1) {
					return false;
				}
			}
			return true;
		}

		static bool CheckFullHouse(CardDeque const& cards) {
			return CheckOnePair(cards) && CheckThreeKind(cards);
		}

		static bool CheckFourKind(CardDeque const& cards) {
			return checkPairNum(cards, 4) == 1;
		}

		static bool CheckStraightFlush(CardDeque const& cards) {
			return CheckStraight(cards) && CheckFlush(cards);
		}

		static bool CheckRoyalFlush(CardDeque const& cards) {
			return allRoyals(cards) && CheckStraight(cards);
		}

		static HandRanks dispatch(CardDeque const& cards) {
			static AssociativeDispatch AD = {
				{HandRanks::royal_flush, CheckRoyalFlush},
				{HandRanks::straight_flush, CheckStraightFlush},
				{HandRanks::four_kind, CheckFourKind},
				{HandRanks::full_house, CheckFullHouse},
				{HandRanks::flush, CheckFlush},
				{HandRanks::straight, CheckStraight},
				{HandRanks::three_kind, CheckThreeKind},
				{HandRanks::two_pair, CheckTwoPair},
				{HandRanks::one_pair, CheckOnePair},
				{HandRanks::evens, CheckEven},
				{HandRanks::odds, CheckOdd},
			};

			for (int i = (int) HandRanks::royal_flush; i != (int) HandRanks::high_card; i--) {
				HandRanks currentRank = static_cast<HandRanks>(i);
				if (AD[currentRank](cards)) {
					return currentRank;
				}
			}

			return HandRanks::high_card;
		}

		static Faces getHighCardGroupSize(CardDeque const& cards, size_t aSize) {
			FaceCount theCount = countFaces(cards);
			Faces theHighFace = Faces::noface;
			for (auto const& card : cards) {
				if (theCount[card.getFace()] != aSize) {
					continue;
				}
				if ((int) card.getFace() > (int) theHighFace) {
					theHighFace = card.getFace();
				}
			}
			return theHighFace;
		}

		static Faces getHighCard(CardDeque const& cards, HandRanks const& aRank) {
			switch (aRank) {
				case HandRanks::unknown:
				case HandRanks::high_card:
				case HandRanks::straight:
				case HandRanks::flush:
				case HandRanks::straight_flush:
				case HandRanks::royal_flush:
					return getHighCardGroupSize(cards, 1);

				case HandRanks::one_pair:
				case HandRanks::two_pair:
					return getHighCardGroupSize(cards, 2);

				case HandRanks::three_kind:
				case HandRanks::four_kind:
				case HandRanks::full_house:
					return getHighCardGroupSize(cards, 3);
			}
			return Faces::noface;
		}
	};
}