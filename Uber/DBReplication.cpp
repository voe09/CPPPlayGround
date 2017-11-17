/*
用自己熟悉的语言定义一个DB类，
支持get(key:string) => string和set(key:string, val:string)方法。
然后要求实现replicate方法：
replicate(db1, db2)
调用之后所有db1上的数据会转移到db2上，
并且db1.set()调用的结果会replicate到db2上面。

要注意
replicate(db1,db2)
replicate(db2,db1)
之后set被死循环调用的情况

整个模拟需要写主函数测试打印结果。
 */

class DB {
public:
    DB() {}

    string get(string key) {

    }

    void set(string key, string val) {

    }

private:
    unordered_map<string, string> cache_;
    DB* linked_db_;
};
