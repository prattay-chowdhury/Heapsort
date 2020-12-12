//Creating heap and performing heapsort
//Submitted by Prattay Chowdhury

#include <iostream>
using namespace std;


void print_array(int a[16]){
	int i;
	for (i=0;i<16;i++)
		cout<<a[i]<<' ';
		
	cout<<endl;
}

void build_heap(int a[16], int parent){
	int left_child,right_child;
	int min;
	int temp;
	
	if (parent>a[0]/2)    //base case
		return;
	
	
	left_child=parent*2;

	if ((parent*2+1)<=a[0]){
		
		right_child=parent*2+1;
		
		if ((a[parent]>a[left_child]) || (a[parent]>a[right_child])){
			if (a[left_child]<a[right_child])
				min=left_child;
			else 
				min=right_child;
			
			temp=a[parent];
			a[parent]=a[min];
			a[min]=temp;
			build_heap(a,min);  //percolate down
			return;
		}
		
		else
			return;
	}
	
	else {
		
		//when only left child exists
		if ((a[parent]>a[left_child]) ) { 
		
			
			min=left_child;
			temp=a[parent];
			a[parent]=a[min];
			a[min]=temp;
			build_heap(a,min);   //percolate down
			return;
		}
		
		else
			return;
	}
	
	
}		


	
void floyd(int a[16]){
	
	int parent=a[0]/2;
	
	while(parent>0){
		build_heap(a,parent);
		parent=parent-1;
	}
}

void percolate_down(int a[16], int start_index){
	int left_child,right_child;
	int min;
	int temp;
	
	if (start_index*2>a[0])
		return;
	
	int parent=start_index;
	left_child=parent*2;

	if ((parent*2+1)<=a[0]){
		right_child=parent*2+1;
		
		if ((a[parent]>a[left_child]) || (a[parent]>a[right_child])){
			
			if (a[left_child]<a[right_child])
				min=left_child;
			else 
				min=right_child;
			
			temp=a[parent];
			a[parent]=a[min];
			a[min]=temp;
			percolate_down(a,start_index+1);  //percolate down
			return;
		}
		
		else
			return;
	}
	
	else {
		
		//when only left child exists
		if ((a[parent]>a[left_child]) )  {
			
			min=left_child;
			temp=a[parent];
			a[parent]=a[min];
			a[min]=temp;
			percolate_down(a,start_index+1);   //percolate down
			return;
		}
		
		else
			return;
	}
	
	
}

void heapsort(int a[16]){
	
	int temp;
	
	while(a[0]>0){
	
		temp=a[1];
		a[1]=a[a[0]];
		a[a[0]]=temp;
		a[0]--;
		percolate_down(a,1);
	}
}




int main()
{
	int a[]={15,33,24,56,42,2,18,35,66,21,8,14,29,37,44,11};  //a[0] contains array size
	cout<<"Unsorted array:"<<endl;
	print_array(a);
  
	floyd(a);  //creats heap using floyd's algorithm
	cout<<"New array after creation of min heap:"<<endl;
	print_array(a);
  
	heapsort(a);
	cout<<"Array after heapsort in descending order:"<<endl;
	print_array(a);
	return 0;
}
