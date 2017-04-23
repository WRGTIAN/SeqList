#include <iostream>  
#include <assert.h>  
using namespace std;  
template <typename T>  
  
class SeqList  
{  
public:  
    SeqList()  
        :_arr(NULL)  
        , _size(0)  
        , _capacity(0)  
    {}  
    SeqList(const SeqList<T>& seq)//拷贝构造  
    {  
        _arr = new T[seq._capacity];  
        for (size_t i = 0; i < seq._size; i++)  
        {  
            _arr[i] = seq._arr[i];  
        }  
        _capacity = seq._capacity;  
        _size = seq._size;  
    }  
    SeqList& operator=(const SeqList& seq)//赋值运算符重载  
    {  
        if (this != &seq)  
        {  
            SeqList<T> tmp(seq);  
            std::swap(_arr, tmp._arr);  
            _capacity = tmp._capacity;  
            _size = tmp._size;  
            return *this;  
        }  
        return *this;  
          
    }  
    ~SeqList()  
    {  
        if (_arr)  
        {  
            delete[] _arr;  
            _arr = NULL;  
            _capacity = _size = 0;  
        }  
    }  
    void PushBack(const T& x)//传引用减少资源浪费  
    {  
        _CheckCapacity();  
        _arr[_size] = x;  
        _size++;  
    }  
    void PopBack()  
    {  
        _size--;  
    }  
    void PushFront(const T& x)//头插(1、顺序表为空  2、多个元素)  
    {  
        _CheckCapacity();  
        if (_size == 0)//顺序表为空  
        {  
            _size++;  
            _arr[0] = x;  
        }  
        for (size_t i = _size; i >0; i--)//顺序表有多个数据  
        {  
            _arr[i] = _arr[i-1];  
        }  
        _arr[0] = x;  
        _size++;  
    }  
    void PopFront()//头删  
    {  
        for (size_t i = 0; i < _size-1;i++)  
        {  
            _arr[i] = _arr[i + 1];  
            //_arr[0] = _arr[1];  
            //_arr[_size-2] = _arr[_size-1];  
        }  
        --_size;  
    }  
    void Insert(int pos, const T& d)//前面插入  
    {  
        assert(pos>0);  
        assert(pos < _size);  
        _CheckCapacity();  
        for (size_t i = pos; i < _size;i++)  
        {  
            _arr[i + 1] = _arr[i];  
        }  
        _arr[pos] = d;  
        _size++;  
    }  
    int Search(const T& d)  
    {  
        for (size_t i = 0; i < _size;i++)  
        {  
            if (_arr[i] == d)  
            {  
                return i;  
            }  
        }  
        return -1;  
    }  
  
    void Remove(const T&x)//删除一个特定元素  
    {  
        size_t ret = 0;  
        ret = Search(x);  
        if (ret != -1)  
        {  
            for (size_t i = ret; i < _size; i++)  
            {  
                _arr[i] = _arr[i + 1];  
            }  
            _size--;  
        }  
        else  
            cout << "你要删除的元素不存在" << endl;  
    }  
    void Sort()//从小到大排序  
    {  
        assert(_size != 0);  
        size_t ret = _size - 1;  
        for (size_t i = 0; i < _size-1;i++)  
        {  
            for (size_t j = 0; j<ret;j++)  
            {  
                if (_arr[j]>_arr[j + 1])  
                {  
                    T tmp = _arr[j];  
                    _arr[j] = _arr[j + 1];  
                    _arr[j + 1] = tmp;  
                }  
            }  
        }  
    }  
    void Print()  
    {  
        for (size_t i = 0; i < _size; i++)  
        {  
            cout << _arr[i] << "  ";  
        }  
        cout << endl;  
        cout << _capacity << endl;  
        cout << _size << endl;  
    }  
  
private:  
    void _CheckCapacity()//1、判断 2、空间不够新加(a、顺序表为空 b、顺序表容量不足)  
    {  
        if (_size == _capacity)  
        {  
            size_t _NewCapacity = _capacity * 2 + 3;//如果顺序表原来为空，第一次申请三个对象                                                                   小空间  
            T* tmp = new T[_NewCapacity];  
            for (size_t i = 0; i < _size; i++)  
            {  
                tmp[i] = _arr[i];  
            }  
            delete[] _arr;  
            _arr = tmp;//更新_arr的空间大小  
            _capacity = _NewCapacity;  //更新容量  
        }  
    }  
      
private:  
    T* _arr;  
    size_t _size;  
    size_t _capacity;  
};  
int main()  
{  
    SeqList<int> a;  
/* 
    a.PushBack(1); 
    a.PushBack(2); 
    a.PushBack(3); 
    a.PushBack(4); 
    a.PushBack(5);*/  
    /*a.Remove(90);//测试不存在元素 
    cout << a.Search(3) << endl; 
    a.Print(); 
    cout << a.Search(10) << endl;*/  
    /*a.PushBack(6); 
    a.PushBack(3); 
    a.PushBack(2); 
    a.PushBack(1); 
    a.PushBack(5); 
    a.Sort(); 
    a.Print();*/  
    /*a.PushBack(1); 
    a.PushBack(2); 
    a.PushBack(3); 
    a.PushBack(4); 
    a.PushBack(5); 
    SeqList<int> b(a); 
    b.Print();*/  
    a.PushBack(1);  
    a.PushBack(2);  
    a.PushBack(3);  
    a.PushBack(4);  
    a.PushBack(5);  
    /*SeqList<int> b = a; 
    b.Print();*/  
    SeqList<int> b;  
    b.PushBack(1);  
    b.PushBack(1);  
    b.PushBack(1);  
    b.PushBack(1);  
    b.PushBack(1);  
    b.PushBack(1);  
    b.PushBack(1);  
    b.PushBack(1);  
    b = a;  
    b.Print();  
    system("pause");  
    return 0;  
} 