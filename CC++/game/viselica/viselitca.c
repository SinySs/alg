#include <stdio.h>
#include <malloc.h>

#include "print_read.h"
#include "viselitca.h"

int start_game(struct words_arr *Guess, struct TextInfo *Words, char *filename)
{
    struct game_word new_game;

    if(Guess->words == NULL) {
        if(Words->buf == NULL) {
            ReadInBuF(Words, 1, filename);
        }

        buf_to_words(Words, Guess);
    }

    new_game.named_letters = calloc(alphabet_len, sizeof(int));

    printf("Мы начинаем игру. Будет сложно(нет)\n");

    return 0;
}
