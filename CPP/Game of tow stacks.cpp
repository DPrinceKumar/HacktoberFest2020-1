#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

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

int max_tam(_stack &stac, _stack &popedItems, int &x){
    int size = stac.size, sumando, act_size = 0;
    for (int i = 0; i < size; i ++){
        sumando = stac.top();
        if (x - sumando >=0){
            stac.pop();
            popedItems.push(sumando);
            x -= sumando;
            act_size ++;
        }
        else break;      
    }
    return act_size;
}

int intercalado (int x, int tam_act, _stack b, _stack res){
    int sumando, max_tam = tam_act, size = b.size;
    for (int i = 0; i < size; i ++){
        sumando = b.top();
        if ( x - sumando >= 0){
            b.pop();
            x -= sumando;
            tam_act ++;
            if (tam_act > max_tam) max_tam = tam_act;
        }
        else if (res.size > 0){
            i --;
            x += res.pop();
            tam_act --;
        }
        else break;
    }
    return max_tam;
}


int twoStacks(int &x, _stack &_a, _stack &_b) {

    _stack c = _stack(_a.size);
    int tam_sub_a = max_tam(_a, c, x);
    return intercalado(x, tam_sub_a,  _b, c);

}

int main()
{
    int g;
    cin >> g;
    while (g--){
        int n, m , x;
        cin>>n>>m>>x;
        _stack a = _stack(n, true);
        _stack b = _stack(m, true);
        for(int i = 0; i < n; i++)cin>>a.nStack[n-(i+1)];
        for(int i = 0; i < m; i++)cin>>b.nStack[m-(i+1)];

        cout << twoStacks(x,a,b)<<endl;
    }
    return 0;
}