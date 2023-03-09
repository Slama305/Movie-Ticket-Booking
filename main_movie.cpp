#include <bits/stdc++.h>
#include <fstream>
using namespace std;
//////////////////////////////////////////////////////////
class movie{
	public:     //movie info 
		int code;
		char name[10];
		char date[10];
		char time[10];
		int price;
};
//////////////////////////////////////////////////////////
class book{
	public:     //user data
		char m_name[10];
		char namee[10];
		int phone;
		int num_tick;
};
//////////////////////////////////////////////////////////
void insert_data(){
	fstream f1,f2;
	book b;
	movie s;
	f1.open("data.txt",ios::out);
	f1.open("data.txt",ios::in);
	f2.open("movie.txt",ios::in);
		cout<<" Enter Movie Name : ";   //enter user data
		cin>>b.m_name;
		cout<<" your Name : ";
		cin>>b.namee;
		cout<<" mobile phone : ";
		cin>>b.phone;
		cout<<" total number of tickets : ";
		cin>>b.num_tick;
		f1.write((char*)&b,sizeof(b));
		cout<<" Reservation sucessful \n";
		cout<<" _________________________________________________\n";
  /*************************************************************/                     	
	int code=0;
	string n=b.m_name;
	int flag=0;
	while(!f1.eof() && !f2.eof()){       //view user data
		f1.read((char*)&b,sizeof(b));
		f2.read((char*)&s,sizeof(s));
		if(s.code!=code){
	    	if(s.name == n){
	    		cout<<"\n\t**** "<<s.name<<" Movie ****";
		   	cout<<"\n\tName : "<<b.namee
		   	<<"\n\tNumber phone : "<<b.phone
		   	<<"\n\tMovie code : "<<s.code
		   	<<"\n\tMovie Name : "<<s.name
		   	<<"\n\tDate : "<<s.date
		   	<<"\n\tTime : "<<s.time
		   	<<"\n\tTotal seats : "<<b.num_tick
		   	<<"\n\tTotal Amount : "<<(b.num_tick)*(s.price)<<" EGP"<<"\n";
				cout<<"____________________________________________________\n"; 
		  	   flag=1;
	      }
	      code=s.code;
	   } 
	}
	if(flag==0){
		cout<<"\n\tthis movie not found..!\n";  
		cout<<" _________________________________________________\n";  
	}
	/****************************************************************/
	f1.close();
	f2.close();
}
////////////////////////////////////////////////////////// 
void insert_movie(){
	fstream f;   // add new movie
	movie m;
	string str;
	f.open("movie.txt",ios::out|ios::app);
		cout<<" Enter Movie Code : ";
		cin>>m.code;
		cout<<" Enter Name : ";
		cin>>m.name;
		cout<<" Enter Relice Date : ";
		cin>>m.date;
		cout<<" Enter Time : ";
		cin>>m.time;
		cout<<" Enter Ticket price : ";
		cin>>m.price;
		f.write((char*)&m,sizeof(m));
		cout<<" Record insert sucessfull \n";
		cout<<" _________________________________________________\n";
	
	f.close();
}
////////////////////////////////////////////////////////// 
void view_all_movie(){
	fstream f;      // show all movie
	movie s;
	int code=0;
	int c=0;
	f.open("movie.txt",ios::in);
	while(!f.eof()){
		c++;
		f.read((char*)&s,sizeof(s));
		if(s.code!=code){
		   	cout<<"\nRecorde : "
				<<c<<"\nCode : "
				<<s.code<<"\nName: "
				<<s.name<<"\nDate :"
		   	<<s.date<<"\nTime :"
		   	<<s.time<<"\nTicket Price :"
				<<s.price<<"\n";
				cout<<" _________________________________________________\n";
	      code=s.code;
	   } 
	}
	f.close();
}
////////////////////////////////////////////////////////// 
void search(){
	fstream f;    //shearch by name
	movie s;
	int code=0;
	string n;
	int c=0;
	cout<<"please ..!Enter movie name  : ";
	cin>>n;
	f.open("movie.txt",ios::in);
	int flag=0;
	while(!f.eof()){
		c++;
		f.read((char*)&s,sizeof(s));
		if(s.code!=code){
	    	if(s.name == n){
		   	cout<<"\nRecorde : "
			   	<<c<<"\nCode : "
			   	<<s.code<<"\nName: "
		   		<<s.name<<"\nDate :"
		      	<<s.date<<"\nTime :"
		   	   <<s.time<<"\nTicket Price :"
		   		<<s.price<<"\n";
		   	cout<<" _________________________________________________\n";
		  	   flag=1;
	      }
	      code=s.code;
	   } 
	}
	if(flag==0){
		cout<<"this movie not found..!\n";
		cout<<" _________________________________________________\n";
	}
	f.close();
}
////////////////////////////////////////////////////////// 
void update(){
//	view_all_movie();
	fstream f;    //update Movie
	movie s;
	string n;
	int c=0;
	cout<<"\nplease ..!Enter movie name  : ";
	cin>>n;
	f.open("movie.txt",ios::in|ios::out);
	int flag=0;
	f.read((char*)&s,sizeof(s));
	while(!f.eof()){
		c++;
	    	if(n == s.name){
	    		int q;
	    		int cur_pos;
	    		int rec_size;
	    		do{
	    		cout<<"\n\tprass (1) Edit Name "
	    		    <<"\n\tprass (2) Edit Code "
	    		    <<"\n\tprass (3) Edit Price Ticket "
	    		    <<"\n\tprass (4) Edit Date "
	    		    <<"\n\tprass (5) Edit Time \n\t";
	    		int x;cin >> x ;
	    		if(x==1){
	    			cout<<"Enter New Name : ";
	    			cin>>s.name;
				 }
				else if(x==2){
	    			cout<<"Enter New Code : ";
	    			cin>>s.code;
				 }
				else if(x==3){
	    			cout<<"Enter New price : ";
	    			cin>>s.price;
				 }
				else if(x==4){
	    			cout<<"Enter New Date : ";
	    			cin>>s.date;
				 }
				else if(x==5){
	    			cout<<"Enter New Time : ";
	    			cin>>s.time;
				 }
				cout<<" _________________________________________________\n";
				  cur_pos = f.tellg();
				  rec_size =sizeof(s);
				 f.seekp(cur_pos-rec_size,ios::beg);
				 f.write((char*)&s,sizeof(s));
				 cout<<"\n\tpress (1) modify something esle "
				     <<"\n\tpress (0) confirmation ";
				     cin>>q;
				     if(q==0)return;
				   cout<<" _________________________________________________\n";
			}while(q!=0);
		       f.seekg(cur_pos-rec_size,ios::beg);
				 f.read((char*)&s,sizeof(s));
				cout<<"\n\tModified successfully ";
		   	cout<<"\nRecorde : "
			   	<<c<<"\nCode : "
			   	<<s.code<<"\nName: "
		   		<<s.name<<"\nDate :"
		      	<<s.date<<"\nTime :"
		   	   <<s.time<<"\nTicket Price :"
		   		<<s.price<<"\n";
		   	cout<<" _________________________________________________\n";
		  	   flag=1;
	      }
	}
	if(flag==0){
		cout<<"this movie not found..!\n";
		cout<<" _________________________________________________\n";
	}
	f.close();
}
//////////////////////////////////////////////////////////
void del_movie(){
	string n;         //delete movie by name
	cout<<"please ..!Enter movie name to delete for : ";
	cin>>n;
	movie s;
	ifstream f("movie.txt",ios::in);
	ofstream nf("after.txt",ios::out);
	int flag=0;
	f.read((char*)&s,sizeof(s));
	while(!f.eof()){
	    	if(s.name != n){
	    		nf.write((char*)&s,sizeof(s));
		   	flag=1;
	      }
	      f.read((char*)&s,sizeof(s));
	}
	if(flag==0){
		cout<<"this movie not found..!\n";
		cout<<" _________________________________________________\n";
	}
	f.close();
	nf.close();
	remove("movie.txt");
	rename("after.txt","movie.txt");
	cout<<"\n\tdeleted successfully \n";
	cout<<" _________________________________________________\n";
}
////////////////////////////////////////////////////////// 
void fun(){   //solve here
	  cout<<"\t\t\t******************************\n"
	      <<"\t\t\t**                          **\n"
	      <<"\t\t\t**   Movie Ticket booking   **\n"
	      <<"\t\t\t**                          **\n"
	      <<"\t\t\t******************************\n\n";
	while(true){
   	cout<<endl;
     	int x;
	  cout<<"\t\t\t   Press (1) Insert Movie \n"
	      <<"\t\t\t   Press (2) View All Movie \n"
	      <<"\t\t\t   Press (3) Search Movie \n"
	      <<"\t\t\t   Press (4) Book Ticket \n"
	      <<"\t\t\t   Press (5) Update movie \n"
	      <<"\t\t\t   Press (6) Delete movie \n"
	      <<"\t\t\t   Press (0) Exit \n\n";
	  	   cin>>x;
	      if(x==0){
	      	cout<<"\t\t\tThank you !\n";
	      	return ;
			}
	  		else if(x==1){  
	  			insert_movie();
	  			cout<<"__Press (0) Exit \n"
	  			    <<"__Press (1) continue\n";
	  			int q;cin>>q;
	  			cout<<" _________________________________________________\n";
	  			if(q==0){
	  				cout<<"\t\t\tThank you !\n";;
					  return;
				  }
	  			else{
	  		    	fun();
					}
			  }
	  		else if(x==2){
	  			view_all_movie();
	  				cout<<"__Press (0) Exit \n"
	  			       <<"__Press (1) continue\n";
	  			   int q;cin>>q;
	  			   cout<<" _________________________________________________\n";
	  		    	if(q==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return;
						}
	  		    	else{
	  		    		fun();
						}
			  }
	  		else if(x==3){
	  			search();
	  			cout<<"__Press (0) Exit \n"
	  			    <<"__Press (1) continue\n";
	  			   int q;cin>>q;
	  			   cout<<" _________________________________________________\n";
	  		    	if(q==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return;
						}
	  		    	else{
	  		    		fun();
						}
			  }
			else if(x==4){
	  			insert_data();
	  			cout<<"__Press (0) Exit \n"
	  			    <<"__Press (1) continue\n";
	  			   int q;cin>>q;
	  			   cout<<" _________________________________________________\n";
	  		    	if(q==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return;
						}
	  		    	else{
	  		    		fun();
						 }
			  }
			  else if(x==5){
	  			update();
	  			cout<<"__Press (0) Exit \n"
	  			    <<"__Press (1) continue\n";
	  			   int p;cin>>p;
	  			   cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return;
						}
	  		    	else{
	  		    		fun();
						 }
			  }
			  else if(x==6){
	  			del_movie();
	  			cout<<"__Press (0) Exit \n"
	  			    <<"__Press (1) continue\n";
	  			   int p;cin>>p;
	  			   cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return;
						}
	  		    	else{
	  		    		fun();
						 }
			  }
	  		else{
	  			cout<<"this number is incorrect!\n";
	  			cout<<" _________________________________________________\n";
	  			return;
			  }
	  }
}
////////////////////////////////////////////////////////// 
int main(int argc, char** argv) {
	 fun();
	return 0;
}