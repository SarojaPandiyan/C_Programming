#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define FILENAME "book_details.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    int year;
    char category[MAX_TITLE_LENGTH];
} Book;

void displayBookDetails(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Price: %.2f\n", book.price);
    printf("Year: %d\n", book.year);
    printf("Category: %s\n", book.category);
    printf("-----------------------\n");
}

void displayAllBooks(Book books[], int numBooks) {
    printf("All Book Details:\n");
    for (int i = 0; i < numBooks; i++) {
        displayBookDetails(books[i]);
    }
}

void displayBooksByCategory(Book books[], int numBooks, char category[]) {
    printf("Books in the %s category:\n", category);
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].category, category) == 0) {
            displayBookDetails(books[i]);
        }
    }
}

void displayCostliestBook(Book books[], int numBooks) {
    float maxPrice = 0;
    int maxIndex = -1;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].price > maxPrice) {
            maxPrice = books[i].price;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        printf("Costliest Book Details:\n");
        displayBookDetails(books[maxIndex]);
    } else {
        printf("No books found.\n");
    }
}

void displayBooksByAuthor(Book books[], int numBooks, char author[]) {
    printf("Books by %s:\n", author);
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].author, author) == 0) {
            displayBookDetails(books[i]);
        }
    }
}

void displayBooksPublishedBeforeYear(Book books[], int numBooks, int year) {
    printf("Books published on or before %d:\n", year);
    for (int i = 0; i < numBooks; i++) {
        if (books[i].year <= year) {
            displayBookDetails(books[i]);
        }
    }
}

int countArticlesInFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    char ch;
    int count = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == 'a' || ch == 'A') {
            count++;
        }
    }

    fclose(file);
    return count;
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    // Storing book details in a file
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter book details:\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        Book book;
        printf("Book %d:\n", i + 1);

        printf("Title: ");
        fgets(book.title, MAX_TITLE_LENGTH, stdin);

        printf("Author: ");
        fgets(book.author, MAX_AUTHOR_LENGTH, stdin);

        printf("Price: ");
        scanf("%f", &book.price);

        printf("Year: ");
        scanf("%d", &book.year);

        printf("Category: ");
        fgets(book.category, MAX_TITLE_LENGTH, stdin);

        // Remove the extra newline character from fgets
        strtok(book.category, "\n");

        // Store book details in the file
        fprintf(file, "%s\n%s\n%.2f\n%d\n%s\n", book.title, book.author, book.price, book.year, book.category);

        // Remove the extra newline character from fgets
        strtok(book.title, "\n");
        strtok(book.author, "\n");

        books[i] = book;
        numBooks++;

        char dummy[10]; // To consume the newline character after scanf
        fgets(dummy, sizeof(dummy), stdin); // Consume the newline character
        printf("-----------------------\n");
    }

    fclose(file);

    // Retrieving and performing operations on book details from the file
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\n");

    char line[200];
    int lineCount = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        switch (lineCount % 5) {
            case 0:
                strcpy(books[lineCount / 5].title, line);
                strtok(books[lineCount / 5].title, "\n");
                break;
            case 1:
                strcpy(books[lineCount / 5].author, line);
                strtok(books[lineCount / 5].author, "\n");
                break;
            case 2:
                sscanf(line, "%f", &books[lineCount / 5].price);
                break;
            case 3:
                sscanf(line, "%d", &books[lineCount / 5].year);
                break;
            case 4:
                strcpy(books[lineCount / 5].category, line);
                strtok(books[lineCount / 5].category, "\n");
                break;
        }

        lineCount++;
    }

    fclose(file);

    // Perform operations on book details
    displayAllBooks(books, numBooks);
    printf("\n");

    char category[MAX_TITLE_LENGTH];
    printf("Enter a category to display books: ");
    fgets(category, MAX_TITLE_LENGTH, stdin);
    strtok(category, "\n");
    displayBooksByCategory(books, numBooks, category);
    printf("\n");

    displayCostliestBook(books, numBooks);
    printf("\n");

    char author[MAX_AUTHOR_LENGTH];
    printf("Enter an author name to display books: ");
    fgets(author, MAX_AUTHOR_LENGTH, stdin);
    strtok(author, "\n");
    displayBooksByAuthor(books, numBooks, author);
    printf("\n");

    int year;
    printf("Enter a year to display books published on or before: ");
    scanf("%d", &year);
    displayBooksPublishedBeforeYear(books, numBooks, year);

    printf("\n");

    int articleCount = countArticlesInFile(FILENAME);
    if (articleCount != -1) {
        printf("Number of articles in the file: %d\n", articleCount);
    }

    return 0;
}
