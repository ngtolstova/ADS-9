// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
struct Word {
  char word[40];
  int len;
};
struct Node {
  struct Word wd;
  int freq;
  Node *left;
  Node *right;
  int h;
};
template <typename T>
  class BST {
   private:
    int compare(struct Word* Root, struct Word* Read) {
      int i = 0, circle = std::max(Read->len, Root->len), result = 0;
      while (i < circle) {
        if (Read->word[i] > Root->word[i]) {
          result = 1;
          break;
        } else if (Read->word[i] < Root->word[i]) {
          result = -1;
          break;
        }
        i++;
      }
      return result;
    }
    int d;

   public:
    Node* root;
    Node* unit;
    BST() {
      root = unit = nullptr;
      d = 0;
    }
    void readWord(fstream *file, struct Word *tmp) {
      char c;
      snprintf(tmp->word, sizeof(tmp->word), "00000000000000000000000000000000000000000");
      tmp->len = 0;
      while (file->get(c)) {
        if ((c >= 'A' && c <= 'Z')) {
          c = c + 32;
          tmp->word[tmp->len] = c;
          tmp->len++;
        } else if ((c >= 'a' && c <= 'z')) {
          tmp->word[tmp->len] = c;
          tmp->len++;
        } else if (tmp->len >0) {
          return;
        }
      }
      if (tmp->len == 0) {
        file->close();
        return;
      }
      return;
    }
    void insert(Node *unit, struct Word tmp) {
      int path = compare(&unit->wd, &tmp);
      if (path == 1) {
        if (unit->right != nullptr) {
          insert(unit->right, tmp);
        } else {
          unit->right = new Node{ tmp, 1, nullptr, nullptr, unit->h+1};
          d = std::max(d, unit->h+1);
          return;
        }
      }
      if (path == -1) {
        if (unit->left != nullptr) {
          insert(unit->left, tmp);
        } else {
          unit->left = new Node{ tmp, 1, nullptr, nullptr, unit->h+1};
          d = std::max(d, unit->h+1);
          return;
        }
      }
      if (path == 0) {
        unit->freq++;
      }
      return;
    }
    int search(const char *look) {
      struct Word wd;
      wd.len = strlen(look);
      snprintf(wd.word, sizeof(tmp->word), look);
      int path = compare(&unit->wd, &wd);
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
      return unit->freq;
    }
    int depth() {
      return mydepth(root)-1;
    }
    int mydepth(Node*) {
      if (root == nullptr) return 0;
      return 1 + max(mydepth(root->left), mydepth(root->right));
    }
    int getD() {
      return d;
    }
    void setD(int a) {
      d = a;
      return;
    }
  };
#endif  // INCLUDE_BST_H_
