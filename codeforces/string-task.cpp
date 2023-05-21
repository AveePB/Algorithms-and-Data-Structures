#include <bits/stdc++.h>

using namespace std; 

vector<char> vowels{'a', 'o', 'y', 'e', 'u', 'i'}; 
string phrase{}; 


void transform_letter(char& letter){
    for(char vowel: vowels){
        if (vowel == letter)
            return; 
    }

    cout << "." << letter;
}

int main(){ 
    cin >> phrase; 

    transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower); 

    for(char letter: phrase){
        transform_letter(letter); 
    }


    return 0; 
}
