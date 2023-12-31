#include <algorithm>
#include <array>
#include <random>
#include <iostream>

template<typename T, typename V>
T search(T first, T last, V v){

    while(first != last){

        if(*first == v){
            return first;
        }

        first++;
    }


    return last;
}

int main(){
    std::array<std::size_t, 100> A;

    std::mt19937 rg(std::random_device{}());

    std::uniform_int_distribution<std::size_t> uid(
        std::numeric_limits<std::size_t>::min(),
        std::numeric_limits<std::size_t>::max()
        );


    std::generate(A.begin(), A.end(), [&rg, &uid]{return uid(rg);});


    const auto u = A[std::uniform_int_distribution<std::size_t>(0, A.size() )(rg)];

    auto find = search(A.begin(), A.end(), u);


    std::cout << "u: " << u << (find == A.end() ? " not found\n" : " found\n");







    return 0;
}
