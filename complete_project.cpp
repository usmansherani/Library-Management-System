#include <iostream>
#include <string>
using namespace std;

// =====================================================
//           LIBRARY MANAGEMENT SYSTEM PROJECT
//
// Member 1: Usman Sherani
// Member 2: Ahmed Imran
// Member 3: Arslan Haider
// =====================================================


// =====================================================
//                 MEMBER 1 SECTION
//                 Usman Sherani
//        Linked List + Book Management
// =====================================================


// ---------- BOOK STRUCTURE ----------

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo;
};


// ---------- LINKED LIST ----------

struct Node {
    Book data;
    Node* next;
};


// ---------- STACK ----------

struct StackNode {
    Book data;
    StackNode* next;
};


// ---------- QUEUE ----------

struct QueueNode {
    int bookId;
    string personName;
    QueueNode* next;
};


// ---------- GLOBAL VARIABLES ----------

Node* head = NULL;

StackNode* stackTop = NULL;

QueueNode* qFront = NULL;
QueueNode* qRear = NULL;

int nextId = 1;


// ---------- LINKED LIST FUNCTIONS ----------

void addToList(Book b) {

    Node* newNode = new Node();

    newNode->data = b;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}


Node* findBook(int id) {

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.id == id) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}


void showAllBooks() {

    if (head == NULL) {
        cout << "No books available." << endl;
        return;
    }

    Node* temp = head;

    cout << "\n========== ALL BOOKS ==========" << endl;

    while (temp != NULL) {

        cout << "ID: " << temp->data.id
             << " | Title: " << temp->data.title
             << " | Author: " << temp->data.author;

        if (temp->data.isIssued) {
            cout << " | Issued To: " << temp->data.issuedTo;
        }
        else {
            cout << " | Available";
        }

        cout << endl;

        temp = temp->next;
    }
}


void addBook() {

    Book b;

    b.id = nextId;
    nextId++;

    b.isIssued = false;
    b.issuedTo = "";

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    addToList(b);

    cout << "Book Added Successfully!" << endl;
}


void searchBook() {

    int id;

    cout << "Enter Book ID: ";
    cin >> id;

    Node* result = findBook(id);

    if (result == NULL) {
        cout << "Book Not Found." << endl;
    }
    else {

        cout << "\nBook Found" << endl;

        cout << "ID: " << result->data.id << endl;
        cout << "Title: " << result->data.title << endl;
        cout << "Author: " << result->data.author << endl;

        if (result->data.isIssued) {
            cout << "Status: Issued To "
                 << result->data.issuedTo << endl;
        }
        else {
            cout << "Status: Available" << endl;
        }
    }
}


