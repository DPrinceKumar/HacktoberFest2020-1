class Fine {};
class Demo {
    int a = 0;

   public:
    int* operator&() {
        return &a;
    }
};

template <class T>
T* addressof(T& v) {
    return reinterpret_cast<T*>(
        &const_cast<char&>(reinterpret_cast<const volatile char&>(v)));
}

int main() {
    Fine* f1;
    Fine f2;
    f1 = &f2;

    Demo* d1;
    Demo d2;
    d1 = addressof(d2);

    return 0;
}
