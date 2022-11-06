//
// Created by jeune on 31/10/2022.
//

#include <iostream>
#include <fstream>
#include "SyntaxicTree.h"


LexicoTree::SyntaxicTree::SyntaxicTree(const std::string& filename) {
    wordsInTree = 0;
    node = new Node('.');
    unsigned int res = loadFile(filename);
    if (res == 1) {
        std::cout << "Properly created tree and imported external library\n";
    }
    else
        throw std::invalid_argument("Incorrect path");
}

void LexicoTree::SyntaxicTree::addLetter(char letter) {
    node->addLetter(letter);
}

void LexicoTree::SyntaxicTree::addWord(const std::string& word) {
    if (wordIsValid(word)) {
        Node *currentNode = node;
        for (char letter: word) {
            currentNode->addLetter(letter);
            currentNode = currentNode -> getLetter(letter);
        }
        if (currentNode != nullptr)
            currentNode->setEow(true);
        ++wordsInTree;
    }
}

LexicoTree::SyntaxicTree::~SyntaxicTree() {
    delete node;
}

LexicoTree::Node *LexicoTree::SyntaxicTree::get(char letter) {
    return node->getLetter(letter);
}

char LexicoTree::SyntaxicTree::root() const {
    return node -> root();
}

bool LexicoTree::SyntaxicTree::wordExists(const std::string& word) const {
    Node* currentNode = node;
    for(char letter : word) {
        if (currentNode ->getLetter(letter) != nullptr)
            currentNode = currentNode ->getLetter(letter);
        else
            return false;
    }
    if (currentNode -> isEow())
        return true;
    return false;
}

bool LexicoTree::SyntaxicTree::wordIsValid(const std::string& word) {
    for(char letter : word) {
        if (!(letter >= 'a' && letter <= 'z'))
            return false;
    }
    return true;
}



unsigned int LexicoTree::SyntaxicTree::loadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (!file.eof()) {
            getline(file, line);
            ++wordsInDic;
            addWord(line);

        }
        file.close();
        return 1;
    }
    return 0;
}

std::vector<std::string> LexicoTree::SyntaxicTree::listAnswers(const std::string &word) const {
    std::vector<std::string> answers;
    unsigned int wordSize = word.size();

    //Itérer sur les lettres du mot
    //Cases :   ?bc
//              a?c
//              ab?
//              ??c
//              ?b?
//              a??
//              ???
}

std::vector<LexicoTree::Node*> LexicoTree::SyntaxicTree::getAllLetters() {
    return std::vector<Node *>();
}

//Useless, \r automatically removed
//void LexicoTree::SyntaxicTree::clearWord(std::string& word) {
//    word.erase(word.size() - 1);
//}


//std::ostream &LexicoTree::operator<<(std::ostream &ostream, LexicoTree::SyntaxicTree tree) {
//    ostream << "[" << tree.root() << std::endl;
//
//    ostream << "]" << std::endl;
//    return ostream;
//}
