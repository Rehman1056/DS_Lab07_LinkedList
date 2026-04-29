/*#include <iostream>
using namespace std;

template<class T>
class node {
public:
    T data;
    node* next;
    node(T value, node* new_node = nullptr) {
        data = value;
        next = new_node;
    }
};

template<class T>
class link_list {
private:
    node<T>* head;
public:
    link_list() : head(nullptr) {}
    
    ~link_list() { // destructor
        node<T>* temp = head;
        while (temp != nullptr) {
            node<T>* next_node = temp->next;
            delete temp;
            temp = next_node;
        }
        head = nullptr;
    }
    
    bool isempty() {
        return head == nullptr;
    }
    
    // --- Insert Functions ---
    void insert_head(T v) {
        head = new node<T>(v, head);
    }
    
    void insert_tail(T v) {
        node<T>* new_node = new node<T>(v);
        
        if (isempty()) {
            head = new_node;
            return;
        }
        
        node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insert_postion(T v, int pos) {
        if (isempty() || pos <= 0) {
            insert_head(v);
            return;
        }
        
        node<T>* temp = head;
        for (int i = 1; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            return;
        }
        
        node<T>* new_node = new node<T>(v, temp->next);
        temp->next = new_node;
    }
    
    // delete function
    void delete_beg() {
        if (isempty()) {
            cout << "The list is Empty!." << endl;
            return;
        }
        node<T>* temp = head;
        head = head->next;
        delete temp;
        
        cout << "Node deleted from the beginning: \n";
    }

    void delete_End() {
        if (isempty()) {
            cout << "The list is Empty!" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "node deleted from end.: \n";
            display();
            return;
        }
        
        node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = nullptr;
        
        cout << "node deleted from end: \n";

    }

    void delete_Position(int pos) {
        if (isempty() || pos < 0) {
            cout << "the list is empty!" << endl;
            return;
        }
        
        if (pos == 0) {
            delete_beg();
            return;
        }
        
        node<T>* temp = head;
        for (int i = 1; i < pos && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "not found!" << endl;
            return;
        }
        
        node<T>* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        
        cout << "Node deleted from position: " << pos << "\n";
    }
    
    void search(T value) {
        node<T>* temp = head;
        int pos = 0;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value " << value << " does not exist in the list." << endl;
    }

    void update(int pos, T newValue) {
        if (isempty() || pos < 0) {
            cout << "the list is empty!" << endl;
            return;
        }
        
        node<T>* temp = head;
        for (int i = 0; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "not found!" << endl;
            return;
        }
        
        temp->data = newValue;
        cout << "Node at position " << pos << " updated successfully.\n";
    }

    void display() {
        if (isempty()) {
            cout << "The list is Empty!" << endl;
            return;
        }
        node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main() {
    link_list<int> list;
    int choice;
    int value;
    int position;

    do {
        cout << "\n========== EXTENDED LINKED LIST MENU ==========\n";
        cout << "1.  Insert a node at the beginning\n";
        cout << "2.  Insert a node at the end\n";
        cout << "3.  Insert a node at a given position\n";
        cout << "4.  Delete a node from the beginning\n";
        cout << "5.  Delete a node from the end\n";
        cout << "6.  Delete a node from a given position\n";
        cout << "7.  Search for an element\n";
        cout << "8.  Update the value of a node at a given position\n";
        cout << "9.  Display the linked list\n";
        cout << "10. Exit\n";
        cout << "===============================================\n";
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert_head(value);
                cout << "Value inserted successfully.\n";
                break;
                
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insert_tail(value);
                cout << "Value inserted successfully.\n";
                break;
                
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position (0 for the beginning): ";
                cin >> position;
                list.insert_postion(value, position);
                cout << "Insertion attempt complete.\n";
                break;
                
            case 4:
                list.delete_beg();
                break;
                
            case 5:
                list.delete_End();
                break;
                
            case 6:
                cout << "Enter position to delete (0 for the beginning): ";
                cin >> position;
                list.delete_Position(position);
                break;
                
            case 7:
                cout << "Enter value to search for: ";
                cin >> value;
                list.search(value);
                break;
                
            case 8:
                cout << "Enter position to update: ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> value;
                list.update(position, value);
                break;

            case 9:
                cout << "\nCurrent Linked List: \n";
                list.display();
                break;
                
            case 10:
                cout << "Exiting the program...\n";
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1 and 10.\n";
        }
    } while (choice != 10);

    return 0;
}*/ 
