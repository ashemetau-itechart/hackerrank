//
//  strings_func_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetau on 17/05/2024.
//

#include "strings_func_ex.hpp"
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <map>

using namespace std;


string superReducedString(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (result.empty()) {
            result += s[i];
        } else {
            if (result[result.length() -1] == s[i]) {
                result.pop_back();
            } else {
                result += s[i];
            }
        }
    }
    return result.empty() ? "Empty String" : result;
}

void superReducedString_ex(){
    cout << "superReducedString_ex\n";
    string input = "aaabccddd";
    string expected = "abd";
    string calculated = superReducedString(input);
    string result = calculated == expected ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

int camelcase(string s) {
    int count = 0;
    if (!s.empty()) {
        count ++;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < 'a') {
                count++;
            }
        }
    }
    return count;
}

void camelcase_ex() {
    cout << "camelcase_ex\n";
    string input = "saveChangesInTheEditor";
    int expected = 5;
    int calculated = camelcase(input);
    string result = calculated == expected ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

int strongPassword(int n, string password) {
    string specialStr = "!@#$%^&*()-+";
    set<char> specialSet(specialStr.begin(), specialStr.end());
    
    bool hasNumbers = false;
    bool hasSpecial = false;
    bool hasLower = false;
    bool hasUpper = false;
    int requiredSymbols = 4;
    
    int i = 0;
    while (!(i == password.length() || (i > 6 && requiredSymbols == 0))) {
        if (password[i] >= 'a' && password[i] <= 'z' && !hasLower){
            hasLower = true;
            requiredSymbols --;
        } else if (password[i] >= 'A' && password[i] <= 'Z' && !hasUpper){
            hasUpper = true;
            requiredSymbols --;
        } else if (password[i] >= '0' && password[i] <= '9' && !hasNumbers){
            hasNumbers = true;
            requiredSymbols --;
        } else if (specialSet.count(password[i]) > 0 && !hasSpecial){
            hasSpecial = true;
            requiredSymbols --;
        }
        i++;
    }
    int result = max((int)(6-password.length()), requiredSymbols);
    return result;
}

void strongPassword_ex() {
    cout << "strongPassword_ex\n";
    string input = "#HackerRank";
    int expected = 1;
    int calculated = strongPassword((int)input.length(), input);
    string result = calculated == expected ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

bool canConstruct(string ransomNote, string magazine) {
    if (magazine.length() < ransomNote.length()) return false;
    int result = 0;
    vector<int> letters('z' - 'a' + 1, 0);
    for (int i=0; i<magazine.length(); i++){
        char lm = magazine[i];
        int ilm = lm - 'a';
        letters[ilm] = letters[ilm] + 1;
        if (letters[ilm] == 0) result++;
        if (i < ransomNote.length()) {
            char lr = ransomNote[i];
            int ilr = lr - 'a';
            letters[ilr] = letters[ilr] - 1;
            if (letters[ilr] == -1) result--;
        }
    }
    return result >= 0;
}

void canConstruct_ex(){
    cout << "canConstruct_ex\n";
    string ransomNote = "aa";
    string magazine = "ab";
    bool result = canConstruct(ransomNote, magazine);
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

/*
 https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150
 
Isomorphic Strings
 Given two strings s and t, determine if they are isomorphic.
 Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
 Input: s = "paper", t = "title"
 Output: true
 
 */

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    map<char, char> ms;
    map<char, char> mt;
    for (int i=0; i<s.size(); i++){
        char cs = s[i];
        char ct = t[i];
        if (ms.contains(cs)) {
            if (ms[cs] != ct) return false;
        } else {
            ms[cs] = ct;
        }
        if (mt.contains(ct)) {
            if (mt[ct] != cs) return false;
        } else {
            mt[ct] = cs;
        }
    }
    return true;
}

void isIsomorphic_ex() {
    cout << "isIsomorphic_ex\n";
    string s = "paper";
    string t = "title";
    bool result = isIsomorphic(s, t);
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}


/*
 https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150
 
125 Valid palindrome
 A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 Given a string s, return true if it is a palindrome, or false otherwise.

 Example 1:

 Input: s = "A man, a plan, a canal: Panama"
 Output: true
 Explanation: "amanaplanacanalpanama" is a palindrome.
 
 */

bool isPalindrome(string s) {
    char *b = &s[0];
    char *e = &s[s.length()-1];
    while (b < e) {
        char bv = *b;
        char ev = *e;
        if(!isalnum(bv)){b++; continue;}
        if(!isalnum(ev)){e--;continue;}
        if(tolower(bv)!=tolower(ev)) {
            return false;
        } else {
            b++;
            e--;
        }
    }
    return true;
}

void isPalindrome_ex() {
    cout << "isPalindrome_ex\n";
    string s = "A man, a plan, a canal: Panama";
//    string s = "  ";
//    string s = "0P";
    bool result = isPalindrome(s);
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}
