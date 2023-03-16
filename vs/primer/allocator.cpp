#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
//allocator �ཫ �ڴ�����Լ�������ֿ���

int main()
{
    allocator<string> allo;
    auto const p = allo.allocate(10); //����10��δ��ʼ����string


    /*  allocator�з���δ������ڴ�     */
    auto q = p; // qָ��������Ԫ��֮���λ��
    allo.construct(q++, string("a"));
    allo.construct(q++); //�մ�
    allo.construct(q++, 10, 'a'); //aaaaaaaaaa
    allo.construct(q++, "hi"); //hi
    cout << *p << endl; // ��ȷ
    cout << *q << endl; // ���� qָ��δ��ʼ����  δ����
    // ����������ռ�� Ҫ��������
    while (q != p)
        allo.destroy(--q);  //ֻ�ܶ��Ѿ������Ԫ����destroy
    // ���ٺ� �������¹��� ���߽��ռ仹��ϵͳ
    allo.deallocate(p, 10);  //�ռ��С ���������ǰһ��
    /*          */


    /*  ���������Ϊ��ʼ���ڴ���㷨*/
    vector<int> vI({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
    allocator<int> alloca;
    auto p = alloca.allocate(vI.size() * 2);
    auto q = uninitialized_copy(vI.begin(), vI.end(), p);
    uninitialized_fill_n(q, vI.size(), 100);
        
    return 0;
}