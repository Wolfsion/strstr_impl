#include <iostream>
#include <string>
#include "./include/algs.h"

using namespace std;

int main() {
    string parent = "goolegooglogooglegoo";
    string pattern = "google";
    cout << rbStrStr(parent, pattern) << endl;
    system("pause"); 
    return 0;
}