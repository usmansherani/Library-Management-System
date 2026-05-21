#include <iostream>
#include <string>
using namespace std;

// ===== Implemented by Member 2 =====

struct Book {
int id;
string title;
string author;
bool isIssued;
string issuedTo;
};

struct StackNode {
Book data;
StackNode* next;
};

struct Node {
Book data;
Node* next;
};

extern Node* head;

StackNode* stackTop = NULL;

Node* findBook(int id);

void pushStack(Book b) {

StackNode* newNode = new StackNode();

newNode->data = b;
newNode->next = stackTop;

stackTop = newNode;
}

void showStack() {

if (stackTop == NULL) {
cout << "No recently returned books." << endl;
return;
}

StackNode* temp = stackTop;

cout << "\n--- Recently Returned Books ---" << endl;

while (temp != NULL) {

cout << "ID: " << temp->data.id
<< " | Title: " << temp->data.title << endl;

temp = temp->next;
}
}

void returnBook() {

int id;

cout << "Enter book ID to return: ";
cin >> id;

Node* result = findBook(id);

if (result == NULL) {
cout << "Book not found." << endl;
return;
}

if (!result->data.isIssued) {
cout << "Book is already available." << endl;
return;
}

cout << result->data.title
<< " returned by "
<< result->data.issuedTo << endl;

pushStack(result->data);

result->data.isIssued = false;
result->data.issuedTo = "";

cout << "Book returned successfully." << endl;
}
