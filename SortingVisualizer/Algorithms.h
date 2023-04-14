#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
// Heap Sort
void heapSort(int *array, int size, sf::RenderWindow& window, const unsigned int WINDOW_WIDTH, const unsigned int WINDOW_HEIGHT);
// Merge Sort
void merge(int* array, int l, int m, int r);
void mergeSort(int* array, int l, int r, sf::RenderWindow& window, const int size, unsigned int WINDOW_WIDTH, unsigned int WINDOW_HEIGHT);
// Quick Sort
int partition(int* array, int l, int r); // return pivot
void quickSort(int *array, int l, int r, sf::RenderWindow& window, const int size, unsigned int WINDOW_WIDTH, unsigned int WINDOW_HEIGHT);
/////////////////////////////////////////////////////////
void printArray(int* array, int size);