#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    //ostringstream oss;
    string number;
    cin>>number;
    for (int i = 0;i < number.length();i++)
    {
        int x;
        //stringstream convertor(number[i]);
        //convertor>>x;
        x = number[i] - '0';
        if (i == 0)
        {
            if (x >= 5 && x != 9)
            {
                x = 9 - x;
            }
        }
        else
        {
            if (x >= 5)
            {
                x = 9 - x;
            }
        }
        //oss << newNumber << x;
        cout<<x;
    }
    //cout << newNumber.str();
    cout<<endl;
}
