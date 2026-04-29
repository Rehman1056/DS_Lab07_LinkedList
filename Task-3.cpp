/*#include <iostream>
using namespace std;
// function to manage the student
class Student {
public:
    int roll;
    string name;
    float marks;

    Student(int r = 0, string n = "", float m = 0) {
        roll = r;
        name = n;
        marks = m;
    }

    void display() {
        cout << "Roll No: " << roll
             << ", Name: " << name
             << ", Marks: " << marks << endl;
    }
};

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

    ~link_list() {
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

    void insert_after_roll(int roll, T v) {
        node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data.roll == roll) {
                node<T>* new_node = new node<T>(v, temp->next);
                temp->next = new_node;
                return;
            }
            temp = temp->next;
        }

        cout << "Roll number not found!\n";
    }

    void delete_roll(int roll) {
        if (isempty()) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data.roll == roll) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted successfully\n";
            return;
        }

        node<T>* temp = head;

        while (temp->next != nullptr) {
            if (temp->next->data.roll == roll) {
                node<T>* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                cout << "Deleted successfully\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Roll number not found!\n";
    }

    void search(int roll) {
        node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data.roll == roll) {
                cout << "Student Found:\n";
                temp->data.display();
                return;
            }
            temp = temp->next;
        }

        cout << "Student not found!\n";
    }

    void update(int roll) {
        node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data.roll == roll) {
                cout << "Enter new name: ";
                cin >> temp->data.name;

                cout << "Enter new marks: ";
                cin >> temp->data.marks;

                cout << "Updated successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Student not found!\n";
    }

    void display() {
        if (isempty()) {
            cout << "List is empty!\n";
            return;
        }

        node<T>* temp = head;

        while (temp != nullptr) {
            temp->data.display();
            temp = temp->next;
        }
    }

    void statistics() {
        if (isempty()) {
            cout << "List is empty!\n";
            return;
        }

        node<T>* temp = head;

        float total = 0;
        float maxMarks = temp->data.marks;
        float minMarks = temp->data.marks;
        int count = 0;

        while (temp != nullptr) {
            float m = temp->data.marks;

            if (m > maxMarks) maxMarks = m;
            if (m < minMarks) minMarks = m;

            total += m;
            count++;

            temp = temp->next;
        }

        cout << "Highest Marks: " << maxMarks << endl;
        cout << "Lowest Marks: " << minMarks << endl;
        cout << "Average Marks: " << total / count << endl;
    }
};

int main() {
    link_list<Student> list;
    int choice;

    do {
        cout << "\n===== Student Record System =====\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert After Roll\n";
        cout << "4. Delete by Roll\n";
        cout << "5. Display\n";
        cout << "6. Search\n";
        cout << "7. Update\n";
        cout << "8. Statistics\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int r; string n; float m;
            cout << "Enter Roll, Name, Marks: ";
            cin >> r >> n >> m;

            Student s(r, n, m);

            if (choice == 1)
                list.insert_head(s);
            else
                list.insert_tail(s);
        }

        else if (choice == 3) {
            int roll;
            cout << "Enter roll to insert after: ";
            cin >> roll;

            int r; string n; float m;
            cout << "Enter new student: ";
            cin >> r >> n >> m;

            list.insert_after_roll(roll, Student(r, n, m));
        }

        else if (choice == 4) {
            int roll;
            cout << "Enter roll to delete: ";
            cin >> roll;
            list.delete_roll(roll);
        }

        else if (choice == 5) {
            list.display();
        }

        else if (choice == 6) {
            int roll;
            cout << "Enter roll to search: ";
            cin >> roll;
            list.search(roll);
        }

        else if (choice == 7) {
            int roll;
            cout << "Enter roll to update: ";
            cin >> roll;
            list.update(roll);
        }

        else if (choice == 8) {
            list.statistics();
        }

    } while (choice != 0);

    return 0;
}*/ 
