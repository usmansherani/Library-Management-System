#include <iostream>
using namespace std;

// Function declarations

void showAllBooks();
void addBook();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();
void showStack();
void showQueue();

int main() {

int choice;

cout << "=== Library Management System ===" << endl;

do {

cout << "\n1. View all books" << endl;
cout << "2. Add a book" << endl;
cout << "3. Search a book" << endl;
cout << "4. Issue a book" << endl;
cout << "5. Return a book" << endl;
cout << "6. Delete a book" << endl;
cout << "7. Recently returned books" << endl;
cout << "8. Waiting list" << endl;
cout << "0. Exit" << endl;

cout << "Enter choice: ";
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
cout << "Invalid choice." << endl;
}

} while (choice != 0);

return 0;
}
