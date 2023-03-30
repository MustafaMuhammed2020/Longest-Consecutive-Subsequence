/*************************************************************************/
/* Author    : Mustafa Mohammed Abdo                                     */
/* Date      : 29 Mar 2023                                               */
/* Version   : V01                                                       */
/* Hint      : Implementation of insertion sorting                       */
/*************************************************************************/


#include"Sorting.h"

#include<stdio.h>


sint8_t insertionSort(sint32_t* array, uint8_t arraySize)
{
	sint8_t Localreturnvalue = 0 , Localtempvalue = 0 , Localreversediterator = 0 , Localtemp = 0; /* HOLDS THE RETURN VALUE OF THE FUNCTION */
	uint8_t Localiterator = 0   ;

	/* CHECK ON ARRAY SIZE */
	if (arraySize == 0 || arraySize > 10 )
	{
		Localreturnvalue = -2;
		return -2;

	}

	

	/* CONTINUE IF THE PREVIOUS CONDITIONS ARE FALSE */
	if(Localreturnvalue != -1 && Localreturnvalue != -2)
	{
		/* INSERTION SORT ALGORITHM                            */
		/* HOLD FROM THE SECOND ELEMENT                        */
		/* STORE THIS ELEMENT IN SEPERATE TEMPORARY VARIABLE   */
		/* COMPARE THIS VARIABLE TO THE PREVIOUS ELEMENTS      */
		/* IF ONE GREATER FOUND , SWAP BETWEEN THEM            */
		for (Localiterator = 1 ; Localiterator < arraySize ; Localiterator++)
		{
			Localreversediterator = Localiterator - 1  ; /* STARTS FROM THE PREVIOUS ELEMENT UNTILL THE FIRST ONE */
			
			Localtempvalue = array[Localiterator] ;      /* STORE THE SECOND VARIABLE IN TEMP */

			while (Localreversediterator >= 0 ) /* UNTILL WE REACHED THE FIRST ELEMENT */
			{
				if (array[Localreversediterator] > Localtempvalue)  /* TRUE WHEN A PREVIOUS ELEMENT IS GREATER */
				{
					/* SWAP THE TWO ELEMENTS */
					Localtemp = array[Localreversediterator];
					array[Localreversediterator] = array[Localreversediterator+1];
					array[Localreversediterator + 1] = Localtemp;

				}
				else
				{
					/* DO NOTHING */
				}
				Localreversediterator--; /* INCREASE UNTILL THE FIRST ELEMENT */
			}

		}
		Localreturnvalue = 0; /* RETURN THE STATUS AS 0 */
	}

	return Localreturnvalue; /* RETURN THE FUNCTION STATUS */
}





void printArray(sint32_t* array, uint8_t arraySize)
{
	uint8_t Localiterator = 0; /* USED FOR LOOPING */

	for ( Localiterator = 0 ; Localiterator < arraySize ; Localiterator++)
	{
		printf("%d\t", array[Localiterator]); /* PRINT ALL ELEMENTS SEPERATED BY TAB */
	}
}


sint8_t lcsGetSize(sint32_t* array, uint8_t arraySize, uint8_t* sizeofLCS)
{
	sint8_t Localreturnvalue = 0 ; /* HOLDS THE STATUS OF THE FUNCTION */

	uint8_t Localiterator = 0 , Localcurrentelement = 0 , LocalCosecutivecounter = 1 , Localmaxconsecutive = 1 , LocalZeroiterator = 0, zeros = 0 , foundstatus = 0;

	/* CHECK ON ARRAY SIZE */
	if (arraySize > 10 || arraySize == 0)
	{
		Localreturnvalue = -2;
		return -2;
	}

	/* CHECK IF THE ARRAY IS EMPTY */
	for (LocalZeroiterator = 0; LocalZeroiterator < 10; LocalZeroiterator++) /* CHECK IF THE ARRAY IS EMPTY */
	{
		if (array[LocalZeroiterator] == 0)
		{
			zeros++;
		}

	}

	if (zeros == 10)
	{
		Localreturnvalue = -1;
		return -1;
	}

	
	if (Localreturnvalue != -1 && Localreturnvalue != -2)
	{
		/* LOOP ON ARRAY ELEMENTS */
		for (Localiterator = 0; Localiterator < arraySize; Localiterator++)
		{

			Localcurrentelement = Localiterator; /* HOLDS THE CURRENT ELEMENT */

			while (array[Localcurrentelement + 1 ] == (array[Localcurrentelement] + 1) ) /* MEANS THAT THE NEXT ELEMENT EQUALS CURRENT ELEMENT + 1 */
			{
				
				LocalCosecutivecounter++; /* COUNTER FOR CONSECUTIVES */
				Localcurrentelement++;    /* ACTS AS ITERATOR */
			}

			if (LocalCosecutivecounter > Localmaxconsecutive)
			{
				Localmaxconsecutive = LocalCosecutivecounter; /* UPDATE THE MAX VALUE */
				LocalCosecutivecounter = 1; /* INITIALIZE THE COUNTER TO START FROM 0 AGAIN */
				foundstatus = 1;
			}

			LocalCosecutivecounter = 1; /* INITIALIZE THE CONSECUTIVE COUNTERS TO 0 */
			
		}

		if (foundstatus == 1)
		{
			Localreturnvalue = 0; /* RETURN AS FUNCTION DONE PROPERLY */
		}

		else if (foundstatus == 0)
		{
			Localreturnvalue = -3; /* RETURN WHEN THERE IS NO CONSECUTIVE NUMBERS */
			return -3;
		}
	}

	
	*sizeofLCS = Localmaxconsecutive; /* RETURN THE MAX CONSECUTIVE SUB ARRAY */

	return Localreturnvalue;
}
