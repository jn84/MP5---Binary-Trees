//////////////////////////////////////////////////////////////////////////
//       Name: Jeremy Nims
// Assignment: Binary Trees Homework #10
//      Class: CPS 272, Wed 5:30
//////////////////////////////////////////////////////////////////////////

#include <string>
#include "BST.h"

using namespace std;

const string punctChars = ".,;:()\"'\\/!@#$%^&*{}[]|<>?+=_";

void removePunctuation(string& text);

void main()
{
    string inputText = "";
    BST<string> wordTokenTree;

    cout << "Enter a sentence: ";
    getline(cin, inputText);

    removePunctuation(inputText);

    // make all lower case
    for (int i = 0; i <  inputText.length(); i++)
        inputText[i] = tolower(inputText[i]);

    int wEnd = 0, wBegin = 0;
    while (wEnd != string::npos)
    {
        // get the bounds of the word and insert the token into the tree
        wBegin = inputText.find_first_not_of(' ', wEnd);
        wEnd = inputText.find_first_of(' ', wBegin);
        wordTokenTree.insert(inputText.substr(wBegin, wEnd - wBegin));
    }
    cout << "\n\nInOrder:\n";
    wordTokenTree.inOrderTraversal();
    cout << "\n\nPostOrder:\n";
    wordTokenTree.postOrderTraversal();
    cout << endl << endl;
}

void removePunctuation(string& text)
{
    string::iterator sit = text.begin();
    while (sit != text.end())
    {
        punctChars.find(*sit) != string::npos ?
            sit = text.erase(sit) :
            sit++;
    }
}