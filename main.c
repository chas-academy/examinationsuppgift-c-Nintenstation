#include <stdio.h>
#include <ctype.h>

//Define void function using pointer as parameter, Capitalize input String in main function
void capitalize_String(char *str){
    // Convert the first character to uppercase
    str[0] = toupper((unsigned char)str[0]);

    // Convert the remaining characters to lowercase
    for (int i = 1; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}


int main(){
    //Declare and initialize multidimensional character variable, to store strings as input
    //Declare and initialize the points of 13 different exams, using multidimensional integer array
    char name[5][10];
    int scores[5][13];

    //Utilize for-loop to write in a total of 5 names, store the in the predefined String array.
    for(int i = 0; i < 5; i++){
        scanf("%s", name[i]);
        capitalize_String(name[i]);
    }
    

    //Use for-loop, Assign input integer value to every row and its respective columns
    //Slight error-handling using while-loop, prevents integer input >10
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 13; y++){
            scanf("%d", &scores[x][y]);
            while(scores[x][y] > 10){
                scanf("%d", &scores[x][y]);
            }
        }
    }

    //print names and test scores on each line
    for(int x = 0; x < 5; x++){
        printf("%s ", name[x]);
        for(int y = 0; y < 13; y++){
            printf("%d ", scores[x][y]);
        }
        printf("\n");
    }

    //Use nested for loop to count the average score of each student, store them in an integer array (Declared before for-loop)
    int average[5];
    for(int x = 0; x < 5; x++){
        int sum = 0;
        for(int y = 0; y < 13; y++){
            sum += scores[x][y];
        }
        int divide = sum/13;
        average[x] = divide;
    }

    //Print out averages
    printf("\n");
    for(int i = 0; i < 5; i++){
        printf("%s ", name[i]);
        printf("%d\n", average[i]);
    }
    //Print out student with the biggest average point
    for(int i = 0, j = 1; i < 5; i++, j++){
        if(average[i] < average[j]){
            i = j;
            printf("%s", name[i]);
        }
    }
    //Count the total average of all points
    int total_average = 0;
    for(int i = 0; i < 5; i++){
        total_average += average[i];
    }
    total_average /= 5;

    //Identify whose average points is below total average
    for(int i = 0; i < 5; i++){
        if(total_average > average[i]){
            printf("\n%s", name[i]);
        }
    }

    
    return 0;
}
