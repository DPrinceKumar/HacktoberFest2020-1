#include<iostream>
using namespace std;

int main() {
     int num;
     cout << "Enter the numbers to be added: " << endl;;
     cin >> num;

     int result = 0;
     while (num != -1) {
          result += num;
          cin >> num;
     }
     cout << "Sum of all numbers is: " << result << endl;


     return 0;
}
