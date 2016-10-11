//// Stefan Retief
//// CS211 LAB 12-1, HW7
//// dictionary Client
//// ======================================================
//
//#include <iostream>
//#include <fstream>
//#include "LL_T.hpp"
//using namespace std;
//
//void buildLL(LL<string>& q);
//void removeBadWords(LL<string>& q);
//void outputToFile(LL<string>& q);
//
//int main() {
//    LL<string> words;
//    
//    buildLL(words);         //make the LL for the words
//    removeBadWords(words);  //Remove the bad words
//    outputToFile(words);    //output words to files
//}
//
//void buildLL(LL<string>& q) {
//    ifstream input;     //open essay.txt to read the words
//    input.open("essay.txt");
//    
//    string word;
//    
//    if (!input) {       //make sure we find the files
//        cout << "ERROR: File not found." << endl;
//    }
//    else {          //else, start importing the words
//        while (input) {
//            input >> word;
//            //make all the words lowercase and make sure they're all letters
//            for (int i = 0; i < word.length(); i++) {
//                word[i] = tolower(word[i]);
//                if (!isalpha(word[i])) {
//                    word.erase(i);
//                }
//            }       //check if the word already exists in the list
//            if (!q.search(word)) {
//                q.addInOrderAscend(word);   //add the word if it doesn't
//            }
//        }
//    }
//    input.close();      //close the import file
//}
//
//void removeBadWords(LL<string>& q) {
//    ifstream input;     //open the bad words file
//    input.open("bad.txt");
//    
//    string word;
//    
//    if (!input) {   //make sure we have the file
//        cout << "ERROR: File not found." << endl;
//    }
//    else {      //delete the words that are bad
//        while (input) {
//            input >> word;
//            q.deleteNode(word);
//        }
//    }
//    input.close();  //close the file
//}
//
//void outputToFile(LL<string>& q) {
//    ofstream output;    //open the output files
//    
//    string s = q.deleteFront(); //get the first words
//    string fileName = "./dictionary/?.txt";
//    fileName[13] = toupper(s[0]);   //set the file name to the first letter of the word
//    output.open(fileName.c_str());  //open said file
//    
//    while (!q.isEmpty()) {  //until the LL isn't empty, export
//        if (toupper(s[0]) != fileName[13]) {    //if the letters don't match
//            output.close();         //close the file
//            fileName[13] = toupper(s[0]);   //and open a new one with the correct letter
//            output.open(fileName.c_str());
//        }
//        output << s << endl;
//        s = q.deleteFront();    //keep getting words
//    }
//    output.close();     //close the files
//}