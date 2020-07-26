#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000

int main()
{
    FILE *fptr;
    char path[1000000];
    int i, len, index, isUnique;

    char words[MAX_WORDS][50];
    char word[50];

    int  count[MAX_WORDS];

    printf("Enter file path: ");
    scanf("%s", path);

    fptr = fopen(path, "r");

    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }

    for (i=0; i<MAX_WORDS; i++)
        count[i] = 0;

    index = 0;

    while (fscanf(fptr, "%s", word) != EOF)
    {

        strlwr(word);

        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';

        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        if (isUnique)
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    fclose(fptr);

    printf("\nOccurrences of all distinct words in file: \n");
    for (i=0; i<index; i++)
    {
        printf("%-15s => %d\n", words[i], count[i]);
    }

    return 0;
}
