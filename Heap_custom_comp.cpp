#include <bits/stdc++.h>
using namespace std;
class Car
{
    public:
        int x, y;
        Car(int a, int b)
        {
            x = a;
            y = b;
        }
        int dist()
        {
            return x * x + y * y;
        }
};
class CarCompare
{
    public:
        bool operator()(Car a, Car b)
        {
            return a.dist() < b.dist();
        }
};
int main() {
    priority_queue<Car,vector<Car>, CarCompare> pq;
    Car c(5, 8);
    pq.push(c);
   pq.push(Car(6, 18));
   pq.push(Car(3, 9));
    while (!pq.empty())
    {
        Car temp = pq.top();
        cout << "x =  "<<temp.x << "   y = "<<temp.y << " ";
        cout << "distance = " << temp.dist() << endl;
        pq.pop();
    }
}
