/* APPROACH

-> Only Maths


*/

/* LESSON
-> 1 to n numbers range --> Actually think around sum or sum of squares
-> OVERFLOW - Typecasting

*/

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    long long int n = A.size();
    long long int expectedSumofN = ((n) * (n + 1)) / 2;
    long long int expectedSumofSqN = (n * (n + 1) * (2 * n + 1)) / 6;

    long long int actualSumofN = 0, actualSumOfSqN = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        actualSumofN += (long long int)A[i];
        temp = (long long int)A[i] * (long long int)A[i];
        actualSumOfSqN += (long long int)temp;
    }

    long long int diffN = expectedSumofN - actualSumofN;
    long long int diffSqN = expectedSumofSqN - actualSumOfSqN;

    long long int missingNumber = ((diffSqN / diffN) + diffN) / 2;
    long long int repeatingNumber = missingNumber - diffN;

    return {repeatingNumber, missingNumber};
}
