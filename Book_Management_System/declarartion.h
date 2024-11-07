
#include <stdio.h>
#include <string.h>      // for strings
#include <conio.h>      // for getch()
#include <stdbool.h>   // for true / false
#include <stdlib.h>   // memory allocation
#include <ctype.h>   // toLower()


// Book Structure
typedef struct Book {
    int bookID;
    char name[50];
    char author[25];
    char category[20];
    double price;
    float rating;
} Book;



// Hardcoded Books:
void hardcodedBooks(Book *brr, int *size)
{
    Book hardcodedBooks[] = {
        {1, "The Pragmatic Programmer", "Andrew Hunt", "Programming", 15.99, 4.8},
        {2, "Pride and Prejudice", "Jane Austen", "Romance", 9.99, 4.8},
        {3, "The Hobbit", "J.R.R. Tolkien", "Fantasy", 14.99, 4.9},
        {4, "Clean Code", "Robert C. Martin", "Programming", 21.99, 4.7},
        {5, "To Kill a Mockingbird", "Harper Lee", "Classic", 10.99, 4.9},
        {6, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", 12.99, 4.8},
        {7, "Introduction to Algorithms", "Thomas H. Cormen", "Programming", 35.99, 4.9},
        {8, "1984", "George Orwell", "Classic", 12.99, 4.8},
        {9, "Embedded Systems", "Michael J. Pont", "Electronics", 22.99, 4.5},
        {10, "Eloquent JavaScript", "Dennis Rit", "Programming", 16.99, 4.5},
        {11, "The Fault in Our Stars", "John Green", "Romance", 12.99, 4.8},
        {12, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 18.99, 4.9},
        {13, "You Dont Know JS", "Kyle Simpson", "Programming", 19.99, 4.6},
        {14, "The Great Gatsby", "F. Scott Fitzgerald", "Classic", 11.99, 4.7},
        {15, "Electronics for Dummies", "Cathleen Sham", "Electronics", 17.99, 4.3}
    };

    *size = sizeof(hardcodedBooks) / sizeof(hardcodedBooks[0]);
    for (int i = 0; i < *size; i++)
    {
        brr[i] = hardcodedBooks[i]; // Copy hardcoded books to array
    }
}


// Function prototypes
void getBooksDetail(Book*, Book*, int);
void getValidInput(char*, int, char *, int);
void displayBookDetails(Book *b);
void displayBooks(Book*, int);
int findBookByID(Book*, int, int);
void toLowerCase(char *);
int substringCaseSensitive(char*, char*);
void updateBookByNameOrID(Book*, int, int);
void searchBook(Book*, int, int);
void removeBookByNameOrID(Book*, int*, int);
void getBookName(char*, int);
void getAuthorOrCategory(char*, int, const char*);
void displaySortedBooks(Book*, int, int);
void hardcodedBooks(Book* , int* );

