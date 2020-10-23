#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class _stack{
    public:
        int size = 0;
        int *nStack;

        _stack(int n){
            size = 0;
            nStack = new int[n];
        }
        
        _stack(int n, bool a){
            size = n;
            nStack = new int[size];
        }

        _stack(int a[],int n){
            size = n;
            nStack = new int[size];
            for (int i = 0; i< size; i++){
                nStack[i] = a[size-(i+1)];
            }
        }
        int top(){
            return nStack[size-1];
        }
        int pop(){
            size --;
            return nStack[size];
        }
        void push(int a){
            nStack[size] = a;
            size ++;
        }
};

class _queue{
    private:
        int head;
        int tail;
        int* arrayman;
    public:
        _queue(){
            head = 0;
            tail = 0;
            arrayman = new int[tail];    
        }
        _queue(int size){
            head = 0;
            tail = 0;
            arrayman = new int[size];    
        }
        void enqueue(int dato){
            arrayman[tail] = dato;
            tail ++;
        }
        int dequeue (){
            head ++;
            return arrayman[head - 1];
        }
        bool isEmpty(){
            return head == tail ? true : false;
        }
};

int main() {
    int threads, tasks;
    cin>>threads>>tasks;
    int ethread[threads] = {0};
    _queue etasks(tasks);
    for (int i = 0; i < tasks; i++){
        int dato;
        cin >> dato;
        etasks.enqueue(dato);
    }
    for (int t = 0; t < tasks; t++){
        for (int j = 0; j < threads; j++){
            if (ethread[j] == 0 && ! etasks.isEmpty()){
                cout << j << ' ' << t << endl;
                ethread[j] = etasks.dequeue();
            } 
            ethread[j]--;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
