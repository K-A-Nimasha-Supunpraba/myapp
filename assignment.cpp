#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<string.h>
#include <sstream>

using namespace std;

struct seat{
		string row_number;
		string clss;
		string seat_aval;
		
	};

class flight{
	
	public:
		void available_flights();
		void view_flight(string f_number);
		int seat_availability(string f_number, string class_B_E,int NOS);
		int seat_booking(string f_number,string row_number);
		void exit();	
		void print();
			
		
	
	
		string flight_number;
		string date_time;
		string dep_airport;
		string arr_airport;
		struct seat seat_details[70];
};

void flight::available_flights(){
	int j=0;
	int count_B=0;
	int count_E=0;
		cout<<flight_number<<"\n"<<date_time<<"\n"<<dep_airport<<"\n"<<arr_airport<<"\n";
		for(int j=0;seat_details[j].row_number.empty()!=1;j++)
		{
			//cout<<seat_details[j].row_number<<" ";
			//cout<<seat_details[j].clss<<" ";
			//cout<<seat_details[j].seat_aval<<endl;
			if(seat_details[j].clss=="B")
			{
				int z= seat_details[j].seat_aval.size();
				//cout<<"z="<<z<<endl;
				count_B= count_B + seat_details[j].seat_aval.size();		
			}
			else if(seat_details[j].clss=="E") 
			{
				int z= seat_details[j].seat_aval.size();
				//cout<<"z="<<z<<endl;
				count_E = count_E + seat_details[j].seat_aval.size();
			}
		}
		cout<<"Ecconomic Class:"<<count_E<<endl;
		cout<<"Bussiness Class:"<<count_B<<endl;
		cout<<"\n";
	cout<<"\n";

}

void flight::view_flight(string f_number){
	int count1=0;
	int count_B=0,count_E=0;
	if(flight_number==f_number)
	{
		cout<<"Departure date/time:"<<date_time<<endl;
		cout<<"Departure airport:"<<dep_airport<<endl;
		cout<<"Arrival airport:"<<arr_airport<<endl;
		for(int j=0;seat_details[j].row_number.empty()!=1;j++)
		{
			if(seat_details[j].clss=="B")
			{
				int z= seat_details[j].seat_aval.size();
				count_B= count_B + seat_details[j].seat_aval.size();		
			}
			else if(seat_details[j].clss=="E") 
			{
				int z= seat_details[j].seat_aval.size();
				count_E = count_E + seat_details[j].seat_aval.size();	
				} 
			}	
			cout<<"Ecconomic Class:"<<count_E<<endl;
			cout<<"Bussiness Class:"<<count_B<<endl;		
		}
		else
		{
			count1++;
			
		}
		/*if(count1!=0)
		{
			cout<<"Invalid Flight Number!!!"<<endl;	
		}*/	
		cout<<endl;
}

int flight::seat_availability(string f_number, string class_B_E, int NOS ){
	int count3=0,count=0;
	if(f_number==flight_number)
	{
		count++;
		for(int j=0;seat_details[j].row_number.empty()!=1;j++)
		{
			if(seat_details[j].clss==class_B_E)
			{
				count3= count3 + seat_details[j].seat_aval.size();	
			}
		}
		if(count3>=NOS)
		{
			cout<<"Available Seats:"<<endl;
			for(int j=0;seat_details[j].row_number.empty()!=1;j++)
			{
				cout<<"Row Number: "<<seat_details[j].row_number<<"   ";
				cout<<"Seats: "<<seat_details[j].seat_aval<<endl;
			}		
		}
		else
		{
			cout<<" No Enough Seats  Available!!!"<<endl;
		}
	}

	return count;
	
}

