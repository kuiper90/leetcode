/* https://leetcode.com/problems/integer-to-roman/description/ */

int strLength(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void myBzero(void *s, size_t n)
{
	size_t i;
	char *s_char;

	i = 0;
	s_char = s;
	while (i < n)
	{
		s_char[i] = 0;
		i++;
	}
}

void myStrcat(char *dest, const char *src)
{
	int i;
	int size;

	i = 0;
	size = strLength(dest);
	while (src[i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i];
}

char* intToRoman(int num) {
	
	/*the elements in the input[] and the roman_nr arrays must correspond*/
	int input[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };	
	char *roman_nr[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	
	char *output;
	int i;

	i = 0;
	if (!(output = (char *)malloc(sizeof(char) * 20)))
		return (0);
		/* myBzero function places 20 zero-valued bytes in the area pointed to by output. Without myBzero, the following testcase fails:
				Input: 88
				Output: "LXXXVIII\""
				Expected: "LXXXVIII" */
	myBzero(output, 20);
	/*while num!=0 subtract the largest roman numeral from it and add it to the final string output*/
	while (num)
	{
		while (num / input[i])
		{
			myStrcat(output, roman_nr[i]);
			num -= input[i];
		}
		i++;
	}
	return (output);
}