#include <iostream>
#include "gamblomatic.h"

int main() {
	Deck bicycle {false}; // create a standard 52-card deck (no jokers)
	printDeck(bicycle);
	return 0;
}
