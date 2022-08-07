#include <iostream>
#include <cstring>

using namespace std;

class Stack
{
private:
    int Top;
    char *S; // 1   NOtee dont forget to change the typ of stackkk

public:
    int size;
    Stack(int sz)
    {
        this->Top = -1;
        this->size = sz;
        S = new char[this->size];
    }

    // void Create(int x);
    void Push(int x);
    int Pop();
    int StackTop();
    //-----------------------
    int IsOperand(char x);
    int Precdence(int x);
    //-------------------
    int PostToInf(char *postfix);
};

void Stack::Push(int x)
{
    if (Top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        Top++;
        S[Top] = x;
    }
}

int Stack::Pop()
{
    int x = -1;
    if (Top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = S[Top];
        Top--;
    }
    return x;
}

int Stack::IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Stack::PostToInf(char *postfix)
{
    // char *infix = new char[strlen(postfix) + 1];
    int i, j, x1, x2, res;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (IsOperand(postfix[i]))
        {
            Push(postfix[i] - '0'); // NOTE THISSS********
        }
        else
        {
            x2 = Pop();
            x1 = Pop();
            switch (postfix[i])
            {
            case '+':
                res = x1 + x2;
                Push(res);
                break;
            case '-':
                res = x1 - x2;
                Push(res);
                break;
            case '*':
                res = x1 * x2;
                Push(res);
                break;
            case '/':
                res = x1 / x2;
                Push(res);
                break;

            default:
                break;
            }
        }
    }
    return Pop();
}

int main()
{
    char *postfix = "35*62/+4-\0";
    Stack stk(strlen(postfix) + 2);

    cout << "Evaulation of postfix exp is : " << stk.PostToInf(postfix) << endl;

    return 0;
}
