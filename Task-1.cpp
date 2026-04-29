/*#include<iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    node* next;
    node(T value,node* new_node=nullptr){
        data=value;
        next=new_node;
    }
};

template<class T>
class link_list{
private:
    node<T>* head;
public:
    link_list():head(nullptr){}
    
    ~link_list(){ // destructor
        node<T>* temp = head;
        while(temp != nullptr){
            node<T>* next_node = temp->next;
            delete temp;
            temp = next_node;
        }
        head=nullptr;
    }
    
    bool isempty(){
        return head==nullptr;
    }
    
    // insert functions
    
    void insert_head(T v){
        head=new node<T>(v,head);
    }
    
    void insert_tail(T v){
        node<T>* new_node=new node<T>(v);
        
        if(isempty()){
            head=new_node;
            return;
        }
        
        node<T>* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=new_node;
        
    }
    void insert_postion(T v,int pos){
        
        if(isempty() || pos<=0){
            insert_head(v);
            return;
        }
        
        node<T>* temp=head;
        for(int i=1;i<pos && temp!=nullptr;i++){
            temp=temp->next;
        }
        
        if (temp==nullptr){
            return;
        }
        
        node<T>* new_node=new node<T>(v,temp->next);
        temp->next=new_node;
    }
    
    void display(){
        if(isempty()){
            cout<<"The list is Empty!"<<endl;
            return;
        }
        node<T>* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<" Null"<<endl;
    }
        
};

int main() {
    link_list<int> list;
    int choice;
    int value;
    int position;

    do {
        cout << "\n========== LINKED LIST MENU ==========\n";
        cout << "1. Insert a node at the beginning\n";
        cout << "2. Insert a node at the end\n";
        cout << "3. Insert a node at a given position\n";
        cout << "4. Display the linked list\n";
        cout << "5. Exit\n";
        cout << "======================================\n";
        cout << "Enter your choice (1-5): ";
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
                cout << "\nCurrent Linked List: \n";
                list.display();
                break;
                
            case 5:
                cout << "Exiting the program...\n";
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}*/
