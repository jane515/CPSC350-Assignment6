//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 6

#include "Process.h"
Process::Process()
{
  arraySize=10;
}
Process::~Process()
{
  delete quickArray;
  delete mergeArray;
  delete selectionArray;
  delete insertArray;
  delete bubbleArray;
  delete merge;
}
//read the file
void Process::readFile(string fileName)
{
  ifstream file;
  file.open(fileName);
  int lineNum =1;
  int position = 0;
  if(file.is_open())
  {
    string line;
    while(std::getline(file,line))
    {
      //the first line is the number of items in the file
      if(lineNum==1)
      {
        arraySize = stoi(line);
        quickArray = new double[arraySize];
        mergeArray = new double[arraySize];
        selectionArray = new double[arraySize];
        insertArray = new double[arraySize];
        bubbleArray = new double[arraySize];
        lineNum++;
      }
      //adding the numbers to array
      else
      {
        quickArray[position] = stod(line);
        mergeArray[position] = stod(line);
        selectionArray[position] = stod(line);
        insertArray[position] = stod(line);
        bubbleArray[position] = stod(line);
        position++;
      }
    }
  }
}

void Process::generateNumber(string fileName)
{
  ofstream out;
  out.open(fileName);
  numItem = rand()%10000;
  //store how many numbers to be srot in the first line
  out<<numItem<<endl;
  //output random number of doubles in the file
  for(int i =0;i<numItem;i++)
  {
    //generate random doubles
    //errno_t err;
    double min = 0.1;
    double max = 100.0;
    unsigned int num;
    //err = rand_s(&num);
    //double number = (double)num/((double)UNIT_MAX+1)*max);
    double f = (double)rand()/RAND_MAX;
    double number = min+f*(max-min);
    out<<number<<endl;
  }
  out.close();
}
int Process::partition(double array[],int lowInt,int highInt)
{
  //choose the middle index as the pivot
  int midpoint = lowInt +(highInt-lowInt)/2;
  double pivot = array[midpoint];
  bool done = false;
  while(!done)
  {
    while(array[lowInt]<pivot)
    {
      lowInt+=1;
    }
    while(pivot<array[highInt])
    {
      highInt-=1;
    }
    if(lowInt>=highInt)
    {
      done = true;
    }
    else
    {
      //swap
      double temp = array[lowInt];
      array[lowInt]=array[highInt];
      array[highInt]=temp;

      lowInt++;
      highInt--;
    }
  }
  return highInt;
}
void Process::quickSort(double array[],int lowInt,int highInt)
{
  //if partition size is 0 or 1
  if(lowInt>=highInt)
  {
    return;
  }
  int lowEndInd = partition(array,lowInt,highInt);
  quickSort(array,lowInt,lowEndInd);
  quickSort(array,lowEndInd+1,highInt);

}
void Process::merges(double array[],int i,int j,int k)
{
  int times = 1;
  int mergedSize = k-i+1;
  int mergePos = 0; //position to insert merged number
  int leftPos = 0;
  int rightPos = 0;
  //new array for merged things
  merge = new double[arraySize];

  leftPos = i;
  rightPos = j+1;
  //cout<<"leftPos"<<leftPos<<endl;
  //cout<<"rightPos"<<rightPos<<endl;
  while(leftPos<=j && rightPos<=k)
  {
    if(array[leftPos]<=array[rightPos])
    {
      merge[mergePos]=array[leftPos];
      ++leftPos;
    }
    else
    {

      merge[mergePos]=array[rightPos];
      ++rightPos;
    }
    ++mergePos;
  }
  //if left part is not empty
  while(leftPos<=j)
  {
    merge[mergePos]=array[leftPos];
    ++leftPos;
    ++mergePos;
  }
  //if right part is not empty
  while(rightPos<=k)
  {
    merge[mergePos]=array[rightPos];
    ++rightPos;
    ++mergePos;
  }
  //copy the tempery array to the mergeArray
  for(mergePos=0;mergePos<mergedSize;++mergePos)
  {
    mergeArray[i+mergePos]=merge[mergePos];
  }
/*
  cout<<"ha"<<endl;
  for(int i =0;i<arraySize;i++)
  {
    cout<<"i: "<<merge[i]<<endl;
  }
*/
}
void Process::mergeSort(double array[],int i,int k)
{
  int j = 0;
  if(i<k)
  {
    j = (i+k)/2;
    //cout<<"j: "<<j<<endl;
    mergeSort(array,i,j);
    mergeSort(array,j+1,k);
    merges(array,i,j,k);
  }

}
void Process::selectionSort(double array[],int arrSize)
{
  int i =0;
  int j =0;
  //smallest element in the array
  int indexSmall = 0;
  double temp = 0;
  for(i=0;i<arrSize;++i)
  {
    indexSmall = i;
    for(j=i+1;j<arrSize;++j)
    {
      if(array[j]<array[indexSmall])
      {
        indexSmall = j;
      }
    }
    //swap
    temp = array[i];
    array[i] = array[indexSmall];
    array[indexSmall]=temp;
  }
}
void Process::insertSort(double array[],int arrSize)
{
  int i =0;
  int j = 0;
  double temp = 0;
  for(i=1;i<arrSize;++i)
  {
    j=i;
    while(j>0 && array[j]<array[j-1])
    {
      //swap
      temp = array[j];
      array[j]=array[j-1];
      array[j-1]=temp;
      --j;
    }
  }
}
void Process::bubbleSort(double array[],int arrSize)
{
  int i =0;
  int j =0;
  for(i=0;i<arrSize-1;i++)
  {
    for(j=0;j<arrSize-i-1;j++)
    {
      if(array[j]>array[j+1])
      {
        //swap
        double temp = array[j];
        array[j]=array[j+1];
        array[j+1]=temp;
      }
    }
  }
}
void Process::printMenu()
{
  cout<<"What do you want to do?"<<endl;
  cout<<"1. generate random numbers"<<endl;
  cout<<"2. sorting numbers and display result"<<endl;
  cout<<"3. exit program"<<endl;
}

