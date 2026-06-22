
#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>





using namespace std;


class clsString {
private:
    string _Vaule;




public:
    clsString() {
        _Vaule = "";

    }


    clsString(string Vaule) {
        _Vaule = Vaule;
    }


    void SetVaule(string Vaule) {
        _Vaule = Vaule;
    }
    string GetVaule() {
        return _Vaule;
    }

    __declspec(property(get = GetVaule, put = SetVaule)) string Vaule;



    static short Length(string S1) {
        return S1.length();

    }

    short Length() {
        return _Vaule.length();

    }

    static short CountWords(string S) {

        short counter = 0;
        string delimter = " ";
        string StorWord;
        size_t pos = 0;

        while ((pos = S.find(delimter)) != std::string::npos) {

            StorWord = S.substr(0, pos);

            if (StorWord != "") {
                counter++;
            }
            S.erase(0, pos + delimter.length());

        }
        if (S != "") {
            counter++;

        }
        return counter;
    }

    short CountWords() {
        return CountWords(_Vaule);
    }



    static string UpperFirstLetterOfEachWord(string S) {
        bool FirstLetter = true;

        for (short i = 0; i < S.length(); i++) {
            if (S[i] != ' ' && FirstLetter) {

                S[i] = toupper(S[i]);
            }
            FirstLetter = (S[i] == ' ' ? true : false);
        }
        return S;
    }

    void UpperFirstLetterOfEachWord() {
        _Vaule = UpperFirstLetterOfEachWord(_Vaule);
    }

    static string LowerFirstLetterOfEachWord(string S) {
        bool FirstLetter = true;

        for (short i = 0; i < S.length(); i++) {
            if (S[i] != ' ' && FirstLetter) {

                S[i] = tolower(S[i]);
            }
            FirstLetter = (S[i] == ' ' ? true : false);
        }
        return S;
    }

    void LowerFirstLetterOfEachWord() {
        _Vaule = LowerFirstLetterOfEachWord(_Vaule);
    }


    static string UpperAllString(string S) {
        for (short i = 0; i < S.length(); i++) {

            S[i] = toupper(S[i]);
        }
        return S;
    }

    void UpperAllString() {
        _Vaule = UpperAllString(_Vaule);
    }

    static string LowerAllString(string S) {
        for (short i = 0; i < S.length(); i++) {

            S[i] = tolower(S[i]);
        }
        return S;
    }

    void LowerAllString() {
        _Vaule = LowerAllString(_Vaule);
    }




    static char InvertLetter(char Letter) {
        return isupper(Letter) ? tolower(Letter) : toupper(Letter);
    }


    static string InvertAllLettersCase(string S) {

        for (short i = 0; i < S.length(); i++)
            S[i] = InvertLetter(S[i]);
        return S;
    }

    void InvertLetterCase() {
        _Vaule = InvertAllLettersCase(_Vaule);
    }

    enum enWhatToCount { SmallLetters = 0, CaptialLetters = 1, All = 2 };

    static short CountLetters(string S, enWhatToCount WhatToCount = enWhatToCount::All) {
        short Counter = 0;

        if (WhatToCount == enWhatToCount::All) {
            return S.length();
        }


        for (short i = 0; i < S.length(); i++) {
            if ((WhatToCount == CaptialLetters && isupper(S[i])) ||
                (WhatToCount == SmallLetters && islower(S[i])))
                Counter++;
        }
        return Counter;
    }


    static short CountCaptialLetters(string S) {
        short counter = 0;

        for (short i = 0; i < S.length(); i++)
            if (isupper(S[i])) {
                counter++;

            }

        return counter;
    }


    short CountCaptialLetters() {
        return CountCaptialLetters(_Vaule);
    }

    static short CountSmallLetters(string S) {
        short counter = 0;

        for (short i = 0; i < S.length(); i++)
            if (islower(S[i])) {
                counter++;

            }

        return counter;
    }


