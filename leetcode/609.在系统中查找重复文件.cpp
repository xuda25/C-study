/*
 * @lc app=leetcode.cn id=609 lang=cpp
 *
 * [609] 在系统中查找重复文件
 */

// @lc code=start
class Solution {
public:
// 从每个path中取出 目录  然后取出依次取出各个文件的 名称、内容
// 文件内容与 res 的index 存入 unordered_map中， 遇到一样的按照 路径/文件 格式存入vector中
    string getPath(string& str, int& index)
    {
        while (str[index] != ' ')
            ++index;
        return str.substr(0, index);
    }

    string getName(string& str, int& index)
    {
        int tmp = index;
        while (str[index] != '(')
            ++index;
        return str.substr(tmp, index - tmp);
    }

    string getContents(string& str, int& index)
    {
        int tmp = index;
        while (str[index] != ')')
            ++index;
        return str.substr(tmp, index - tmp);
    }

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int vecIndex = 0;
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        vecIndex = 0;

        for (string& s : paths)
        {
            int index = 0;
            string path = getPath(s, index);
            ++index;
            while (index < s.size())
            {
                string name = getName(s, index);
                ++index;
                string contents = getContents(s, index);
                index += 2;
                string file = path + '/' + name;
                if (!mp.count(contents))
                {
                    res.emplace_back(vector<string>());
                    res[vecIndex].emplace_back(file);
                    mp[contents] = vecIndex;
                    ++vecIndex;
                }
                else
                    res[mp[contents]].emplace_back(file);
            }

        }

        vector<vector<string>> ans;

        for (auto& v : res)
            if (v.size() > 1)
                ans.emplace_back(v);

        return ans;
    }
};

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string> &paths) {
    //key为文件内容，value为目录+文件名
    unordered_map<string, vector<string>> m;
    for (string &s : paths) {
      //' '前的字符串即为目录，为其追加一个'/'
      int start = s.find(' ');
      string path = s.substr(0, start).append(1, '/');
      //寻找`(`
      int leftBracket = s.find('(', start);
      while (leftBracket != -1) {
        //根据'('和' '的位置确定文件名
        string fileName = s.substr(start + 1, leftBracket - start - 1);
        //寻找`)`
        int rightBracket = s.find(')', leftBracket);
        //根据'('和')'的位置确定文件内容，将其作为key，目录和文件名作为value
        m[s.substr(leftBracket + 1, rightBracket - leftBracket - 1)].emplace_back(path + fileName);
        //继续寻找该目录的下一个文件
        start = rightBracket + 1;
        leftBracket = s.find('(', start);
      }
    }
    //找出具有重复内容的文件路径
    vector<vector<string>> result;
    for (auto &p : m) {
      if (p.second.size() >= 2) {
        result.emplace_back(p.second);
      }
    }
    return result;
  }
};

// @lc code=end

