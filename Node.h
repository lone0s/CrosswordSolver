//
// Created by jeune on 31/10/2022.
//

#pragma once


#include <vector>

namespace LexicoTree {
    class Node {
        char value;
        bool eow; //EndOfWord
        Node* childs[26];
        //Ne jamais init en dehors du constructeur

    public:
        explicit Node(char val, bool flag = false);
        bool isEow() const;
        void setEow(bool flag);

        ~Node();
        char root() const;
        Node* getLetter(char letter);
        void addLetter(char letter);
        std::vector<Node*> getChildren() const;
        bool hasLetter(char letter) const;
    };
}

