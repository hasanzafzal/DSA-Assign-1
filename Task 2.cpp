#include <iostream>
#include <fstream>
#include <string>
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
            return -1; 
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
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else 
        {
            return arr[top];
        }
    }
};


bool isPalindrome(string& word) 
{
    Stack s;
    for (char ch : word)
    {
        s.push(ch);
    }
    for (char ch : word) 
    {
        if (ch != s.pop()) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    string filePath;
    cout << "Enter the file path containing words: ";
    cin >> filePath;
    ifstream inputFile(filePath);
    if (!inputFile) 
    {
        cout << "Unable to open file!" << endl;
        return 1;
    }
    string word;
    int palindromeCount = 0;
    while (getline(inputFile, word)) 
    {
        if (isPalindrome(word)) 
        {
            palindromeCount++;
        }
    }
    cout << "Total number of palindromes: " << palindromeCount << endl;
    inputFile.close();
    return 0;
}