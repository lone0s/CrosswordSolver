//
// Created by jeune on 31/10/2022.
//

#include <iostream>
#include "Node.h"

LexicoTree::Node::Node(char val, bool flag /* = false */) : value(val) , eow(flag) {
    for(auto & child : childs) {
        child = nullptr;
    }
}

LexicoTree::Node::~Node() {
    for (auto &node : childs) {
        if (node != nullptr) {
            delete node;
        }
    }
}

LexicoTree::Node* LexicoTree::Node::getLetter(char letter) {
    return childs[letter - 'a'];
}

void LexicoTree::Node::addLetter(char letter) {
    if (childs[letter - 'a'] == nullptr) {
        childs[letter - 'a'] = new Node(letter);
    }
}

bool LexicoTree::Node::isEow() const {
    return eow;
}

void LexicoTree::Node::setEow(bool flag) {
    eow = flag;
}

char LexicoTree::Node::root() const {
    return value;
}

std::vector<LexicoTree::Node *> LexicoTree::Node::getChildren() const {
    std::vector<Node*> res;
    for(auto& child : childs) {
        if (child != nullptr)
            res.push_back(child);
    }
    return res;
}

bool LexicoTree::Node::hasLetter(char letter) const {
    return (childs[letter - 'a'] != nullptr);
}


