#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int thirtyseven()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int memory_size = 0, job_size = 0;
    cin >> memory_size >> job_size;

    vector<int> memory(memory_size, 0);
    int job;

    int checker = 0;
    for (int i = 0; i < job_size; i++)
    {
        cin >> job;
        checker = 0;

        for (int j = 0; j < memory_size; j++)
        {
            if (memory[j] == job)
            {
                checker++;
                for (int k = j; k > 0; k--)
                {
                    memory[k] = memory[k - 1];
                }
                memory[0] = job;
                break;
            }

        }

        if (checker == 0)
        {
            for (int k = memory_size - 1; k > 0; k--)
            {
                memory[k] = memory[k - 1];
            }
            memory[0] = job;
        }

        /*  cout << i << "번째 : " << endl;

          for (int ii : memory)
          {
              cout << ii << " ";
          }

          cout << endl;*/
    }

    for (int i : memory)
        cout << i << " ";



    return 0;
}

