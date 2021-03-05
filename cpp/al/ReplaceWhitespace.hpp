//
// Created by shiwk on 2021/3/4.
//

#include <string>
using namespace std;
class ReplaceWhiteSpace{
public:
    string replaceSpace(string s) {
        int length = s.length();
        int count = 0;
        for(char c:s)
        {
            count += c == ' ';
        }
        s.append(count * 2, ' ');
        int i = s.length() -1;
        int j = length -1;

        while (i != j)
        {
            if (s[j] != ' ')
                s[i--] = s[j--];
            else
            {
                s[i--] = '0';
                s[i--] = '2';
                s[i--]='%';
                j--;
            }
        }

        return s;
    }
};