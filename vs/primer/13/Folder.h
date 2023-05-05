#ifndef FOLDER_H
#define FOLDER_H
#include "Message.h"
#include <set>

using namespace std;

class Folder
{
    friend class Message;
public:
    void addMsg(Message *m)
    {
        msg.insert(m);
    }
    void remMsg(Message *m)
    {
        msg.erase(m);
    }

    Folder(const Folder &f) : msg(f.msg)
    {
        add_to_Message(f);
    }

    ~Folder()
    {
        remove_from_Msgs();
    }
    
    Folder &operator=(const Folder &f)
    {
        remove_from_Msgs();
        msg = f.msg;
        add_to_Message(f);
        return *this;
    }
private:
    set<Message*> msg;
    void add_to_Message(const Folder &f)
    {
        for (auto m : f.msg)
            m->save(this);
    }
    void remove_from_Msgs()
    {
        for (auto m : msg)
            m->remove(this);
    }

};

    void Folder::addMsg(Message &m)
    {

    }

    void Folder::remMsg(Message &m)
    {

    }
#endif