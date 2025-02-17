#include <iostream>
using namespace std;

const int MAX = 100;
class Stack 
{
private:
    char arr[MAX];  
    int top;       
public:
    Stack() 
    {
        top = -1;
    }
    bool isEmpty() 
    {
        return top == -1;
    }
    bool isFull() 
    {
        return top == MAX - 1;
    }
    void push(char value) 
    {
        if (isFull()) 
        {
            cout << "Stack Overflow!" << endl;
        }
        else 
        {
            arr[++top] = value;
        }
    }
    char pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow!" << endl;
            return '\0';  
        }
        else 
        {
            return arr[top--];  
        }
    }
    char peak() 
    {
        if (isEmpty())
        {
            return '\0';  
        }
        else 
        {
            return arr[top];
        }
    }
};

bool isPalindrome(const string& str) 
{
    Stack stack;
    int length = str.length();
    for (int i = 0; i < length; ++i) 
    {
        stack.push(str[i]);
    }
    for (int i = 0; i < length; ++i) 
    {
        if (str[i] != stack.pop()) 
        {
            return false;  
        }
    }
    return true; 
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    if (isPalindrome(input)) 
    {
        cout << "The string is a palindrome." << endl;
    }
    else 
    {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}