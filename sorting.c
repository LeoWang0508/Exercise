#include <stdio.h>
#include <string.h>

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Bubble_sort(int a[], int num) {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num - i - 1; j++) {
			if (a[j] > a[j+1]) {
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

void Selection_sort(int a[], int num) {
	int i, j, min_index;
	for(i = 0; i < num; i++) {
		min_index = i;
		for (j = i+1; j < num; j++) {
			if(a[j] < a[min_index]) {
				min_index = j;
			}
		}
		swap(&a[i],&a[min_index]);
	}
}

void Insertion_sort(int a[], int num) {
	int i, j, insert_num;
	for(i = 1; i < num; i++) {
		j = i - 1;
		insert_num = a[i];
		while(j>=0 && insert_num < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		j++;
		a[j] = insert_num;
	}
}

void Quick_sort(int a[], int l, int r) {
	int i = l, j = r, temp;
	if (l < r) {
		while (l < r) {
			while (a[l] > a[i]) {
				i++;
			}
			while (a[l] < a[j]) {
				j--;
			}
			if(i >= j) {
				break;
			}
			
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		Quick_sort(a,l,j-1);
		Quick_sort(a,j+1,r);
	}
}
	
void Merge(int a[], int left, int mid, int right) {
	int l = left, r = mid+1; //兩個array的起點 
	int size = right - left + 1;
	int temp[size], temp_index = 0;
	while(l <= mid && r <= right) {
		if(a[l] < a[r]) {
			temp[temp_index] = a[l];
			l++;
		}
		else {
			temp[temp_index] = a[r];
			r++;
		}
		temp_index++;
	}
	while(l <= mid) {
		temp[temp_index] = a[l];
		l++;
		temp_index++;
	}
	while(r <= right) {
		temp[temp_index] = a[r];
		r++;
		temp_index++;
	}
	for(temp_index = 0; temp_index < size; temp_index++) {
		a[left+temp_index] = temp[temp_index];
	}
}
void Merge_sort(int a[], int l, int r) {
	int m = (l+r)/2;
	if(l < r) {
		Merge_sort(a, l, m);
		Merge_sort(a, m+1, r);
		Merge(a, l, m, r);
	}
}
int main() {
	int i, a[11] = {3,4,1,2,6,7,9,5,8,0,10};
	int num = sizeof(a) / sizeof(a[0]);
	//Bubble_sort(a,num);
	//Selection_sort(a,num);
	//Insertion_sort(a,num);
	Quick_sort(a, 0, num-1);
	//Merge_sort(a, 0, num-1);
	for(i = 0; i < num; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
