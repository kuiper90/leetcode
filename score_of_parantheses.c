/* https://leetcode.com/problems/score-of-parentheses/description/ */

int scoreOfParentheses(char* S) {
    int depth;
    int bal;
    int i;
    
    depth = 0;
    bal = 0;
    i = 0;
    while (S[i] && S[i] != '\0')
    {
        if (S[i++] == '(')
        {
            if (S[i] == ')')
                depth += 1<<bal;
            bal++;
        }
        else
            bal--;
    }
    return (depth);
}