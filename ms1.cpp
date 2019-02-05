#include <iostream>
#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    /* code */
    int input1 = 5;
    int input2[] = {1,4,5,4,5};
    
    std::sort(input2, input2+input1);
    
    for (int i=0; i < input1; i++) {
        std::cout << input2[i] << "\n";
    }
    int cmp = input2[0];

    for (int i = 1; i < input1; i++) {
        if (input2[i] <= input2[i-1]) {
            input2[i] = input2[i-1] + 1;
        }
    }
    for (int i=0; i < input1; i++) {
        std::cout << input2[i] << "\n";
    }


    return 0;
}