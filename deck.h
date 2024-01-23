#ifndef DECK_H
#define DECK_H

/**
 * struct card_s - Struct representing a standard playing card
 *
 * @value: Value of the card (e.g., "10")
 * @kind: Kind of the card (e.g., "Heart")
 */
typedef struct card_s
{
    const char *value;
    const char *kind;
} card_t;

/**
 * struct deck_node_s - Doubly linked list node representing a card in a deck
 *
 * @card: Pointer to the card
 * @prev: Pointer to the previous card in the deck
 * @next: Pointer to the next card in the deck
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

#endif /* DECK_H */
