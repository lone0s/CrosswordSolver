#include <iostream>
#include <fstream>
#include "Node.h"
#include "SyntaxicTree.h"
#include "Chrono.h"

using namespace LexicoTree;
using namespace std;
int main() {
//    Node test('a');
//    test.addLetter('a');
//    test.addLetter('b');
//    test.getLetter('a')->addLetter('c');
//    std::cout << "Root Node : " << test.root() << " | Fst son : " << test.getLetter('a')->root() << "Son : " << test.getLetter('a')->getLetter('c')-> root() << " | Second son : " << test.getLetter('b')->root() << std::endl;
//
    Chrono chrono;
    chrono.start();
    SyntaxicTree tree("../dico_FRUTF.txt");
    chrono.end();
    std::string wordExists = tree.wordExists("fritterons") ? "Existe" : "Existe pas";
    std::cout << chrono.howMuchTimePassed() << endl;
    std::cout << "Nb words added [" << tree.wordsInTree << "] on [" << tree.wordsInDic << "] words.\n" ;
    std::cout << "Mot fritterons : " << wordExists << endl;
}
