#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    int addTwoDigits(ListNode *l1, ListNode *l2, int *digitUp)
{
    int a, b;
    if (l1 != NULL)
    {
        a = l1->val;
    }
    else
    {
        a = 0;
    };
    if (l2 != NULL)
    {
        b = l2->val;
    }
    else
    {
        b = 0;
    };

    int sum = a + b + *digitUp;
    *digitUp = sum / 10; //new digitUp
    
    return sum % 10;
}


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
   int digitUp = 0; //0 or 1
    //int foo;
    ListNode *tmpP;
    ListNode *tmpH = new ListNode(addTwoDigits(l1, l2, &digitUp));
    tmpP = tmpH;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    while ((l1 != NULL) || (l2 != NULL))
    {
        tmpP->next = new ListNode(addTwoDigits(l1, l2, &digitUp));
        //cout << tmpP->val << endl;
        tmpP = tmpP->next;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    };
    if (digitUp != 0)
        tmpP->next = new ListNode(1);
    return tmpH;
}
void display(ListNode *l1)
{
    while (l1 != NULL)
    {
        cout << l1->val << ',';
        l1 = l1->next;
    }
    cout << endl;
}
int main(void)
{
    int a = 81;
    int b = 0;
    int tmp = a;
    ListNode *tmpP, *tmpN;
    ListNode *La = new ListNode(tmp % 10);
    tmpP = La;
    while (tmp >= 10)
    {
        tmp /= 10;
        tmpN = new ListNode(tmp % 10);
        tmpP->next = tmpN;
        tmpP = tmpN;
    }

    tmp = b;
    ListNode *Lb = new ListNode(tmp % 10);
    tmpP = Lb;
    while (tmp >= 10)
    {
        tmp /= 10;
        tmpN = new ListNode(tmp % 10);
        tmpP->next = tmpN;
        tmpP = tmpN;
    }
    display(La);
    display(Lb);
    display(addTwoNumbers(La, Lb));
}