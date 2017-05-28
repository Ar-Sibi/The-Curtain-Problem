#include<iostream>
using namespace std;
int main(){	
	void printAll(int array[1000],int size,int what);
	int queries,input_size,index;
	int First_Fail=0,Best_Fail=0,Worst_Fail=0;
	int best[1000],worst[1000],first[1000];
	cout<<"Enter size of array followed by elements"<<endl;
	cin>>input_size;
	for(int i=0;i<input_size;i++){
		cin>>best[i];
		worst[i]=first[i]=best[i];
	}
	cout<<"Enter no. of queries"<<endl;
	cin>>queries;
	for(int q=0;q<queries;q++){
		cout<<"Required size\n";
		int query;
		cin>>query;
		int max=0,min=50000,min_index=0;
		for(index=0;index<input_size;index++){
			if(worst[max]<worst[index])
				max=index;
		}
		if(worst[max]<query){
			cout<<"Worst has Failed"<<endl;
		}
		else {
			worst[max]-=query;
			printAll(worst,input_size,0);
			Worst_Fail++;
		}
		for(index=0;index<input_size;index++){
			if((min>best[index])&&(best[index]>=query)){
				min_index=index;
				min=best[index];
			}
		}
		if(min==50000){	
			cout<<"Best has Failed";
		}
		else{
			best[min_index]-=query;
			printAll(best,input_size,1);
			Best_Fail++;
		}		
		for(index=0;index<input_size;index++){
			if(query<=first[index])
			break;
		}
		if(index==input_size){
			cout<<"First has failed"<<endl;
		}
		else {
			first[index]-=query;
			printAll(first,input_size,2);
			First_Fail++;
		}	
	}
	cout<<"First has failed in\t"<<(queries)-First_Fail<<"\toccasions\n";
	cout<<"Worst has failed in\t"<<(queries)-Worst_Fail<<"\toccasions\n";
	cout<<"Best has failed in\t"<<(queries)-Best_Fail<<"\toccasions\n";
	return 0;
}
void printAll(int array[1000],int size,int what){
	switch(what){
		case 0:	cout<<"Worst   :";
				break;
		case 1:	cout<<"Best    :";
				break;
		case 2: cout<<"First   :";
				break;			
	}
	for(int i=0;i<size;i++){
		cout<<array[i]<<"   ";
	}
	cout<<endl;
}
