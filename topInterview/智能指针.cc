#ifndef __SHARED_PTR_
#define __SHARED_PTR_

template <typename T>
class shared_ptr {
public:
    shared_ptr(T* p) : count(new int(1)), _ptr(p) {}
    shared_ptr(shared_ptr<T>& other) : count(&(++*other.count)), _ptr(other._ptr) {}
    T* operator->() { return _ptr; }
    T& operator*() { return *_ptr; }
    shared_ptr<T>& operator=(shared_ptr<T>& other)
    {
        ++*other.count;
        if (this->_ptr && 0 == --*this->count)
        {
            delete count;
            delete _ptr;
        }
        this->_ptr = other._ptr;
        this->count = other.count;
        return *this;
    }
    ~shared_ptr()
    {
        if (--*count == 0)
        {
            delete count;
            delete _ptr;
        }
    }
    int getRef() { return *count; }
private:
    int* count;
    T* _ptr;
};


#endif
