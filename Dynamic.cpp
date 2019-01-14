#include "Dynamic.h"


Dynamic::Dynamic()
{}

Dynamic::~Dynamic()
{}

int Dynamic::DynamicKnapsack( int n, int capacity, int weight[],
                              int profit[])
{
    //Two dimensional array to store the results
    int knapSack[n+1][capacity+1];

    //populate the matrix with profit table
    //number of items
    for(int i = 1; i <=n; i++)
    {
        //weight of the items
        for(int w = 0; w <= capacity; w++)
        {
            //initialize the first row and column to zero
            if(i == 0 || w == 0)
            {
                knapSack[i][w] = 0;
            }
            else if(weight[i-1] >  w)
            {
                knapSack[i][w] = knapSack[i-1][w];
            }
            else
            {
                knapSack[i][w] = maxProfit(knapSack[i-1][w],
                                           profit[i-1] +knapSack[i-1][w-weight[i-1]] );
            }
        }
    }
    int result = knapSack[n][capacity];
    return result;
}
int Dynamic::maxProfit(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

