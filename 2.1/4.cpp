#include <algorithm>
#include <array>
#include <random>
#include <iostream>


template<typename T, std::size_t N, std::size_t NC>
void add(const std::array<T,N> &a,const std::array<T,N> &b, std::array<T,NC> &c){


    std::size_t carry = 0;

    for(std::size_t i = N; i != 0; --i){
        c[i+1] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry)/2;
    }

    c[0] = carry;
}


int main(){
    constexpr const std::size_t n = 10;

    std::array<std::size_t, n> A;
    std::array<std::size_t, n> B;
    std::array<std::size_t, n+1> C;
    C.fill(0);


    std::mt19937 rg(std::random_device{}());



    std::generate(A.begin(), A.end(), [&rg, bd = std::bernoulli_distribution(0.5)]()mutable{return bd(rg);});
    std::generate(B.begin(), B.end(), [&rg, bd = std::bernoulli_distribution(0.5)]()mutable{return bd(rg);});


    std::cout << ' ';
    for(auto i : A){
        std::cout << i;
    }

    std::cout << "\n ";

    for(auto i : B){
        std::cout << i;
    }

    add(A,B,C);

    std::cout << '\n';
    for(auto i : C){
        std::cout << i;
    }




    std::cout << '\n';

}
