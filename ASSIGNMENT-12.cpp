// Write program to implement a priority queue in C++ using 
// an order list/array to store the items in the queue. Create a 
// class that includes the data items (which should be template) 
// and the priority (which should be int). The order list/array 
// should contain these objects, with operator <= overloaded so 
// that the items with highest priority appear at the beginning of 
// the list/array (which will make it relatively easy to retrieve the
// highest item.)

#include <iostream>
using namespace std;

template<class T>
class Item{
public:
    T item;
    int priority;
};

template<class T>
class PriorityQueue{
    Item<T> *arr;
    int front;
    int rear;
public:
    PriorityQueue(){
        front = -1;
        rear = -1;
        arr = new Item<T>[100];
    }
    void enqueue(){
        if(rear == 99){
            cout << "Queue is full." << endl;
            return;
        }
        else{
            Item<T> temp;
            cout << "Enter the item: ";
            cin >> temp.item;
            cout << "Enter the priority: ";
            cin >> temp.priority;
            if(rear==-1){
                front = 0;
                rear++;
                arr[rear] = temp;
            }
            else{
                int index = -1;
                for(int i=front;i<=rear;i++){
                    if(arr[i].priority > temp.priority){
                        index = i;
                        break;
                    }
                }
                if(index == -1){
                    rear++;
                    arr[rear] = temp;
                }
                else{
                    rear++;
                    for(int i=rear;i>index;i--){
                        arr[i] = arr[i-1];
                    }
                    arr[index] = temp;
                }
            }
        }
    }
    void dequeue(){
        if(rear == -1 || front == rear + 1){
            cout << "Queue is empty." << endl;
            return;
        }
        cout << arr[rear].item << " " << arr[rear].priority << endl;
        cout << "---------------------" << endl;
        rear--;
    }
    void display(){
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        for(int i=front;i<=rear;i++){
            cout << arr[i].item << " " << arr[i].priority << endl;
        }
    }
    PriorityQueue<T> operator <=(PriorityQueue<T> obj3){
        PriorityQueue <T> obj2;
        int x = obj3.rear;
        obj2.front = obj3.front;
        obj2.rear = obj3.rear;
        for(int i=obj3.front;i<=obj3.rear;i++){
            obj2.arr[x] = obj3.arr[i];
            x--;
        }
        return obj2;
    }
}; 

int main()
{
    PriorityQueue<string> obj;
    while(true){
        cout << "1. Add element." << endl;
        cout << "2. Delete element." << endl;
        cout << "3. Display elements." << endl;
        cout << "4. Display elements in decreasing order of priority." << endl;
        cout << "0. EXIT" << endl;
        int choice;
        cin >> choice;
        if(choice == 1){
            obj.enqueue();
            obj.display();
        }
        else if(choice == 2){
            obj.dequeue();
            obj.display();
        }
        else if(choice == 3){
            obj.display();
        }
        else if(choice == 4){
            PriorityQueue<string> temp = (temp<=obj);
            temp.display();
        }
        else if(choice == 0){
            break;
        }
    }
}