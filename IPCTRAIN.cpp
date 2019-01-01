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
            while (pqd.empty() || pqd.top().d == d) {
                Trainer temp = pqd.top();
                std::cout << temp.d << " " << temp.s << "\n";
                pqs.push(temp);
                pqd.pop();
            }
            Trainer temp = pqs.top();
            std::cout << "Popped pqs" << temp.d << "\n" ;
            pqs.pop();
            temp.decrement();
            if (temp.t > 1) {
                pqs.push(temp);
            }
        }
    }
}