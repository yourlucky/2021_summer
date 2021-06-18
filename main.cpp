#include<iostream>
#include <fstream>
#include<vector>


using namespace std;

int main()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    char input[100] = { 0 };
    cin.getline(input, 100);

    std::vector<char> correct_a;


    int i = 0;
    char n;

    while (int(input[i]) != 0)
    {
        if (int(input[i]) >= 97 && int(input[i]) <= 122)
        {
            correct_a.push_back(input[i]);
        }

        if (int(input[i]) >= 65 && int(input[i]) <= 90)
        {
            n = input[i] + 32;
            correct_a.push_back(n);
        }
        i++;
    }

    for (auto i = correct_a.begin(); i != correct_a.end(); ++i)
    {
        std::cout << *i;
    }


    return 0;
}