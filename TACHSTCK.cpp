#include <iostream>
#include <algorithm>
#include <array>
#include <functional>

std::array<int, 100001> chopsticks = {0};

// return index of farthest chopstick. -1 if none
int find_pair(int start, int end, int l, int d) {
    if (start > end) {
        return -1;
    }
    int mid = (end-start)/2 + start;
    if (l - d > chopsticks[mid]) {
        // Nothing acceptable found
        // search left
        return find_pair(start, mid-1, l, d);
    } else if (l - d == chopsticks[mid]) {
        // check this
        // Extreme fit
        return mid;
    } else {
        // check right
        // Buffer current result, 
        // if nothing better is found return current
        int temp = find_pair(mid + 1, end, l, d);
        if (temp == -1)
            return mid;
        return temp;
    }
    // Check if current value is bigger than l-d
    return -1;
}

int main(int argc, char const *argv[])
{
    int N,D, temp;
    int pair_count = 0;
    std::cin >> N >> D;
    for (int i=0; i < N; i++) {
        std::cin >> temp;
        chopsticks[i] = temp;
    }
    std::sort(chopsticks.begin(), chopsticks.end(), std::greater<int>());
    for (int i=0; i < N-1; i++) {
        // for (int j=0; j < N; j++) {
        //     std::cout << chopsticks[j] << " ";
        // }
        // std::cout << "\n";
        // int pair_index = find_pair(i, N-1, chopsticks[i], D);
        // if (pair_index > i) {
        //     // std::cout << chopsticks[i] << " pair: " << chopsticks[pair_index] << " index: " << pair_index << "\n";

        //     // shift items
        //     for (int j=pair_index; j < N; j++) {
        //         chopsticks[j] = chopsticks[j+1];
        //     }
        //     N--;
        //     pair_count++;
        // }
        if (chopsticks[i] - chopsticks[i+1] <= D) {
            pair_count++;
            i++;
        }
    }
    std::cout << pair_count << "\n";

    return 0;
}

