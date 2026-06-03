#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Room
{
	private:
		int roomNo;
		bool booked;
		string customerName;
	public:
		Room(int n)
		{
			roomNo=n;
			booked=false;
			customerName="";
		}
		int getRoomNo()
		{
			return roomNo;
		}
		
		bool isBooked()
		{
			return booked;	
		}
		
		string getCustomerName()
		{
			return customerName;
		}
		
		
		void bookRoom(string name)
		{
			booked=true;
			customerName=name;
		}
		
		void checkout()
		{
			booked=false;
			customerName="";
		}
		
		void display()
		{
			cout<<"Room "<<roomNo<<":";
			if(booked==true)
			{
				cout<<"Booked by:"<<customerName;
			}
			else
			cout<<"Available!!!";
			cout<<endl;
		}
};
int main()
{
	vector<Room>rooms;
	for(int i=101;i<=110;i++)
	{
		rooms.push_back(Room(i));
	}
	int choice;
	while(true)
	{
		cout<<"\n!!!!!!! HOTEL MANAGEMENT SYSTEM !!!!!!\n";
		cout<<"1.View Rooms"<<endl;
		cout<<"2.Book Rooms"<<endl;
		cout<<"3.Checkout Room"<<endl;
		cout<<"4.Generate Bill"<<endl;
		cout<<"5.Exit"<<endl;
		
		cout<<"Enter Choice:"<<endl;
		cin>>choice;
		
		if(choice==1)
		{
			cout<<endl<<"!!!!Room Status!!!!"<<endl;
			for(size_t i = 0; i < rooms.size(); i++)
			{
    			rooms[i].display();
			}
		}
		else if(choice==2)
		{
			int roomNo;
			string name;
			cout<<"Enter room Number:";
			cin>>roomNo;
			bool found=false;
			for(size_t i=0;i<rooms.size();i++)
			{
				if(rooms[i].getRoomNo()==roomNo)
				{
					found=true;
					if(rooms[i].isBooked())
					{
						cout<<"Room Already Booked"<<endl;
					}
					else
					{
						cin.ignore();
						cout<<"Enter Customer Name:";
						getline(cin,name);
						rooms[i].bookRoom(name);
						cout<<"Room Booked successfully!!!!"<<endl;
					}
				}
			}
			if(!found)
			{
				cout<<"Room Not Found!!!"<<endl;
			}
		}
		else if(choice==3)
		{
			int roomNo;
			cout<<"Enter Room Number:";
			cin>>roomNo;
			bool found=false;
			for(size_t i=0;i<rooms.size();i++)
			{
				if(rooms[i].getRoomNo()==roomNo)
				{
					found=true;
					if(rooms[i].isBooked()==true)
					{
						rooms[i].checkout();
						cout<<"CheckOut Successfully!!!!"<<endl;
					}
					else
					{
						cout<<"Room Already Empty"<<endl;
					}
				}
			}
			if(found==false)
			{
				cout<<"Room Not Found"<<endl;
			}
		}
		else if(choice==4)
		{
			int roomNo;
			int days;
			cout<<"Enter room No:";
			cin>>roomNo;
			
			cout<<"Enter days:";
			cin>>days;
			bool found=false;
			for(size_t i=0;i<rooms.size();i++)
			{
				if(rooms[i].getRoomNo()==roomNo)
				{
					found=true;
					if(rooms[i].isBooked()==true)
					{
						double roomPrice=1500;
						double totalBill=roomPrice*days;
						cout<<endl<<"!!! BILL !!!"<<endl;
						cout<<"Room Number:"<<roomNo<<endl;
						cout<<"Days stayed:"<<days<<endl;
						cout<<"Room Charge:"<<roomPrice<<endl;
						cout<<"Total Bill:"<<totalBill<<endl;
					}
					else
					{
						cout<<"Room is not Booked!!!"<<endl;
					}
				}
			}
			if(found==false)
			{
				cout<<"Room doesn't Found !!!!!"<<endl;
			}
		}
		else if(choice==5)
		{
			cout<<"!!!! ThankYou !!!!"<<endl;
			cout<<"For using my Hotel management project"<<endl;
			cout<<"!!!! Made By VINAY YADAV !!!!";
			break;
		}
		else
		{
			cout<<"INVALID CHOICE TRY AGAIN !!!!!"<<endl;
		}
	}
}
