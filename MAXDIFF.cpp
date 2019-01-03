#include<bits/stdc++.h>


int arr[100002] = {0};


int main(void) {
    int T;
    std::cin >> T;
    while (T--) {
        int N, K, temp;
        std::cin >> N;
        std::cin >> K;
        long sum = 0;
        // int arr[N] = {0};
        for (int i=0; i < N; i++) {
            std::cin >> temp;
            arr[i] = temp;
            arr[i+1]=0;
            sum += temp;
        }
        std::sort(arr, arr+N);
        // std::cout << "SORT" <<std::endl;
        long subsum = 0;
        if (K > (N-K)) {
            K = N-K;
        }
        for (int i=0; i < K; i++) {
            subsum += arr[i];
            // std::cout << arr[i] << " ";
        }
        std::cout << (sum - 2* subsum) << "\n";
    }
}
