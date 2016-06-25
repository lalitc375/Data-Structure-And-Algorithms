#include<bits/stdc++.h>
using namespace std;
struct job
{
    int id;
    int profit;
    int deadline;
};

bool compare(struct job job1,struct job job2)
{
    return job1.profit>job2.profit;
}

