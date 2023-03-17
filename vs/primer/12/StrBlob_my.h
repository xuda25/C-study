// #ifndef STRBLOB_MY_H
// #define STRBLOB_MY_H

// #include <string>
// #include <vector>
// #include <memory>

// using namespace std;

// class StrBlob_my
// {
// public:
//     typedef vector<string>::size_type size_type;
//     StrBlob_my();
//     StrBlob_my(initializer_list<string> il);

//     bool empty() {return data->empty();}
//     void push_back(const string &s) {data->push_back(s);}
//     void pop_back();
//     string &front();
//     string &back();
//     const string &front() const;
//     const string &back() const;

// private:
//     shared_ptr<vector<string>> data;
//     void check(size_type i, const string &msg) const;    
// };

// StrBlob_my::StrBlob_my() : data(make_shared<vector<string>>()) {}
// StrBlob_my::StrBlob_my(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

// void StrBlob_my::check(size_type i, const string &msg) const
// {
//     if (i >= data->size())
//         throw out_of_range(msg);
// }

// void StrBlob_my::pop_back()
// {
//     check(0, "pop_back");
//     data->pop_back();
// }

// const string &StrBlob_my::front() const
// {
//     check(0, "front");
//     data->front();
// }

// const string &StrBlob_my::back() const
// {
//     check(0, "back");
//     data->back();
// }

// string &StrBlob_my::front()
// {
//     check(0, "front");
//     data->front();
// }

// string &StrBlob_my::back()
// {
//     check(0, "back");
//     data->back();
// }

// #endif