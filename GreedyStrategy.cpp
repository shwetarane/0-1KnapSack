#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#include<iomanip>
#include "GreedyStrategy.h"
using namespace std;


GreedyStrategy::GreedyStrategy() {}

int GreedyStrategy::find (double array[], double &m, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(array[i] == m)
        {
            return i;
        }
    }
}

void GreedyStrategy::Greedy(int n, int weight[],
                            int profit[], int capacity)
{
    int subOptimal[capacity];
    int maxProfit = 0;
    int i;
    double *m;
    int pos;
    int track[capacity];
    double mult[capacity];

    double PW[n];
    // ------ Displaying input data ------------
    cout<<endl;
    cout << "Profits : ";
    for (int i = 0; i < n; ++i)
        cout << profit[i] << " ";

    cout<<endl;
    cout << "Weights : ";
    for (int i = 0; i < n; ++i)
        cout << weight[i] << " ";

    cout << "\nProfit/Weights : ";
    for (int i = 0; i < n; ++i)
    {
        PW[i] = ceil((double)profit[i]/weight[i]);
        cout <<PW[i] << " ";
    }

    // ------------------------------------------
    // stores the sub-optimal solution
    for ( i = 0; i < n; i++)
        subOptimal[i] = 0;

    // tracks the last maximum element in the array
    for ( i = 0; i < n; i++)
    {
        track[i] = 1;
        // cout<<"Track : "<<track[i]<<" ";
    }

    //stores the product of PW i.r the ratio and track
    for(int j = 0; j < n; j++)
    {
        mult[j] = PW[j]* track[j];
        // cout<<"MULT:  "<<mult[j]<<" ";
    }

    // -----------------------------------------

    for ( i = 0; i < n; i++)
    {
        //gets the maximum element
        m = max_element(mult, mult+n);
        //gets position of maximum element
        pos = find(mult, *m, n);
        //marks the position of maximum element 0
        track[pos] = 0;
        //marks for the chosen value
        subOptimal[pos] = 1;

        mult[pos] = mult[pos]*track[pos];

        maxProfit = maxProfit + profit[pos];
        //display the data
        cout<<endl;
        cout<<right<<"Position :"<<pos<<right<<setw(12);
        cout<<right<<"Profit["<<pos<<"] : "<<profit[pos]<<right<<setw(12);
        cout<<right<<"Weight["<<pos<<"] : "<<weight[pos]<<right<<endl;

        capacity = capacity - weight[i];

        if (weight[i] > capacity)
            break;
    }
//    if (i < n)
//        subOptimal[i] = capacity / weight[i];
    maxProfit = maxProfit + (subOptimal[pos] * profit[pos]);

    for(int j = 0; j < n; j++)
    {
        mult[j] = PW[j]* track[j];
    }
    cout<<endl;
    cout<<endl;
    cout<<"MAXIMUM PROFIT:"<<maxProfit<<endl;

    cout<<"Solution Subset(Sub-optimal Solution): ";
    for (int i = 0; i < n; i++)
        cout<<subOptimal[i]<<" ";
    cout<<endl;
}

GreedyStrategy::~GreedyStrategy() {}

