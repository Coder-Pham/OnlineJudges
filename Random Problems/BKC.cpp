/**
 * Author:  Pham Trong Nhan
 * Date:    
**/

/**
 * Có 1 dãy các thùng chứa nằm liên tiếp nhau lần lượt có dung tích là B1, B2,..
 * Công ty muốn lựa ra 3 thùng chứa có tổng dung tích lớn nhất để trữ 
 * sao cho không có 2 thùng chứa nào đứng liên tiếp được chọn.
 * Input:
 * 8
 * 2 4 5 3 5 9 4 2
 * Output: 16
 * 
 * Input: 8
 * 1 2 5 5 8 9 8 2
**/

/**
 * SOLUTION: Dynamic programming
 * Result table: a[i][j] - Biggest sum when choose i number from first j number 
 *      0   1   2   3   4   5   6   7   8
 * 0    0   0   0   0   0   0   0   0   0   
 * 1    0   1   2   5   5   8   9   9   9
 * 2    0   0   0   6   7   13  14  16  16
 * 3    0   0   0   0   0   14  16  21  21
 * ///////////////////////////////////
 * a[i][j] = a[i][j-1] or s[j-1] + a[i-1][j-2]
 * if i = 1, a[1][j] = a[i][j-1] or s[j-1]
**/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> s;

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        s.push_back(temp);
    }

    std::vector<std::vector<int>> arr(4);
    for (auto &&line : arr)
    {
        line.resize(n + 1, 0);
    }

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < n + 1; j++)
            if (i == 1)
            {
                arr[i][j] = (arr[i][j - 1] > s[j - 1]) ? arr[i][j - 1] : s[j - 1];
            }
            else if (j >= (i * 2 - 1))
            {
                arr[i][j] = (arr[i][j - 1] > (s[j - 1] + arr[i - 1][j - 2])) ? arr[i][j - 1] : (s[j - 1] + arr[i - 1][j - 2]);
            }
    }

    std::cout << arr[3][n];
    return 0;
}
