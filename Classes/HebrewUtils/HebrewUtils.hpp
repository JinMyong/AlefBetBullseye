//
//  HebrewUtils.hpp
//  AlephBet
//
//  Created by Fredric on 12/16/15.
//
//

#ifndef HebrewUtils_hpp
#define HebrewUtils_hpp

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

enum LETTER_INDEXES {
    ALEPH_IDX,		// 0
    BET_IDX,		// 1
    VET_IDX,		// 2
    GIMMEL_IDX,		// 3
    DALET_IDX,		// 4
    HEY_IDX,		// 5
    VAV_IDX,		// 6
    ZAYIN_IDX,		// 7
    CHET_IDX,		// 8
    TET_IDX,		// 9
    YOD_IDX,		// 10
    KAF_IDX,		// 11
    KHAF_IDX,		// 12
    KHAF_SOFIT_IDX,	// 13
    LAMED_IDX,		// 14
    MEM_IDX,		// 15
    MEM_SOFIT_IDX,	// 16
    NUN_IDX,		// 17
    NUN_SOFIT_IDX,	// 18
    SAMEKH_IDX,		// 19
    AYIN_IDX,		// 20
    PEY_IDX,		// 21
    FEY_IDX,		// 22
    FEY_SOFIT,		// 23
    TSADE_IDX,		// 24
    TSADE_SOFIT_IDX,	// 25
    QOF_IDX,		// 26
    RESH_IDX,		// 27
    SHIN_IDX,		// 28
    SIN_IDX,		// 29
    TAV_IDX,		// 30,	// Last consanant
    
    BAH_1_IDX,		// 31, First vowel, bah 1
    BAH_2_IDX,		// 32
    BEE_1_IDX,		// 33
    BEE_2_IDX,		// 34
    BAY_1_IDX,		// 35
    BAY_2_IDX,		// 36
    BEH_IDX,		// 37
    BOH_1_IDX,		// 38
    BOH_2_IDX,		// 39
    BOO_1_IDX,		// 40
    BOO_2_IDX,		// 41
    B_SLNT_IDX,		// 42
    
    NUM_LETTERS_IDX
};

#define FIRST_CONSONANT_IDX	BAH_1_IDX
#define LAST_CONSONANT_IDX	TAV_IDX

class HebrewUtils
{
private:
    static HebrewUtils* instance;
    string letterNames[43];
    string letterFontKeyMap[43];
    CCArray* soundAlikes;
    
public:
    HebrewUtils();
    ~HebrewUtils();
    static  HebrewUtils*    getInstance();
    
    string   getLetterName(int index);
    string   getKeyMapFont(int index);
    int      getLetterIndex(string letterName);
    
    void     setupLetterFontKeyMap_Print();
    void     setupLetterFontKeyMap_Cursive();
    void     setupLetterNameArray();
    void     setupSoundAlikes();
    
    bool     isSoundaAlikesVowel(int scrLetter, int compareLetter);
    bool     isVowel(int scrLetter);
};

#endif /* HebrewUtils_hpp */
