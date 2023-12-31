#include <algorithm>
#include <array>
#include <iomanip>
#include <random>
#include <iostream>

template<typename T>
void reverse_insertion_sort(T first, T last){


    for(auto j = first + 1; j != last; ++j){
        const auto key = *j;

        auto i = j - 1;

        while(i > (first-1) && *i < key){
            *(i+1) = *i;
            i--;
        }

        *(i+1) = key;

    }




}

template<typename A, std::size_t T>
void reverse_insertion_sort(std::array<A,T>&v){


    for(std::size_t j = 1; j != v.size(); ++j){
        const auto key = v[j];

        std::size_t i = j - 1;

        while(i < std::numeric_limits<std::size_t>::max() && v[i] < key){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;


    }




}



int main(){
    std::array<std::size_t, 10> A;
    std::array<std::size_t, 10> B;


    std::mt19937 rg(std::random_device{}());

    std::uniform_int_distribution<std::size_t> uid(
        std::numeric_limits<std::size_t>::min(),
        100
        );


    std::generate(A.begin(), A.end(), [&rg, &uid]{return uid(rg);});

    B = A;

    std::cout << "original array:  ";
    for(auto it = A.begin() ; it != A.end(); ++it){
        std::cout << *it;

        if(it + 1 != A.end()){
            std::cout << ' ';
        }else{
            std::cout << '\n';
        }

    }

    reverse_insertion_sort(B.begin(),B.end());
    reverse_insertion_sort(A);



    std::cout << "sort array: " << std::setw(7);
    for(auto it = A.begin() ; it != A.end(); ++it){
        std::cout << *it;

        if(it + 1 != A.end()){
            std::cout << ' ';
        }else{
            std::cout << '\n';
        }

    }

    std::cout << "sort iter array: ";
    for(auto it = B.begin() ; it != B.end(); ++it){
        std::cout << *it;

        if(it + 1 != B.end()){
            std::cout << ' ';
        }else{
            std::cout << '\n';
        }

    }




    return 0;
}
