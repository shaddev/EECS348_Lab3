/*
 * Program2.c
 *
 *  Created on: Feb 11, 2023
 *      Author: Shad Ahmed
 */

#include <stdio.h>

void print_possibility(int out_arr[]){
    printf("%d TD + 2 pt, ", out_arr[0]);
    printf("%d TD + FG, ", out_arr[1]);
    printf("%d TD, ", out_arr[2]);
    printf("%d 3pt FG, ", out_arr[3]);
    printf("%d Safety\n", out_arr[4]);
}

void pos(int points, int index, int given_arr[], int out_arr[], int size){
    for (int i = 0; i <= (points / given_arr[index]); i++){
        int new_points = points - given_arr[index]*i;
        out_arr[index] = i;
        if (new_points >= 0 && index < size - 1){
            pos(new_points, index+1, given_arr, out_arr, size);
        }
        if (new_points == 0 && index == size - 1){
            print_possibility(out_arr);
        }
    }
}

int main(){

    int points, out_arr[5];
    int given_arr[] = {8, 7, 6, 3, 2};

    do{
        printf("Enter 0 or 1 to STOP\n");
        scanf("%d", &points);
        if(points > 1){
            pos(points, 0, given_arr, out_arr, 5);
        }
    } while(points > 1);

    printf("Exiting...\n");

    return 0;
}
