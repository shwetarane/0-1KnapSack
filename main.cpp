#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>
#include "Dynamic.h"
#include "GreedyStrategy.h"
#include "BruteForce.h"
#include "GreedyTrial.h"
using namespace std;

int main()
{
    //creating objects for each class
    Dynamic dp;
    GreedyStrategy gs;
    BruteForce bf;

    // ======================= BRUTEFORCE APPROACH DRIVER ======================
    //input from:  https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_01/knapsack_01.html
    //is a set of 15 weights and profits for a knapsack of capacity 750,
    // from Kreher and Stinson, with an optimal profit of 1458.

//    int profit[] = {135,139,149,150,156,163,173,184,192,201,
//                     210,214,221,229,240,135,139,149,150,156,
//                     163,173,184,192,201,210,214,221,229,240,
//                    };
//    int weight[] = {70,73,77,80,82,87,90,94,98,106,110,113,
//                     115,118,120,70,73,77,80,82,87,90,94,98,
//                     106,110,113,115,118,120
//
//};

    int SIZE = 15;
    int profit[SIZE];
    int weight[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        profit[i] =  rand() % 500 + 1;
//        cout<<profit[i]<<" " ;
    }
    for(int i = 0; i < SIZE; i++)
    {
        weight[i] = rand() % 200 + 1;
    }

    int  capacity = 1200;
    int initialProfit=0;
//    int SIZE = 15;
//    int capacity = 750;
//    int profit[] = {135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};
//    int weight[] = {70,73,77,80,82,87,90,94,98,106,110,113,115,118,120};
    cout<<" ------------------------------------------------------- " <<endl;
    cout<<"|    0-1 KnapSack Problem implemented as BruteForce,     |"<<endl;
    cout<<"|    Greedy Strategy and Dynamic Programming             |"<<endl;
    cout<<" ------------------------------------------------------- " <<endl;


    cout<<"------- Brute Force -------- "<<endl;

    //Recording the time required by the algorithm referred from
    //http://www.gnu.org/software/libc/manual/html_node/CPU-Time.html
    clock_t startBF, endBF;
    startBF=clock();
    int result = bf.Bruteforce (SIZE,capacity,weight, profit, initialProfit);
    endBF=clock();

    cout<<"Profit(Maximum):"<<result<<endl;
    cout<<"Time taken by BruteForce Approach: "<<
        (double)(endBF-startBF)/CLOCKS_PER_SEC<<" seconds";
    cout<<endl<<endl;


    //  ===========DYNAMIC APPROACH DRIVER  ====================

    int SIZE1 = 50;
    int profit1[SIZE1];
    int weight1[SIZE1];
    for(int i = 0; i < SIZE1; i++)
    {
        profit1[i] =  rand() % 1000 + 1;
//        cout<<profit[i]<<" " ;
    }
    for(int i = 0; i < SIZE1; i++)
    {
        weight1[i] = rand() % 300 + 1;
    }
    int  capacity1 = 1500;


    cout<<"------- Dynamic Programming Approach ------- "<<endl;

    clock_t startDP, endDP;
    startDP = clock();
    cout << "Profit (Maximum): "
         << dp.DynamicKnapsack(SIZE1, capacity1, weight1, profit1) << endl;
    endDP = clock();
    cout<<"Time taken by Dynamic Approach : "<<
        (double)(endDP-startDP)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;


    //  ========= GREEDY STRATEGY DRIVER ==============
    cout<<"------- Greedy Algorithm ---------- ";

    clock_t startGA, endGA;
    startGA =clock();
    gs.Greedy(SIZE1, weight1, profit1, capacity1);
    endGA=clock();
    cout<<"Time taken by Greedy Algorithm: "<<
        (double)(endGA-startGA)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;


    return 0;
}
