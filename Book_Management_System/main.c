
// #include <stdio.h>
// #include <string.h>         // for strings
// #include <conio.h>         // for getch()
// #include <stdbool.h>      // for true / false
// #include <stdlib.h>      // memory allocation
#include "definition.c"    // for definitions and functions

void main()
{
    int size = 15;                             // Size of hardcoded books
    Book *books = malloc(size * sizeof(Book)); // Allocate memory for books
    if (books == NULL)
    {
        printf("Memory allocation failed!\n");
        return; // Exit if allocation fails
    }

    int booksCnt = 0; // Total count of books
    hardcodedBooks(books, &booksCnt); // Add hardcoded books to the array

    int choice;

    do
    {
        // Display the menu before processing any input
        printf("\n--------------- Book Management System ---------------\n");
        printf("1 -> Add Book \n");
        printf("2 -> Display Books \n");
        printf("3 -> Update Book \n");
        printf("4 -> Search Book \n");
        printf("5 -> Remove Book \n");
        printf("6 -> Display Sorted Books \n");
        printf("7 -> Exit... \n");

        printf("Enter your choice for operations: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n You have selected the option - Add Books. \n");
            if (booksCnt >= size)
            {
                size = size * 2; // Double the size
                books = realloc(books, size * sizeof(Book)); // Reallocate array
                if (books == NULL)
                {
                    printf("Memory allocation failed!\n");
                    return; // Exit if realloc fails
                }
            }
            getBooksDetail(&books[booksCnt], books, booksCnt);
            booksCnt++;
            break;

        case 2:
            printf("\n You have selected the option - Display Books. \n");
            if (booksCnt == 0)
            {
                printf("No books available to display.\n");
            }
            else
            {
                displayBooks(books, booksCnt);
            }
            break;

        case 3:
            printf("\n You have selected the option - Update Books. \n");
            if (booksCnt == 0)
            {
                printf("No books available to update.\n");
            }
            else
            {
                int searchBy;
                printf("Update by:\n1. ID\n2. Name\nEnter your choice: ");
                scanf("%d", &searchBy);
                updateBookByNameOrID(books, booksCnt, searchBy);
            }
            break;

        case 4:
            printf("\n You have selected the option - Search Books. \n");
            if (booksCnt == 0)
            {
                printf("No books available to search.\n");
            }
            else
            {
                int searchChoice;
                printf("Search by:\n1. ID\n2. Name\n3. Author\n4. Category\nEnter your choice: ");
                scanf("%d", &searchChoice);
                searchBook(books, booksCnt, searchChoice);
            }
            break;

        case 5:
            printf("\n You have selected the option - Remove Books. \n");
            if (booksCnt == 0)
            {
                printf("No books available to remove.\n");
            }
            else
            {
                int searchBy;
                printf("Remove by:\n1. ID\n2. Name\nEnter your choice: ");
                scanf("%d", &searchBy);
                removeBookByNameOrID(books, &booksCnt, searchBy);
            }
            break;

        case 6:
            printf("\n You have selected the option - Sort the books. \n");
            if (booksCnt == 0)
            {
                printf("No books available to sort.\n");
            }
            else
            {
                int sortBy;
                printf("Sort by:\n1. Price\n2. Rating\nEnter your choice: ");
                scanf("%d", &sortBy);
                displaySortedBooks(books, booksCnt, sortBy);
            }
            break;

        case 7:
            printf("\n You have selected the option - Exit. \n");
            printf("Thank you sir... You have done with all !!!\n");
            printf("Chal ab bahar nikal....\n");
            break;

        default:
            printf("\n Invalid option selected. Please select a valid option.\n");
            break;
        }

    } while (choice != 7);

    free(books); // Free the allocated memory
}
