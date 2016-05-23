//
//  HebrewUtils.cpp
//  AlephBet
//
//  Created by Fredric on 12/16/15.
//
//

#include "HebrewUtils.hpp"
#include "GameOptions.hpp"

HebrewUtils* HebrewUtils::instance = NULL;

HebrewUtils* HebrewUtils::getInstance()
{
    if (instance == NULL) {
        instance = new HebrewUtils();
    }
    return instance;
}

HebrewUtils::HebrewUtils()
{
    if (GameOptions::getInstance()->getFontType()) {
        setupLetterFontKeyMap_Print();
    }else
    {
        setupLetterFontKeyMap_Cursive();
    }
    
    setupLetterNameArray();
}

HebrewUtils::~HebrewUtils()
{
    
}

void HebrewUtils::setupLetterFontKeyMap_Print()
{
// Consonant
    letterFontKeyMap[0]  = "a";      // 0, alef
    letterFontKeyMap[1]  = "B";      // 1, bet
    letterFontKeyMap[2]  = "b";      // 2, vet
    letterFontKeyMap[3]  = "g";
    letterFontKeyMap[4]  = "d";
    letterFontKeyMap[5]  = "h";
    letterFontKeyMap[6]  = "w";
    letterFontKeyMap[7]  = "z";
    letterFontKeyMap[8]  = "x";
    letterFontKeyMap[9]  = "j";
    letterFontKeyMap[10] = "y";
    letterFontKeyMap[11] = "K";
    letterFontKeyMap[12] = "k";
    letterFontKeyMap[13] = "$";
    letterFontKeyMap[14] = "l";
    letterFontKeyMap[15] = "m";
    letterFontKeyMap[16] = "~";
    letterFontKeyMap[17] = "n";
    letterFontKeyMap[18] = "!";
    letterFontKeyMap[19] = "s";
    letterFontKeyMap[20] = "[";
    letterFontKeyMap[21] = "P";
    letterFontKeyMap[22] = "p";
    letterFontKeyMap[23] = "@";
    letterFontKeyMap[24] = "c";
    letterFontKeyMap[25] = "#";
    letterFontKeyMap[26] = "q";
    letterFontKeyMap[27] = "r";
    letterFontKeyMap[28] = "v";
    letterFontKeyMap[29] = "f";
    letterFontKeyMap[30] = "t";         // 30, tet
// Vowel
    letterFontKeyMap[31] = "B;";		// 31, Ba 1
    letterFontKeyMap[32] = "B'";		// 32, Ba 2
    letterFontKeyMap[33] = "yBi";		// 33, Bee 1
    letterFontKeyMap[34] = "Bi";		// 34, Bee 2
    letterFontKeyMap[35] = "yBe";		// 35, Bay 1
    letterFontKeyMap[36] = "Be";		// 36, Bay 2
    letterFontKeyMap[37] = "B,";		// 37, Beh
    letterFontKeyMap[38] = "AB";		// 38, Boh 1
    letterFontKeyMap[39] = "Bo";		// 39, Boh 2
    letterFontKeyMap[40] = "WB";		// 40 Boo 1
    letterFontKeyMap[41] = "Bu";		// 41 Boo 2
    letterFontKeyMap[42] = "B.";		// 42 b (silent)
}

void HebrewUtils::setupLetterFontKeyMap_Cursive()
{
// Consonant
    letterFontKeyMap[0]  = "a";         // 0, alef
    letterFontKeyMap[1]  = "b<";        // 1, bet
    letterFontKeyMap[2]  = "b";         // 2, vet
    letterFontKeyMap[3]  = "g";         // gimmel
    letterFontKeyMap[4]  = "d";         // dalet
    letterFontKeyMap[5]  = "h";         // hey
    letterFontKeyMap[6]  = "v";         // vav
    letterFontKeyMap[7]  = "z";         // zayin
    letterFontKeyMap[8]  = "c";
    letterFontKeyMap[9]  = "e";
    letterFontKeyMap[10] = "y";
    letterFontKeyMap[11] = "k<";
    letterFontKeyMap[12] = "k";
    letterFontKeyMap[13] = "K";
    letterFontKeyMap[14] = "l";
    letterFontKeyMap[15] = "m";
    letterFontKeyMap[16] = "M";
    letterFontKeyMap[17] = "n";
    letterFontKeyMap[18] = "N";
    letterFontKeyMap[19] = "s";
    letterFontKeyMap[20] = "i";
    letterFontKeyMap[21] = "pf";
    letterFontKeyMap[22] = "p";
    letterFontKeyMap[23] = "P";
    letterFontKeyMap[24] = "x";
    letterFontKeyMap[25] = "X";
    letterFontKeyMap[26] = "q";
    letterFontKeyMap[27] = "r";
    letterFontKeyMap[28] = "D";
    letterFontKeyMap[29] = "S";
    letterFontKeyMap[30] = "t";         // 30 tav
// Vowel
    letterFontKeyMap[31] = "b<-";		// 31 Ba 1
    letterFontKeyMap[32] = "b<=";		// 32 Ba 2
    letterFontKeyMap[33] = "yb<1";      // 33 Bee 1
    letterFontKeyMap[34] = "b<1";		// 34 Bee 2
    letterFontKeyMap[35] = "yb<2";		// 35 Bay 1
    letterFontKeyMap[36] = "b<2";		// 36 Bay 2
    letterFontKeyMap[37] = "b<3";		// 37 Beh
    letterFontKeyMap[38] = "ob<";		// 38 Boh 1
    letterFontKeyMap[39] = "Ob<<";		// 39 Boh 2
    letterFontKeyMap[40] = "Vb<";		// 40 Boo 1
    letterFontKeyMap[41] = "b<5";		// 41 Boo 2
    letterFontKeyMap[42] = "b<4";		// 42 b (silent)
}

