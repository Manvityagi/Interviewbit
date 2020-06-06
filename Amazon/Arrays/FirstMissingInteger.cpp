/* APPROACH

-> First => range - (smallest,largest) - see what is not present
Time: O(nlogn)
Space : O(1)
TLE

-> Second


*/

/* LESSON


*/

//Approach 1
int Solution::firstMissingPositive(vector<int> &A)
{
    int smallest = INT_MAX, largest = INT_MIN; //only positive
    for (auto a : A)
        if (a >= 0)
            smallest = min(a, smallest), largest = max(a, largest);

    if ((smallest != 1 && smallest != 0) || smallest == INT_MAX)
        return 1;

    for (int i = smallest; i <= largest; i++)
        if (find(A.begin(), A.end(), i) == A.end())
            return i;

    return largest + 1;
}

//Approach 2

int Solution::firstMissingPositive(vector<int> &A)
{
    int n = A.size();
    //ith index pe i+1 number hona chahiye

    //(A[i] <= n) number ko A[i]-1 index pe rakho
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
        {
            int idx = A[i] - 1;

            if (A[i] != A[idx])
            {
                swap(A[i], A[idx]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}
