/* this program counts and sorts the number of occurences of integers in a given file */

#include<stdio.h>

int main()
{
    FILE *input;
    FILE *output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    int numArr[100], index=0, num;
    
    //scanning contents of file and adding them to the buffer
    while( fscanf(input, "%d", &num) != EOF )
    {
        numArr[index] = num;
        index++; //index will also serve as the number of elements in the file
    }

    //counting the number of occurrences of an element in the array
    int countArr[index];
    for(int j=0; j<index; j++)
    {
        int currNum = numArr[j];
        int count = 0;

        //counting the number of occurences of current element 
        for(int k=0; k<index; k++)
        {
            int compNum = numArr[k];
            if(currNum == compNum)
                count++;
        }

        //placing count of element to corresponding array index
        for(int m=0; m<index; m++)
        {
            int compNum = numArr[m];
            if(compNum == currNum)
                countArr[m] = count;
        }
    }

    //removing duplicates from array
    for(int x=0; x<index; x++)
    {
        for(int y=x+1; y<index; y++)
        {
            if(numArr[x] == numArr[y])
            {
                for(int k=y; k<index; k++)
                {
                    numArr[k] = numArr[k+1];
                    countArr[k] = countArr[k+1];
                }

                index--;
                y--;
            }
        }
    }

    //sorting arrays
    for(int x=0; x < index; x++)
    {
        for(int y = x+1; y<index; y++)
        {
            //sorting both arrays by count
            if(countArr[x] > countArr[y])
            {
                int tempC = countArr[x];
                int tempN = numArr[x];

                countArr[x] = countArr[y];
                numArr[x] = numArr[y];

                countArr[y] = tempC;
                numArr[y] = tempN;
            }

            //sorting numbers array by value if count is the same
            if(numArr[x] > numArr[y] && countArr[x] == countArr[y])
            {
                int tempN = numArr[x];
                numArr[x] = numArr[y];
                numArr[y] = tempN;
            }
        }
    }

    //printing results to output file   
    for(int z=0; z<index; z++)
    {
        int n = numArr[z];
        int c = countArr[z];

        fprintf(output, "%d:%d\n", n,c);
    }

    fclose(input);
    fclose(output);

    return 0;
}