void HebrewUtils::setupLetterNameArray()
{
    letterNames[0] =  "alef";
    letterNames[1] =  "bet";
    letterNames[2] =  "vet";
    letterNames[3] =  "gimmel";
    letterNames[4] =  "dalet";
    letterNames[5] =  "hey";
    letterNames[6] =  "vav";
    letterNames[7] =  "zayin";
    letterNames[8] =  "chet";
    letterNames[9] =  "tet";
    letterNames[10] = "yud";
    letterNames[11] = "kaf";
    letterNames[12] = "chaf";
    letterNames[13] = "chaf sofit";
    letterNames[14] = "lamed";
    letterNames[15] = "mem";
    letterNames[16] = "mem sofit";
    letterNames[17] = "nun";
    letterNames[18] = "nun sofit";
    letterNames[19] = "samech";
    letterNames[20] = "ayin";
    letterNames[21] = "pey";
    letterNames[22] = "fey";
    letterNames[23] = "fey sofit";
    letterNames[24] = "tsadi";
    letterNames[25] = "tsadi sofit";
    letterNames[26] = "kuf";
    letterNames[27] = "resh";
    letterNames[28] = "shin";
    letterNames[29] = "sin";
    letterNames[30] = "tav";		// Last letter
    letterNames[31] = "bah";		// First vowel, bah 1
    letterNames[32] = "bah";		// bah 2
    letterNames[33] = "bee";		// bee 1
    letterNames[34] = "bee";		// bee 2
    letterNames[35] = "bay";		// bay 1
    letterNames[36] = "bay";		// bay 2
    letterNames[37] = "beh";
    letterNames[38] = "boh";		// boh 1
    letterNames[39] = "boh";		// boh 2
    letterNames[40] = "boo";		// boo 1
    letterNames[41] = "boo";		// boo 2
    letterNames[42] = "b (silent)";
}

bool HebrewUtils::isSoundaAlikesVowel(int scrLetter, int compareLetter)
{
    CCLog("HebrewUtils::isSoundaAlikesVowel >>>>> %s", letterNames[scrLetter].c_str());
    CCLog("HebrewUtils::isSoundaAlikesVowel >>>>> %s", letterNames[compareLetter].c_str());
    if (letterNames[scrLetter].compare(letterNames[compareLetter]) == 0) {
        CCLog("HebrewUtils::isSoundaAlikesVowel >>>>> True");
    }else
    {
        CCLog("HebrewUtils::isSoundaAlikesVowel >>>>> False");
    }
    return letterNames[scrLetter].compare(letterNames[compareLetter]) == 0;
}

bool HebrewUtils::isVowel(int scrLetter)
{
    bool isVowel = false;
    if (scrLetter >= FIRST_CONSONANT_IDX) {
        isVowel = true;
    }
    return isVowel;
}

string HebrewUtils::getLetterName(int index)
{
    string letterName;
    if (index < (sizeof(letterNames) / sizeof(letterNames[0]))) {
        letterName = letterNames[index];
    }else
    {
        letterName = "Not Found";
    }
    
    return letterName;
}

int HebrewUtils::getLetterIndex(string letterName)
{
    int index = 100000;
    for (int i = 0 ; i < (sizeof(letterNames) / sizeof(letterNames[0])); i++) {
        if (letterNames[i].compare(letterName)) {
            index = i;
        }
    }
    return index;
}

string HebrewUtils::getKeyMapFont(int index)
{
    string keyMap;
    int sz = sizeof(letterFontKeyMap) / sizeof(letterFontKeyMap[0]);
    if (index < sz) {
        keyMap = letterFontKeyMap[index];
    }else
    {
        keyMap = "Not Found";
    }
    
    return keyMap;
}