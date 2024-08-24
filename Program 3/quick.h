#include <vector>
#include <iostream>
using namespace std;

class quick{
public:
    quick(vector<int> v_): v(v_){}

    vector<int> sort(){
        quick_sort_partation(0, v.size()-1);
        return v;
    }

    vector<int> sort_print(){
        quick_sort_partation_print(0, v.size()-1);
        return v;
    }

	void quick_sort_partation(int front, int rear){
        if(front<rear)
        {
        	int i=front, j=rear+1, pivot=v[front];
        	do{
        		do i++; while(v[i]<pivot);	// Find the first number from the left that is greater than the pivot.
        		do j--; while(v[j]>pivot);	// Find the first number from the right that is less than the pivot.
        		if(i<j) swap(v[i], v[j]);
			}while(i<j);
			swap(v[front], v[j]);			// Move the pivot to its correct position.
			
			quick_sort_partation(front, j-1);
			quick_sort_partation(j+1, rear);
		}
        return;
    }
    
    void quick_sort_partation_print(int front, int rear){
        if(front<rear)
        {
        	int i=front, j=rear+1, pivot=v[front];
        	do{
        		do i++; while(v[i]<pivot);
        		do j--; while(v[j]>pivot);
        		if(i<j) swap(v[i],v[j]);
			}while(i<j);
			swap(v[front],v[j]);
			cout << front << "-" << rear << " :" << endl;
			print_v();
			
			quick_sort_partation_print(front,j-1);
			quick_sort_partation_print(j+1,rear);
		}
        return;
    }

    void print_v(){
        for(auto vi : v){
            cout << vi << ",";
        }
        cout << endl;
    }

public:
    vector<int> v;
};
