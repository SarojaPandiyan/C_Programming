#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[50], word[20];
    FILE *fp;
    int count = 0, article_count = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        if (strcmp(word, "a") == 0 || strcmp(word, "an") == 0 || strcmp(word, "the") == 0) {
            article_count++;
        }
        count++;
    }

    printf("Number of articles: %d\n", article_count);

    fclose(fp);

    return 0;
}