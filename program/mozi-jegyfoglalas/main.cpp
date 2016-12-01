#include <iostream>

#include "MovieTicketBookingSystem.h"
#include <algorithm>

int main()
{
    DateTime d1(2016, 10, 1, 10, 4);
    DateTime d2(2016, 12, 1, 10, 4);
    DateTime d3(2016, 10, 10, 20, 4);
    DateTime d4(2016, 3, 1, 2, 7);
    vector<DateTime> v;
    v.push_back(d1);
    v.push_back(d2);
    v.push_back(d3);
    v.push_back(d4);
    for(unsigned int i= 0; i<v.size(); i++)
    {
        v[i].print();
        cout << endl;
    };
    cout << "--------------------" << endl;
    sort(v.begin(), v.end());
    for(unsigned int i= 0; i<v.size(); i++)
    {
        v[i].print();
        cout << endl;
    };
    
    return 0;
}

