/* https://leetcode.com/problems/longest-valid-parentheses/description/ */

int maxValue(int nr1, int nr2)
{
    if (nr1 > nr2)
        return (nr1);
    return (nr2);
}

int longestValidParentheses(char* s) {
    int i;
    int j;
    int count;
    int stack[999999];
    
    i = 0;
    stack[0] = -1;
    j = 1;
    count = 0;
    while (s[i])
    {
		//push the index of  '(' elements to stack
        if (s[i] == '(')
            stack[j++] = i;
        else
        {
			//if stack is not empty, check if the length of the current valid substring > maxValue so far
            if (--j != 0)
                count = maxValue(count, i - stack[j - 1]);
            else
                stack[j++] = i;            
        }
        i++;    
    }
    return (count);
}