void deleteBook() {

    int id;

    cout << "Enter Book ID To Delete: ";
    cin >> id;

    if (head == NULL) {
        cout << "No Books Available." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {

        if (temp->data.id == id) {

            if (temp->data.isIssued) {
                cout << "Book Is Issued. Return It First." << endl;
                return;
            }

            if (prev == NULL) {
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }

            delete temp;

            cout << "Book Deleted Successfully." << endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Book Not Found." << endl;
}



// =====================================================
//                 MEMBER 2 SECTION
//                  Ahmed Imran
//            Stack + Return Book System
// =====================================================


// ---------- STACK FUNCTIONS ----------

void pushStack(Book b) {

    StackNode* newNode = new StackNode();

    newNode->data = b;
    newNode->next = stackTop;

    stackTop = newNode;
}


void showStack() {

    if (stackTop == NULL) {
        cout << "No Recently Returned Books." << endl;
        return;
    }

    StackNode* temp = stackTop;

    cout << "\n===== RECENTLY RETURNED BOOKS =====" << endl;

    while (temp != NULL) {

        cout << "ID: "
             << temp->data.id
             << " | Title: "
             << temp->data.title << endl;

        temp = temp->next;
    }
}



// =====================================================
//                 MEMBER 3 SECTION
//                 Arslan Haider
//          Queue + Waiting List System
// =====================================================


// ---------- QUEUE FUNCTIONS ----------

void addToQueue(int bookId, string name) {

    QueueNode* newNode = new QueueNode();

    newNode->bookId = bookId;
    newNode->personName = name;
    newNode->next = NULL;

    if (qRear == NULL) {

        qFront = newNode;
        qRear = newNode;
    }
    else {

        qRear->next = newNode;
        qRear = newNode;
    }

    cout << name << " Added To Waiting List." << endl;
}


string removeFromQueue(int bookId) {

    QueueNode* temp = qFront;
    QueueNode* prev = NULL;

    while (temp != NULL) {

        if (temp->bookId == bookId) {

            string name = temp->personName;

            if (prev == NULL) {
                qFront = temp->next;
            }
            else {
                prev->next = temp->next;
            }

            if (temp == qRear) {
                qRear = prev;
            }

            delete temp;

            return name;
        }

        prev = temp;
        temp = temp->next;
    }

    return "";
}


void showQueue() {

    if (qFront == NULL) {
        cout << "Waiting List Empty." << endl;
        return;
    }

    QueueNode* temp = qFront;

    cout << "\n========== WAITING LIST ==========" << endl;

    while (temp != NULL) {

        cout << "Book ID: "
             << temp->bookId
             << " | Name: "
             << temp->personName << endl;

        temp = temp->next;
    }
}



// =====================================================
//            MEMBER 3 - ISSUE BOOK SYSTEM
// =====================================================

void issueBook() {

    int id;

    cout << "Enter Book ID To Issue: ";
    cin >> id;

    Node* result = findBook(id);

    if (result == NULL) {
        cout << "Book Not Found." << endl;
        return;
    }

    if (result->data.isIssued) {

        cout << "Book Already Issued To "
             << result->data.issuedTo << endl;

        cout << "Join Waiting List? (1 = Yes, 0 = No): ";

        int choice;
        cin >> choice;

        if (choice == 1) {

            string name;

            cin.ignore();

            cout << "Enter Your Name: ";
            getline(cin, name);

            addToQueue(id, name);
        }
    }
    else {

        string name;

        cin.ignore();

        cout << "Enter Your Name: ";
        getline(cin, name);

        result->data.isIssued = true;
        result->data.issuedTo = name;

        cout << "Book Issued Successfully." << endl;
    }
}



// =====================================================
//            MEMBER 2 - RETURN BOOK SYSTEM
// =====================================================

void returnBook() {

    int id;

    cout << "Enter Book ID To Return: ";
    cin >> id;

    Node* result = findBook(id);

    if (result == NULL) {
        cout << "Book Not Found." << endl;
        return;
    }

    if (!result->data.isIssued) {
        cout << "Book Already Available." << endl;
        return;
    }

    cout << result->data.title
         << " Returned By "
         << result->data.issuedTo << endl;

    pushStack(result->data);

    string nextPerson = removeFromQueue(id);

    if (nextPerson != "") {

        result->data.issuedTo = nextPerson;

        cout << nextPerson
             << " Was Next In Waiting List." << endl;

        cout << "Book Auto-Issued Successfully." << endl;
    }
    else {

        result->data.isIssued = false;
        result->data.issuedTo = "";
    }
}



// =====================================================
//                    MAIN FUNCTION
// =====================================================

int main() {

    // Default Books

    Book b1;

    b1.id = nextId;
    nextId++;

    b1.title = "Introduction To Algorithms";
    b1.author = "CLRS";
    b1.isIssued = false;
    b1.issuedTo = "";

    addToList(b1);


    Book b2;

    b2.id = nextId;
    nextId++;

    b2.title = "Data Structures In C++";
    b2.author = "Adam Drozdek";
    b2.isIssued = false;
    b2.issuedTo = "";

    addToList(b2);


    Book b3;

    b3.id = nextId;
    nextId++;

    b3.title = "Operating System Concepts";
    b3.author = "Silberschatz";
    b3.isIssued = false;
    b3.issuedTo = "";

    addToList(b3);


    int choice;

    cout << "========== LIBRARY MANAGEMENT SYSTEM ==========" << endl;

    do {

        cout << "\n1. View All Books" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Delete Book" << endl;
        cout << "7. Recently Returned Books" << endl;
        cout << "8. View Waiting List" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            showAllBooks();
        }

        else if (choice == 2) {
            addBook();
        }

        else if (choice == 3) {
            searchBook();
        }

        else if (choice == 4) {
            issueBook();
        }

        else if (choice == 5) {
            returnBook();
        }

        else if (choice == 6) {
            deleteBook();
        }

        else if (choice == 7) {
            showStack();
        }

        else if (choice == 8) {
            showQueue();
        }

        else if (choice == 0) {
            cout << "Goodbye!" << endl;
        }

        else {
            cout << "Invalid Choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
