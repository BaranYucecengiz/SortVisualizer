#include "Algorithms.h"

#include <Windows.h>
//////////////////////////////////////////////////////////////////////////////////////////
// Recursive Heap Sort 
void heapify(int* arr, int size, int node) {

	// 2 * i + 1 -> Left child
	// 2 * i + 2 -> Right child
	// i/ 2 -> Parent
	// Start node -> (array size / 2) - 1;
	int largest = node;
	int left = 2 * node + 1;
	int right = 2 * node + 2;
	// Look right child if larger than parent assing as largest
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	// Look left child if larger than parent assing as largest
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	// if start node is not equal largest, there is a child larger than parent so 
	// first swap parent and child than recurse the operation for lower nodes
	if (largest != node) {
		std::swap(arr[node], arr[largest]);
		heapify(arr, size, largest);
	}
}
void heapSort(int* arr, int size, sf::RenderWindow& window, const unsigned int WINDOW_WIDTH, const unsigned int WINDOW_HEIGHT) {
	int x_pos = WINDOW_WIDTH / size;

	// Build max heap
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
	
	// Sort
	for (int i = size - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		window.clear(sf::Color::White);
		for (int i = 0; i < size; i++) {
			
			int y_pos = arr[i];
			sf::RectangleShape rec(sf::Vector2f(x_pos, y_pos));
			rec.setPosition(i * x_pos, WINDOW_HEIGHT - arr[i]);
			rec.setFillColor(sf::Color::Black);
			rec.setOutlineThickness(1.f);
			rec.setOutlineColor(sf::Color::Red);
			window.draw(rec);
		}
		window.display();
		// call max heapify on the reduced heap
		heapify(arr, i, 0);

	}
}
//////////////////////////////////////////////////////////////////////////////////////////
// Merge Sort
void merge(int* array, int l, int m, int r){
	
	int left = l;
	int mid = m + 1;
	int right = r;
	int k = 0;
	int* sub_array = new int[r - l + 1];
	while (left <= m && mid <= right) {
		if (array[left] < array[mid]) {
			sub_array[k++] = array[left++];
		}
		else {
			sub_array[k++] = array[mid++];
		}
	}
	for (; left <= m; left++) {
		sub_array[k++] = array[left];
	}
	for (; mid <= right; mid++) {
		sub_array[k++] = array[mid];
	}
	k = 0;
	for (int i = l; i <= r; i++) {
		array[i] = sub_array[k++];
	}
	
	delete [] sub_array;
}

void mergeSort(int* array, int left, int right, sf::RenderWindow& window, const int size, unsigned int WINDOW_WIDTH, unsigned int WINDOW_HEIGHT){
	int x_pos = WINDOW_WIDTH / size;
	int mid = (left + right) / 2;
	if(left < right){
		// Visualize
		window.clear(sf::Color::White);
		for (int i = 0; i < size; i++) {
			int y_pos = array[i];
			sf::RectangleShape rec(sf::Vector2f(x_pos, y_pos));
			rec.setPosition(i * x_pos, WINDOW_HEIGHT - array[i]);
			rec.setFillColor(sf::Color::Black);
			rec.setOutlineThickness(1.f);
			rec.setOutlineColor(sf::Color::White);
			window.draw(rec);
		}
		window.display();
		mergeSort(array, left, mid, window, size, WINDOW_WIDTH,  WINDOW_HEIGHT);
		mergeSort(array, mid + 1, right, window, size, WINDOW_WIDTH, WINDOW_HEIGHT);
		merge(array, left, mid, right);
	}
		
		
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////
// Firts Index - Quick Sort
int partition(int *array, int l, int r) {
	int pivot = array[l];
	int low = l;
	while (l < r) {
		do {
			l++;
		}while (array[l] <= pivot);
		do {
			r--;
		} while (array[r] > pivot);
		if(l < r)
			std::swap(array[l], array[r]);
	}
	std::swap(array[low], array[r]);
	return r;
}

void quickSort(int* array, int l, int r, sf::RenderWindow& window, const int size, unsigned int WINDOW_WIDTH, unsigned int WINDOW_HEIGHT){
	int x_pos = WINDOW_WIDTH / size;
	if (l < r) {
		window.clear(sf::Color::White);
		for (int i = 0; i < size; i++) {
			int y_pos = array[i];
			sf::RectangleShape rec(sf::Vector2f(x_pos, y_pos));
			rec.setPosition(i * x_pos, WINDOW_HEIGHT - array[i]);
			rec.setFillColor(sf::Color::Black);
			rec.setOutlineThickness(1.f);
			rec.setOutlineColor(sf::Color::White);
			window.draw(rec);
		}
		window.display();
		int j = partition(array, l, r);
		
		quickSort(array, l, j, window, size, WINDOW_WIDTH, WINDOW_HEIGHT);

		quickSort(array, j + 1, r, window, size, WINDOW_WIDTH, WINDOW_HEIGHT);
		
	}
	return;
}
