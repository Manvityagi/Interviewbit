/* APPROACH

(1) Use a map & keep subtracting numbers -- Works only for < 4000
(2) Generalised method for any number

*/

/*-----------------------------------APPROACH - 1 ---------------------------------------------------------*/
string Solution::intToRoman(int A)
{
    vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans;
    int i = 0;
    while (A > 0)
    {
        while (i < 13 && A >= values[i])
        {
            ans += romans[i];
            A -= values[i];
        }
        i++;
    }
    return ans;
}

/*-----------------------------------APPROACH - 2 ---------------------------------------------------------*/
string something(int n, char a, char b, char c)
{
    cout << n << " " << a << " " << b << " " << c << "\n";
    string ans = "";
    if (n <= 3)
    {
        for (int i = 0; i < n; ++i)
            ans += a;
        return ans;
    }
    if (n == 4)
    {
        ans += b;
        ans += a;
        return ans;
    }
    if (n < 9)
    {
        for (int i = 5; i < n; ++i)
            ans += a;
        ans += b;
        return ans;
    }
    if (n == 9)
    {
        ans += c;
        ans += a;
        return ans;
    }
    return ans;
}
string intToRoman(int num)
{
    string abc = "IVXLCDM    ";
    int i = 0;
    string ans = "";
    while (num)
    {
        cout << num << " " << num % 10 << "\n";
        ans += something(num % 10, abc[i], abc[i + 1], abc[i + 2]);
        num /= 10;
        i += 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}