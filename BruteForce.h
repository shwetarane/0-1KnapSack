#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <string>
#include <iostream>
using namespace std;

static string s="";

class BruteForce
{
public:
    BruteForce();
    int Bruteforce( int, int, int[], int[], int);
    string ToBin(int);
    string to_string(int);
    virtual ~BruteForce();
protected:

private:
};

#endif // BRUTEFORCE_H
