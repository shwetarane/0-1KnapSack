#include "BruteForce.h"
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

BruteForce::BruteForce()
{}

int BruteForce::Bruteforce(int size, int capacity, int weight[],
                           int profit[],  int maxValue)
{
    int i;
    int n = pow(2,size);
    int count=0;
    cout<<"All possible values are : "<<endl;

    for (i=0; i<n; i++)
    {
        string result = ToBin(i);
//        cout<<"result :"<<result<<endl;
        int number[size];
        int resultSize = result.length();
//        cout<<resultSize<<endl;

        for (int i = 0; i < size; i++)
        {
            if (i < resultSize)
            {
                number[i] = result[i] - '0';
            }
            else
            {
                number[i] = 0;
            }
        }

        int tempWeight = 0;
        int tempProfit = 0;

        for (int k = 1; k < size; k++)
        {
            if (number[k] == 1)
            {
//                cout<<number[k]<<endl;
                tempWeight = tempWeight + weight[k];
                tempProfit = tempProfit + profit[k];
            }
        }
        if (tempProfit > maxValue && tempWeight <= capacity)
        {
            maxValue = tempProfit;
            cout<<maxValue<< " ";
            count++;
        }
    }

    cout<<endl;
    cout<<"Total possible combinations : "<<count + 1<<endl;
    return maxValue;
}

string BruteForce::ToBin(int number)
{
    if ( number == 0 )
        return "0";
    if ( number == 1 )
        return "1";
    if ( number % 2 == 0 )
        return ToBin(number / 2) + "0";
    else
        return ToBin(number / 2) + "1";
}

BruteForce::~BruteForce()
{}
