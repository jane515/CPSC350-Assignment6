//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 6
#include <iostream>
#include <sstream>
#include<fstream>
#include<random>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include<chrono>
#include<climits>
#include<time.h>
using namespace std;
class Process
{
public:
  Process();
  ~Process();

  double *quickArray;
  double *mergeArray;
  double *selectionArray;
  double *insertArray;
  double *bubbleArray;
  double *merge;
  double *test;
  int arraySize;
  int numItem;
  void quickSort(double array[],int lowInt,int highInt);
  int partition(double array[],int lowInt,int highInt);
  void mergeSort(double array[],int i,int k);
  void merges(double array[],int i,int j,int k);
  void selectionSort(double array[],int arrSize);
  void insertSort(double array[],int arrSize);
  void bubbleSort(double array[],int arrSize);
  void swap(double array[],int i1,int i2);
  void readFile(string filename);
  void generateNumber(string fileName);
  void printMenu();
  void run(string fileName);
};
/*
cout<<"Unsorted array from merge sort: ";
for(int i =0;i<arraySize;i++)
{
  cout<<mergeArray[i]<<" ";
}
cout<<endl;*/
/*
cout<<"sorted array from merge sort: ";
for(int i =0;i<arraySize;i++)
{
  cout<<mergeArray[i]<<" ";
}
cout<<endl;
*/
