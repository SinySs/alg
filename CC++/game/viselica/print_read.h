#ifndef PRINT_READ_H_INCLUDED
#define PRINT_READ_H_INCLUDED


struct TextInfo {

    char *buf; ///< buffer with the contests of file
    const char *Text_name; ///< name of the text read from file
    int Text_size; ///< size of text read from file
    int num_of_words; ///< number of words of text read from file
    char *file;

};

int ReadInBuF(struct TextInfo *Text, int param, char *filename);

int print_rules(char *filename);

int look_at_words(char *filename);




#endif // PRINT_READ_H_INCLUDED
