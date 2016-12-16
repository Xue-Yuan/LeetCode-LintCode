// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int rd = 0;
        while (rd < n) {
            if (beg < end) {
                *(buf+rd++) = tmp[beg++];
            } else {
                if ((end = read4(tmp)) == 0) {
                    break;    
                }
                beg = 0;
            }
        }
        return rd;
    }
private:
    char tmp[4];
    int beg = 0, end = 0;
};
