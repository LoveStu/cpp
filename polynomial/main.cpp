#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    Polynomial pol_1(2);
    cin >> pol_1;
    Polynomial pol_2(2);
    cin >> pol_2;
    Polynomial tem_pol = pol_1 * pol_2;
    cout << tem_pol;
}