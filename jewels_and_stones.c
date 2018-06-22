/* https://leetcode.com/problems/jewels-and-stones/description/ */

int numJewelsInStones(char* J, char* S) { 
    int count;
    int ind;
    int i;
    int len;
    
    i = 0;
    ind = 0;
    count = 0;
    if ((J[ind] == '\0') || S[i] == '\0')
        return (0);    
    while (J[ind] && J[ind] != '\0')
    {   
        i = 0;
        while (S[i] && S[i] != '\0')
        {
            if (S[i] == J[ind])                
                count++;  
            i++;
        }
        ind++;
    }
    return (count);
}