// 7 A) The ticket booking system of Cinemax theatre has to be
// implemented using C++ program. There are 10 rows and 7 seats in
// each row. Doubly circular linked list has to be maintained to keep
// track of free seats at rows. Assume some random booking to start with.
// Use array to store pointers (Head pointer) to each row. On demand a)
// The list of available seats is to be displayed b) The seats are to be
// booked c) The booking can be cancelled.

#include <iostream>
using namespace std;

class Node{
    int seatno;
    Node*next;
    Node*previous;
    bool status;
public:
    Node(){
        seatno = 0;
        next = NULL;
        previous = NULL;
        status = false;
    }
    Node(int seatno, bool s){
        this->seatno = seatno;
        status = s;
        next = NULL;
        previous = NULL;
    }
    friend class Cinemax;
};

class Cinemax{
    Node* head[10];
public:
    Cinemax(){
        for(int i=0;i<10;i++){
            head[i] = NULL;
        }
    }
    void createTheater(){
        for(int i=0;i<10;i++){
            for(int j=0;j<7;j++){
                Node* newNode = new Node(j+1,false);
                if(head[i] == NULL){
                    newNode->next = newNode;
                    newNode->previous = newNode;
                    head[i] = newNode;
                }
                else{
                    Node* temp = head[i]->previous;
                    newNode->previous = temp;
                    newNode->next = head[i];
                    temp->next = newNode;
                    head[i]->previous = newNode;
                }
            }
        }
    }
    void displaySeats(){
        for(int i=0;i<10;i++){
            cout << "DISPLAYING DATA FOR ROW - " << i + 1 << endl << endl;
            cout << "SEAT NO\tSTATUS" << endl;
            Node*temp = head[i];
            for(int j=0;j<7;j++){
                if(temp->status == false){
                    cout << temp->seatno << "\t" << "AVAILABLE" << endl;
                    temp = temp->next;
                }
                else{
                    cout << temp->seatno << "\t" << "UNAVAILABLE" << endl;
                    temp = temp->next;
                }
            }
        }
    }
    void bookseats(){
        int row;
        int column;
        cout << "Enter the row: ";
        cin >> row;
        cout << "Enter the column: ";
        cin >> column;
        int i;
        Node*temp = head[row-1];
        for(i=0;i<column-1;i++){
            temp = temp->next;
        }
        if(temp->status == false){
            temp->status = true;
            cout << "Seat booked successfully." << endl;
        }
        else{
            cout << "Seat is already booked." << endl;
            return;
        }
    }
    void cancelbooking(){
        int r,c;
        cout << "Enter the row: ";
        cin >> r;
        cout << "Enter the column: ";
        cin >> c;
        int i;
        Node*temp = head[r-1];
        for(i=0;i<c-1;i++){
            temp = temp->next;
        }
        if(temp->status == false){
            cout << "Cannot cancel not booked seat" << endl;
        }
        else{
            temp->status = false;
            cout << "Seat cancelled." << endl;
        }
    }
};

int main()
{
    Cinemax obj;
    obj.createTheater();
    while(true){
        cout << "1. Display seats" << endl;
        cout << "2. Book tickets." << endl;
        cout << "3. Cancel booking." << endl;
        cout << "0. Exit" << endl;
        int choice;
        cin >> choice;
        if(choice == 1){
            obj.displaySeats();
        }
        else if(choice == 2){
            obj.bookseats();
        }
        else if(choice == 3){
            obj.cancelbooking();
        }
        else if(choice == 0){
            break;
        }
    }
}
