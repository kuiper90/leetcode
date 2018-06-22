/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ */

int removeDuplicates(int* nums, int numsSize) {
    int i;
    int j;
    int *nr;
    int count;
        
    i = 0; 
    count = 0;
    nr = nums;
	/*iterate through the array and compare each element with the previous ones*/
    while (i < numsSize)
    {
        j = 0;
		/*start from the beginning of the array and check if the current element was already found*/
        while (j < count)
        {
            if (nums[i] == nr[j])
                break;
            j++;
        }
		/*if the current element was not found, add it to the result array - that contains no duplicates*/
        if (j == count)
        {
            nr[count] = nums[i];
            count++;
        }
       i++;    
    }    
    return (count);
}
