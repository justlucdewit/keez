#include <stdio.h>
#include "card.h"

int main() {
	// Create some card and print it
	CARD a = create_card(VALUE_FIVE, SUIT_DIAMONDS);
	print_card(a);

	return 0;
}