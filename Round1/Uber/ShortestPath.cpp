/*
上周刚面完店面， 给一个json input，列了一个list的intersection。
每个intersection有一个list的road。每条road有通向的intersection，cost和名字。
求给一个起始intersection和一个终点intersection，找到最短的路径并且打印出来。
ex..

intersection A: [ {name: "road1", cost: 3, destination: "intersection B"}, 
{name: "road2", cost: 2, destination: "intersection B"}, 
{name: "road3", cost: 1, destination: "intersection B"}]
intersection B: [ {name: "road4", cost: 4, destination: "intersection C"} ]
intersection C: []

最短路径从A到C：road3 -> road4

面试官先问如何把这个json转化成数据结构。楼主选择先建一个intersection class
和一个road class，然后再用一个HashMap建一个adjacent list。算法是用dfs去搜索。
但是楼主最后始终输出的路径不是最短的一条，不知道最后能不能过。。。
 */

class vertext {
public:
    char val;
    unordered_map<char, pair<string, int>> neighbors;
};

vector<string> 
