#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
class Customer{
	public:	
		int id;
		int arrivaltime;
		int reqdtime;
		int priority;		
};
void doFCFS(Customer Prior[1000],int size);
void doPriority(Customer Prior[1000],int size);
void doRoundRobin(Customer Prior[1000],int size,int timeq);
int main(){
	int size,timeq,totalpriorities;
	Customer Prior[1000];
	int priorities[1000];
	Customer Robin[1000],Fcfs[1000];
	cout<<"Enter number of customers"<<endl;
	cin>>size;
	cout<<"Enter Time Quantum to be used for Round Robin"<<endl;
	cin>>timeq;
	cout<<"Enter the id, arrival time , time required to complete work , priority level respectively of  "<<size<<"  elements"<<endl;
	for(int i=0;i<size;i++){
		cin>>Robin[i].id;
		cin>>Robin[i].arrivaltime;		
		cin>>Robin[i].reqdtime;
		cin>>Robin[i].priority;
		Prior[i]=Robin[i];
	}
	cout<<"By FCFS rule "<<endl;
	doFCFS(Prior,size);
	cout<<"Press any key to continue"<<endl;
	getch();
	cout<<"By Round Robin rule "<<endl;
	doRoundRobin(Robin,size,timeq);
	cout<<"Press any key to continue"<<endl;
	getch();
	cout<<"By Priority "<<endl;
	doPriority(Prior,size);
	return 0;
}
void doFCFS(Customer Prior[1000],int size){
	int nextarrival=Prior[1].arrivaltime;
	int work=0;
	int arrived=0;
	vector<Customer> v;
	v.insert(v.begin(),Prior[0]);
	int time=0;
	while(v.size()!=0||arrived!=size-1){
		while(nextarrival-time==0){
			if(arrived<size-1){
				arrived++;
				nextarrival=Prior[arrived+1].arrivaltime;	
				v.insert(v.begin()+v.size(),Prior[arrived]);
				cout<<Prior[arrived].id<<"  has arrived"<<endl;
			}
			else
				nextarrival-=2000;		
		}
		if(v.size()!=0){
			v.at(0).reqdtime--;
			if(v.at(0).reqdtime!=0)
				cout<<"Working on   "<<v.at(0).id<<"\t Remaining time for current customer "<<":"<<v.at(0).reqdtime;
			else
				cout<<v.at(work).id<<"'s work is completed in "<<time-v.at(0).arrivaltime+1;
				cout<<"\tTotal elapsed time:"<<time<<endl;
			if(v.at(work).reqdtime<=0){
				v.erase(v.begin());
			}
		}
		time++;
	}
}
void doRoundRobin(Customer Prior[1000],int size,int timeq){
	int nextarrival=Prior[1].arrivaltime;
	int work=0;
	int arrived=0;
	vector<Customer> v;
	v.insert(v.begin(),Prior[0]);
	int time=0;
	int delayfactor=0;
	while(v.size()!=0||arrived!=size-1){
		while(nextarrival-time==0){
			if(arrived<size-1){
				arrived++;
				nextarrival=Prior[arrived+1].arrivaltime;	
				v.insert(v.begin()+v.size(),Prior[arrived]);
				cout<<Prior[arrived].id<<"  has arrived"<<endl;
			}
			else
				nextarrival-=2000;		
		}
		if(v.size()!=0){
			work=work%v.size();
			v.at(work%v.size()).reqdtime--;
			if(v.at(work%v.size()).reqdtime!=0)
				cout<<"Working on   "<<v.at(work).id<<"\t Remaining time for current customer "<<":"<<v.at(work).reqdtime;
			else
				cout<<v.at(work).id<<"'s work is completed in "<<time-v.at(work).arrivaltime+1;
				cout<<"\tTotal elapsed time:"<<time<<endl;
			if(v.at(work).reqdtime<=0){
				v.erase(v.begin()+work);
				delayfactor=time%timeq-1;
			}
		}
		time++;
		if((time+delayfactor)%timeq==0)
			work++;
	}
}
void doPriority(Customer Prior[1000],int size)
{
	int unfinished=0;
	int nextarrival=Prior[1].arrivaltime;
	int work=0;
	int arrived=0;
	vector<Customer> v;
	v.insert(v.begin(),Prior[0]);
	int time=0;
	//Prior[arrived].priority=-10000;
	while(v.size()!=0||arrived!=size-1){
		while(nextarrival-time==0){
			if(arrived<size-1){
				arrived++;
				nextarrival=Prior[arrived+1].arrivaltime;	
				int indice=0;
				while(indice<v.size()){
					Customer c=v.at(indice);
					if(c.priority<Prior[arrived].priority)
						break;
					else
						indice++;
				}
				v.insert(v.begin()+indice,Prior[arrived]);
				cout<<Prior[arrived].id<<"  has arrived"<<endl;
			}
			else
				nextarrival-=2000;
				
		}
		if(v.size()!=0){
			v.at(0).reqdtime--;
			if(v.at(0).reqdtime!=0)
				cout<<"Working on   "<<v.at(0).id<<"\t Remaining time for current customer "<<":"<<v.at(0).reqdtime;
			else
				cout<<v.at(0).id<<"'s work is completed in "<<time-v.at(0).arrivaltime+1;
			cout<<"\tTotal elapsed time:"<<time<<endl;
			if(v.at(0).reqdtime<=0){
				v.erase(v.begin());
			}
		}
		time++;
	}
}
