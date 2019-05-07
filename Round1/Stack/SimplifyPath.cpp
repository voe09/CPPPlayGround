/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> address;
        string res;
        string tmp;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/' || i == path.size() - 1) {
                if (i == path.size() - 1 && path[i] != '/')
                    tmp = tmp + path[i];
                if (!tmp.empty()) {
                    if (tmp == "..") {
                        if (!address.empty())
                            address.pop();
                        tmp = "";
                    }
                    else if (tmp == ".") {
                        tmp = "";
                    }
                    else {
                        address.push(tmp);
                        tmp = "";
                    }
                }
            } else {
                tmp = tmp + path[i];
            }
        }
        if (!tmp.empty()) {

        }
        // reverse the stack
        stack<string> new_address;
        while (!address.empty()) {
            new_address.push(address.top());
            address.pop();
        }
        
        if (new_address.empty()) {
            res = res + '/';
            return res;
        }

        while (!new_address.empty()) {
            res = res + '/' + new_address.top();
            new_address.pop();
        }
        return res;
    }
};
