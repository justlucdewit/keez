#include <stdio.h>
#include "card.h"

int main() {
	DECK d = create_ordered_deck();
	print_deck(d);

	return 0;
}