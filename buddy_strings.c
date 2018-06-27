/* https://leetcode.com/problems/buddy-strings/description/ */
/* typedef enum {false = 0, true = 1} bool; */

int str_length(char *str)
{
	int count;

	count = 0;
	while (str[count] && str[count] != '\0')
		count++;
	return (count);
}

char *myBzero(int n)
{
	int i;
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

bool buddyStrings(char* A, char* B) {
	int i;	
	int lenA;
	int lenB;
	int count;
	char *str;
	int map[32] = { 0 };
		
	lenA = str_length(A);
	lenB = str_length(B);
	if (lenA != lenB)
		return (false);
	if (lenA > 20000 || lenA == 0)
		return (false);
	i = 0;	
	count = 0;
	str = myBzero(2);
	while (i < lenA)
	{
		if (A[i] != B[i] && count < 2)		
		{
			if (count == 2)
				return (false);
			str[count++] = i;
			if (count == 2 && (A[str[0]] != B[str[1]] || A[str[1]] != B[str[0]]))
				return (false);			
		}
		i++;
	}
	if (count == 1)
		return (false);
	if (count == 0)
	{
		i = 0;
		while (i < lenA)
		{
			map[A[i] - 'a']++;			
			if (map[A[i] - 'a'] == 2)		
			/* if (++map[A[i] - 'a'] == 2)	*/			
				return (true);
			i++;
		}
		return (false);
	}
	return (true);
}