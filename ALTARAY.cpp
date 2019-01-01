// https://www.codechef.com/problems/ALTARAY
#include <iostream>

int M[100001];
int arr[100001] = {0};

int calc_len(int i, int n) {
   // Check memory
   if (M[i] > 0) {
       return M[i];
   }
   // Base case
   if (i+1 == n) { // End of input
       return 1;
   }
   if (arr[i] * arr[i+1] > 0) {
       // Signs are same
       return 1;
   } else {
       // signs are diffenent
       int temp = 1 + calc_len(i+1, n);
       M[i] = temp;
       return temp;
   }
}

int main(int argc, char const *argv[])
{
    int T;
    int N;
    int temp;

    std::cin >> T;
    while (T--) {
        std::cin >> N;        
        for (int i = 0; i < N; i++) {
            std::cin >> temp;
            if (temp < 0)
                arr[i] = -1;
            else
                arr[i] = 1;
            arr[i+1] = 0;
            M[i] = -1;
        }
        for (int i = 0; i < N; i++) {
            // std::cout << i << " " << calc_len(i, N) << std::endl;;
            std::cout << calc_len(i,N);
            if (i + 1 == N)
                std::cout << "\n";
            else
                std::cout << " ";
        }
    }
    return 0;
}
