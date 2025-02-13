#pragma once

#include <vector>
#include <random>
#include <algorithm>

struct Card {
	int rank;
	int suit; // suit would be an enum but doesn't play well with for loops, so 0=Spades, 1=Hearts, 2=Diamonds, 3=Clubs
};

class Deck {
	public:
	std::vector<Card> deck;
	bool jokersOn;

	void createDeck() {
			for (int i = 0; i<=3; i++) {
				// loop for each suit
				for (int j = 2; j <= 14; j++) {
					// loop for each rank
						Card newCard;
						newCard.rank = j;
						newCard.suit = i;
						deck.push_back(newCard);
				}
			}
				if (jokersOn) {
					// Add the jokers to the deck.
					Card joker;
					joker.rank = 15;	
					joker.suit = 4;
					deck.push_back(joker);
					deck.push_back(joker);
				}
		}

		Deck(bool jokers) {
				jokersOn = jokers;
				createDeck();
		}

		void printDeck() {
			int cardCount = (jokersOn) ? 54 : 52;
			for (int i = 0; i < cardCount; i++) {
				switch (deck.at(i).rank) {
						case 11:
							std::cout << "Jack of ";
							break;
						case 12:
							std::cout << "Queen of ";
							break;
						case 13:
							std::cout << "King of ";
							break;
						case 14:
							std::cout << "Ace of ";
							break;
						case 15:
							std::cout << "Joker";
						default:
							std::cout << deck[i].rank << " of ";
							break;
				}

				switch (deck.at(i).suit) {
						case 0:
							std::cout << "Spades";
							break;
						case 1:
							std::cout << "Hearts";
							break;
						case 2:
							std::cout << "Diamonds";
							break;
						case 3:
							std::cout << "Clubs";
				}
				std::cout << "\n";
			}
		}

		// from https://stackoverflow.com/a/6926473/22506735
		void shuffleDeck() {
				std::random_device rd;
				auto rng = std::default_random_engine {rd()};
				std::ranges::shuffle(deck, rng);
		}
};

