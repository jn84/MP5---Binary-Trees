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

    // Remove non-alphanumeric characters
    removePunctuation(workingText);

    for (int i = 0; i < workingText.length(); i++)
        workingText[i] = tolower(workingText[i]);

    while (!workingText.empty())
    {
        int spaceLoc = 0;

        // erase any leading spaces
        workingText.erase(0, workingText.find_first_not_of(' '));

        // insert the word token into the tree
        spaceLoc = workingText.find_first_of(' ');
        wordTokenTree.insert(workingText.substr(0, spaceLoc));

        // Remove the word token from the string
        workingText.erase(0, spaceLoc);
    }

    workingText = inputText;
    removePunctuation(workingText);
    for (int i = 0; i < workingText.length(); i++)
        workingText[i] = tolower(workingText[i]);
    int endIndex = 0, beginIndex = 0;
    while (endIndex != string::npos)
    {
        // get the  bounds of the word and insert the token into the tree
        beginIndex = workingText.find_first_not_of(' ', endIndex);
        endIndex = workingText.find_first_of(' ', beginIndex);
        wordTokenTree.insert(workingText.substr(beginIndex, endIndex - beginIndex));
    }

    wordTokenTree.inOrderTraversal();
    cout << endl << endl;
    wordTokenTree.postOrderTraversal();
    cout << endl << endl;

    system("pause");

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