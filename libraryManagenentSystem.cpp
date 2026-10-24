#include <iostream>
#include <vector>
using namespace std;

// Use -std=c++11 or cpp17 to run without warning

class LMS
{
    int bookId, bookStock;
    string bookName, authorName;

public:
    // accept books data
    void acceptBookData()
    {
        cout << "\nEnter the Book Id : ";
        cin >> bookId;
        cout << "Enter the Book Name : ";
        cin >> bookName;
        cout << "Enter the Author Name : ";
        cin >> authorName;
        cout << "Enter the Book Stock : ";
        cin >> bookStock;
    }

    // display the book data
    void displayBookData()
    {
        cout << "\nBook ID : " << bookId << endl;
        cout << "Book Name : " << bookName << endl;
        cout << "Book Author : " << authorName << endl;
        cout << "Book Stock : " << bookStock << endl;
    }

    void issueBook()
    {
        cout << "Ente the book name :";
    }

    // get the current book ID
    int getBookId()
    {
        return bookId;
    }
};

int main()
{
    vector<LMS> books;
    int choice;

    cout << "========== LIBRARY MANAGEMENT SYSTEM ==========" << endl;
    do
    {
        // display operation menu
        cout << "\n1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice :";
        cin >> choice;

        switch (choice)
        {
        // add book operation
        case 1:
        {
            LMS book;
            book.acceptBookData();
            books.push_back(book);
            cout << "\nBook added successfully!" << endl;
            break;
        }

        // display book operation
        case 2:
        {
            if (books.empty())
            {
                cout << "\nNo books available." << endl;
            }
            else
            {
                cout << "\n========== ALL BOOKS DATA ==========" << endl;
                for (LMS book : books)
                {
                    book.displayBookData();
                }
            }
            break;
        }

        // search book operation
        case 3:
        {
            int bookId;
            cout << "\nEnter the book ID : ";
            cin >> bookId;

            for (LMS book : books)
            {
                if (book.getBookId() == bookId)
                {
                    book.displayBookData();
                }
            }
        }
        break;

        // issue book
        case 4:
        {
            int bookId;
            cout << "Enter the book ID : ";
            cin >> bookId;

            for (LMS book : books)
            {
                if (book.getBookId() == bookId)
                {
                }
            }
        }
        break;

        // exit the operation menu
        case 5:
            cout << "\nExiting Library Management System..." << endl;
            break;

        // handle invalid input choice
        default:
            cout << "\nInvalid choice!" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}