    short CountSmallLetters() {
        return CountSmallLetters(_Vaule);
    }


    static short CountSpecificLetter(string S, char C, bool MatchCase = true) {
        short Counter = 0;
        for (size_t i = 0; i < S.length(); i++) {
            if (MatchCase) {
                if (S[i] == C) Counter++;
            }
            else {
                if (tolower(S[i]) == tolower(C)) Counter++;
            }
        }
        return Counter;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true) {
        return CountSpecificLetter(_Vaule, Letter, MatchCase);
    }


    static bool IsVowelLetter(char L) {
        L = tolower(L);
        return (L == 'a' || L == 'e' || L == 'i' || L == 'o' || L == 'u');
    }


    static short CountVowelsLetter(string S) {
        short counter = 0;
        for (short i = 0; i < S.length(); i++)
            if (IsVowelLetter(S[i]))
                counter++;
        return counter;
    }

    short CountVowelsLetter() {
        return CountVowelsLetter(_Vaule);
    }



    static vector<string>  Split(string S1, string delimter) {

        vector <string> vString;

        int pos = 0;

        string sWord;

        while ((pos = S1.find(delimter)) != std::string::npos) {

            sWord = S1.substr(0, pos);

            if (sWord != "") {
                vString.push_back(sWord);

            }
            S1.erase(0, pos + delimter.length());
        }

        if (S1 != "") {
            vString.push_back(S1);
        }
        return vString;
    }


    vector <string > Split(string Delim) {
        return Split(_Vaule, Delim);
    }


    static string TrimLeft(string S) {
        for (size_t i = 0; i < S.length(); i++)
            if (S[i] != ' ') return S.substr(i);
        return "";
    }

    void TrimLeft() {
        _Vaule = TrimLeft(_Vaule);
    }

    static string TrimRight(string S) {
        for (int i = S.length() - 1; i >= 0; i--)
            if (S[i] != ' ') return S.substr(0, i + 1);
        return "";
    }

    void TrimRight() {
        _Vaule = TrimRight(_Vaule);
    }


    static string Trim(string S) {
        return TrimLeft(TrimRight(S));
    }

    void Trim() {
        _Vaule = Trim(_Vaule);
    }


    static string JoinString(vector<string> vJoin, string delimter) {

        string S = "";

        for (string& v : vJoin) {

            S += v + delimter;
        }

        return S.substr(0, S.length() - delimter.length());

    }

    static string JoinString(string arrString[], short Lenght, string delimter) {
        string S = "";

        for (int i = 0; i < Lenght; i++) {
            S += arrString[i] + delimter;
        }

        return S.substr(0, S.length() - delimter.length());
    }




    static string ReversedWordInString(string S) {
        vector<string> v = Split(S, " ");
        string S2 = "";
        vector<string>::iterator iter = v.end();
        while (iter != v.begin()) {
            --iter;
            S2 += *iter + " ";
        }
        return S2.substr(0, S2.length() - 1);
    }

    void ReversedWordInString() {
        _Vaule = ReversedWordInString(_Vaule);
    }

    static string ReplaceWords(string S, string ReplaceWord, string ReplaceTo, bool MatchCase = true) {
        vector<string> vString = Split(S, " ");
        for (string& v : vString) {
            if (MatchCase) {
                if (v == ReplaceWord) v = ReplaceTo;
            }
            else {
                if ((v) == LowerAllString(ReplaceWord)) v = ReplaceTo;
            }
        }
        return JoinString(vString, " ");
    }


    string ReplaceWords(string ReplaceWord, string ReplaceTo) {
        return ReplaceWords(_Vaule, ReplaceWord, ReplaceTo);
    }


    static string RemovePuncFromString(string S) {

        string S2 = "";
        for (short i = 0; i < S.length(); i++)
            if (!ispunct(S[i])) S2 += S[i];
        return S2;
    }

    void RemovePuncFromString() {
        _Vaule = RemovePuncFromString(_Vaule);
    }



};



