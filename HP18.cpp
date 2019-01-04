// https://www.codechef.com/JAN19B/problems/HP18
#include <iostream>

int arr[200007];

void winBob(bool won) {
    if (won)
        std::cout << "BOB" << "\n";
    else
        std::cout << "ALICE" << "\n";
}

int main(void) {
    int T;
    std::cin >> T;
    while (T--) {
        int N, a, b;
        int temp;
        std::cin >> N >> a >> b;
        for (int i = 0; i < N; i++) {
            std::cin >> temp;
            arr[i] = temp;
            arr[i+1] = 0;
        }
        int div_bob = 0;
        int div_alice = 0;
        int div_ba = 0;
        // Count bob items
        for (int i=0; i < N; i++) {
            // std::cout << arr[i] << "\n";
            if (arr[i] % a == 0) {
                div_bob++;
                arr[i] = -1*arr[i]; // Mark as visited
            }
        }
        for (int i=0; i < N; i++) {
            // std::cout << arr[i] << "\n";

            if (arr[i] % b == 0) {
                if (arr[i] < 0) {
                    div_ba++;
                } else {
                    div_alice++;
                }
                
            }
        }
        // std::cout << div_bob << " " << div_alice << "\n";

        //   If Alice has some elements left Alice removes them
        //      If Bob still has some elements, bob wins
        //      Else Alice win
        //   Else Bob wins
        // if (a==b) {
        //     // If a==b bob removes everything, wins the round
        //     winBob(true);
        //     continue;
        // } else {
        // Turn: 1 : Bob
        if (div_bob <= 0) {
            // bob has none
            // alice wins
            winBob(false);
            continue;
        }
        if (div_ba > 0) {
            // If there are common elements 
            // bob removes them first
            // Optimal for bob
            div_bob -= div_ba;
        } else {
            div_bob--;
        }
        // Turn 2: Alice
        if (div_alice <= 0) {
            // After the commons are removed, 
            // Alice has zero => bob wins
            winBob(true);
            continue;

        }
        // }
        // So presently alice has not zero elems
        // If alice has more she wins
        if (div_alice > div_bob) {
            winBob(false);
            continue;
        } else {
            winBob(true);
            continue;
        }


    }
}