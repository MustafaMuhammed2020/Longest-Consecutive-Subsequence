/*************************************************************************/
/* Author    : Mustafa Mohammed Abdo                                     */
/* Date      : 29 Mar 2023                                               */
/* Version   : V01                                                       */
/* Hint      : Get The Longest Consecutive Subsequence                   */
/*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS


#include<stdio.h>

#include"Sorting.h"

/*
1. Test Case 1
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1]  size : 10 
- Print the LCS size

2. Test Case 2
- Ask the user to enter array elements
- Press Enter without entering any element

3. Test Case 3
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12]  size : 12

4. Test Case 4
- Ask the user to enter array elements
- Enter the following elements
- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]   size : 10
- Print the LCS size

5. Test Case 5
- Ask the user to enter array elements
- Enter the following elements
- [2, 8, 4, 10, 6, 20, 16, 12, 14, 16]  : 10

*/

int main(void)
{

	sint32_t  Arr[10] = { 0 } ; /* ARRAY FOR TESTING */
	
	uint8_t LCS = 0 , Localiterator = 0 , Arrsize = 10 , endstatus = 0  ;

	sint8_t state = 0 , LCSstatus = 0 ; /* HOLDS THE STATE OF THE FUNCTION AFTER CALLING */
	
	printf("Enter THe Size Of Array\n"); /* PROMPT FOR ARRAY SIZE */
	scanf("%d", &Arrsize);
	{
		if (Arrsize < 10)
		{
			/* DO NOTHING */
		}
	}

	for (Localiterator = 0; Localiterator < Arrsize; Localiterator++)
	{
		printf("Enter element number %d\n", Localiterator + 1);
		scanf("%d", &Arr[Localiterator]);
	}
	
	state = insertionSort(Arr , Arrsize);   /* SORT THE ARRAY */
	 
	printf("\nArray after sorting\n");

	printArray(Arr, Arrsize);  /* PRINT THE SORTED ARRAY */

	
	LCSstatus = lcsGetSize(Arr, Arrsize, &LCS); /* GET THE LCS */

	//printf("%d\n", LCSstatus); /* FOR DEBUGGING */


	if (LCSstatus == -1) /* ARRAY IS EMPTY STATUS */
	{
		printf("\nArray is empty\n");
	}
	else if (LCSstatus == -2) /* MAXIMUM SIZE EXCEEDED */
	{
		printf("\nYou exceeded the maximum size\n");
	}
	else if(LCSstatus == -3) /* NO LCS */
	{
		printf("\nNo Longest Consecutive subseqyence found\n");
	}
	else /* LCS FOUND */
	{
		printf("\nThe longest consecutive sequence  = %d \n", LCS); /* PRINT THE LCS */
	}
	
	return 0;
}