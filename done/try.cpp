#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;



int main()
{
    int noSec, noMin, noHours, secLeft, minLeft;

    

    cout << "enter the seconds :";
    cin >> noSec;

    noMin = noSec / 60;
    secLeft = noSec % 60;

    noHours = noMin / 60;
    minLeft = noMin % 60;

    
    cout << "the time is Hour " << noHours << " : Min " << minLeft <<  " : Sec " << secLeft << "\n\n\a" << endl; 
    cout << "the time is Hour " << setfill('0') << setw(2) << noHours << " : Min " << setw(2) << minLeft <<  " : Sec " << setw(2) << secLeft << endl; 
    return 0;
}