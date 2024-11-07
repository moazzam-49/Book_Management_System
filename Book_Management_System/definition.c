
#include "declarartion.h"

// Function to find a book by its ID
int findBookByID(Book *brr, int booksCnt, int bookID)
{
    for (int i = 0; i < booksCnt; i++)
    {
        if (brr[i].bookID == bookID)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to get book details
void getBooksDetail(Book *b, Book *brr, int booksCnt) {
    while (1) {
        printf("Enter the book ID: ");
        scanf("%d", &b->bookID);
        getchar(); // Clear the buffer

        if (findBookByID(brr, booksCnt, b->bookID) != -1) {
            printf("Book ID %d already exists. Please enter a unique ID.\n", b->bookID);
        } else {
            break; // Unique ID, exit the loop
        }
    }

    getValidInput(b->name, sizeof(b->name), "Enter the book name: ", 1); // For book name
    getValidInput(b->author, sizeof(b->author), "Enter the author name: ", 0); // For author
    getValidInput(b->category, sizeof(b->category), "Enter the book category: ", 0); // For category

    while (1) {
        printf("Enter the price: ");
        if (scanf("%lf", &b->price) != 1) {
            printf("Invalid input. Please enter a valid number for the price.\n");
            while (getchar() != '\n'); // Clear input buffer if necessary
            continue; // Retry the loop
        }
        getchar(); // Clear the buffer
        if (b->price >= 0)
            break;
        else
            printf("Price cannot be negative. Please enter a valid price.\n");
    }

    while (1) {
        printf("Enter the rating (0 to 5): ");
        if (scanf("%f", &b->rating) != 1) { // Check if the input is a valid float
            printf("Invalid input. Please enter a valid number for the rating.\n");
            while (getchar() != '\n'); // Clear input buffer if necessary
            continue; // Retry the loop
        }

        if (b->rating >= 0.0 && b->rating <= 5.0)
            break; // Valid rating, exit the loop
        else
            printf("Please enter a valid rating between 0 and 5.\n");
    }
}


// Valid Book Name
void getValidInput(char *input, int size, char *prompt, int isBookName)
{
    int valid = 0; // Assume invalid initially
    while (!valid)
    {
        valid = 1; // Set valid status
        printf("%s", prompt);
        fgets(input, size, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline

        if (strlen(input) == 0)
        {
            valid = 0; // Set valid to false
            printf("Input cannot be empty. Please enter a valid input.\n");
            continue; // Restart the loop
        }

        // Additional checks for book name
        if (isBookName && (input[0] == ',' || input[0] == '-' ||
                           input[strlen(input) - 1] == ',' || input[strlen(input) - 1] == '-'))
        {
            valid = 0; // Set valid to false
            printf("Invalid entry. Book name cannot start or end with a comma/dash.\n");
            continue; // Restart the loop
        }

        // Character validation
        for (int i = 0; input[i] != '\0'; i++)
        {
            if ((!((input[i] >= 'a' && input[i] <= 'z') ||
                  (input[i] >= 'A' && input[i] <= 'Z') ||
                  (input[i] >= '0' && input[i] <= '9') ||
                  input[i] == ',' || input[i] == '-' || input[i] == ' ')) && isBookName)
                {
                    valid = 0; // Set valid to false
                    printf("Only alphabets, commas, and dashes are allowed for book names.\n");
                    break;
                }
        }
    }
}

// Function to display details of a book
void displayBookDetails(Book *b)
{
    printf("Book ID: %d\n", b->bookID);
    printf("Book name: %s\n", b->name);
    printf("Author name: %s\n", b->author);
    printf("Category: %s\n", b->category);
    printf("Price: %.2lf\n", b->price);
    printf("Rating: %.1f\n", b->rating);
    printf("\n");
}

// Function to display details of multiple books
void displayBooks(Book *brr, int booksCnt)
{
    printf("\n--------------- Book Details ---------------\n");

    if (booksCnt <= 0)
    {
        printf("No books available. \n");
        printf("You can add by using the menu options below. \n");
        return;
    }

    for (int i = 0; i < booksCnt; i++)
    {
        displayBookDetails(&brr[i]); 
    }
}



// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


// Function to check if a substring exists in a string in a case-insensitive way
int substringCaseSensitive(char *str, char *substr) {
    char lowerStr[50], lowerSubstr[50]; // Adjust size as needed

    // Copy the strings to lowercase buffers
    strcpy(lowerStr, str);
    strcpy(lowerSubstr, substr);

    toLowerCase(lowerStr);
    toLowerCase(lowerSubstr);

    return strstr(lowerStr, lowerSubstr) != NULL;
}


// Function to update a book's details by ID
void updateBookByNameOrID(Book *brr, int booksCnt, int searchBy)
{
    printf("\n--------------- Update Book by Name or ID ---------------\n");

    if (booksCnt <= 0)
    {
        printf("No books available to update.\n");
        return;
    }

    if (searchBy == 1)
    {
        int bookID;
        printf("Enter the book ID to update: ");
        scanf("%d", &bookID);

        int index = findBookByID(brr, booksCnt, bookID);
        if (index == -1)
        {
            printf("No book found with the ID: %d\n", bookID);
            return;
        }

        printf("Book found. Now update it ....\n");
        printf("Want to update the price?\n1. If yes (1)\n2. If No (2)\n");
        printf("Enter the choice: ");
        int priceChoice;
        scanf("%d", &priceChoice);
        if (priceChoice == 1)
        {
            printf("Enter updated Price: ");
            scanf("%lf", &brr[index].price);
        }

        printf("Want to update the rating?\n1. If yes (1)\n2. If No (2)\n");
        printf("Enter the choice: ");
        int ratingChoice;
        scanf("%d", &ratingChoice);
        if (ratingChoice == 1)
        {
            printf("Enter updated rating: ");
            scanf("%f", &brr[index].rating);
        }

        printf("Book updated Successfully!!!\n");
    }
    else if (searchBy == 2)
    {
        char bookName[50];
        printf("Enter the book name to update: ");
        getchar(); 
        fgets(bookName, sizeof(bookName), stdin);
        bookName[strcspn(bookName, "\n")] = 0; 

        int found = 0; 
        for (int i = 0; i < booksCnt; i++)
        {
            if (substringCaseSensitive(brr[i].name, bookName))
            { // Check if the name matches
                found = 1;
                printf("Book found. Now update it ....\n");

                // Call the function to update price and rating
                printf("Want to update the price?\n1. Yes \n2. No\n");
                printf("Enter the choice: ");
                int priceChoice;
                scanf("%d", &priceChoice);
                if (priceChoice == 1)
                {
                    printf("Enter updated Price: ");
                    scanf("%lf", &brr[i].price);
                }

                printf("Want to update the rating?\n1. Yes \n2. No\n");
                printf("Enter the choice: ");
                int ratingChoice;
                scanf("%d", &ratingChoice);
                if (ratingChoice == 1)
                {
                    printf("Enter updated rating: ");
                    scanf("%f", &brr[i].rating);
                }

                printf("Book updated Successfully!!!\n");
                break; // Exit after updating one match
            }
        }

        if (!found)
            printf("No book found with the name: %s\n", bookName);
        
    }

    else
        printf("Invalid choice for updating.\n");
    
}

// Reusable search function for name, author, and category
void searchBooks(Book *brr, int booksCnt, int searchField, const char *prompt)
{
    printf("\n---------- Searching --------------\n");

    if (booksCnt <= 0)
    {
        printf("No books available.\n");
        printf("Kuch availabe hoga tabhi to dhundhunga...\n");
        return;
    }

    char searchInput[50];
    printf("%s", prompt);
    getchar(); // Clear the buffer
    fgets(searchInput, sizeof(searchInput), stdin);
    searchInput[strcspn(searchInput, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\nBooks found containing \"%s\":\n", searchInput);
    int foundIDs[booksCnt]; // Array to store IDs of found books
    int foundCount = 0;     // Counter for found books

    for (int i = 0; i < booksCnt; i++)
    {
        int match = 0;

        // Search by the specified field
        if (searchField == 1 && substringCaseSensitive(brr[i].name, searchInput))
        {
            match = 1; // Match by name
        }

        else if (searchField == 2 && substringCaseSensitive(brr[i].author, searchInput))
        {
            match = 1; // Match by author
        }

        else if (searchField == 3 && substringCaseSensitive(brr[i].category, searchInput))
        {
            match = 1; // Match by category
        }

        // If match is found, display the book and store its ID
        if (match)
        {
            displayBookDetails(&brr[i]);
            foundIDs[foundCount++] = brr[i].bookID; // Store the found book ID
            found = 1;
        }
    }

    if (!found)
        printf("No books found matching \"%s\".\n", searchInput);
    

    else
    {
        int selectedID;
        printf("Enter the ID of the book you want details for: ");
        scanf("%d", &selectedID);

        // Find the book by the selected ID
        int index = findBookByID(brr, booksCnt, selectedID);
        if (index != -1)
        {
            printf("\nDetailed information for Book ID: %d\n", selectedID);
            displayBookDetails(&brr[index]); // Display details of the selected book
        }

        else
            printf("No book found with ID: %d\n", selectedID);
        
    }
}


// Search a book either by ID,name, author or category
void searchBook(Book *brr, int booksCnt, int searchBy)
{
    if (booksCnt <= 0)
    {
        printf("No books available to search.\n");
        return;
    }

    switch (searchBy)
    {
    case 1:
    { // Search by ID
        int searchID;
        printf("Enter Book ID to search: ");
        scanf("%d", &searchID);

        int index = findBookByID(brr, booksCnt, searchID);
        if (index != -1)
        {
            printf("\nBook found:\n");
            displayBookDetails(&brr[index]);
        }

        else
            printf("Book with ID %d not found.\n", searchID);
        break;
    }

    case 2:
    { // Search by Name
        searchBooks(brr, booksCnt, 1, "Enter a substring to search in Book Names: ");
        break;
    }

    case 3:
    { // Search by Author
        searchBooks(brr, booksCnt, 2, "Enter a substring to search in Author Names: ");
        break;
    }

    case 4:
    { // Search by Category
        searchBooks(brr, booksCnt, 3, "Enter a substring category to search: ");
        break;
    }

    default:
        printf("Invalid search option.\n");
        break;
    }
}


// Function to remove a book by ID
void removeBookByNameOrID(Book *brr, int *booksCnt, int searchBy)
{
    printf("\n--------------- Remove Book by Name or ID ---------------\n");

    if (*booksCnt <= 0)
    {
        printf("No books available to remove.\n");
        return;
    }

    if (searchBy == 1)
    {
        int bookID;
        printf("Enter the book ID to remove: ");
        scanf("%d", &bookID);

        int index = findBookByID(brr, *booksCnt, bookID);
        if (index == -1)
        {
            printf("No book found with the ID: %d\n", bookID);
            return;
        }

        for (int i = index; i < *booksCnt - 1; i++)
        {
            brr[i] = brr[i + 1];
        }

        (*booksCnt)--;  // Decrease the count of books
        printf("Book with ID '%d' removed successfully!\n", bookID);
    }
    else if (searchBy == 2)
    {
        char bookName[50];
        printf("Enter the book name to remove: ");
        getchar();
        fgets(bookName, sizeof(bookName), stdin);
        bookName[strcspn(bookName, "\n")] = 0; 

        int found = 0; 
        for (int i = 0; i < *booksCnt; i++)
        {
            if (substringCaseSensitive(brr[i].name, bookName)) 
            { 
                for (int j = i; j < *booksCnt - 1; j++)      
                {
                    brr[j] = brr[j + 1];    // Shift books down to remove the book from the array
                }

                (*booksCnt)--;  // Decrease the count of books
                found = 1;
                printf("Book '%s' removed successfully!\n", bookName);
                break;
            }
        }


        if (!found)
            printf("No book found with the name: %s\n", bookName);
        
    }

    else
        printf("Invalid choice for removal.\n");
    
}


// displaySorted Books
void displaySortedBooks(Book *brr, int booksCnt, int sortBy)
{
    printf("\n--------------- Display sorted books ---------------\n");

    if (booksCnt <= 0)
    {
        printf("No books available.\n");
        return;
    }

    Book sortedBooks[booksCnt];
    for (int i = 0; i < booksCnt; i++)
    {
        sortedBooks[i] = brr[i];
    }

    int pattern;
    printf("Choose the pattern:\n1. Ascending\n2. Descending\nEnter your choice: ");
    scanf("%d", &pattern);

    // Validate the order input
    if (pattern != 1 && pattern != 2)
    {
        printf("Invalid choice.....\n");
        return;
    }

    // selection sort
    for (int i = 0; i < booksCnt - 1; i++)
    {
        for (int j = i + 1; j < booksCnt; j++)
        {
            int karoSwap = 0;

            // Sort by price
            if (sortBy == 1)
            {
                if (pattern == 1)
                { // Ascending
                    if (sortedBooks[i].price > sortedBooks[j].price)
                        karoSwap = 1;
                }

                else
                { // Descending
                    if (sortedBooks[i].price < sortedBooks[j].price)
                        karoSwap = 1;
                }
            }

            // Sort by rating
            else if (sortBy == 2)
            {
                if (pattern == 1) 
                { // Ascending
                    if (sortedBooks[i].rating > sortedBooks[j].rating)
                            karoSwap = 1;
                }
                
                else
                { // Descending
                    if (sortedBooks[i].rating < sortedBooks[j].rating)
                            karoSwap = 1;
                }
                
            }

            if (karoSwap)
            {
                Book temp = sortedBooks[i];
                sortedBooks[i] = sortedBooks[j];
                sortedBooks[j] = temp;
            }
        }
    }

    displayBooks(sortedBooks, booksCnt);
}
