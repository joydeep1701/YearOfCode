#include <bits/stdc++.h>

int attack[101] = {0};
int defence[101] = {0};

int getNetAttack(int i, int n) {
    if (i == 0)
        return attack[1] + attack[n-1];
    if (i == n-1)
        return attack[i-1] + attack[0];
    return attack[i-1] + attack[i+1];
}

int main(void) {
    int T;
    std::cin >> T;
    while(T--) {
        int N;
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;
            attack[i] = temp;
        }
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;
            defence[i] = temp;
        }
        // int index = -1;
        int max_def = -1;

        for (int i=0; i < N; i++) {
            if (defence[i] > getNetAttack(i, N)) {
                if (max_def < defence[i]) {
                    max_def = defence[i];
                }
            }
        }
        std::cout << max_def << std::endl;
    }
}