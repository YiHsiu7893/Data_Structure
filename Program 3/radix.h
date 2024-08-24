#include <vector>
#include <iostream>
#include <queue> 
#include <math.h>
#define d 3		// Since num<1000, there will be a total of 3 passes.
#define r 10	// The 'num's are in base-10.
using namespace std;

class radix{
public:
    radix(vector<int> v_) : v(v_){}

    vector<int> sort(){
    	queue<int> container[r];  // containers
    	
        for(int i=1; i<=d; i++)   // 3 passes
        {
        	// Bucketing
        	int num, idx=0;
        	while(idx<v.size())
        	{
        		num=v[idx];
				for(int k=1; k<i; k++) num/=10;	// Move to the digit place for this pass.
				num%=10;
				
				container[num].push(v[idx]);
				
				idx++;
			}
			
			// Merging
			idx=0;
			for(int j=0; j<r; j++)
			{
				while(!container[j].empty())
				{
					num=container[j].front();
					container[j].pop();
					v[idx++]=num;
				}
			}
		}
        return v;
    }

    vector<int> sort_print(){
        queue<int> container[r];
        
        for(int i=1; i<=d; i++)    
        {
        	// Bucketing
        	int num, idx=0;
        	while(idx<v.size())
        	{
        		num=v[idx];
				for(int k=1; k<i; k++) num/=10;	
				num%=10;
				
				container[num].push(v[idx]); 
				
				idx++;
			}
			
			switch(i)
			{
				case 1:
					cout << "First-pass:" << endl;
					break;
				case 2:
					cout << "Second-pass:" << endl;
					break;
				case 3:
					cout << "Third-pass:" << endl;
			}
			
			// Merging
			idx=0;                      
			for(int j=0; j<r; j++)
			{
				cout << j << " |";
				while(!container[j].empty())
				{
					num=container[j].front();
					container[j].pop();
					v[idx++]=num;
					cout << " --> " << num;
				}
				cout << endl;
			}
        	print_v();
		}
        return v;
    }

    void print_v(){
    	cout << "resulting chain : ";
        for(auto vi : v){
            cout << vi << ",";
        }
        cout << endl << endl;
    }
    
public:
    vector<int> v;
};
