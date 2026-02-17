#include <iostream>
#include <cstring>
#include <iomanip> //rounding gpa
#include "Node.h"
#include "Student.h"


using namespace std;




int main() {
    Node* head = nullptr;

    while (true) {
        cout << "Use one of the commands (ADD, PRINT, DELETE, AVERAGE, QUIT)" << endl;

        char arr[10];
        cin >> arr;

        for (int x = 0; x < strlen(arr); x++) {//makes command uppercase
            arr[x] = toupper(arr[x]);
        }

        if (strcmp(arr, "ADD") == 0) {
            addStudent(head);
        }
        else if (strcmp(arr, "DELETE") == 0) {
            deleteStudent(head);
        }
        else if (strcmp(arr, "PRINT") == 0) {
            printStudent(head);
        }
        else if (strcmp(arr, "AVERAGE") == 0) {
            printAverage(head);
        }
        else if (strcmp(arr, "QUIT") == 0) {
            break;
        }
    }

    // frees data before exit
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp->getStudent();
        delete temp;
    }

    return 0;
}

