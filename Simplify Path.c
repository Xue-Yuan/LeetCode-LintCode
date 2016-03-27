char* simplifyPath(char* path) {
    if (!path) return strdup("/");
    int len = strlen(path);
    char* ret = (char*)malloc(len + 2);
    if (ret) {
        int ch;
        int skips = 0;
        char* p = ret + len + 1;
        char* q = path + len - 1;
        *p-- = '\0';
        while ((q >= path) && ((ch = *q--) == '/'));
        while (q >= path) {
            char* lastDir = q + 1;
            if (ch == '.') {
                int t = 0;
                while ((ch = *q--) == '.') t++;
                if ((ch == '/') && (t <= 1)) {
                    skips += t;
                    while ((q >= path) && ((ch = *q--) == '/'));
                    continue;
                }
            }
            if (--skips < 0) {
                skips = 0;
                while (*lastDir != '/') *p-- = *lastDir--;
                q = lastDir;
                *p-- = '/';
            } else {
                while (*q != '/') q--;
            }
            while ((q >= path) && ((ch = *q--) == '/'));
        }
        if (p[1] != '/') {
            *p = '/';
        } else {
            p++;
        }

        if (p > ret) {
            memmove(ret, p, (ret - p) + len + 2);
            path = realloc(ret, (ret - p) + len + 2);
            if (path) ret = path;
        }
    }
    return ret;
}
