// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <fstream>
#include <iostream>
#include  <cstdlib>
#include <stdio.h>
#include <conio.h>
using namespace std;
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
    int compare(struct Word* Root, struct Word* Read);
		int d;
   public:
		Node* root;
		Node* unit;
    BST() {
      root=unit=nullptr;
      d = 0;
    };
    void readWord(ifstream *file, struct Word *tmp);
		void insert(Node *unit, struct Word tmp);
		int search( const char *look);
		int depth();
		int mydepth(Node*);
		int getD() { return d; };
		void setD(int a) {
      d = a;
      return;
		};
    void print(Node* unit);
};
#endif  // INCLUDE_BST_H_
