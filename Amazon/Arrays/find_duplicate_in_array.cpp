/* APPROACH

-> 1. Floyd warshall Algo                ------- O(n) time, O(1) space
-> 2. Maths - blocks of size sqrt(n)     ------- O(n) time, O(sqrt(n)) space


*/

/* LESSON

-> Duplicates - floyd warshall Algo

*/

//Soolution - 1

int Solution::repeatedNumber(const vector<int> &A)
{

    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}

//Solution - 2

int Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int sq = sqrt(n);

    int max_blocks = n / sq + 1;        // max blocks for 1 to n range
    vector<int> block_freq(max_blocks); //count of elements in ith block

    for (int i = 0; i < n; i++)
    { //for all the array elts, to which block each elem. belongs to
        block_freq[(A[i] - 1) / sq]++;
    }

    int duplicate_block;
    //go through each block count, and see, which block has count > sq
    for (int i = 0; i < max_blocks; i++)
    {
        if (block_freq[i] > sq)
        {
            duplicate_block = i;
            break;
        }
    }

    //go through all array elements and store the count of only those elements whose block number is duplicate_block
    //Wohlaaa -----> O(sqrt(n)) space complexity

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int block = (A[i] - 1) / sq;
        if (block == duplicate_block)
        {
            mp[A[i]]++;
        }

        if (mp[A[i]] > 1)
        {
            return A[i];
        }
    }

    return -1;
}
