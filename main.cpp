/*题目
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.*/

public:
    char findTheDifference(string s, string t) {
       /*
       std::set<char> myset;
        std::set<char>::iterator ite;
        int i;
        for(i = 0;i < s.length();i++)
        {
            myset.insert(s[i]);
        }

        for(i = 0;i < t.length();i++)
        {
            ite = myset.find(t[i]);
            if(ite != myset.end())//找到了
            {
                myset.erase(ite);
            }
            else
            {
                myset.insert(t[i]);
            }

        }

        for(ite = myset.begin();ite != myset.end();ite++)
        {
            return *ite;
        }
        return 0;*/
        //上面的思路有问题 用set是不能有重复元素的 但是s串本身可以有重复元素 wrong answer的问题在这里吗
        //同样的思路 应该用hash_map 每个pair是字符-出现次数  注意map的概念是pair vector set之类的概念是元素
        hash_map<char,int> ha;
        int i;
        for(i = 0;i < s.length();i++)
        {
            if(ha[s[i]] != 0)
            {
                ha[s[i]] ++;
            }
            else
            {
                ha.insert(s[i],1);
            }
        }

        for(i = 0;i < t.length();i++)
        {
            if(ha.find(t[i]) != ha.end())
            {
                ha[t[i]]--;
            }
            else
            {
                ha.insert(t[i],1);
            }
        }

        hash_map<char,int>::iterator ite;

        for(ite = ha.begin();ite != ha.end();ite++)
        {
            if(ite -> second == 1)
              return ite->first;
        }
        return 0;
    /*    vector<int> count(26,0);//统计元素个数的数组 下标是每个字母转数字
        int i;
        for(i = 0;i < s.length();i++)
        {
            count[s[i] - 'a']++;
        }

        for(i = 0;i < t.length();i++)
        {
            count[t[i] - 'a']--;
        }
        for(i = 0;i < 26;i++)
        {
            if(count[i] == -1)
              return i + 'a';
        }
        return 0;    acepted*/
    }
};
