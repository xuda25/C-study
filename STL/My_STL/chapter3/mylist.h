template <typename T>
class ListItem
{
public:
    ListItem(T val, ListItem* next) : _value(val), _next(next) {}
    T value() const {return _value;}
    ListItem* next() const {return _next;}
private:
    T _value;
    ListItem* _next;
};


template <typename T>
class List
{
public:
    void insert_front(T value);
    void insert_back(T value);
    void display(std::ostream &os = std::cout) const;

private:
    ListItem<T>* _end;
    ListItem<T>* _begin;
    long _size;
}; 