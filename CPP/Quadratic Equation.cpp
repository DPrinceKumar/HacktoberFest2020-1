#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    double x1, x2;
    cout << "Insert a, b, c value: " "\n";
    cin >> a >> b >> c;
    
    x1 = (-b + sqrt(b * b - 4*a*c)) / (2*a);
    x2 = (-b - sqrt(b * b - 4*a*c)) / (2*a);
    
    cout << "x1: " << x1 << "\n" << "x2: " << x2;
}