int flight::seat_booking(string f_number,string row_num){
	int count=0;
	string seat_number;
	if(f_number==flight_number)
	{
		count++;
		for(int j=0;seat_details[j].row_number.empty()!=1;j++)
		{
			if(row_num==seat_details[j].row_number)
			{
				cout<<"Available Seats:"<<seat_details[j].seat_aval<<endl;
				cout<<"Seat Number:";
				cin>>seat_number;
				//cout<<seat_details[j].seat_aval;
				for(int n=0;n<=seat_details[j].seat_aval.size();n++)
				{
					
					
					if(seat_details[j].seat_aval.substr(n,n+1)==seat_number)
					{
						
						seat_details[j].seat_aval.erase(n,1);
						//cout<<"AAA-"<<seat_details[j].seat_aval<<endl;
						//break;
					}	
				}
			}
			else
			{
				//cout<<"There is no empty seats in that row!!!"<<endl;
			}
		}
		
	}
	return count;
		
}
int main(){
//	void update(flight array[],int count);
	int count=0,j=0,i=0,option;
	string val;
	ifstream newfile;
	newfile.open("flights.txt");
	if(newfile)
	{
		while(getline(newfile,val))
		{
			if(val.substr(0,2)=="VA")
			{
				count++;
				//cout<<val.substr(0,2)<<endl;
			}
		}
	}else{
		cout << "file errow "<< endl;
	}
	newfile.close();
	
	flight *array= new flight[count]; //array=flight array
	newfile.open("flights.txt");
	if(newfile){
		while(!newfile.eof()){
			getline(newfile,val);
			array[i].flight_number=val; //cout << "ses 1" << endl; 
			getline(newfile,val);
			array[i].date_time=val;//cout << "ses 1" << endl;
			getline(newfile,val);
			array[i].dep_airport=val;
			getline(newfile,val);
			array[i].arr_airport=val;
			j=0;
			while(!val.empty()){
					getline(newfile,val);
					stringstream ss(val);
					ss >> array[i].seat_details[j].row_number >> array[i].seat_details[j].clss >> array[i].seat_details[j].seat_aval;
						//cout << array[i].seat_details[j].row_number<< " " << array[i].seat_details[j].clss << " " << array[i].seat_details[j].seat_aval << endl;
					j++;
			}
		i++;
		}
	/*	int a=0,b=0;
	for(a=0;a<count;a++){
		cout<<array[a].flight_number<<"\n"<<array[a].date_time<<"\n"<<array[a].dep_airport<<"\n"<<array[a].arr_airport<<"\n";
		for(b=0;b<10;b++){
			cout<<array[a].seat_details[b].row_number<<" ";
			cout<<array[a].seat_details[b].clss<<" ";
			cout<<array[a].seat_details[b].seat_aval<<endl;
		}
	}*/ 

	}

		cout<<"1.Display available flights."<<endl;
		cout<<"2.View Flight."<<endl;
		cout<<"3.Seat Availability."<<endl;
		cout<<"4.Seat Booking."<<endl;
		cout<<"5.Exit."<<endl;
		while(1){
		cout<<"Select an option:";
		cin>>option;

		switch(option){
			case 1:{
				for(int i=0;i<count;i++){
					array[i].available_flights();
			}
				break;
				
			}
			case 2:{
				string f_number;
				cout<<"Enter the flight Number:";
				cin>>f_number;
				for(int i=0;i<count;i++)
				{
					array[i].view_flight(f_number);
				}
				break;
				
			}
			case 3:{
				string f_number;
				string class_B_E;
				int NOS,count2;
				cout<<"Enter the flight Number:";
				cin>>f_number;
				cout<<"Enter the class(B or E):";
				cin>>class_B_E;
				cout<<"Number of seats:";
				cin>>NOS;//Number of seats
				for(int i=0;i<count;i++)
				{
					count2=array[i].seat_availability(f_number,class_B_E, NOS);		
				}
				if(count2!=1)
				{
					cout<<"Invalid Entry!!!"<<endl;
						
				}
				break;
			}		
			case 4:{
				string f_number,row_num;
				int count2=0;
				cout<<"Enter the flight Number:";
				cin>>f_number;
				cout<<"Row Number:";
				cin>>row_num;
				for(int i=0;i<count;i++)
				{
					count2=array[i].seat_booking(f_number,row_num);		
				}
				if(count2!=1)
				{
					cout<<"Invalid Entry!!!"<<endl;
						
				}
				break;
			}
			case 5:{
			//	update(array,count);
				break;
			}

			default:
				break;
			}
		}
		return 0;
}
/*
void update(flight array[],int count){
	ofstream update;
	update.open("flights.dat");
	for(int m=0;m<count;m++){
			update<<array[m].flight_number<< endl;
			update<<array[m].date_time<<endl;
			update<<array[m].dep_airport<<endl;
			update<<array[m].arr_airport<<endl;
			for(int l=0;array[m].seat_details[l].row_number.empty()!=1;l++){
				update<<array[m].seat_details[l].row_number<<" "<<array[m].seat_details[l].clss<<" "<<array[m].seat_details[l].seat_aval<<endl;
			}
			update<<endl;
		}
	update.close();
	exit(0);
	}
*/
