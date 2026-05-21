#include <iostream>
#include <string>
using namespace std;

// ===== Implemented by Member 1 =====

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

Node* head = NULL;
int nextId = 1;

void addToList(Book b) {
Node* newNode = new Node();
newNode->data = b;
newNode->next = NULL;

if (head == NULL) {
head = newNode;
} else {
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

cout << "\n--- All Books ---" << endl;

while (temp != NULL) {

cout << "ID: " << temp->data.id
<< " | Title: " << temp->data.title
<< " | Author: " << temp->data.author;

if (temp->data.isIssued) {
cout << " | Issued to: " << temp->data.issuedTo;
} else {
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

cout << "Enter book title: ";
getline(cin, b.title);

cout << "Enter author name: ";
getline(cin, b.author);

addToList(b);

cout << "Book added successfully!" << endl;
}

void searchBook() {
int id;

cout << "Enter book ID: ";
cin >> id;

Node* result = findBook(id);

if (result == NULL) {
cout << "Book not found." << endl;
} else {

cout << "ID: " << result->data.id << endl;
cout << "Title: " << result->data.title << endl;
cout << "Author: " << result->data.author << endl;

if (result->data.isIssued) {
cout << "Issued to: " << result->data.issuedTo << endl;
} else {
cout << "Available" << endl;
}
}
}

void deleteBook() {
int id;

cout << "Enter book ID to delete: ";
cin >> id;

if (head == NULL) {
cout << "No books available." << endl;
return;
}

Node* temp = head;
Node* prev = NULL;

while (temp != NULL) {

if (temp->data.id == id) {

if (temp->data.isIssued) {
cout << "Book is issued. Return it first." << endl;
return;
}

if (prev == NULL) {
head = temp->next;
} else {
prev->next = temp->next;
}

delete temp;

cout << "Book deleted successfully." << endl;
return;
}

prev = temp;
temp = temp->next;
}

cout << "Book not found." << endl;
}
