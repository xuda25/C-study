#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include <algorithm>

using namespace std;


class StrVec
{
public:
    friend bool operator<(const StrVec& s1, const StrVec& s2);
    friend bool operator<=(const StrVec& s1, const StrVec& s2);
    friend bool operator>(const StrVec& s1, const StrVec& s2);
    friend bool operator>=(const StrVec& s1, const StrVec& s2);
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string> il);
    StrVec(const StrVec&); //�������캯��
    StrVec& operator=(const StrVec&); //������ֵ����
    StrVec(StrVec&& s) noexcept;
    StrVec& operator=(StrVec&&);
    ~StrVec(); //��������
    StrVec& operator=(initializer_list<string> il);
    string& operator[](size_t n) {return elements[n];}
    const string& operator[](size_t n) const {return elements[n];}
    void push_back(const string&);
    void push_back(string&&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - first_free;}
    size_t capacityall() const {return cap - elements;}
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string& s);
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static allocator<string> alloc;

    // ��� �Ƿ��пռ�
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    // ������ΧԪ��
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    // ����Ԫ�� ���ͷ�
    void free();
    // ���·���ռ�
    void reallocate();
    void reallocate(size_t n);
    string* elements; // ָ����Ԫ��
    string* first_free; // ָ���һ������Ԫ�ص�ָ��
    string* cap; //ָ��ռ�ĩβ��һ��λ��

};

void StrVec::push_back(const string& s)
{
    // ����Ƿ��пռ�  �оͷ� û�о�reallocate()
    chk_n_alloc();
    // ������Ԫ��  ��first_free����һλ
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string&& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

// ��Χ��������  ����һ��pair  �ֱ��� �¿ռ�� ͷ �� β
pair<string*, string*> StrVec::alloc_n_copy(const string* s1, const string* s2)
{
    auto data = alloc.allocate(s2 - s1); // ����ռ�
    return {data, uninitialized_copy(s1, s2, data)};
}

// free����  ����Ԫ�� Ȼ���ͷſռ�
// void StrVec::free()
// {
//     // ���ܴ���deallocate ��ָ��
//     if (elements)
//     {
//         for (auto p = first_free; p != elements; /**/)
//             alloc.destroy(--p);
//         alloc.deallocate(elements, cap - elements);
//     }
// }

void StrVec::free()
{
    if (elements)
        for_each(elements, first_free, [](string& s) {alloc.destroy(&s);});
}

StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();  //�ͷŵ�ǰ�ռ�

    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::StrVec(StrVec&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // ��s�����״̬------������ȫ
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

/*�����������֪ʶ��*/
void StrVec::reallocate()
{   
    // ���������ռ�
    auto newcapacity = size() ? 2 * size() : 1;
    // ��ʼ����
    auto first = alloc.allocate(newcapacity);
    // һ��ָ���¿ռ� һ��ָ��Ϳռ�  �������ݵ��ƶ�
    // ʹ���ƶ�������
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    free();  // �ͷžɿռ�

    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::reallocate(size_t n)
{   
    // ���������ռ�
    auto newcapacity = n;
    // ��ʼ����
    auto newdata = alloc.allocate(newcapacity);
    // һ��ָ���¿ռ� һ��ָ��Ϳռ�  �������ݵ��ƶ�
    auto dest = newdata; // ������ ��һ��λ��
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));  // д�ĺð�   move  �ƶ����캯��

    free();  // �ͷžɿռ�

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n > capacityall())
        reallocate(n);
}

void StrVec::resize(size_t n)
{
    if (n > size())
        while (size() < n)
            push_back("");
    else if (n < size())
        while (size() > n)
            alloc.destroy(--first_free);
}

void StrVec::resize(size_t n, const string& s)
{
    if (n > size())
        while (size() < n)
            push_back(s);
}

bool operator<(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;

        if (p1 == s1.end() && p2 != s2.end())
            return true;
        else
            return false;
    }
}

bool operator<=(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;

        if (p1 == s1.end())
            return true;
        else
            return false;
    }
}

bool operator>(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 > *p2)
            return true;
        else if (*p1 < *p2)
            return false;

        if (p1 != s1.end() && p2 == s2.end())
            return true;
        else
            return false;
    }
}

bool operator>=(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 > *p2)
            return true;
        else if (*p1 < *p2)
            return false;

        if (p2 == s2.end())
            return true;
        else
            return false;
    }
}

StrVec& StrVec::operator=(initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());

    free();

    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
#endif