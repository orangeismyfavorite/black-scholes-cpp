#include <iostream>
#include <cmath>
using namespace std;


double normalCDF(double value)
{
   return 0.5 * erfc(-value * M_SQRT1_2);
}

void callOption(float s, float k, float sigma, float r, float t)
{
    float d1;
    float d2;
    float price;

    d1 = ((log(s / k)) + (t * (r + (pow(sigma, 2))))) / (sigma * sqrt(t));
    d2 = d1 - (sigma * sqrt(t));

    price = (s * normalCDF(d1)) - (k * exp(-(r * t)) * normalCDF(d2));

    cout << price << '\n';
}

void putOption(float s, float k, float sigma, float r, float t)
{
    float d1;
    float d2;
    float price;

    d1 = ((log(s / k)) + (t * (r + (pow(sigma, 2))))) / (sigma * sqrt(t));
    d2 = d1 - (sigma * sqrt(t));

    price = (k * exp(-(r * t)) * normalCDF(-d2)) - (s * normalCDF(-d1));

    cout << price << '\n';
}

int main()
{   
    float s, k, sigma, r, t;
    s = price;
    k = strike price;
    sigma = volatility;
    r = interest rate;
    t = days until exercise;

    t = t / 365;

    cout << "The price of the call is: ";
    callOption(s, k, sigma, r, t);
    cout << '\n';

    cout << "The price of the put is: ";
    putOption(s, k, sigma, r, t);
    cout << '\n';

    return 0;
}
