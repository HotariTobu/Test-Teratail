#pragma once

//#include <bits/stdc++.h>

#include <iostream>
#include <map>

using namespace std;

struct Node
{
    Node* next;
    Node* prev;
    int key;
    int value;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class LRarray
{
public:
    int capacity;

    Node* head;
    Node* tail;

    map<int, Node*> mp;

    LRarray(int);
    void set(int, int); // key value
    void get(int);// key
};

LRarray::LRarray(int cp)
{
    this->capacity = cp;

    //終端を表すダミーを用意する。mpには追加しない。
    this->head = new Node(0, 0);
    this->tail = new Node(0, 0);

    this->head->next = this->head;
    this->head->prev = this->tail;
    this->tail->next = this->head;
    this->tail->prev = this->tail;

    //this->head = new Node(this->tail, NULL, 0, 0);
    //this->tail = new Node(NULL, this->head, 0, 0);
}

void LRarray::set(int k, int v)
{
    Node* second = new Node(this->head->prev, this->head, k, v);
    this->head->prev->next = second;
    this->head->prev = second;
    this->mp[k] = second;
    if ((int)(this->mp.size()) > (this->capacity)) {
        cout << "capacity: " << this->capacity << endl;
        cout << "size: " << this->mp.size() << endl;
        cout << "Too many items" << endl;
    }
    //関数外で参照できなくなってしまうのでdeleteしない。
    //delete second;

}
void LRarray::get(int k)
{
    auto itr = this->mp.find(k);
    if (itr != this->mp.end()) {
        cout << this->mp[k]->value << endl;
    }
    else {
        cout << "There is no value attached key: " << k << endl;
    }
}

int entry() {

    int n;
    cin >> n; //入力回数

    int c;
    cin >> c; //capasity of array

    LRarray arr(c);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "set") {
            int key, value;
            cin >> key >> value;
            arr.set(key, value);
        }
        else if (command == "get") {
            int k;
            cin >> k;
            arr.get(k);
        }
    }


    return 0;
}