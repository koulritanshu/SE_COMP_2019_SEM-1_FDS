// A double-ended queue (deque) is a linear list in which 
// additions and deletions may be
// made at either end. Obtain a data representation mapping a 
// deque into a one
// dimensional array. Write C++ program to simulate deque 
// with functions to add and
// delete elements from either end of the deque.

#include <iostream>
#define MAX 100
using namespace std;

template <class T>
class Queue{
    T arr[MAX];
    int front;
    int rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void push_back(T val){
        if(rear == MAX-1){
            cout << ">> Queue full." << endl;
            return;
        }
        if(front == -1) front = 0;
        rear++;
        arr[rear] = val;
    }

    T pop_front(){
        char x = arr[front];
        rear--;
        for(int i=front;i<=rear;i++){
            arr[i] = arr[i+1];
        }
        return x;
    }

    T pop_back(){
        char x = arr[rear];
        rear--;
        return x;
    }
    
    void push_front(T val){
        if(rear==MAX-1){
            cout << ">> Queue is full." << endl;
        }
        else if(front == -1){
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            for(int i=rear;i>front;i--){
                arr[i] = arr[i-1];
            }
            arr[front] = val;
        }
    }
    void display(){
        if(rear == -1){
            cout << ">> Deque is empty." << endl;
            return;
        }
        cout << "[";
        for(int i=front;i<rear;i++){
            cout << arr[i] << ", ";
        }
        cout << arr[rear] << "]" << endl;
    }
    bool empty(){
        if((front == rear+1) || (rear==-1) || (front == -1)) return true;
        return false;
    }
};

int main(){
    Queue<int> dq;
    while(true){
        cout << "1. Add front" << endl;
        cout << "2. Add rear" << endl;
        cout << "3. Delete front" << endl;
        cout << "4. Delete rear" << endl;
        cout << "0. Quit" << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            int x;
            cout << "Enter value to insert: "; 
            cin >> x;
            dq.push_front(x);
            dq.display();
        }
        else if(choice == 2){
            int x;
            cout << "Enter value to insert: "; 
            cin >> x;
            dq.push_back(x);
            dq.display();
        }
                
        else if(choice == 3){
            if(dq.empty()){
                cout << ">> Queue is empty." << endl;
            }
            else{
                cout << dq.pop_front() << endl;
                dq.display();
            }
        }
        else if(choice == 4){
            if(dq.empty()){
                cout << ">> Queue is empty." << endl;
            }
            else{
                cout << dq.pop_back() << endl;
                dq.display();
            }
        }

    }
}

