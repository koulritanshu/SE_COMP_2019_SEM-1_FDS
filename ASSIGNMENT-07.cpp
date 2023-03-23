// 7 A) The ticket booking system of Cinemax theatre has to be
// implemented using C++ program. There are 10 rows and 7 seats in
// each row. Doubly circular linked list has to be maintained to keep
// track of free seats at rows. Assume some random booking to start with.
// Use array to store pointers (Head pointer) to each row. On demand a)
// The list of available seats is to be displayed b) The seats are to be
// booked c) The booking can be cancelled.
// OR
// 7 B) Write C++ program for storing binary number using doubly
// linked lists. Write functions- a) To compute 1„s and 2„s complement b)
// Add two binary numbers

#include <iostream>
using namespace std;

class Node
{
    int val;
    Node *next;
    Node *previous;

public:
    Node(int x)
    {
        val = x;
        next = NULL;
        previous = NULL;
    }
    int getValue()
    {
        return val;
    }
    Node *getNext()
    {
        return previous;
    }
    friend class dll;
};

class dll
{
    Node *head;

public:
    dll()
    {
        head = NULL;
    }
    Node *getEnd()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    dll push_front(int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
    }
    void display()
    {
        cout << "--------------------------" << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "--------------------------" << endl;
    }
};

class binary
{
    int binaryNumber;

public:
    binary(int x)
    {
        binaryNumber = x;
    }
    void convert_to_binary()
    {
        dll obj;
        int x = binaryNumber;
        while (x)
        {
            obj.push_front(x % 2);
            x = x / 2;
        }
        obj.display();
    }
    dll bin()
    {
        dll obj;
        int x = binaryNumber;
        while (x)
        {
            obj.push_front(x % 2);
            x = x / 2;
        }
        return obj;
    }
    dll onesCompliment(int number)
    {
        dll onesCompliment2;
        int x = number;
        while (x)
        {
            int val = x % 2;
            if (val == 0)
            {
                val = 1;
            }
            else
            {
                val = 0;
            }
            x = x / 2;
            onesCompliment2.push_front(val);
        }
        return onesCompliment2;
    }
    void twosCompliment(int number)
    {
        dll answer = onesCompliment(number);
        dll n;
        n.push_front(1);
        answer = addBinary(answer.getEnd(), n.getEnd());
        answer.display();
    }
    dll addBinary(Node *start1, Node *start2)
    {
        dll sumLinkedList;
        int carry = 0;
        while (start1 != NULL && start2 != NULL)
        {
            int sum = start1->getValue() + start2->getValue() + carry;
            if (sum == 0)
            {
                carry = 0;
                sumLinkedList.push_front(0);
            }
            else if (sum == 1)
            {
                carry = 0;
                sumLinkedList.push_front(1);
            }
            else if (sum == 2)
            {
                carry = 1;
                sumLinkedList.push_front(0);
            }
            else if (sum == 3)
            {
                carry = 1;
                sumLinkedList.push_front(1);
            }
            start1 = start1->getNext();
            start2 = start2->getNext();
        }
        while (start1 != NULL)
        {
            int sum = start1->getValue() + carry;
            if (sum == 0)
            {
                sumLinkedList.push_front(0);
                carry = 0;
            }
            if (sum == 1)
            {
                sumLinkedList.push_front(1);
                carry = 0;
            }
            if (sum == 2)
            {
                sumLinkedList.push_front(0);
                carry = 1;
            }
            start1 = start1->getNext();
        }
        while (start2 != NULL)
        {
            int sum = start2->getValue() + carry;
            if (sum == 0)
            {
                sumLinkedList.push_front(0);
                carry = 0;
            }
            if (sum == 1)
            {
                sumLinkedList.push_front(1);
                carry = 0;
            }
            if (sum == 2)
            {
                sumLinkedList.push_front(0);
                carry = 1;
            }
            start2 = start2->getNext();
        }
        if (carry)
        {
            sumLinkedList.push_front(1);
            carry = 0;
        }
        return sumLinkedList;
    }
};

int main()
{
    int number;
    bool given = false;
    while (true)
    {
        cout << "1. Enter decimal number." << endl;
        cout << "2. Convert to binary" << endl;
        cout << "3. 1's compliment" << endl;
        cout << "4. 2's compliment" << endl;
        cout << "5. Add two binary numbers." << endl;
        cout << "0. Exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter number: ";
            cin >> number;
            given = true;
        }
        else if (choice == 2)
        {
            if (!given)
            {
                cout << "Enter number first" << endl;
            }
            else
            {
                binary obj(number);
                obj.convert_to_binary();
            }
        }
        else if (choice == 3)
        {
            if (!given)
            {
                cout << "Enter number first" << endl;
            }
            else
            {
                binary obj(number);
                obj.convert_to_binary();
                dll answer = obj.onesCompliment(number);
                answer.display();
            }
        }
        else if (choice == 4)
        {
            if (!given)
            {
                cout << "Enter number first" << endl;
            }
            else
            {
                binary obj(number);
                obj.convert_to_binary();
                obj.twosCompliment(number);
            }
        }
        else if (choice == 5)
        {
            cout << "Enter the first number: ";
            int n1;
            cin >> n1;
            cout << "Enter the second number: ";
            int n2;
            cin >> n2;
            cout << "------------------------" << endl;
            binary obj1(n1);
            obj1.convert_to_binary();
            cout << "------------------------" << endl;
            binary obj2(n2);
            obj2.convert_to_binary();
            cout << "------------------------" << endl;
            dll firstbin = obj1.bin();
            dll secondbin = obj2.bin();
            dll answer = obj1.addBinary(firstbin.getEnd(), secondbin.getEnd());
            answer.display();
        }
        else if (choice == 0)
        {
            break;
        }
    }
    return 0;
}