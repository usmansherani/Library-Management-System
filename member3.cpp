#include <iostream>
#include <string>
using namespace std;

// ===== Implemented by Member 3 =====

struct Book {
int id;
string title;
string author;
bool isIssued;
string issuedTo;
};

struct Node {
Book data;
Node* next;
};

struct QueueNode {
int bookId;
string personName;
QueueNode* next;
};

extern Node* head;

QueueNode* qFront = NULL;
QueueNode* qRear = NULL;

Node* findBook(int id);

void addToQueue(int bookId, string name) {

QueueNode* newNode = new QueueNode();

newNode->bookId = bookId;
newNode->personName = name;
newNode->next = NULL;

if (qRear == NULL) {

qFront = newNode;
qRear = newNode;

} else {

qRear->next = newNode;
qRear = newNode;
}

cout << name << " added to waiting list." << endl;
}

string removeFromQueue(int bookId) {

QueueNode* temp = qFront;
QueueNode* prev = NULL;

while (temp != NULL) {

if (temp->bookId == bookId) {

string name = temp->personName;

if (prev == NULL) {
qFront = temp->next;
} else {
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
cout << "Waiting list empty." << endl;
return;
}

QueueNode* temp = qFront;

cout << "\n--- Waiting List ---" << endl;

while (temp != NULL) {

cout << "Book ID: " << temp->bookId
<< " | Name: " << temp->personName << endl;

temp = temp->next;
}
}

void issueBook() {

int id;

cout << "Enter book ID to issue: ";
cin >> id;

Node* result = findBook(id);

if (result == NULL) {
cout << "Book not found." << endl;
return;
}

if (result->data.isIssued) {

cout << "Book already issued to "
<< result->data.issuedTo << endl;

cout << "Join waiting list? (1 = Yes, 0 = No): ";

int choice;
cin >> choice;

if (choice == 1) {

string name;

cin.ignore();

cout << "Enter your name: ";
getline(cin, name);

addToQueue(id, name);
}

} else {

string name;

cin.ignore();

cout << "Enter your name: ";
getline(cin, name);

result->data.isIssued = true;
result->data.issuedTo = name;

cout << "Book issued successfully." << endl;
}
}
