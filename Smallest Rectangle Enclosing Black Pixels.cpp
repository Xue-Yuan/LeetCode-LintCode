/*
    An image is represented by a binary matrix with 0 as a white pixel and 1 as 
        a black pixel. The black pixels are connected, i.e., there is only one 
        black region. Pixels are connected horizontally and vertically. Given 
        the location (x, y) of one of the black pixels, return the area of the 
        smallest (axis-aligned) rectangle that encloses all black pixels.

    For example, given the following image:

    [
      "0010",
      "0110",
      "0100"
    ]
    and x = 0, y = 2,
    Return 6.
*/

//intuitive dfs solution
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) 
    {
        if (image.empty() || image[0].empty()) return 0;
        
        r = (int)image.size(), c = (int)image[0].size();
        minX = r, maxX = 0; 
        minY = c, maxY = 0;
        
        dfs(image, x, y);
        
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
private:
    void dfs(vector<vector<char>> &image, int x, int y)
    {
        if (x<0 || x>= r || y<0 || y>=c || image[x][y] == '0')
            return;
        
        image[x][y] = '0';
        minX = min(minX, x), maxX = max(maxX, x);
        minY = min(minY, y), maxY = max(maxY, y);
        
        dfs(image, x+1, y);
        dfs(image, x-1, y);
        dfs(image, x, y+1);
        dfs(image, x, y-1);
    }
private:
    int minX, maxX, minY, maxY;
    int r, c;
};
