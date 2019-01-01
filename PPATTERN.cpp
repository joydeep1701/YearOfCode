#include <iostream>

int main(int argc, char const *argv[])
{
    int t, n;
    int arr[101][101] = {0};

    std::cin >> t;
    for (; t > 0; t--) {
        std::cin >> n;

        int base_column = 0;
        int base_row = 0;
        int r = 0;
        int c = base_column;
        // 00 01 10 02 11 20 03 12 21 30
        for (int i=1; i <= n*n; i++) {
            // std::cout << r << "," << c << " " << i << "\n";
            arr[r][c] = i;

            if (c != 0 && r < n-1) {
                r++;
                c--;
            } else {
                if (base_column < n-1)
                    base_column++;
                else 
                    base_row++;                   
                
                r =  base_row;
                c = base_column;
                
            }
            

        }
        for (r = 0; r < n; r++) {
            for (c = 0; c < n; c++) {
                std::cout << arr[r][c];

                if (c != n-1) {
                    std::cout << " ";
                } else {
                    std::cout << "\n";
                }
            }
        }

    }
    


    return 0;
}