void Process::run(string fileName)
{
  while(true)
  {
    printMenu();
    int answer;
    cin>>answer;
    if(answer==1)
    {
      cout<<"Start to generate numbers, may take a while"<<endl;
      generateNumber(fileName);
      cout<<"number has been generated in the file"<<endl;
    }
    //sorting numbers from file
    else if(answer==2)
    {
      /*
      readFile(fileName);
      auto q1 = std::chrono::high_resolution_clock::now();
      //quickSort(quickArray);
      auto q2 = std::chrono::high_resolution_clock::now();
      auto quickTime = std::chrono::duration_case<std::chrono::microseconds>(q2-q1).count();

      auto m1 = std::chrono::high_resolution_clock::now();
      mergeSort(mergeArray,0,arraySize-1);
      auto m2 = std::chrono::high_resolution_clock::now();
      auto mergeTime = std::chrono::duration_case<std::chrono::microseconds>(m2-m1).count();

      auto s1 = std::chrono::high_resolution_clock::now();
      //selectionSort();
      auto s2 = std::chrono::high_resolution_clock::now();
      auto selectionTime = std::chrono::duration_case<std::chrono::microseconds>(s2-s1).count();

      auto i1 = std::chrono::high_resolution_clock::now();
      //insertSort();
      auto i2 = std::chrono::high_resolution_clock::now();
      auto insertTime = std::chrono::duration_case<std::chrono::microseconds>(i2-i1).count();

      auto b1 = std::chrono::high_resolution_clock::now();
      //bubbleSort();
      auto b2 = std::chrono::high_resolution_clock::now();
      auto bubbleTime = std::chrono::duration_case<std::chrono::microseconds>(b2-b1).count();

      cout<<"the quick sort start at: "<<q1<<", and end at: "<<q2<<endl;
      cout<<"the merge sort start at: "<<m1<<", and end at: "<<m2<<endl;
      cout<<"the selection sort start at: "<<s1<<", and end at: "<<s2<<endl;
      cout<<"the insert sort start at: "<<i1<<", and end at: "<<i2<<endl;
      cout<<"the bubble sort start at: "<<b1<<", and end at: "<<b2<<endl;
      cout<<"the runtime of quick sort is: "<<quickTime<<endl;
      cout<<"the runtime of merge sort is: "<<mergeTime<<endl;
      cout<<"the runtime of slection sort is: "<<selectionTime<<endl;
      cout<<"the runtime of insert sort is: "<<insertTime<<endl;
      cout<<"the runtime of bubble sort is: "<<bubbleTime<<endl;
      */
      readFile(fileName);
      clock_t start;
      clock_t end;
      float duration;
      //display how many numbers had been generated
      cout<<"Numbers of items to be sort: "<<arraySize<<endl;
      cout<<"-----------Quick Sort-------------"<<endl;
      start = clock();
      quickSort(quickArray,0,arraySize-1);
      end = clock();
      duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
      cout<<"the quick sort start at: "<<start<<", and end at: "<<end<<endl;
      cout<<"the quick of merge sort is: "<<duration<<endl;

      cout<<"-----------Merge Sort-------------"<<endl;
      start = clock();
      mergeSort(mergeArray,0,arraySize-1);
      end = clock();
      duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
      cout<<"the merge sort start at: "<<start<<", and end at: "<<end<<endl;
      cout<<"the runtime of merge sort is: "<<duration<<endl;

      cout<<"-----------Selection Sort-------------"<<endl;
      start = clock();
      selectionSort(selectionArray,arraySize);
      end = clock();
      duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
      cout<<"the Selection sort start at: "<<start<<", and end at: "<<end<<endl;
      cout<<"the runtime of Selection sort is: "<<duration<<endl;

      cout<<"-----------Insert Sort-------------"<<endl;
      start = clock();
      insertSort(insertArray,arraySize);
      end = clock();
      duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
      cout<<"the Insert sort start at: "<<start<<", and end at: "<<end<<endl;
      cout<<"the runtime of Insert sort is: "<<duration<<endl;

      cout<<"-----------Bubble Sort-------------"<<endl;
      start = clock();
      bubbleSort(bubbleArray,arraySize);
      end = clock();
      duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
      cout<<"the Bubble sort start at: "<<start<<", and end at: "<<end<<endl;
      cout<<"the runtime of Bubble sort is: "<<duration<<endl;
    }
    else
    {
      break;
    }
  }

}
