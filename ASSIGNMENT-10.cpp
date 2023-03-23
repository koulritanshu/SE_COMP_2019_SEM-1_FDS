// Implement C++ program for expression conversion as infix to 
// postfix and its evaluation using stack based on given 
// conditions: 1. Operands and operator, both must be single
// character. 2. Input Postfix expression must be in a desired 
// format. 3. Only '+', '-', '*' and '/ ' operators are expected.

#include <iostream>
using namespace std;

class Stack{
    int top;
    char arr[100];
public:
    Stack(){
        top = -1;
    }
    void push(char x){
        if(top == 99){
            cout << ">> Stack is full." << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    char pop(){
        char x = arr[top];
        top--;
        return x;
    }
    bool empty(){
        return (top == -1);
    }
    char TOP(){
        return arr[top];
    }
};

class Expression{
    string s;
public:
    Expression(string s){
        this->s = s;
    }
    int priority(char x){
        if(x=='+'||x=='-') return 1;
        else return 2;
    }
    string convert(){
        Stack obj;
        string infix = s;
        string postfix = "";
        for(int i=0;i<infix.size();i++){
            cout << postfix << endl;
            if(infix[i] == '('){
                obj.push(infix[i]);
            }
            else if(infix[i] == ')'){
                while(obj.TOP() != '('){
                    cout << "here\n";
                    postfix += obj.TOP();
                    obj.pop();
                }
                obj.pop();
            }
            else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
                if(obj.empty()){
                    obj.push(infix[i]);
                }
                else if(obj.TOP() == '('){
                    obj.push(infix[i]);
                }
                else{
                    if(priority(infix[i])>priority(obj.TOP())){
                        obj.push(infix[i]);
                    }   
                    else{
                        while(!obj.empty() && priority(infix[i]) <= priority(obj.TOP())){
                            postfix += obj.TOP();
                            obj.pop();
                        }
                        obj.push(infix[i]);
                    }
                }
            }
            else{
                postfix += infix[i];
            }
        }
        while(!obj.empty()){
            postfix += obj.TOP();
            obj.pop(); 
        }
        cout << "Postfix expression is" << endl;
        cout << postfix << endl;
        return postfix;
    }
    void evaluate(string postfix){
        Stack obj;
        for(int i=0;i<postfix.size();i++){
            if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*'){
                int second = (obj.TOP()-'0');
                obj.pop();
                int first = (obj.TOP()-'0');
                obj.pop();
                if(postfix[i] == '-'){
                    int result = first - second;
                    obj.push(result+'0');
                }
                else if(postfix[i] == '+'){
                    int result = first + second;
                    obj.push(result+'0');
                }
                else if(postfix[i] == '/'){
                    int result = first / second;
                    obj.push(result+'0');
                }
                else if(postfix[i] == '*'){
                    int result = first * second;
                    obj.push(result+'0');
                }
            }
            else{
                obj.push(postfix[i]);
            }
        }
        cout << ">> " << obj.TOP() - '0' << endl;
    }
};


int main(){
    string s;
    while(true){
        cout << "1. Enter expression." << endl;
        cout << "2. Convert to postfix." << endl;
        cout << "3. Evaluate" << endl;
        cout << "0. Exit" << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        if(choice == 1){
            cin >> s;
        }
        else if(choice == 2){
            Expression obj(s);
            string postfix = obj.convert();
        }
        else if(choice == 0){
            cout << "GoodBye!" << endl;
            break;
        }
        else if(choice == 1000){
            cout << s << endl;
        }
        else if(choice == 3){
            Expression obj(s);
            string postfix = obj.convert();
            obj.evaluate(postfix);
        }
        else{
            cout << "Invalid input." << endl;
        }
    }
}