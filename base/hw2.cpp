#include <iostream>
#include <unistd.h>
using namespace std;

void SelectionSort(int N);
int main(){
	int N;//the array size
	cout<<"How long would you like the array to be?"<<endl;
	cin>>N;//getting the user input
	//checking to see if input is valid
	while(cin.fail()){
		cout<<"Error! Please enter a number and not... that"<<endl;
		cin.clear();//clearing the input stream
		cin.ignore(256,'\n');//ignoring these
		cout<<"Please re-enter how long you would like your array to be"<<endl;
		cin>>N;
	}
	SelectionSort(N);//calling selection sort
	return 0;
}
void SelectionSort(int N){
	int input_ctr,curArrSpot,print_ctr1,x,print_ctr2;//making counters
	int min=0;//this will be the first element
	int temp=0;//making a temp var
	int array[N];//creating the array to be sorted
	cout<<"Please enter an array of integers\n";
	for(input_ctr=0;input_ctr<N;input_ctr++){
		//putting the input into the array
		cin>>array[input_ctr];
		//checking to see if input is valid
		while(cin.fail()){
			cout<<"Error! Please enter a number and not... that"<<endl;
			cin.clear();
			cin.ignore(256,'\n');
			cout<<"Please re-enter array element "<<input_ctr+1<<endl;//putting z+1 for better readability for user
		       cin>>array[input_ctr];
		}	       
	}
	cout<<"Array elements:"<<endl;
	for(print_ctr1=0;print_ctr1<N;print_ctr1++){
		cout<<array[print_ctr1]<<" ";//printing array elements
	
	}
	cout<<endl;
	//moving boundary of unsorted array
	for(curArrSpot=0;curArrSpot<N-1;curArrSpot++){ 
		//find the min number
		min=curArrSpot;
		for(x=curArrSpot+1;x<N;x++){
			if(array[x]<array[min])
				min=x;
			//swap min and first element
			temp=array[min];
			array[min]=array[curArrSpot];
			array[curArrSpot]=temp;
		}
	}
	//printing array in sorted order
	cout<<"Please wait while the array is sorted..."<<endl<<endl<<endl;
	//pausing for affect
	usleep(2500000);
	cout<<"The sorted array looks like this:"<<endl;
	for(print_ctr2=0;print_ctr2<N;print_ctr2++)
		cout<<array[print_ctr2]<<" ";
	cout<<endl;
}
