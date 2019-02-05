// https://www.codechef.com/problems/CIELRCPT
#include <iostream>
#include <cmath>

int main(void) {
    int T;
    std::cin >> T;
    while (T--) {
        int p;
        std::cin >> p;
        int temp = p % 2048;
        int count = p/2048;
        while (temp != 0) {
            if (temp == 1) {
                count++;
                break;
            }
            // std::cout << temp << "->";
            int shift = std::log2(temp) - 1;
            temp -= 2 << shift;
            // std::cout << temp << "\n";
            count++;

            
        }
        std::cout << count << "\n";   

    }
}