int strStr(string haystack, string needle) {
    const char *res = strstr(haystack.c_str(), needle.c_str());

    if (res)
        return haystack.find(needle, 0);
    return -1;

}