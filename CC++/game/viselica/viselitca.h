#ifndef VISELITCA_H_INCLUDED
#define VISELITCA_H_INCLUDED

#define alphabet_len 32

struct game_word {

    char *hidden_word;
    char *answer;
    int size;

    int *named_letters; // 0 if letter wasn't called

};

int start_game(struct words_arr *Guess, struct TextInfo *Words, char *filename);

#endif // VISELITCA_H_INCLUDED
