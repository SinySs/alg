#ifndef PRINT_READ_H_INCLUDED
#define PRINT_READ_H_INCLUDED

struct TextInfo {

    char *buf; ///< buffer with the contests of file
    const char *nameOfText; ///< name of the text read from file
    int text_size; ///< size of text read from file
    int num_of_words; ///< number of words of text read from file
    char *file = NULL;

};


#endif // PRINT_READ_H_INCLUDED
