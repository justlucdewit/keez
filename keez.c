#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "card.h"

int main() {
	// Randomized seed
	srand(time(NULL));

	// Create a deck
	DECK d = create_shuffled_deck();

	// Print it
	print_deck(d);

	return 0;
}