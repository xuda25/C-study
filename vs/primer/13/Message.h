#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include "Folder.h"
using namespace std;

class Message
{
    friend class Folder;
public:
    explicit Message(const string &str = "") : content(str) {}
    // �������Ƴ�Ա
    Message(const Message&);
    Message &operator=(const Message&);
    ~Message();

    // ɾ�� ��Ӳ���
    void remove(Folder&);
    void save(Folder&);

    void swap(Message &lhs, Message &rhs)
    {
        using std::swap;

        for (auto f : lhs.folders)
            f->remMsg(&lhs);
        for (auto f : rhs.folders)
            f->remMsg(&rhs);

        swap(lhs.content, rhs.content);
        swap(lhs.folders, rhs.folders);

        for (auto f : lhs.folders)
            f->addMsg(&lhs);
        for (auto f : rhs.folders)
            f->addMsg(&rhs);
    }
private:
    string content;
    set<Folder*> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

    void Message::save(Folder &f)
    {
        folders.insert(&f);
        f.addMsg(this);
    }

    void Message::remove(Folder &f)
    {
        folders.erase(&f);
        f.remMsg(this);
    }

    void Message::add_to_Folders(const Message &m)
    {
        for (auto f : m.folders)
            f->addMsg(this);
    }

    Message::Message(const Message &m) : content(m.content), folders(m.folders)
    {
        add_to_Folders(m);
    }

    void Message::remove_from_Folders()
    {
        for (auto f : folders)
        {
            f->remMsg(this);
        }
    }

    Message::~Message()
    {
        remove_from_Folders();
    }
    // �Զ����� content set

    Message &Message::operator=(const Message &rhs)
    {
        remove_from_Folders();
        content = rhs.content;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }

#endif