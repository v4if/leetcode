/**
class MyStr{
public:
    MyStr(char* pData = NULL):m_pData(pData) {}
    ~MyStr() {delete m_pData;}
private:
    char* m_pData;
};
 */

// 没有考虑new的异常安全  bad_alloc
MyStr& MyStr::operator= (const MyStr& other) {
    if (this == &other) return *this;

    delete[] m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(other.m_pData) + 1];
    return *this;
}

MyStr& Mystr::operator= (const Mystr& other) {
    if (this != &other) {
        MyStr strTemp(other.m_pData);

        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
