// Copyright 2021 NNTU-CS
#include "bst.h"
using namespace std;
BST<std::string> makeTree(const char* filename) {
  struct Word buf;
  BST <std::string> tree;
  fstream file;
  file.open(filename);
  if (!file) {
    return tree;
  }
  if (tree.root == nullptr) {
    tree.readWord(&file, &buf);
    if (buf.len == 0) {
      return tree;
    }
    tree.root = new Node{buf, 1, nullptr, nullptr, 1};
    tree.setD(1);
  }
  while (1) {
    tree.readWord(&file, &buf);
    if (buf.len == 0) {
      break;
    } else {
      tree.insert(tree.root, buf);
    }
  }
  tree.unit = tree.root;
  return tree;
}
