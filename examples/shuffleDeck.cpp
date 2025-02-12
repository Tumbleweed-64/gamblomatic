#include <iostream>
#include "cards.h"

// NOTE: This file and all other example files require cards.h to be in the same directory, or it won't work.
int main() {
		deck bicycle = createDeck();
		printDeck(bicycle);
    std::cout << "\nShuffled:\n\n";
    shuffleDeck(bicycle);
    printDeck(bicycle);
		return 0;
}
