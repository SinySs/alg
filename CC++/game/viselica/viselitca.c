#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "print_read.h"
#include "viselitca.h"

void game_preparatoin(struct words_arr *Guess, struct TextInfo *Words, struct game_word *new_game)
{
    new_game->named_letters = calloc(alphabet_len, sizeof(int));
    new_game->hidden_word = Guess->words[0]; //!TODO: random
    new_game->size = strlen(new_game->hidden_word);
    new_game->answer = calloc(new_game->size + 1, sizeof(char));
    new_game->incorrect_enter = 0;
    new_game->right_letters = 0;
    new_game->game_status = 0;

    for(int i = 0; i < new_game->size; i++) {
        new_game->answer[i] = '?';
    }
}

int check_in(const char *str, char letter, int size)
{
    for(int i = 0; i < size; i++) {
        if(str[i] == letter)
            return 1;
    }

    return 0;
}

int  replace_answer_letters(const char *str, char letter, int size, char *answer)
{
    int repleced_letters = 0;

    for(int i = 0; i < size; i++) {
        if(str[i] == letter) {
            answer[i] = letter;
            repleced_letters++;
        }
    }
    return repleced_letters;
}

void check_win_lose(struct game_word *new_game)
{
    if(new_game->right_letters == new_game->size) {
        new_game->game_status = 100;
        return;
    }

    if(new_game->incorrect_enter >= 10) {
        new_game->game_status = -1;
    }
}

int start_game(struct words_arr *Guess, struct TextInfo *Words, char *filename)
{
    struct game_word new_game;
    char letter;
    int res;

    if(Guess->words == NULL) {
        if(Words->buf == NULL) {
            ReadInBuF(Words, 1, filename);
        }

        buf_to_words(Words, Guess);
    }

    game_preparatoin(Guess, Words, &new_game);

    printf("Мы начинаем игру. Будет сложно(нет)\n");



    while(!new_game.game_status) {

        printf("You will have to guess this word: %s\n", new_game.answer);
        printf("Enter one letter\n");

        res = scanf("\n%c", &letter); //!TODO %s and check str to errors

        if(check_in(new_game.hidden_word, letter, new_game.size) == 1) {
            printf("This letter in word. Good job!\n");
            new_game.right_letters += replace_answer_letters(new_game.hidden_word, letter,
                                                             new_game.size, new_game.answer);

        } else {
            printf("Oh... You did a mistake!\n");
            new_game.incorrect_enter++;
        }

        check_win_lose(&new_game);

    }


    return 0;
}
