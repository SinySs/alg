#ifndef VISELITCA_H_INCLUDED
#define VISELITCA_H_INCLUDED

#define alphabet_len 32
#define MAX_MISTAKE 10

struct game_word {

    char *hidden_word;
    char *answer;
    int size;
    int right_letters;

    int *named_letters; // 0 if letter wasn't called
    int incorrect_enter; // if > 10 game over
    int game_status;

};

int start_game(struct words_arr *Guess, struct TextInfo *Words, char *filename);

#endif // VISELITCA_H_INCLUDED
