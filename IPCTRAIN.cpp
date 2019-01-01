// https://www.codechef.com/JULY17/problems/IPCTRAIN
#include <iostream>
#include <queue>
#include <vector>


class Trainer {
    public:
        int d;
        int t;
        int s;
        Trainer(int d, int t, int s) {
            this->d = d;
            this->t = t;
            this->s = s;
        }
        void decrement();
};
void Trainer::decrement() {
    this->t--;
}
class CompareDate {
    public: bool operator() (Trainer t1, Trainer t2) {
        return t1.d > t2.d; 
    }
};
class CompareSadness {
    public: bool operator() (Trainer t1, Trainer t2) {
        return t1.s < t2.s;
    }
};

int main(void) {
    int T;
    int d,t,s;
    std::cin >> T;
    while (T--) {
        int N,D;
        std::priority_queue<Trainer, std::vector<Trainer>, CompareDate> pqd;
        std::priority_queue<Trainer, std::vector<Trainer>, CompareSadness> pqs;

        std::cin >> N;
        std::cin >> D;
        for (int i=0; i < N; i++) {

            std::cin >> d;
            std::cin >> t;
            std::cin >> s;
            pqd.push(Trainer(d,t,s));
        }
        for (int d = 1; d <= D; d++) {
            // std::cout << "d_iter: " << d << "\n";
            while (!pqd.empty() && pqd.top().d == d) {
                // std::cout << pqd.empty() << "\n";
                Trainer temp = pqd.top();
                // std::cout << "d: " << temp.d << " t:"<< temp.t << " s:" << temp.s << "\n";
                pqs.push(temp);
                pqd.pop();
            }
            if (!pqs.empty()) {
                Trainer temp = pqs.top();
                // std::cout << "Popped from pqs, d: " << temp.d << " t:"<< temp.t << " s:" << temp.s << "\n";
                pqs.pop();
                if (temp.t > 1) {
                    temp.decrement();
                    pqs.push(temp);
                }
            }
            
        }
        long long int total_sadness = 0;
        // Remaining stuff
        while (!pqs.empty()) {
            Trainer temp = pqs.top();
            pqs.pop();
            total_sadness += (long long int) temp.t * temp.s;
        }
        std::cout << total_sadness << "\n";
    }
}