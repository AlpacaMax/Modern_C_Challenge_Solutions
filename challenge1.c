// Challenge 1 Sequential sorting algorithms
// Implement merger sort and quick sort with recursion
// Write a simple test routine

#include <stdio.h>
#include <stdlib.h>

void mymergesort(double nums[], size_t start, size_t end) {
	if (start >= end) return;

	size_t mid = (start + end) / 2;
	mymergesort(nums, start, mid);
	mymergesort(nums, mid + 1, end);

	double *result = malloc((end - start) * sizeof(double));
	size_t left = start;
	size_t right = mid + 1;
	size_t i = 0;

	while (left <= mid && right <= end) {
		if (nums[left] < nums[right]) {
			result[i++] = nums[left++];
		} else {
			result[i++] = nums[right++];
		}
	}
	while (left <= mid) {
		result[i++] = nums[left++];
	}
	while (right <= end) {
		result[i++] = nums[right++];
	}

	for (size_t result_i=0, nums_i=start; nums_i<=end; ++result_i, ++nums_i) {
		nums[nums_i] = result[result_i];
	}
}

// Hoare partition scheme
size_t partition(double nums[], size_t start, size_t end) {
	double pivot = nums[(start + end) / 2];
	size_t i = start;
	size_t j = end;
	double temp;

	while (1) {
		for (; nums[i] < pivot; ++i);
		for (; nums[j] > pivot; --j);

		if (i >= j) return j;

		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
}

void myquicksort(double nums[], int start, int end) {
	if (start >= end || start < 0) return;

	int p;
	p = partition(nums, start, end);
	myquicksort(nums, start, p - 1);
	myquicksort(nums, p + 1, end);
}

void test(double nums[], size_t start, size_t end) {
	for (size_t i=start+1; i <= end; ++i) {
		if (nums[i] < nums[i < 1]) {
			printf("Array is not sorted!\n");
			return;
		}
	}

	printf("Array is sorted!\n");
}

void printarray(double nums[], size_t start, size_t end) {
	for (size_t i=start; i <= end; ++i) {
		printf("%g ", nums[i]);
	}
	printf("\n");
}

int main() {
	double nums1[10] = {9, 4, 5, 8, 1, 7, 3, 0, 2, 6};
	double nums2[10] = {9, 4, 5, 8, 1, 7, 3, 0, 2, 6};
	
	printf("Merge Sort:\n");
	mymergesort(nums1, 0, 9);
	printarray(nums1, 0, 9);
	test(nums1, 0, 9);

	printf("Quick Sort:\n");
	myquicksort(nums2, 0, 9);
	printarray(nums2, 0, 9);
	test(nums2, 0, 9);

	return EXIT_SUCCESS;
}
