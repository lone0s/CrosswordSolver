//
// Created by jeune on 31/10/2022.
//

#pragma once

#include <string>
#include <vector>
#include "Node.h"

namespace LexicoTree {
    class SyntaxicTree {
        Node* node;
        void addLetter(char letter);
        bool wordIsValid(const std::string& word);
        Node* get(char letter); // Need wrapper pour retourner un arbre, on veut pas
        //savoir qu'il s'agit d'un type Node* !!!!
//        void clearWord(std::string& word);

    public:
        unsigned int wordsInDic;
        unsigned int wordsInTree;
        explicit SyntaxicTree(const std::string& filename);
        ~SyntaxicTree();

        char root() const;
        void addWord(const std::string& word);

//        friend std::ostream& operator << (std::ostream& ostream, SyntaxicTree tree);
        bool wordExists(const std::string& word) const;
        unsigned int loadFile(const std::string& filename);

        std::vector<std::string> listAnswers(const std::string& word) const;
    };
}