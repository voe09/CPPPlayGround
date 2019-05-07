/*
面我的是一个西人大哥。这轮考数据结构设计，time travel table。接口呀，合法输入值啊，返回值啊什么的都得跟面试官讨论。. 涓€浜�-涓夊垎-鍦帮紝鐙鍙戝竷
不过具体功能如下：
输入： "key1" time1 "val1"  // 插入一条记录
输入： “key1“ time2  ”val2" // 插入一条记录
输入： “key1" time2  "val3" // 把key1的time2记录的值从val2改成val3
输入： “key1" time6  "val4" // 插入一条记录
输入： “key1” time1 // 取出记录，val1
输入： “key1” time2 // 取出记录，val3
输入： “key1” time4 // 取出记录，val3，取出第一个时间戳比现在时间小的值
输入： “key1” time0 // 取一个不存在时间戳小于等于输入值的，返回null. more info on 1point3acres.com

我用了hashmap+treeMap解决问题。. 1point 3acres 璁哄潧
感觉西人大哥有点累，全程都比较沉默。而我上一轮面试前喝的咖啡现在才发挥功效，然后各种亢奋地说个不停...
btw，5+经验，面的是global growth team。地里找的内推。本来安排了一位国人大神面的，后来因为有事所以改期了。换成了西人大哥，人挺好没有为难我。
 */

#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;


class TimeTable {
public:
    TimeTable() {};

    void set(int key, int time, int val) {
        if (!m_.count(key)) {
            m_[key].emplace(time, val);
        } else {
            auto &tmp = m_[key];
            tmp[time] = val;
        }
    }

    int get(int key, int time) {
        if (m_.count(key)) {
            auto &tmp = m_[key];
            if (tmp.count(time)) return tmp[time];
            auto ptr = tmp.lower_bound(time);
            if (ptr == tmp.begin()) return -1;
            return (--ptr)->second;
        } else {
            return -1;
        }
    }

private:
    unordered_map<int, map<int, int>> m_;
};


int main() {
    TimeTable table = TimeTable();
    table.set(1, 1, 1);
    table.set(1, 2, 2);
    table.set(1, 2, 3);
    table.set(1, 6, 4);
    std::cout << table.get(1, 1) << std::endl;
    std::cout << table.get(1, 2) << std::endl;
    std::cout << table.get(1, 4) << std::endl;
    std::cout << table.get(1, 0) << std::endl;
}
