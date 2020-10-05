#include<stdio.h>

int count = 0;

void merge(int arr[], int l, int m, int r){

	int n1,n2;
	n1 = m-l+1;
	n2 = r-m;

	int L[n1], R[n2];

	for(int i=0; i<n1; i++){
		L[i] = arr[l + i];
	}

	for(int i=0; i<n2; i++){
        R[i] = arr[m+i+1];
	}

	int i=0, j=0, k=l;

	while( i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while( i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}

	// printf("\narray sorting:\n");
	// for(int i=0; i<n1; i++){
	// 	printf("%d ",L[i]);
	// }
	// printf("\t");
	// for(int i=0; i<n2; i++){
	// 	printf("%d ",R[i]);
	// }
	// printf("\n");
	// for(int i=l; i<=r; i++){
	// 	printf("%d ",arr[i]);
	// }

}

void mergeSort(int arr[], int l, int r){
	count++;
	// printf("\nArray at divide %d\n", count);

	// for(int i=l; i<=r; i++){
	// 	printf("%d ",arr[i]);
	// }

	if(l < r){
		int m = l + (r-l)/2;

		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}

int main(int argc, char const *argv[])
{
    int length;
    //sscanf(argv[1],"%d",&length);
    scanf("%d",&length);
    printf("\n length : %d", length );
    int arr[length];

    for(int i=0; i<length; i++){
    	//sscanf(argv[i+2], "%d",&arr[i]);
    	scanf("%d",&arr[i]);
    }

    int new_length = sizeof(arr)/sizeof(arr[0]);

    //printf("\nNew length : %d", new_length);

    // int x=0;
    // while(x < length){
    // 	printf("\n%d ==> %d",x, arr[x]);
    // 	x++;
    // }

    mergeSort(arr,0, length-1);
    
    // int x = 0;
    // printf("\nsorted array:\n");
    // while(x < length){
    // 	printf("\n%d ==> %d",x, arr[x]);
    // 	x++;
    // }
     printf("\nProgram finished successfully");
	return 0;
}
