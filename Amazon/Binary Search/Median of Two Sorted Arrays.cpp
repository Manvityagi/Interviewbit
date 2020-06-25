/* APPROACH

(1) Merge 2 sorted arrays - TLE
    Time Complexity - O(m+n)
    Space Complexity - O(m+n)

(2) Binary Search - AC
    Time Complexity - O(LOG(MIN(M,N)))
    Space Complexity - O(1)

*/

vector<int> merge(const vector<int> &A, const vector<int> &B)
{
    vector<int> ans;
    int p1 = 0, p2 = 0;
    int n1 = A.size(), n2 = B.size();
    while (p1 < n1 && p2 < n2)
    {
        if (A[p1] < B[p2])
        {
            ans.emplace_back(A[p1]);
            p1++;
        }
        else
        {
            ans.emplace_back(B[p2]);
            p2++;
        }
    }
    while (p1 < n1)
    {
        ans.emplace_back(A[p1]);
        p1++;
    }
    while (p2 < n2)
    {
        ans.emplace_back(B[p2]);
        p2++;
    }
    return ans;
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    double ans;
    vector<int> arr = merge(A, B);

    int n = arr.size();
    if (n & 1)
        ans = arr[n / 2];
    else
        ans = (arr[n / 2] + arr[n / 2 - 1]) / (2 * 1.0);

    return ans;
}


/////////////////////////BINARY SEARCH APPROACH///////////////////////////////////////

double Solution::findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2)
{

    int n1 = nums1.size(), n2 = nums2.size();
    //now nums1 is smaller array

    //doing binary search on the smaller array
    if (nums1.size() > nums2.size()) //swap nums1,nums2
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    // int n1 = nums1.size(), n2 = nums2.size();
    //now nums1 is smaller array

    int st = 0;
    int end = n1;
    int max_left_x, max_left_y, min_right_x, min_right_y;
    while (st <= end)
    {
        //partitionX + partitionY = (n1+n2+1)/2; bcz left half aur right half me equal elements honge
        int partitionX = st + (end - st) / 2;
        int partitionY = (n1 + n2 + 1) / 2 - partitionX;

        max_left_x = (partitionX - 1 >= 0 && partitionX - 1 < n1) ? nums1[partitionX - 1] : INT_MIN;
        max_left_y = (partitionY - 1 >= 0 && partitionY - 1 < n2) ? nums2[partitionY - 1] : INT_MIN;

        min_right_x = (partitionX >= 0 && partitionX < n1) ? nums1[partitionX] : INT_MAX;
        min_right_y = (partitionY >= 0 && partitionY < n2) ? nums2[partitionY] : INT_MAX;

        if (max_left_x <= min_right_y && min_right_x >= max_left_y)
        {
            if ((n1 + n2) & 1)
            {
                return (double(max(max_left_x, max_left_y)));
            }

            return double((max(max_left_x, max_left_y) + min(min_right_x, min_right_y))) / 2.0;
        }

        if (max_left_x > min_right_y)
        {
            end = partitionX - 1;
        }
        else
        {
            st = partitionX + 1;
        }
    }
    return -1;
}
