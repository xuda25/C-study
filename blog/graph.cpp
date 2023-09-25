#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class GraphAdjMat
{
public:
    GraphAdjMat(const vector<int>& ver, const vector<vector<int>>& edges) : vertices(ver), adjMat(edges) {}


    /*获取顶点个数 */
    int size() const
    {
        return vertices.size();
    }

    /*添加顶点*/
    void addVertex(int val)
    {
        int n = size();
        vertices.push_back(val);
        adjMat.emplace_back(vector<int>(n, 0));
        for (auto& row : adjMat)
            row.push_back(0);
    }

    //删除顶点
    void removeVertex(int index)
    {
        if (index >=size())
            throw out_of_range("顶点不存在");
        // 删除顶点列表中index的元素
        vertices.erase(vertices.begin()+index);
        // 删除领接矩阵 顶点的连线
        // 先删除行
        adjMat.erase(adjMat.begin()+index);
        //删除列
        for (auto& row : adjMat)
            row.erase(row.begin()+index);        
    }

    // 添加边
    void addEdge(int i, int j)  
    {
        if (i < 0 || j < 0 || i > size() || j > size() || i == j)
            throw out_of_range("顶点不存在");
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    // 删除边
    void removeEdge(int i, int j)   
    {
        if (i < 0 || j < 0 || i > size() || j > size() || i == j)
            throw out_of_range("顶点不存在");
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    //打印领接矩阵
    void print()
    {
        cout << "顶点列表:" << endl;
        printVector(vertices);
        cout << "领接矩阵:" << endl;
        printVectorMatrix(adjMat); 
    }
private:
    vector<int> vertices; // 顶点列表， 元素代表顶点， 索引代表顶点索引
    vector<vector<int>> adjMat; // 领接矩阵 行列索引代表顶点索引   
};


class VerTex
{
    int val;
};

class GraphAdjList
{
public:
    GraphAdjList(const vector<vector<Vertex *>> &edges) {
        // 添加所有顶点和边
        for (const vector<Vertex *> &edge : edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    void remove(vector<VerTex*>& vec, VerTex* vet)
    {
        for (int i = 0; i < vec.size(); ++i)
            if (vec[i] == vet)
            {
                vec.erase(vec.begin()+i);
                break;
            }
    }

    // 获取顶点数量
    int size()
    {
        return adjList.size();
    }

    //添加边
    void addEdge(VerTex* vet1, VerTex* vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw out_of_range("不存在顶点");
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    //删除边
    void removeEdge(VerTex* vet1, VerTex* vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw out_of_range("不存在顶点");
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }
    
    // 添加顶点
    void addVertex(VerTex* vet)
    {
        if (adjList.count(vet))
            return;
        adjList[vet] = vector<VerTex*>();
    }

    // 删除节点
    void removeVertex(VerTex* vet)
    {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶顶啊");
        adjList.erase(vet);
        for (auto& adj : adjList)
            remove(adj.second, vet);
    }

    // 打印列表
    void print()
    {
        cout << "邻接表:" << endl;
        for (auto& adj : adjList)
        {
            const auto& key = adj.first;
            const auto& vec = adj.second;
            cout << key->val << ":";
            printVector(vetToVals(vec));
        }
    }

    unordered_map<VerTex*, vector<VerTex*>> adjList;
};


// 广度优先遍历
vector<VerTex*> graphBFS(GraphAdjList& graph, VerTex* startVet)
{
    vector<VerTex*> res;  //遍历序列
    unordered_set<VerTex*> visited{startVet};
    queue<VerTex*> que;
    que.push(startVet);

    while (!que.empty())
    {
        VerTex* vet = que.front();
        que.pop();
        res.push_back(vet);

        for (auto adjVet : graph.adjList[vet])
        {
            if (visited.count(adjVet))
                continue;
            que.push(adjVet);
            visited.emplace(adjVet);
        }    
    }

    return res;
}


// 深度优先遍历
void dfs(GraphAdjList& graph, unordered_set<VerTex*>& visited, vector<VerTex*>& res, VerTex* startVet)
{
    res.push_back(startVet);
    visited.emplace(startVet);

    for (auto adjVet : graph.adjList[startVet])
    {
        if (visited.count(adjVet))
            continue;
        dfs(graph, visited, res, adjVet);
    }
}

vector<VerTex*> graphDFS(GraphAdjList& graph, VerTex* startVet)
{
    vector<VerTex*> res;
    unordered_set<VerTex*> visited;
    dfs(graph, visited, res, startVet);
    return res;
}
