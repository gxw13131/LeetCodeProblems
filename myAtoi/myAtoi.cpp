#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <cmath>
using namespace std;
int myAtoi(const string str)
{
    map<char, int> mapAtoi;
    for (int i = 0; i < 10; i++)
    {
        mapAtoi[(char)'0' + i] = i;
        // cout << (char)'0' + i << ':' << i << endl;
    }

    int A[11];    //for int type, 11 char is sufficient to cover -2^31~2^31-1
    int sign = 1; //default sign is positive
    bool digitsExist = false;
    int d = 0;
    string::size_type l = 0;
    //jump 'space'
    cout << "jump white space:" << endl;
    while (l < str.length())
    {
        if ((str[l] < '0' || str[l] > '9') && (str[l] != '-') && (str[l] != '+') && str[l]!=' ')
            return 0; //invalid string: other chars go before [+,-, ,0~9]
        cout << str[l] << endl;
        if (str[l] != ' ')
            break;
        l++;
    }
    cout << "check +/- sign:" << endl;
    // check +/- sign
    if (str[l] == '-' && (str[l + 1] >= '0' && str[l + 1] <= '9'))
    {
        sign = -1;
        l++;
    }
    else if (str[l] == '+' && (str[l + 1] >= '0' && str[l + 1] <= '9'))
    {
        sign = 1;
        l++;
    }

    // read digits
    cout << "read digits:" << endl;
    bool isValid=false;
    while (l < str.length() && d < 11 && str[l] >= '0' && str[l] <= '9')
    {
        A[d] = mapAtoi[str[l]];
        l++;
        if(A[d]!=0 && !isValid) isValid=true;
        if(isValid) d++;
    }

    // convert digits Array to integer
    cout << "convert digits Array to integer:" << endl;
    for (int i = 0; i < d; i++)
    {
        cout << i << ':' << A[i] << endl;
    };
    if (d == 0)
        return 0;
    long int tmp = 0;
    for (int i = 0; i < d; i++)
    {
        tmp += sign * A[i] * pow(10, d - i - 1);
    }
    if (tmp > numeric_limits<int>::max())
        return numeric_limits<int>::max();
    if (tmp < numeric_limits<int>::min())
        return numeric_limits<int>::min();
    return tmp;
}

int main()
{
    string test = "  00000006871232";
    cout << "string:"<<test << endl;
    cout << "integer:" << myAtoi(test) << endl;
}