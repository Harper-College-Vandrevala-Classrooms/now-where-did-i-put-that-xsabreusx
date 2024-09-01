/*
Name: Humberto
Lab: Now Where Did I Put That
Info: Searches for the position of either a substring or a character within a given string.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findWhere (string, char);
int findWhere (string, string);

int main()
{
string myString = "The quick brown fox"; //test string

cout << "\n\nDriver is running..." << endl;
cout << "Performing searches in the following string: " << endl;
cout << "\"" << myString << "\""<< endl;

cout << "\nIndex of 'e' returns: " << findWhere(myString, 'e') << endl;
cout << "Index of \"e\" returns: " << findWhere(myString, string("e")) << endl;
cout << "Index of ',' returns: " << findWhere(myString, ',') << endl;
cout << "Index of \"quick\" returns: " << findWhere(myString, "quick") << endl;
cout << "Index of \"quiet\" returns: " << findWhere(myString, "quiet") << endl;
cout << "Index of \"brown\" returns: " << findWhere(myString, "brown") << endl;
cout << "Index of \"fox\" returns: " << findWhere(myString, "fox") << endl;
cout << "Index of \"fo\" returns: " << findWhere(myString, "fo") << endl;
//testing emtpy string
cout << "Testing an empty string returns:" << findWhere(myString, "") << endl;

cout << "\nChecks completed. Good bye!\n\n"; //message indicating end of program

return 0;

}
//searches for characters
int findWhere (string mystring, char findc)
{
    for (int i = 0; i < mystring.size(); ++i) {
        if (mystring[i] == findc) {
            return i; //return the index of the found character
        }
    }
    return -1; //character not found

}
//second version of the function where it searches for a substring that matches part of the main string
int findWhere (string mystring, string mysubstring)
{
    if (mysubstring.empty()) return -1; //in case of empty string

    for (int i = 0; i <= mystring.size() - mysubstring.size(); ++i)
    {
        bool found = true;
        for (int j = 0; j < mysubstring.size(); ++j) 
        {
            if (mystring[i + j] != mysubstring[j]) //comparing the contents of the substring within the string,
            {
                found = false;
                break;
            }
        }
        if (found) return i; //return the starting index of the substring
    }

    return -1; //substring not found

}
