/*
 * Program1.c
 *
 *  Created on: Feb 11, 2023
 *      Author: s326s742
 */

#include <stdio.h>
#include <stdlib.h>

char* index_to_month(int index){
    switch (index){
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default:
            printf("Error");   
    }
}

void print_sales(float sales[]){
    printf("Monthly sales report for 2022:\n");
    printf("%-10s %-10s\n", "Month", "Sales");
    for (int i = 0; i< 12; i++){
        printf("%-10s $%.2f\n", index_to_month(i), sales[i]);
    }
    printf("\n");
}

void min_max_avg(float sales[]){
    int min_index = 0;
    int max_index = 0;
    float sum = 0;

    for (int i=0; i<12; i++){
        if (sales[i] < sales[min_index]){
            min_index = i;
            }
        if (sales[i] > sales[max_index]){
            max_index = i;
        }
        sum += sales[i];
    }

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", sales[min_index], index_to_month(min_index));
    printf("Maximum sales: $%.2f (%s)\n", sales[max_index], index_to_month(max_index));
    printf("Average sales: $%.2f\n", sum / 12);
    printf("\n");
}

void moving_averages(float sales[]){

    printf("Six-Month Moving Average Report:\n");
    float sum;
    for(int i=0; i<7; i++){
        sum = 0;
        for(int j=i; j<i+6; j++){
            sum += sales[j];
        }
        printf("%-10s- %-10s $%.2f\n", index_to_month(i), index_to_month(i+5), sum / 6);
    }
    printf("\n");
}

void sort_sales(float sales[]){

    int indices[12];
    for(int i=0; i<12; i++){ indices[i] = i;}

    for(int i=11; i>0; i--){
        for(int j=0; j<i; j++){
            if (sales[j+1] > sales[j]){
                float temp = sales[j+1];
                sales[j+1] = sales[j];
                sales[j] = temp;

                int temp_index = indices[j+1];
                indices[j+1] = indices[j];
                indices[j] = temp_index;
            }
        }
    }

    printf("Sales report (Highest to Lowest):\n");
    printf("%-10s %-10s\n", "Month", "Sales");

    for (int i=0; i<12; i++){
        printf("%-10s $%-10.2f\n", index_to_month(indices[i]), sales[i]);
    }
    printf("\n");
}

int main(){
    char file_name[50];

    printf("Enter input file name: ");
    scanf("%s", file_name);

    char sales_file[12][20];
    float sales[12];

    FILE *f;

    f = fopen(file_name, "r");
    char ch;
    int i = 0, j = 0;
    do{
        ch = fgetc(f);
        if(('0' <= ch && ch <= '9') || (ch == '.')){
            sales_file[i][j] = ch;
            j++;
        }
        else{
            if(j > 0) {i++;}
            j = 0;
        }
    } while(ch != EOF);

    for (int i=0; i<12; i++){
        sales[i] = atof(sales_file[i]);
    }

    print_sales(sales);
    min_max_avg(sales);
    moving_averages(sales);
    sort_sales(sales);

    return 0;
}