// Queues are frequently used in computer programming, and a 
// typical example is the creation of a job queue by an operating 
// system. If the operating system does not use priorities, then 
// the jobs are processed in the order they enter the system. 
// Write C++ program for simulating job queue. Write 
// functions to add job, display job and delete job from queue.

#include <iostream>
#define MAX 100
using namespace std;

template <class T>
class Queue{
    T arr[MAX+1];
    int front;
    int rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void push(T element){
        if(rear == MAX){
            cout << ">> Queue is full." << endl;
        }
        else if(front == rear + 1){
            front = 0;
            rear = 0;
            arr[rear] = element;
        }
        else{
            front = 0;  
            rear++;
            arr[rear] = element;
        }
    }
    T pop(){
        T ele = arr[front];
        front++;
        return ele;
    }
    bool empty(){
        if(rear == -1 || front == rear + 1){
            return true;
        }
        return false;
    }
    void display(){
        if(front==rear+1 || rear==-1){
            cout << "[]" << endl;
            return;
        }
        cout << "[";
        for(int i=front;i<rear;i++){
            cout << arr[i] << ", ";
        }
        cout << arr[rear] << "]" << endl;
    }
};



int main(){
    Queue<string> obj;
    while(true){
        cout << "1. Enter job" << endl;
        cout << "2. Delete job" << endl;
        cout << "3. Display jobs" << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        if(choice == 1){
            string s;
            cout << "Enter job title: " << endl;
            cin >> s;
            obj.push(s);
        }
        else if(choice == 2){
            if(!obj.empty()){
                cout << obj.pop() << endl;
            }
            else{
                cout << ">> Job Queue is empty." << endl;
            }
        }
        else if(choice==3){
            obj.display();
        }
        else{
            cout << "GoodBye!" << endl;
            break;
        }
    }
}