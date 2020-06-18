/* APPROACH
-> If only 1 or 2 things are popped out, we have reduntant braces
*/

/* LESSON
*/

int Solution::braces(string A) {
    stack<char> st;
    
    int n = A.size();
    
    for(int i = 0; i < n; i++){
        if(A[i] != ')')
          st.push(A[i]);
        else
        {
            int cnt = 0;
            while(st.top() != '(')
            {   
                cnt++;
                st.pop();
            }
            st.pop();
            if( (cnt == 0 || cnt == 1)){
                return 1;
            }
        }
    }   
    return 0;
}
