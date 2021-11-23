#include "algs.h"

int simpleStrStr(string master, string pattern) {
    if (argsCheckout(master, pattern)) {
        return ERROR_RET;
    }

    int subStart = 0, ptMaster = 0, ptPattern = 0;
    while (ptMaster < master.length() && ptPattern < pattern.length()) {
        if (master[ptMaster] == pattern[ptPattern]) {
            ptMaster++;
            ptPattern++;
        }else {
            subStart++;
            ptMaster = subStart;
            ptPattern = 0;
        }
    }
    if (ptPattern >= pattern.length()) {
        return subStart;
    }else {
        return ERROR_RET;
    }
}

int kmpStrStr(string master, string pattern) {
    if (argsCheckout(master, pattern)) {
        return ERROR_RET;
    }
    
    vector<int> next(pattern.length());
    next[0] = -1;
    int start = -1, index = 0;
    while (index < pattern.length()) {
        if (start == -1 || pattern[start] == pattern[index]) {
            start++;
            index++;
            next[index] = start;
        }else {
            start = next[start];
        }
    }
    vector<int> nextval(pattern.length());
    nextval[0] = -1;
    for (int i = 1; i < pattern.length(); i++) {
        if (pattern[i] == pattern[next[i]]) {
            nextval[i] = nextval[next[i]];
        }else {
            nextval[i] = next[i];
        }
    }

    int ptMaster = 0, ptPattern = 0;
    while (ptMaster < master.length() && ptPattern < int(pattern.length())) {
        if (ptPattern == -1 || master[ptMaster] == pattern[ptPattern]) {
            ptMaster++;
            ptPattern++;
        }else {
           ptPattern = nextval[ptPattern];
        }
    }
    if (ptPattern >= pattern.length()) {
        return ptMaster - pattern.length();
    }else {
        return ERROR_RET;
    }
}

int rbStrStr(string master, string pattern) {
    if (argsStrictCheckout(master, pattern)) {
        return ERROR_RET;
    }

    int winSize = pattern.length();
    long weight = 1;
    long mHash = 0, pHash = 0;
    for (int i = 0; i < winSize; i++) {
        mHash = (master[i] - CODE_OFFSET + mHash*CODE_NUM) % MODULUS;
        pHash = (pattern[i] - CODE_OFFSET + pHash*CODE_NUM) % MODULUS;
        weight = weight*CODE_NUM % MODULUS;
    }
    if (mHash == pHash) {
        return 0;
    }else {
        for (int i = 1; i < master.length()-winSize+1; i++) {
            mHash = (mHash*CODE_NUM - (master[i-1] - CODE_OFFSET)*weight 
                        + master[i+winSize-1] - CODE_OFFSET) % MODULUS;
            if (mHash == pHash) 
                return i;
        }
    }
    return ERROR_RET;
}

int hashTreeStrStr(string master, string pattern) {
    if (argsCheckout(master, pattern)) {
        return ERROR_RET;
    }
    
    return ERROR_RET;
}

int argsCheckout(string master, string pattern) {
    int len1 = master.length(), len2 = pattern.length();
    if (len1 >= len2 && len2 != 0) {
        return SUCCESS_RET;
    }else {
        return ERROR_RET;
    }
}

int argsStrictCheckout(string master, string pattern) {
    int len1 = master.length(), len2 = pattern.length();
    if (len1 >= len2 && len2 != 0) {
        for (int i = 0; i < len1; i++) {
            if (!isalpha(master[i])) 
                return ERROR_RET;
        }
        for (int i = 0; i < len2; i++) {
            if (!isalpha(pattern[i])) 
                return ERROR_RET;
        }
        return SUCCESS_RET;
    }else {
        return ERROR_RET;
    }
}