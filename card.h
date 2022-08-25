#include <stdio.h>
#pragma once

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