#pragma once

#include <vector>
#include <random>
#include <algorithm>

typedef struct card {
		int rank;
		int suit; // suit would be an enum but doesn't play well with for loops, so 0=Spades, 1=Hearts, 2=Diamonds, 3=Clubs
} card;

typedef std::vector<card> deck;

deck createDeck() {
		deck theDeck;
		for (int i = 0; i<=3; i++) {
				// loop for each suit
				for (int j = 2; j <= 14; j++) {
						// loop for each rank
						card newCard;
						newCard.rank = j;
						newCard.suit = i;
						theDeck.push_back(newCard);
				}
		}
		return theDeck;
}

void printDeck(deck theDeck) {
		for (int i = 0; i < 52; i++) {
				switch (theDeck.at(i).rank) {
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
						default:
								std::cout << theDeck[i].rank << " of ";
								break;
				}

				switch (theDeck[i].suit) {
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
								break;
				}

				std::cout << "\n";
		}
}

// from https://stackoverflow.com/a/6926473/22506735
void shuffleDeck(deck &deckToShuffle) {
		std::random_device rd;
		std::default_random_engine rng = std::default_random_engine(rd());
		std::ranges::shuffle(deckToShuffle, rng);
}
