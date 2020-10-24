class Calculator{
    public:
    int power(int n, int p)
    {
        if(n<0 || p<0){
            throw runtime_error("n and p should be non-negative");
        }
        else{
            return pow(n,p);
        }
    }
};

