#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[64];

    FILE *fp = fopen("input.txt", "r");
    if(!fp){
        fprintf(stderr, "Can't open input\n");
        return 1;
    }

    int maxCalories = 0;
    int currCalories = 0;
    char *endptr;
    while (fgets(line, sizeof(line), fp))
    {   
        if(line[0]<'0'){
            if(currCalories > maxCalories){
                maxCalories = currCalories;
            }
            currCalories = 0;
        } else {
            currCalories += strtol(line, &endptr, 10);
        }
    }
    //last elf processing
    if(currCalories > maxCalories){
        maxCalories = currCalories;
    }

    fclose(fp);

    printf("%d\n", maxCalories);
}