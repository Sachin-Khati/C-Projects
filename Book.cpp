
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a book
struct Book
{
    string title;
    string author;
    int id;
    bool isAvailable;
};

// Define a structure to represent a member
struct Member
{
    string name;
    int id;
    vector<Book *> borrowedBooks;
};

// Function to add a new book to thee library
void addBook(vector<Book> &library)
{
    Book newBook;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);

    cout << "Enter author name: ";
    getline(cin, newBook.author);

    cout << "Enter book ID: ";
    cin >> newBook.id;

    newBook.isAvailable = true;
    library.push_back(newBook);

    cout << "Book added successfully!" << endl;
}
// Function to add a new member
void addMember(vector<Member> &members)
{
    Member newMember;

    cout << "Enter member name: ";
    cin.ignore();
    getline(cin, newMember.name);

    cout << "Enter member ID: ";
    cin >> newMember.id;

    members.push_back(newMember);
    cout << "Member added successfully!" << endl;
}

// Function to lend a book to a member
void lendBook(vector<Book> &library, vector<Member> &members)
{
    int memberId, bookId;
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << "Enter book ID: ";
    cin >> bookId;

    // Find member
    Member *member = nullptr;
    for (auto &m : members)
    {
        if (m.id == memberId)
        {
            member = &m;
            break;
        }
    }

    // Find book
    Book *book = nullptr;
    for (auto &b : library)
    {
        if (b.id == bookId)
        {
            book = &b;
            break;
        }
    }

    // Handle errors and lending
    if (!member)
        cout << "Member not found." << endl;
    else if (!book)
        cout << "Book not found." << endl;
    else if (!book->isAvailable)
        cout << "Book is already lent out." << endl;
    else
    {
        book->isAvailable = false;
        member->borrowedBooks.push_back(book);
        cout << "Book lent to " << member->name << "." << endl;
    }
}

// Function to display all books in the library
void displayBooks(const vector<Book> &library)
{
    cout << "Library Books:\n";
    for (const auto &book : library)
    {
        cout << "Title: " << book.title
             << ", Author: " << book.author
             << ", ID: " << book.id
             << (book.isAvailable ? " (Available)" : " (Not Available)") << endl;
    }
}

int main()
{
    vector<Book> library;
    vector<Member> members;
    int choice;

    do
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Lend Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            addBook(library);
            break;
        case 2:
            cin.ignore();
            addMember(members);
            break;
        case 3:
            lendBook(library, members);
            break;
        case 4:
            displayBooks(library);
            break;
        case 5:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
