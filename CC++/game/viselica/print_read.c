

long FileSize(FILE *Text)
{
    fseek(Text, SEEK_SET, SEEK_END);

    long sizeFile = 0;
    sizeFile = ftell(Text);

    rewind(Text);

    return sizeFile;
}

int print_rules()
{
    return 0;
}

int look_at_words()
{
    return 0;
}
