// Copyright 2021 NNTU-CS
#include "bst.h"
BST<std::string> makeTree(const char* filename) {
  struct Word buf;
  BST<std::string> tree;
  std::fstream file;
  file.open(filename);
  if (tree.root == nullptr) {
    buf.wd = tree.readWord(&file);
    tree.root = new Node{buf, nullptr, nullptr};
    tree.root->wd.freq = 1;
  }
  while (1) {
    buf.wd = tree.readWord(&file);
    if (buf.wd.length() == 0) {
      break;
    } else {
      tree.insert(tree.root, buf);
    }
  }
  tree.unit = tree.root;
  return tree;
}
