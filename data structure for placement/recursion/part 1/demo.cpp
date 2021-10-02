#include<stdio.h>
#include <stdlib.h>
#include <math.h>
    typedef struct Node
{
    float coeff;
    int power;
    struct Node *next;
} Node;
Node *insert(Node *head, float coe, int pow)
{
    Node *p, *q;
    p = (Node *)malloc(sizeof(Node));
    p->coeff = coe;
    p->power = pow;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        head->next = head;
        return (head);
    }
    if (pow < head->power)
    {
        p->next = head->next;
        head->next = p;
        head = p;
        return (head);
    }
    if (pow == head->power)
    {
        head->coeff = coe + head->coeff;
        return (head);
    }
    q = head;
    while (q->next != head && pow <= q->next->power)
    {
        q = q->next;
    }
    if (p->power == q->power)
    {
        q->power = q->coeff + coe;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
    return (head);
}
void Display(Node *head)
{
    Node *p;
    p = head->next;
    printf("\n");
    do
    {
        printf("%6.2fx^%d ", p->coeff, p->power);
        p = p->next;
    } while (p != head->next);
}
Node *create(struct Node *head)
{
    int n, pow;
    float coe;
    printf("\nENTER HOW MANY TERMS YOU WANT TO ADD\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\n\tENTER EACH TERMS ONE BY ONE (COEFFICIENT, POWER) : \n");
        scanf("%f%d", &coe, &pow);
        head = insert(head, coe, pow);
    }
    return (head);
}
Node *Add(Node *p1, Node *p2)
{
    Node *p;
    Node *head = NULL;
    float coefficient;
    int Power;
    p = p1->next;
    do
    {
        head = insert(head, p->coeff, p->power);
        p = p->next;
    } while (p != p1->next);
    p = p2->next;
    do
    {
        head = insert(head, p->coeff, p->power);
        p = p->next;
    } while (p != p2->next);
    return (head);
}
Node *Multiply(Node *p1, Node *p2)
{
    Node *a, *b;
    Node *head = NULL;
    b = p2->next;
    do
    {
        a = p1->next;
        do
        {
            head = insert(head, a->coeff * b->coeff, a->power + b->power);
            a = a->next;
        } while (a != p1->next);
        b = b->next;
    } while (b != p2->next);
    return (head);
}
float Evaluate(Node *head, float x)
{
    float value = 0.00;
    Node *p;
    p = head->next;
    do
    {
        value = value + p->coeff * pow(x, p->power);
        p = p->next;
    } while (p != head->next);
    return (value);
}
int main()
{
    struct Node *P1, *P2, *P3;
    int op;
    float x, value;
    int choice;
    P1 = P2 = P3 = NULL;
    do
    {
        printf("\n\t1.ENTER THE POLYNOMIAL\n");
        printf("\n\t2.DISPLAY POLYNOMIALS\n");
        printf("\n\t3.ADD POLYNOMIALS\n");
        printf("\n\t4.MULTIPLY POLYNOMIALS\n");
        printf("\n\t5.EVALUATE FIRST POLYNOMIAL\n");
        printf("\n\tENTER CHOICE: \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n\tENTER FIRST POLYNOMIAL\n");
            P1 = create(P1);
            printf("\n\tENTER SECOND POLYNOMIAL\n");
            P2 = create(P2);
            break;
        case 2:
            printf("\n\tFIRST POLYNOMIAL :");
            Display(P1);
            printf("\n\tSECOND POLYNOMIAL :");
            Display(P2);
            break;
        case 3:
            printf("\n\tADDITION : \n");
            P3 = Add(P1, P2);
            Display(P3);
            break;
        case 4:
            printf("\n\tMULTIPLICATION\n :");
            P3 = Multiply(P1, P2);
            Display(P3);
            break;
        case 5:
            printf("\n\tEVALUATE\n");
            printf("\n\tENTER THE VALUE OF X\n");
            scanf("%f", &x);
            value = Evaluate(P1, x);
            printf("\n\tEVALUATED VALUE = %6.2f", value);
            break;
        default:
            printf("\n\tWRONG CHOICE\n");
        }
        printf("\n\tDO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :");
        scanf("%d", &choice);
    } while (choice == 1);
    return 0;
}
 1.ENTER THE POLYNOMIAL

        2.DISPLAY POLYNOMIALS

        3.ADD POLYNOMIALS

        4.MULTIPLY POLYNOMIALS

        5.EVALUATE FIRST POLYNOMIAL

        ENTER CHOICE:
1

        ENTER FIRST POLYNOMIAL

ENTER HOW MANY TERMS YOU WANT TO ADD
2

        ENTER EACH TERMS ONE BY ONE (COEFFICIENT, POWER) :
4
2

        ENTER EACH TERMS ONE BY ONE (COEFFICIENT, POWER) :
1
1

        ENTER SECOND POLYNOMIAL

ENTER HOW MANY TERMS YOU WANT TO ADD
2

        ENTER EACH TERMS ONE BY ONE (COEFFICIENT, POWER) :
3
3

        ENTER EACH TERMS ONE BY ONE (COEFFICIENT, POWER) :
9
1

        DO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :1

        1.ENTER THE POLYNOMIAL

        2.DISPLAY POLYNOMIALS

        3.ADD POLYNOMIALS

        4.MULTIPLY POLYNOMIALS

        5.EVALUATE FIRST POLYNOMIAL

        ENTER CHOICE:
2

        FIRST POLYNOMIAL :
  4.00x^2   1.00x^1
        SECOND POLYNOMIAL :
  3.00x^3   9.00x^1
        DO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :1

        1.ENTER THE POLYNOMIAL

        2.DISPLAY POLYNOMIALS

        3.ADD POLYNOMIALS

        4.MULTIPLY POLYNOMIALS

        5.EVALUATE FIRST POLYNOMIAL

        ENTER CHOICE:
3

        ADDITION :

  3.00x^3   4.00x^2  10.00x^1
        DO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :1

        1.ENTER THE POLYNOMIAL

        2.DISPLAY POLYNOMIALS

        3.ADD POLYNOMIALS

        4.MULTIPLY POLYNOMIALS

        5.EVALUATE FIRST POLYNOMIAL

        ENTER CHOICE:

4

        MULTIPLICATION
 :
 12.00x^5   3.00x^4  36.00x^3   9.00x^2
        DO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :1

        1.ENTER THE POLYNOMIAL

        2.DISPLAY POLYNOMIALS

        3.ADD POLYNOMIALS

        4.MULTIPLY POLYNOMIALS

        5.EVALUATE FIRST POLYNOMIAL

        ENTER CHOICE:
5

        EVALUATE

        ENTER THE VALUE OF X
10

        EVALUATED VALUE = 410.00
        DO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :1

        1.ENTER THE POLYNOMIAL

        2.DISPLAY POLYNOMIALS

        3.ADD POLYNOMIALS

        4.MULTIPLY POLYNOMIALS

        5.EVALUATE FIRST POLYNOMIAL

        ENTER CHOICE:
6

        WRONG CHOICE

        DO YOU WANT TO PERFORM MORE OPERATONS?(1/0) :0