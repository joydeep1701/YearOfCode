#include <bits/stdc++.h>

int main(void) {
    int T;
    std::cin >> T;
    int N;
    char c;

    while(T--) {
        std::cin >> N;
        int N1 = N;
        int table[N][26] = {0};

        while(N--) {
            char s[201] = {0};
            std::scanf("%s", s);
            int i = 0;
            while(s[i]) {
                table[N][s[i] - 97] = 1;
                i++;
            }
        }
        int count = 0;
        for (int i=0; i< 26; i++) {
            int count1 = 0;
            for (int j=0; j<N1; j++) {
                count1 += table[j][i];
            }
            if (count1 >= N1)
                count++;
        }
        std::cout << count << std::endl;
    }
}