#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define slama() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
////////////////////////////////////////////////////////////////////////
class movie{
	public:     //movie info 
		int code=0;
		char name[20]={};
		char date[20]={};
		char time[20]={};
		int price=0;
};
////////////////////////////////////////////////////////////////////////
class book{
	public:     //user data
	   char  movie_name[20]={};
		char user_name[20]={};
		int phone=0;
		int num_tick=0;
};
////////////////////////////////////////////////////////////////////////
bool isFound(string check){
	fstream f_movie ;    //shearch by name
	movie m ;
	bool flag=false; 
	f_movie.open("movie.txt",ios::in);
  	while(!f_movie.eof()){
		f_movie.read((char*)&m,sizeof(m));
	    	if( m.name == check ){
		   	  flag=true; 
			   }
	      }
		return flag; 
	f_movie.close();
}
///////////////////////////////////////////////////////////////////////// 
string nameMovie ;
void insert_data(){
	fstream f_user , f_movie ;
	book b ;
	movie m ;
	
	f_user.open("data.txt",ios::out|ios::in | ios::app);
	f_movie.open("movie.txt",ios::in);
	if(f_user.is_open() || f_movie.is_open() ){
		cout<<" Enter Movie Name : ";   //enter user data
		 cin>>b.movie_name;
		if(!isFound(b.movie_name)){
				cout<<"\n\tthis movie not found..!\n";  
	      	cout<<" _________________________________________________\n";  
	       	return;
		}
		nameMovie=b.movie_name ;
		cout<<" your Name : ";
		cin>>b.user_name;
		cout<<" mobile phone : ";
		cin>>b.phone;
		cout<<" total number of tickets : ";
		cin>>b.num_tick;
		f_user.write((char*)&b,sizeof(b));
		cout<<" Reservation sucessful \n";
		cout<<" _________________________________________________\n";
  /*************************************************************/                     	
	int code=0;
//	string check = b.movie_name ;
// int flag=0;

	while(!f_user.eof() || !f_movie.eof()){       //view user data
		f_user.read((char*)&b,sizeof(b));
		f_movie.read((char*)&m,sizeof(m));
		if(m.code!=code){
	    	if( m.name == nameMovie){
	    		cout<<"\n\t**** "<<m.name<<" Movie ****";
		   	cout<<"\n\tName : "<<b.user_name
		   	<<"\n\tNumber phone : "<<b.phone
		   	<<"\n\tMovie code : "<<m.code
		   	<<"\n\tMovie Name : "<<m.name
		   	<<"\n\tDate : "<<m.date
		   	<<"\n\tTime : "<<m.time
		   	<<"\n\tTicket Price : "<<m.price
		   	<<"\n\tTotal seats : "<<b.num_tick
		   	<<"\n\tTotal Amount : "<<(b.num_tick)*(m.price)<<" EGP"<<"\n";
				cout<<"____________________________________________________\n"; 
		  	  // flag=1;
	      }
	      code=m.code;
	   } 
	}
	/****************************************************************/
	f_user.close();
	f_movie.close();
   }
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
   }
}
///////////////////////////////////////////////////////////////////////// 
void insert_movie(){
	fstream f_movie ;   // add new movie
	movie m ;
	f_movie.open("movie.txt",ios::out|ios::app);
	if(f_movie.is_open() ){
	char check;
	do{
		cout<<" Enter Movie Code : ";
		cin>>m.code;
		cout<<" Enter Name : ";
		cin>>m.name;
		cout<<" Enter Relice Date : ";
		cin>>m.date;
		cout<<" Enter Ticket price : ";
		cin>>m.price;
		cout<<" Enter Time : ";
		cin>>m.time;
		f_movie.write((char*)&m,sizeof(m));
		//////////////////////////////////////////
		cout<<"\n\t\t Movie insert sucessfull \n";
		cout<<" _________________________________________________\n";
		cout<<"Do you want to add another Movie ?(y , n) ";
		cin>>check;
		
	}while(check=='y');
	cout<<"\n__________Done___________\n\n";
	f_movie.close();
	}
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
   }
}
/////////////////////////////////////////////////////////////////////// 
void view_all_movie(){
	fstream f_movie;      // show all movie
	movie m;  // object 
	int code=0;       
	int c=0;   // counter of record
	f_movie.open("movie.txt",ios::in);
	if(f_movie.is_open()){
	while(!f_movie.eof()){
		c++;
		f_movie.read((char*)&m,sizeof(m));
		if(m.code!=code){
		   	cout<<"\nRecorde : "
				<<c<<"\nCode : "
				<<m.code<<"\nName: "
				<<m.name<<"\nDate :"
		   	<<m.date<<"\nTime :"
		   	<<m.time<<"\nTicket Price :"
				<<m.price<<"\n";
				cout<<" _________________________________________________\n";
	      code=m.code;
	   } 
	}
	f_movie.close();
	}
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found Movie  !!!!!!!!!!!\n\n"<<endl;
   }
}
////////////////////////////////////////////////////////////////////////// 
void search(){
	fstream f_movie ;    //shearch by name
	movie m ; 
	int code = 0 ;
	string check ;
	int c = 0 ;
	cout<<"\tplease ..!Enter movie name  : ";
	cin>>check;
	f_movie.open("movie.txt",ios::in);
	int flag = 0 ;
	if(f_movie.is_open()){
  	while(!f_movie.eof()){
		c++;
		f_movie.read((char*)&m,sizeof(m));
		if( m.code != code ){
	    	if( m.name == check ){
		   	cout<<"\nRecorde : "
			   	<<c<<"\nCode : "
			   	<<m.code<<"\nName: "
		   		<<m.name<<"\nDate :"
		      	<<m.date<<"\nTime :"
		   	   <<m.time<<"\nTicket Price :"
		   		<<m.price<<"\n";
		   	cout<<" _________________________________________________\n";
		  	   flag=1;
	      }
	      code=m.code;
	   } 
	}
	if(flag==0){
		cout<<"\n\t\tthis movie not found..!\n";
		cout<<" _________________________________________________\n";
	}
	f_movie.close();
	}
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
   }
}
///////////////////////////////////////////////////////////////////////// 
void update(){
	fstream  f_movie ;    //update Movie
	movie m ;
	string  check;
	int c=0; //conter
	cout<<"\nplease ..!Enter movie name  : ";
	cin>>check; 
	f_movie.open("movie.txt",ios::in | ios::out);
	int flag=0;
	f_movie.read((char*)&m,sizeof(m));
	if(f_movie.is_open()){
	while(!f_movie.eof()){
		c++;
	    	if( m.name == check  ){
	    		flag=1;
	    		int q ;
	    		int cur_pos ;
	    		int rec_size ;
	    		do{
	    		cout<<"\n\tprass (1) Edit Name "
	    		    <<"\n\tprass (2) Edit Code "
	    		    <<"\n\tprass (3) Edit Price Ticket "
	    		    <<"\n\tprass (4) Edit Date "
	    		    <<"\n\tprass (5) Edit Time \n\t";
	    		int x ; cin >> x ; // test case
	    		if(x==1){
	    			cout<<"Enter New Name : ";
	    			cin>>m.name;
				 }
				else if(x==2){
	    			cout<<"Enter New Code : ";
	    			cin>>m.code;
				 }
				else if(x==3){
	    			cout<<"Enter New price : ";
	    			cin>>m.price;
				 }
				else if(x==4){
	    			cout<<"Enter New Date : ";
	    			cin>>m.date;
				 }
				else if(x==5){
	    			cout<<"Enter New Time : ";
	    			cin>>m.time;
				 }
				cout<<" _________________________________________________\n";
				  cur_pos = f_movie.tellg();
				  rec_size =sizeof(m);
				 f_movie.seekp(cur_pos-rec_size,ios::beg);
				 f_movie.write((char*)&m,sizeof(m));
				 cout<<"\n\tpress (1) modify something esle "
				     <<"\n\tpress (0) confirmation \n";
				     cin >> q ; 
				    // if( q==0 )return;
				   cout<<" _________________________________________________\n";
			}while(q!=0);
		       f_movie.seekg(cur_pos-rec_size,ios::beg);
				 f_movie.read((char*)&m,sizeof(m));
				cout<<"\n\tModified successfully ";
		   	cout<<"\nRecorde : "
			   	<<c<<"\nCode : "
			   	<<m.code<<"\nName: "
		   		<<m.name<<"\nDate :"
		      	<<m.date<<"\nTime :"
		   	   <<m.time<<"\nTicket Price :"
		   		<<m.price<<"\n";
		   	cout<<" _________________________________________________\n";
		   	break;
	      }
	      f_movie.read((char*)&m,sizeof(m));
	}
	if(flag==0){
		cout<<"\n\t\tthis movie not found..!\n";
		cout<<" _________________________________________________\n";
		
	}
	f_movie.close();
	}
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
   }
}
///////////////////////////////////////////////////////////////////////
void update_all(){
	fstream  f_movie ;    //update Movie
	movie m ;
	string  check;
	int c=0; //conter
	cout<<"\nplease ..!Enter movie name  : ";
	cin>>check; 
	f_movie.open("movie.txt",ios::in | ios::out);
	int flag=0;
	f_movie.read((char*)&m,sizeof(m));
	if(f_movie.is_open()){
	while(!f_movie.eof()){
		c++;
	    	if( m.name == check  ){
	    		flag=1;
	    		int q ;
	    		int cur_pos ;
	    		int rec_size ;
	    			cout<<"Enter New Name : ";
	    			cin>>m.name;
			
	    			cout<<"Enter New Code : ";
	    			cin>>m.code;
			
	    			cout<<"Enter New price : ";
	    			cin>>m.price;
				
	    			cout<<"Enter New Date : ";
	    			cin>>m.date;
			
	    			cout<<"Enter New Time : ";
	    			cin>>m.time;
	    			
				cout<<" _________________________________________________\n";
				  cur_pos = f_movie.tellg();
				  rec_size =sizeof(m);
				 f_movie.seekp(cur_pos-rec_size,ios::beg);
				 f_movie.write((char*)&m,sizeof(m));
////////////////////////////////////////////////////////////////////////////
				cout<<" _________________________________________________\n";
		         f_movie.seekg(cur_pos-rec_size,ios::beg);
				   f_movie.read((char*)&m,sizeof(m));
				cout<<"\n\tModified successfully ";
		   	cout<<"\nRecorde : "
			   	<<c<<"\nCode : "
			   	<<m.code<<"\nName: "
		   		<<m.name<<"\nDate :"
		      	<<m.date<<"\nTime :"
		   	   <<m.time<<"\nTicket Price :"
		   		<<m.price<<"\n";
		   	cout<<" _________________________________________________\n";
		   	break;
	      }
	      f_movie.read((char*)&m,sizeof(m));
	}
	if(flag==0){
		cout<<"\n\t\tthis movie not found..!\n";
		cout<<" _________________________________________________\n";
		
	}
	f_movie.close();
	}
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
   }
}
///////////////////////////////////////////////////////////////////////
void del_movie(){
	string check;         //delete movie by name
	cout<<"please ..!Enter movie name to delete for : ";
	cin>>check;
	movie m;
	ifstream old_file("movie.txt",ios::in);
	ofstream new_file("after.txt",ios::out);
	int flag=0;
	old_file.read((char*)&m,sizeof(m));
	while(!old_file.eof()){
		   if(m.name == check)flag=1; // check about movie is found
	    	else if(m.name != check){
	    		new_file.write((char*)&m,sizeof(m));
	      }
	      old_file.read((char*)&m,sizeof(m));
	}
	if(flag==0){
		cout<<"\n\t\tthis movie not found..!\n";
		cout<<" _________________________________________________\n";
		return;
	}
	old_file.close();
	new_file.close();
	remove("movie.txt");
	rename("after.txt","movie.txt");
	cout<<"\n\tdeleted successfully \n";
	cout<<" _________________________________________________\n";
}
////////////////////////////////////////////////////////////////////
void del_allmovie(){
	fstream f_movie;         // delete all Movie 
	f_movie.open("after_del.txt");
	remove("movie.txt");
	rename("after_del.txt","movie.txt");
	cout<<"\n\tdeleted successfully \n";
	cout<<" _________________________________________________\n";
}
////////////////////////////////////////////////////////////////////
void del_booking(){
	string check;         //delete booking by your name !
	cout<<"please ..!Enter your name to delete for : ";
	cin>>check;
	book b;
	ifstream old_file("data.txt",ios::in);
	ofstream new_file("new_data.txt",ios::out);
	int flag=0;
	old_file.read((char*)&b,sizeof(b));
	while(!old_file.eof()){
		   if(b.user_name == check)flag=1; // check about user name is found
	    	else if(b.user_name != check){
	    		new_file.write((char*)&b,sizeof(b));
	      }
	      old_file.read((char*)&b,sizeof(b));
	}
	if(flag==0){
		cout<<"\n\t\tthis name not found..!\n";
		cout<<" _________________________________________________\n";
		return;
	}
	old_file.close();
	new_file.close();
	remove("data.txt");
	rename("new_data.txt","data.txt");
	cout<<"\n\t\tdeleted successfully \n";
	cout<<" _________________________________________________\n";
}
/////////////////////////////////////////////////////////////////////////
void Booking_requests(){
	fstream  f_user ;      // show requests to management
	book b;   // object 
	int code=0;
	int flag=0;       
	f_user.open("data.txt",ios::in);
	if( f_user.is_open() ){
	while( !f_user.eof() ){
		f_user.read((char*)&b,sizeof(b));
	    flag++;   // check found 
		if(b.phone!=code){
			//flag++;
			cout<<"\n____________________________________________________\n"; 
		   	cout<<"\n\tName : "<<b.user_name
		   	<<"\n\tNumber phone : "<<b.phone
		   	<<"\n\tMovie Name : "<<b.movie_name
		   	<<"\n\tTotal seats : "<<b.num_tick;
		   	cout<<"\n____________________________________________________\n"; 
		  	   code=b.phone;
	   } 
	}
	if(flag==1){
		cout<<"\n\t\tnot found Booking requests ..!\n";
		cout<<" _________________________________________________\n";
	}
	f_user.close();
	}
   else{
      cout<<"\t\t\t !!!!!!!!!!! cant found Booking requests  !!!!!!!!!!!\n\n"<<endl;
   }
}
/////////////////////////////////////////////////////////////////////
void fun();
void check_(void function()){    // test continue
	         cout<<"__Press (0) Exit \n"
	  			    <<"__Press (1) continue\n";
	  			int q;cin>>q;
	  			cout<<" _________________________________________________\n";
	  			if(q==0){
	  				cout<<"\t\t\tThank you !\n";;
					  return;
				  }
				  else{
	  		      	function();
					   }
}
/////////////////////////////////////////////////////////////////////
void management(){    //management system
      int cases;
	  cout<<"\t\t\t   Press (1) Insert Movie \n"
	      <<"\t\t\t   Press (2) View All Movie \n"
	      <<"\t\t\t   Press (3) Search Movie \n"
	      <<"\t\t\t   Press (4) Update movie \n"
	      <<"\t\t\t   Press (5) Update All Data \n"
	      <<"\t\t\t   Press (6) Delete movie \n"
	      <<"\t\t\t   Press (7) Delete All movie \n"
	      <<"\t\t\t   Press (8) View Booking Requests \n"
	      <<"\t\t\t   Press (9) Home \n"
	      <<"\t\t\t   Press (0) Exit \n\n";
	  	   cin>>cases;
	      if(cases==0){
	      	cout<<"\t\t\tThank you !\n";
	      	return ;
			}
	  		else if(cases==1){  
	  			insert_movie();
	  			check_(management);
			  }
	  		else if(cases==2){
	  		   view_all_movie();
	  			check_(management);
				}
	  		else if(cases==3){
	  			search();
	  	   	check_(management);
			  }
			else if(cases==4){
	  			update();
	  			check_(management);
			  }
			else if(cases==5){
	  			update_all();
	  			check_(management);
			  }
			else if(cases==6){
	  			del_movie();
	  			check_(management);
			  }
			else if(cases==7){
	  			del_allmovie();
	  			check_(management);
			  }
		   
		   else if(cases==8){
	  			Booking_requests();
	  			check_(management);
			  }
			else if(cases==9){
	  			fun();
			  }
	  		else{
	  			cout<<"\n\t\tthis number is incorrect!\n";
	  			cout<<" _________________________________________________\n";
	  			return;
			  }
}
////////////////////////////////////////////////////////////////////////
void viewer(){    // viewer system
		cout<<endl;
     	int cases;
	  cout<<"\t\t\t   Press (1) View All Movie \n"
	      <<"\t\t\t   Press (2) Search Movie \n"
	      <<"\t\t\t   Press (3) Book Ticket \n"
	      <<"\t\t\t   Press (4) Delete Booking \n"
	      <<"\t\t\t   Press (5) Home \n"
	      <<"\t\t\t   Press (0) Exit \n\n";
	  	   cin>>cases;
	      if(cases==0){
	      	cout<<"\t\t\tThank you !\n";
	      	return ;
			}
	  		else if(cases==1){
	  			view_all_movie();
	  			check_(viewer);
			  }
	  		else if(cases==2){
	  			search();
	  			check_(viewer);
			  }
			else if(cases==3){
	  			insert_data();
	  			check_(viewer);
			  }
			else if(cases==4){
	  			del_booking();
	  			check_(viewer);
			  }
			else if(cases==5){
	  			fun();
			  }
			else{
	  			cout<<"this number is incorrect!\n";
	  			cout<<" _________________________________________________\n";
	  			return;
			  }
}
///////////////////////////////////////////////////////////////////////
void fun(){   //solve here
	  cout<<"\t\t\t******************************\n"
	      <<"\t\t\t**                          **\n"
	      <<"\t\t\t**   Movie Ticket booking   **\n"
	      <<"\t\t\t**                          **\n"
	      <<"\t\t\t******************************\n\n";
	   cout<<"\t\t______________________________________________\n";
   	int file;
      cout<<"\n\t\t\t  What do you want to open \n";
      cout<<"\t\t______________________________________________\n";
      cout<<"\n\t\t\t   1- Management System \n"
	       <<"\n\t\t\t   2- Viewers System\n";
	   cout<<"\t\t______________________________________________\n";
	        cin>>file;
	   switch(file){
	   	case 1:
	   		cout<<"\n\t\t\t__please Enter password__\n";
	   		int pass;cin>>pass;
	   		if(pass==1234){
	   		management();
	      	}
	      	else{
	      		cout<<"\t\t______________________________________________\n";
	      		cout<<"\n\t\t\t____This password incorrect____\n";
				}
	   		break;
	      case 2:
	         viewer();
	   		break;	
		}              
}
//////////////////////////////////////////////////////////////////// 
int main(int argc, char** argv) { 
	 fun();
	 slama();
	return 0;
}