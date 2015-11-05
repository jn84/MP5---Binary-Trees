#include <string>
#include "BST.h"

using namespace std;

const string punctChars = ".,;:()\"'\\/!@#$%^&*{}[]|<>?+=_";

void removePunctuation(string& text);

void main()
{
    string inputText = "", workingText = "";
    BST<string> wordTokenTree;

    cout << "Enter a sentence: ";
    getline(cin, inputText);
    workingText = inputText;
    removePunctuation(workingText);

    for (int i = 0; i < workingText.length(); i++)
        workingText[i] = tolower(workingText[i]);

    while (!workingText.empty())
    {
         int spaceLoc = 0;

         // erase any leading spaces
         workingText.erase(0, workingText.find_first_not_of(' '));

         spaceLoc = workingText.find_first_of(' ');
         // insert the word token into the tree
         wordTokenTree.insert(workingText.substr(0, spaceLoc));

         // Remove the word token from the string
         workingText.erase(0, spaceLoc);
     }

     wordTokenTree.inOrderTraversal();
     cout << endl << endl;
     wordTokenTree.postOrderTraversal();
     cout << endl << endl;
     wordTokenTree.preOrderTraversal();
     cout << endl << endl;

    system("pause");

}

void removePunctuation(string& text)
{
    string::iterator sit = text.begin();
    while (sit != text.end())
    {
        if (punctChars.find(*sit) != string::npos)
            sit = text.erase(sit);
        else
            sit++;
    }
}

// I like, big; butts663##^^^#3?? and>< I cannot LI)(!E:::