#include <bits/stdc++.h>
using namespace std;

struct Expression
{
    int coff;
    int power;
    Expression *next;
} *first = nullptr;

void Display(Expression *p, int variable)
{
    int sum = 0;
    while (p)
    {
        cout << "Cofficient and degree of variable " << variable << " is " << p->coff << " and " << p->power << '\n';
        sum += (p->coff * pow(variable, p->power));
        p = p->next;
    }
    cout << "Sum of expression after putting " << variable << " in place of x : " << sum << '\n';
}

int main()
{
    int number_of_expressions = 5;
    int cofficient[]{4, 9, 6, 7, 9};
    int power[]{3, 2, 1, 0, 1};
    int variable = 4;
    for (int i = 0; i < number_of_expressions; i++)
    {
        Expression *newNode = new Expression;
        newNode->coff = cofficient[i];
        newNode->power = power[i];
        newNode->next = nullptr;
        if (first == nullptr)
            first = newNode;
        else
        {
            Expression *q = first;
            while (q->next)
                q = q->next;
            q->next = newNode;
        }
    }
    Display(first, variable);
}