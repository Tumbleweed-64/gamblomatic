#include <iostream>
#include "gamblomatic.h"

// NOTE: This file and all other example files require gamblomatic.h to be in the same directory, or it won't work.
int main() {
	Deck bicycle {false};
	bicycle.printDeck();
	std::cout << "\nShuffled:\n\n";
	bicycle.shuffleDeck();
	bicycle.printDeck();
	return 0;
}
