/*
 * Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

class Solution {
public:
    string simplifyPath(string path) {
        string ret, curDir;
        vector<string> allDir;
        
        path.push_back('/');
        for(int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (curDir.empty()) {
                    continue;
                }
                else if (curDir == ".") {
                    curDir.clear();
                }
                else if (curDir == "..") {
                    if(!allDir.empty())
                        allDir.pop_back();
                    curDir.clear();
                }
                else {
                    allDir.push_back(curDir);
                    curDir.clear();
                }
            }
            else {
                curDir.push_back(path[i]);
            }
        }
        
        for(int i=0; i<allDir.size(); i++) 
            ret.append("/"+allDir[i]);
        if (ret.empty()) ret = "/";
        return ret;
    }
};
