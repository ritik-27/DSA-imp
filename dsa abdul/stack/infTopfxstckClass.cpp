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
    void Display();
    void Push(char x);
    char Pop();
    char Peek(int index);
    char StackTop();
    int isPBalance(char *exp);
    int isAllBalance(char *exp);
    //-----------------------
    int IsOperand(char x);
    int Precdence(char x);
    char *InToPost(char *infix);
    //-------------------
    int IsOperandBr(char x);
    char *InfToPostBr(char *infix);
    int OutstckPrecd(char x);
    int InstckPrecd(char x);
    //---------------------
    int PostToInf(char *postfix);
};

// void Stack::Create(int x)
// {
//     // cout << "Enter Size of Stack: ";
//     // cin >> st->size;
//     st->Top = -1;
//     st->S = new int[x];
// }

void Stack::Display()
{
    for (int i = Top; i >= 0; i--)
    {
        cout << S[i] << " ";
    }
    cout << endl;
}

void Stack::Push(char x)
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

char Stack::Pop()
{
    char x = -1; // NOTE
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

char Stack::Peek(int index)
{
    char x = -1;
    if (Top - index + 1 <= 0)
    {
        cout << "Invalid index" << endl;
    }
    x = S[Top - index + 1];
    return x;
}

char Stack::StackTop()
{
    if (Top != -1)
    {
        return S[Top];
    }
    else
        return -1;
}

// ONLY for ()
int Stack::isPBalance(char *exp)
{
    // Stack st(strlen(exp));
    // st.Top = -1;
    // st.S = new char[strlen(exp)];

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (Top == -1) // NOTE checkk thiss condition .....is s stack is empty or not if yes then there is an extra closing bracket
            {
                return 0;
            }
            else
            {
                Pop();
            }
        }
    }

    // Checking after complete pushing and poping is there something left in stack if YES Then NOT MAtched, if NO thhe MATCHED
    if (Top != -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// For all type of braces (),{},[]
int Stack::isAllBalance(char *exp)
{
    // Stack st(strlen(exp));
    // st.Top = -1;
    // st.S = new char[strlen(exp)];

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (Top == -1) // NOTE checkk thiss condition .....is s stack is empty or not if yes then there is an extra closing bracket
            {
                return 0;
            }
            else
            {
                if (Pop() == '(') // NOTE THISSSS
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
        else if (exp[i] == '}')
        {
            if (Top == -1) // NOTE checkk thiss condition .....is s stack is empty or not if yes then there is an extra closing bracket
            {
                return 0;
            }
            else
            {
                if (Pop() == '{')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
        else if (exp[i] == ']')
        {
            if (Top == -1) // NOTE checkk thiss condition .....is s stack is empty or not if yes then there is an extra closing bracket
            {
                return 0;
            }
            else
            {
                if (Pop() == '[')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
    }

    // Checking after complete pushing and poping is there something left in stack if YES Then NOT MAtched, if NO thhe MATCHED
    if (Top != -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
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
int Stack::Precdence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *Stack::InToPost(char *infix)
{
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        // checking wether it is operand or operator
        if (IsOperand(infix[i]))
        {
            postfix[j] = infix[i];
            j++, i++;
        }
        else
        {
            // after confirming operator, checki g its precdence
            if (Precdence(infix[i]) > Precdence(StackTop()))
            {
                Push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop();
                j++;
            }
        }
    }
    while (Top != '\0')
    {
        postfix[j] = Pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

// For Checking precedece of braces we'll include new precd. functions and new vals
int Stack::IsOperandBr(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Stack::OutstckPrecd(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }
    else
    {
        return 0;
    }
}
int Stack::InstckPrecd(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5; // Note this ..out precd - 1 coz ^ has R to left Associativity
    }
    else if (x == '(')
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

char *Stack::InfToPostBr(char *infix) // LOCHAA hai ULFATTT
{
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        // checking wether it is operand or operator
        if (IsOperandBr(infix[i]))
        {
            postfix[j] = infix[i];
            j++, i++;
        }
        else
        {
            // after confirming operator, check its ""OUT""precdence with instck NOTEE**
            if (OutstckPrecd(infix[i]) > InstckPrecd(StackTop()))
            {
                if (infix[i] == ')')
                {
                    i++;
                }
                else
                {
                    Push(infix[i]);
                    i++;
                }
            }
            else
            {
                if (infix[i] == '(')
                {
                    i++;
                }
                else
                {
                    postfix[j] = Pop();
                    j++;
                }
            }
        }
    }
    while (Top != '\0')
    {
        postfix[j] = Pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

// INFIXX TO POSTFIX ENDS hereee
// Will not throw accurate val

// int Stack::PostToInf(char *postfix) // Note for this u'll hav to convert stack, push,pop totally from char to intS
// {
//     // char *infix = new char[strlen(postfix) + 1];
//     int i, j, x1, x2, res;
//     for (i = 0; postfix[i] != '\0'; i++)
//     {
//         if (!IsOperand(postfix[i]))
//         {
//             x2 = Pop() - '0';
//             x1 = Pop() - '0';
//             switch (postfix[i])
//             {
//             case '+':
//                 res = x1 + x2;
//                 Push(res);
//                 break;
//             case '-':
//                 res = x1 - x2;
//                 Push(res);
//                 break;
//             case '*':
//                 res = x1 * x2;
//                 Push(res);
//                 break;
//             case '/':
//                 res = x1 / x2;
//                 Push(res);
//                 break;
//             default:
//                 break;
//             }
//         }
//         else
//         {
//             Push(postfix[i]);
//         }
//     }
//     return (Pop());
// }

int main()
{
    char *exp = "((a-b)*7+(c-d))";
    Stack st(strlen(exp));
    // Stack st(strlen(exp));

    // if (st.isPBalance(exp))
    // {
    //     cout << "Given exp has MATCHING Parenthesis" << endl;
    // }
    // else
    // {
    //     cout << "Given exp has NOT matching Parenthesis" << endl;
    // }

    // if (st.isAllBalance(exp))
    // {
    //     cout << "Given exp has MATCHING Brackets" << endl;
    // }
    // else
    // {
    //     cout << "Given exp has NOT matching brackets" << endl;
    // }

    // INFIX TO POSTFIX w/o brackets or ()
    // char *infix = "a+b*c-d/e";
    char *infix = "a+b*c-d";
    Stack stk(strlen(infix) + 2);
    stk.Push('#');                          // Note initiall stack is empty so there's nothing meaning to precedence(top);
    char *postfix = stk.InfToPostBr(infix); // Locha hai ulfatt
    cout << "Postfix: " << postfix << endl;

    // INFIX TO POSTFIX w/ brackets or ()
    // char *infix = "((a+b)*c)-d^e^f";
    // Stack stk(strlen(infix) + 2);
    // stk.Push('#');                          // Note initiall stack is empty so there's nothing meaning to precedence(top);
    // char *postfix = stk.InfToPostBr(infix); // Locha hai ulfatt
    // cout << "Postfix: " << postfix << endl;

    // char *postfix = "35*62/+4-\0";
    // Stack stk(strlen(postfix) + 2);
    // cout << "Evaulation of postfix exp is : " << stk.PostToInf(postfix) << endl;

    return 0;
}