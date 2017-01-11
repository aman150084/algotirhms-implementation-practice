#include<stdio.h>
#include<stdlib.h>
int max2(int a, int b){
    if(a>b) return a;
    else return b;
}
int max(int *array, int start, int end){
    int i = start;
    int max= array[start];
    while(i<(end)){
        max= max2(array[i], array[i+1]);
        i++;
    }
    return max;
}
int check_top(int row, int index){//this checks if there is a neighbour in the top
    if(index == -1+row*(row +1)/2){
        return -1;
    }
    return 1;
}
int check_left(int row, int index){//this checks if there is a neighbour in the left
    if(index ==-1+ row*(row-1)/2){
        return -1;
    }
    return 1;
}
int findsum(int* sum, int row, int index, int* array){
    if(index==0)
        return array[index];
    if(check_top(index,row)==1){
        if(check_left(index,row)==-1){
            return array[index]+sum[index-row+1];
        }
        return array[index]+max2(sum[index-1], sum[index-row+1]);
    }
    return array[index]+sum[index-1];
}
int main(){
	int t;
	scanf("%d", &t);
	int rows;
	while(t--){
		scanf("%d", &rows);
		int arr = (rows*(rows+1))/2;
		int* array =(int*)malloc(arr*sizeof(int));
		int* sum =(int*)malloc(arr*sizeof(int));
		int flag = 0;
		int row = 1;
		while(arr--){
		    if(flag==row*(row+1)/2){
		        row+=1;
            }
           // printf("a");
		    scanf("%d", array+flag);
			sum[flag]=findsum(sum, row, flag, array);
		    //printf("\n %d-a\n", sum[flag]);
		    flag++;
		}
        arr = (rows*(rows+1))/2;
		printf("%d\n",max(sum, arr-rows, arr-1));
        int i;
        for (i=0;i < (sizeof (sum) /sizeof (sum[0]));i++) {
                printf("%d\n",sum[i]);
        }
    }
    return 0;
}

