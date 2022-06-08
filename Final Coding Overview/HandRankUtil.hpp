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
using AssociativeDispatch = map<ECE17::HandRanks, HandAnalyzer>;

namespace ECE17 {
	class HandRankUtil {
	public:
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