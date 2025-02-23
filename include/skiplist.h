#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include <vector>
#include <ctime>

namespace my {
    class Skiplist {
    private:
        struct node {
            int val;
            std::vector<node *> nxt;
            node() : val(0), nxt(0) {}
            node(int val) : val(val), nxt(0) {}
        };
        node *head;
        node *nil;
        int level;
    public:
        Skiplist() : level(1), nil(new node(0x7fffffff)), head(new node(-0x80000000)) {
            srand(time(0));
            head->nxt.push_back(nil);
        }
        
        bool search(int target) {
            node *cur = head;
            for (int i = level-1; i >= 0; --i) {
                while (cur->nxt[i]->val < target) {
                    cur = cur->nxt[i];
                }
            }
            return cur->nxt[0]->val == target;
        }
        
        void add(int num) {
            node *cur = head;
            std::vector<node *> pre(level, head);
            for (int i = level-1; i >= 0; --i) {
                while (cur->nxt[i]->val < num) {
                    cur = cur->nxt[i];
                }
                pre[i] = cur;
            }
            node *new_node = new node(num);
            int new_level = 1;
            while ((rand() & 1) && new_level <= level) {
                ++new_level;
            }
            if (new_level > level) { // 至多增加一层
                pre.push_back(head);
                head->nxt.push_back(nil);
                ++level;
            }
            for (int i = 0; i < new_level; ++i) {
                new_node->nxt.push_back(pre[i]->nxt[i]);
                pre[i]->nxt[i] = new_node;
            }
        }
        
        bool erase(int num) {
            node *cur = head;
            std::vector<node *> pre(level, head);
            for (int i = level-1; i >= 0; --i) {
                while (cur->nxt[i]->val < num) {
                    cur = cur->nxt[i];
                }
                pre[i] = cur;
            }
            if (cur->nxt[0]->val != num) {
                return false;
            }
            node *del_node = cur->nxt[0];
            int del_level = del_node->nxt.size();
            for (int i = 0; i < del_level; ++i) {
                pre[i]->nxt[i] = del_node->nxt[i];
            }
            delete del_node;
            while (level > 1 && head->nxt[level-1] == nil) {
                head->nxt.pop_back();
                --level;
            }
            return true;
        }
    };
}

#endif // _SKIPLIST_H_