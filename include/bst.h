// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
struct Word {
  std::string wd;
  int freq;
};
struct Node {
  struct Word wd;
  Node * left;
  Node * right;
};
template<typename T>
class BST {
 private:
  int compare(std::string Read, std::string Root) {
    if (Read > Root)
      return 1;
    if (Read < Root)
      return -1;
    return 0;
  }

 public:
  Node * root;
  Node * unit;
  BST() {
    root = unit = nullptr;
  }
  std::string readWord(std::fstream * file) {
    char c;
    std::string tmp("");
    while (!file->eof()) {
      file->get(c);
      if (c >= 'A' && c <= 'Z') {
        c = c + 32;
        tmp.push_back(c);
      } else if (c >= 'a' && c <= 'z') {
               tmp.push_back(c);
             } else if (tmp.length() > 0) {
                      return tmp;
                    }
      }
      if (tmp.length() == 0) {
        file->close();
        return tmp;
      }
    return tmp;
  }
  void insert(Node * unit, struct Word tmp) {
    int path = compare(tmp.wd, unit->wd.wd);
    if (path == 1) {
      if (unit->right != nullptr) {
        insert(unit->right, tmp);
      } else {
          unit->right = new Node{tmp, nullptr, nullptr};
          unit->right->wd.freq = 1;
          return;
        }
      }
      if (path == -1) {
        if (unit->left != nullptr) {
          insert(unit->left, tmp);
        } else {
            unit->left = new Node{tmp, nullptr, nullptr};
            unit->left->wd.freq = 1;
            return;
          }
      }
      if (path == 0) {
        unit->wd.freq++;
      }
    return;
  }
  int search(const char * look) {
    int path = compare(look, unit->wd.wd);
    if (path == 1) {
      if (unit->right != nullptr) {
        unit = unit->right;
        search(look);
      }
    }  
    if (path == -1) {
      if (unit->left != nullptr) {
        unit = unit->left;
        search(look);
      }
    }  
    return unit->wd.freq;
  }
  int depth() {
    return mydepth(root) - 1;
  }
  int mydepth(Node * root) {
    if (root == nullptr)
      return 0;
    return 1 + std::max(mydepth(root->left), mydepth(root->right));
  }
};
#endif  // INCLUDE_BST_H_
