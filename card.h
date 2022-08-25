#include <stdio.h>
#include <stdlib.h>
#pragma once

// Library for:
// - Managing cards
// - Managing decks
// - Managing shuffling

// ====================================
//    Cards
// ====================================
typedef enum CARD_SUIT {
	SUIT_CLUB,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES
} CARD_SUIT;

typedef enum CARD_VALUE {
	VALUE_ACE,
	VALUE_TWO,
	VALUE_THREE,
	VALUE_FOUR,
	VALUE_FIVE,
	VALUE_SIX,
	VALUE_SEVEN,
	VALUE_EIGHT,
	VALUE_NINE,
	VALUE_TEN,
	VALUE_JACK,
	VALUE_QUEEN,
	VALUE_KING
} CARD_VALUE;

typedef struct CARD {
	CARD_SUIT suit;
	CARD_VALUE value;
} CARD;

CARD create_card(CARD_VALUE value, CARD_SUIT suit) {
	CARD c = {
		.suit=suit,
		.value=value
	};

	return c;
}

char* value_to_string(CARD c) {
	switch(c.value) {
		case VALUE_ACE: return "ace";
		case VALUE_TWO: return "two";
		case VALUE_THREE: return "three";
		case VALUE_FOUR: return "four";
		case VALUE_FIVE: return "five";
		case VALUE_SIX: return "six";
		case VALUE_SEVEN: return "seven";
		case VALUE_EIGHT: return "eight";
		case VALUE_NINE: return "nine";
		case VALUE_TEN: return "ten";
		case VALUE_JACK: return "jack";
		case VALUE_QUEEN: return "queen";
		case VALUE_KING: return "king";
	}  
}

char* suit_to_string(CARD c) {
	switch(c.suit) {
		case SUIT_CLUB: return "clubs";
		case SUIT_DIAMONDS: return "diamonds";
		case SUIT_HEARTS: return "hearts";
		case SUIT_SPADES: return "spades";
	} 
}

void print_card(CARD c) {
	char* value = value_to_string(c);
	char* suit = suit_to_string(c);

	printf("%s of %s\n", value, suit);
}




// ====================================
//    Decks
// ====================================
typedef struct DECK {
	CARD* cards;
	size_t card_count;
} DECK;

DECK create_ordered_deck() {
	DECK d = {
		.cards = malloc(sizeof(CARD) * 52),
		.card_count = 0
	};

	for (int i = 0; i < 4; i++) {
		CARD_SUIT suit = (CARD_SUIT) i;

		for (int j = 0; j < 13; j++) {
			CARD_VALUE value = (CARD_VALUE) j;
			d.cards[d.card_count] = create_card(value, suit);
			++d.card_count;
		}
	}

	return d;
}

void print_deck(DECK deck) {
	for (int i = 0; i < deck.card_count; i++) {
		CARD c = deck.cards[i];
		print_card(c);
	}
}



// ====================================
//    Shuffling
// ====================================

DECK shuffle_deck(DECK* d)
{
    DECK buff = {
    	.cards = malloc(sizeof(CARD) * 52),
		.card_count = 0
    };

    while (d->card_count > 0) {
    	// Determain a random index
    	int random_index = rand() % d->card_count;
    	CARD random_card = d->cards[random_index];

    	// Get that card and clone it to buff
    	buff.cards[buff.card_count] = create_card(random_card.value, random_card.suit);
    	++buff.card_count;

    	// Move the last card to the empty spot and shrink the deck
    	CARD last_card = d->cards[d->card_count - 1];
    	d->cards[random_index] = last_card;
    	--d->card_count;
    }

    return buff;
}

DECK create_shuffled_deck() {
	DECK d = create_ordered_deck();
	DECK sd = shuffle_deck(&d);
	free(d.cards);

	return sd;
}