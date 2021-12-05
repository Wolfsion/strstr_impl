// simple()
int strStr(string haystack, string needle) {
    int len1 = haystack.length(), len2 = needle.length();
    if (len2 == 0)
        return 0;
    if (len1 >= len2)
    {
        int subStart = 0, ptMaster = 0, ptPattern = 0;
        while (ptMaster < haystack.length() && ptPattern < needle.length())
        {
            if (haystack[ptMaster] == needle[ptPattern])
            {
                ptMaster++;
                ptPattern++;
            }
            else
            {
                subStart++;
                ptMaster = subStart;
                ptPattern = 0;
            }
        }
        if (ptPattern >= needle.length())
        {
            return subStart;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

//kmp()
int strStr(string haystack, string needle) {
    int len1 = haystack.length(), len2 = needle.length();
    if (len2 == 0)
        return 0;
    if (len1 >= len2)
    {
        vector<int> next(needle.length());
        next[0] = -1;
        int start = -1, index = 0;
        while (index < needle.length() - 1)
        {
            if (start == -1)
            {
                start++;
                index++;
                next[index] = start;
            }
            else if (needle[start] == needle[index])
            {
                start++;
                index++;
                next[index] = start;
            }
            else
            {
                start = next[start];
            }
        }
        vector<int> nextval(needle.length());
        nextval[0] = -1;
        for (int i = 1; i < needle.length(); i++)
        {
            if (needle[i] == needle[next[i]])
            {
                nextval[i] = nextval[next[i]];
            }
            else
            {
                nextval[i] = next[i];
            }
        }

        int ptMaster = 0, ptPattern = 0;
        while (ptMaster < haystack.length() && ptPattern < int(needle.length()))
        {
            if (ptPattern == -1)
            {
                ptMaster++;
                ptPattern++;
            }
            else if (haystack[ptMaster] == needle[ptPattern])
            {
                ptMaster++;
                ptPattern++;
            }
            else
            {
                ptPattern = nextval[ptPattern];
            }
        }
        if (ptPattern >= needle.length())
        {
            return ptMaster - needle.length();
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

//rb
int strStr(string haystack, string needle){
    const unsigned int MODULUS = 0xffffffff;
    const int CODE_NUM = 26;
    const char CODE_OFFSET = 'a';
    int winSize = needle.length();
    long weight = 1;
    long mHash = 0, pHash = 0;
    for (int i = 0; i < winSize; i++)
    {
        mHash = (haystack[i] - CODE_OFFSET + mHash * CODE_NUM) % MODULUS;
        pHash = (needle[i] - CODE_OFFSET + pHash * CODE_NUM) % MODULUS;
        weight = weight * CODE_NUM % MODULUS;
    }
    if (mHash == pHash)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i < haystack.length() - winSize + 1; i++)
        {
            mHash = (mHash * CODE_NUM - (haystack[i - 1] - CODE_OFFSET) * weight + haystack[i + winSize - 1] - CODE_OFFSET) % MODULUS;
            if (mHash == pHash)
                return i;
        }
    }
    return -1;
}

def trietree()
{
    const unsigned int MODULUS = 0xffffffff;
    const int CODE_NUM = 26;
    const char CODE_OFFSET = 'a';
    int winSize = needle.length();
    long weight = 1;
    long mHash = 0, pHash = 0;

    vector<int> candicate;
    for (int i = 0; i < haystack.length() - winSize + 1; i++) {
        if (haystack[i] == needle[0]) {
            candicate.push_back(i);
        }
    }

    for (int i = 0; i < winSize; i++)
    {
        mHash = (haystack[i] - CODE_OFFSET + mHash * CODE_NUM) % MODULUS;
        pHash = (needle[i] - CODE_OFFSET + pHash * CODE_NUM) % MODULUS;
        weight = weight * CODE_NUM % MODULUS;
    }
    if (mHash == pHash)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i < haystack.length() - winSize + 1; i++)
        {
            mHash = (mHash * CODE_NUM - (haystack[i - 1] - CODE_OFFSET) * weight + haystack[i + winSize - 1] - CODE_OFFSET) % MODULUS;
            if (mHash == pHash)
                return i;
        }
    }
    return -1;
}