#ifndef _ALGS_H_
#define _ALGS_H_

#include <string>
#include <vector>
#include <cmath>

#define SUCCESS_RET 0
#define ERROR_RET -1

const unsigned int MODULUS = 0xffffffff;
const int CODE_NUM = 26;
const char CODE_OFFSET = 'a';

using namespace std;

int simpleStrStr(string master, string pattern);

int kmpStrStr(string master, string pattern);

int rbStrStr(string master, string pattern);

int hashTreeStrStr(string master, string pattern);

int argsCheckout(string master, string pattern);

int argsStrictCheckout(string master, string pattern);

#endif