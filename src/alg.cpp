// Copyright 2021 NNTU-CS
#include "bst.h"
BST<std::string> makeTree(const char* filename) {
  struct Word buf;
  BST<std::string> tree;
  fstream file;
  file.open(filename);
  if (!file) {
    cout << "can't open file!\n" << endl;
    return tree;
  }
  if (tree.root == nullptr) {
    buf.wd = tree.readWord(&file);
    if (buf.wd.length() == 0) {
      cout << "tree empty!\n" << endl;
      return tree;
    }
    tree.root = new Node{buf, nullptr, nullptr};
    tree.root->wd.h = 1;
    tree.root->wd.freq = 1;
    tree.setD(1);
  }
  while (1) {
    buf.wd = tree.readWord(&file);
    if (buf.wd.length() == 0) {
      cout << "the tree is ready!\n" << endl;
      break;
    } else {
      tree.insert(tree.root, buf);
    }
  }
  tree.unit = tree.root;
  return tree;
}
