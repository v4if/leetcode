class Singleton{
public:
    static Singleton* getInstance() {
        if (m_pData == NULL) {
            m_pData = new Singleton();
        }
        return m_pData;
    }
private:
    Singleton();
    static Singleton* m_pData;
};

Singleton* Singleton::m_pData = NULL;

//==================================
template<typename T>  
class Singleton : boost::noncopyable  
{
    public:
        static T& instance()
        {
            pthread_once(&ponce_, &Singleton::init);
            return *value_;
        }

        static void init()
        {
            value_ = new T();
        }
    private:
        static pthread_once_t ponce_;
        static T* value_;

/*
private:
    Singleton();                            // ctor hidden
    Singleton(Singleton const&);            // copy ctor hidden
    Singleton& operator=(Singleton const&); // assign op. hidden
    ~Singleton();                           // dtor hidden
 */
};

template<typename T>  
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>  
T* Singleton<T>::value_ = NULL;  
