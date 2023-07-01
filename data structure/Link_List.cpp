

using namespace std;

class Node
{
public:
    Node(int a) : data(a), next(nullptr) {}
    bool InitList()
    {
        Node* head = new Node(0);
        if (head == nullptr)
            return false;
        else
            return true;
    }
private:
    int data;
    Node* next;
};

int main()
{
    
}