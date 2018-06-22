/* https://leetcode.com/problems/string-to-integer-atoi/description/ */

#define LIMIT 2147483648 // the absolute value of the inferior limit of the 4 bytes int data type

int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int myAtoi(char* str) {
	int i, j;
	long nr;
	int sign;
	int flag;

	i = 0;
	nr = 0;
	sign = 1;
	flag = 0;
	while (!is_digit(str[i]))
	{
		if ((str[i] < 14) && (str[i] > 8) || (str[i] == ' ')) 
			/* ignore the current element if is one of the following: '\n' , '\t' , '\r' , '\v' , '\f' , ' ') */
			i++;
		else if (((str[i] == '-') || (str[i] == '+')) && flag == 0 && (is_digit(str[i + 1])))
		{
			//set the sign variable
			sign = (str[i] == '-' ? -1 : 1);
			flag = 1;
			i++;
		}
		else
			return (0);
	}
	//get over existing 0
	while (str[i] == '0')
		i++;
	j = i;
	while (is_digit(str[i]))
	{		
		/*convert the string into an int, while keeping in mind the int data type limits*/
		if ((nr > LIMIT / 10) || ((nr == LIMIT / 10) && (str[i] > '7')) || (i - j + 1 > 10))
			return (sign == -1 ? (LIMIT * sign) : (LIMIT * sign - 1)); // return LIMIT * sign - 1 for the case when the input is 2147483648; because the 4 bytes int superior limit is 2147483648 - 1 = 2147483647
		nr = nr * 10 + str[i] - '0';
		i++;		
	}	
	return (nr * sign);
}