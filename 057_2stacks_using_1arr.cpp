#include <iostream>
using namespace std;
class Twostack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Twostack(int size)
    {
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        this->arr = new int[size];
    }
    void push1(int data)
    {
        if (top2-top1<=1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        top1++;
        arr[top1] = data;
    }
    void push2(int data)
    {
        if (top2 - top1 <= 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        top2--;
        arr[top2] = data;
    }
    void pop1()
    {
        if (top1 == -1)
            cout << "Stack Underflow\n";
        else
            top1--;
    }
    void pop2()
    {
        if (top2 == size)
            cout << "Stack Underflow\n";
        else
            top2++;
    }
    int peek1()
    {
        return arr[top1];
    }
    int peek2()
    {
        return arr[top2];
    }
    bool isEmpty1()
    {
        if (top1 == -1)
            return true;
        else
            return false;
    }
    bool isEmpty2()
    {
        if (top2 == size)
            return true;
        else
            return false;
    }
};
int main()
{
    Twostack st(8);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push1(5);
    st.push2(6);
    st.push2(7);
    st.push2(8);
    st.push1(34);
    cout<<"Top elements of stack 1 and 2 are "<<st.peek1()<<" "<<st.peek2()<<"\n";
    st.pop1();
    st.pop2();
    st.pop1();
    cout<<st.peek1()<<" "<<st.peek2()<<"\n";
    return 0;
}