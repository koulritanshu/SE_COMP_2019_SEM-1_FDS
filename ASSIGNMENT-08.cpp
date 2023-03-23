// Write C++ program for storing appointment schedule for day. Appointments 
// are booked randomly using linked list. Set start and end time and min and 
// max duration for visit slot. Write functions for- a) Display free slots b) Book 
// appointment c) Cancel appointment (check validity, time bounds, 
// availability) d) Sort list based on time e) Sort list based on time using 
// pointer manipulation
// OR
// Second year Computer Engineering class, set A of students like Vanilla Icecream and set B of students like butterscotch ice-cream. Write C++ program 
// to store two sets using linked list. compute and display- a) Set of students 
// who like both vanilla and butterscotch b) Set of students who like either 
// vanilla or butterscotch or not both c) Number of students who like neither 
// vanilla nor butterscotch

#include <iostream>
using namespace std;

class Node{
    int val;
    Node*next;
public:
    Node(){
        val = 0;
        next = NULL;
    }
    Node(int x){
        val = x;
        next = NULL;
    }
    friend class LL;
};

class LL{
    Node*start;
public:
    LL(){
        start = NULL;
    }
    void push_front(int val){
        Node*temp = new Node(val);
        if(start == NULL){
            start = temp;
        }
        else{
            temp->next = start;
            start = temp;
        }
    }
    void push_back(int val){
        Node*temp = new Node(val);
        if(start == NULL){
            start = temp;
        }
        else{
            Node*head = start;
            while(head->next != NULL){
                head = head->next;
            }
            head->next = temp;
        }
    }
    void display();
    LL Union(Node*obj1, Node*obj2);
    LL Intersection(Node*obj1, Node*obj2);
    LL Difference(Node*obj1, Node*obj2);
    Node* getStart();
};

Node* LL::getStart(){
    return start;
}

void LL::display(){
    Node*temp = start;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

LL LL::Intersection(Node*obj1, Node*obj2){
    LL temp;
    Node*temp1 = obj1;
    Node*temp2 = obj2;
    while(temp1!=NULL){
        temp2 = obj2;
        while(temp2!=NULL){
            if(temp1->val == temp2->val){
                temp.push_front(temp2->val);
            }
            temp2 = temp2->next;
        }
        temp1=temp1->next;
    }
    return temp;
}

LL LL::Difference(Node*obj1,Node*obj2){
    LL ans;
    Node* temp = obj1;
    while(temp!=NULL){
        bool flag = false;
        Node*temp1 = obj2;
        while(temp1!=NULL){
            if(temp->val == temp1->val){
                flag = true;
                break;
            }
            temp1=temp1->next;
        }
        if(!flag){
            ans.push_back(temp->val);
        }
        temp=temp->next;
    }   
    return ans;
}

LL LL::Union(Node*obj1,Node*obj2){
    LL temp;
    Node*temp1 = obj1;
    while(temp1!=NULL){
        temp.push_back(temp1->val);
        temp1=temp1->next;
    }
    temp1 = obj2;
    while(temp1!=NULL){
        bool present = false;
        Node*head = temp.getStart();
        while(head!=NULL){
            if(head->val == temp1->val){
                present = true;
                break;
            }
            head = head->next;
        }
        if(!present){
            temp.push_back(temp1->val);
        }
        temp1=temp1->next;
    }
    return temp;
}


int main(){
    LL obj1,obj2,total;
    while(true){
        cout << "1. Give input." << endl;
        cout << "2. Students who like both vanialla and butterscotch." << endl;
        cout << "3. Students who like either vanialla or butterscotch." << endl;
        cout << "4. Students who like neither vanialla and butterscotch." << endl;
        cout << "5. Union" << endl;
        cout << "6. Intersection" << endl;
        cout << "0. EXIT." << endl;
        cout << ">> ";
        int choice;
        cin >> choice;
        if(choice == 1){
            cout << "Enter the total number of students: ";
            int n;
            cin >> n;
            for(int i=0;i<n;i++){
                cout << "Enter roll number: ";
                int roll;
                cin >> roll;
                total.push_back(roll);
            }
            cout << "Number of students who like vanilla: ";
            int vanilla;
            cin >> vanilla;
            for(int i=0;i<vanilla;i++){
                cout << "Enter roll number: ";
                int rollNumber;
                cin >> rollNumber;
                obj1.push_front(rollNumber);
            }
            cout << "Number of students who like butterscotch: ";
            int butterscotch;
            cin >> butterscotch;
            for(int i=0;i<butterscotch;i++){
                cout << "Enter roll number: ";
                int rollNumber;
                cin >> rollNumber;
                obj2.push_front(rollNumber);
            }
        }
        else if(choice == 2){
            cout << "---------" << endl;
            obj1.display();
            obj2.display();
            cout << "---------" << endl;
            LL answer = obj1.Intersection(obj1.getStart(),obj2.getStart());
            answer.display();
        }
        else if(choice == 3){
            cout << "---------" << endl;
            obj1.display();
            obj2.display();
            cout << "---------" << endl;
            LL answer1 = obj1.Intersection(obj1.getStart(),obj2.getStart());
            LL answer2 = obj1.Union(obj1.getStart(),obj2.getStart());
            LL answer = obj1.Difference(answer2.getStart(),answer1.getStart());
            answer.display();
        }
        else if(choice == 4){
            cout << "---------" << endl;
            obj1.display();
            obj2.display();
            cout << "---------" << endl;
            LL answer1 = obj1.Union(obj1.getStart(),obj2.getStart());
            LL answer = answer1.Difference(total.getStart(),answer1.getStart());
            answer.display();
        }
        else if(choice == 1000){
            obj1.display();
            obj2.display();
        }
        else if(choice == 5){
            cout << "---------" << endl;
            obj1.display();
            obj2.display();
            cout << "---------" << endl;
            LL answer = obj1.Union(obj1.getStart(),obj2.getStart());
            answer.display();
        }
        else if(choice == 6){
            cout << "---------" << endl;
            obj1.display();
            obj2.display();
            cout << "---------" << endl;
            LL answer = obj1.Intersection(obj1.getStart(),obj2.getStart());
            answer.display();
        }
        else if(choice == 0){
            break;
        }
    }
}