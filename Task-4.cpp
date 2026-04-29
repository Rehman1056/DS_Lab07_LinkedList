#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point& p) {
        return (x == p.x && y == p.y);
    }

    void display() {
        cout << "(" << x << "," << y << ")";
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

    void delete_End() {
        if (isempty()) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    bool collisionCheck(T newHead) {
        node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data == newHead) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void move(T newHead, bool grow) {

        if (collisionCheck(newHead)) {
            cout << "💥 Collision Detected! Game Over.\n";
            return;
        }

        insert_head(newHead);

        if (!grow) {
            delete_End();
        }
    }

    void printSnake() {
        if (isempty()) {
            cout << "Snake is empty\n";
            return;
        }

        node<T>* temp = head;
        cout << "Snake: ";

        while (temp != nullptr) {
            temp->data.display();
            cout << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {

    link_list<Point> snake;

    snake.insert_head(Point(2,2));
    snake.insert_head(Point(2,3));
    snake.insert_head(Point(2,4));

    cout << "Initial Snake:\n";
    snake.printSnake();

    cout << "\nMove 1 (no food):\n";
    snake.move(Point(3,4), false);
    snake.printSnake();

    cout << "\nMove 2 (food eaten - grow):\n";
    snake.move(Point(4,4), true);
    snake.printSnake();

    cout << "\nMove 3 (no food):\n";
    snake.move(Point(4,3), false);
    snake.printSnake();

    cout << "\nMove 4 (collision case):\n";
    snake.move(Point(2,3), false); 
    snake.printSnake();

    return 0;
}
