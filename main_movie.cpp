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
		char movie_name[10];
		char user_name[10];
		int phone;
		int num_tick;
};
//////////////////////////////////////////////////////////
void insert_data(){
	fstream f_user , f_movie ;
	book b ;
	movie m ;
	f_user.open("data.txt",ios::out|ios::in);
	f_movie.open("movie.txt",ios::in);
		cout<<" Enter Movie Name : ";   //enter user data
		cin>>b.movie_name;
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
	string check = b.movie_name ;
	int flag=0;
	while(!f_user.eof() || !f_movie.eof()){       //view user data
		f_user.read((char*)&b,sizeof(b));
		f_movie.read((char*)&m,sizeof(m));
		if(m.code!=code){
	    	if(m.name == check){
	    		cout<<"\n\t**** "<<m.name<<" Movie ****";
		   	cout<<"\n\tName : "<<b.user_name
		   	<<"\n\tNumber phone : "<<b.phone
		   	<<"\n\tMovie code : "<<m.code
		   	<<"\n\tMovie Name : "<<m.name
		   	<<"\n\tDate : "<<m.date
		   	<<"\n\tTime : "<<m.time
		   	<<"\n\tTotal seats : "<<b.num_tick
		   	<<"\n\tTotal Amount : "<<(b.num_tick)*(m.price)<<" EGP"<<"\n";
				cout<<"____________________________________________________\n"; 
		  	   flag=1;
	      }
	      code=m.code;
	   } 
	}
	if(flag==0){
		cout<<"\n\tthis movie not found..!\n";  
		cout<<" _________________________________________________\n";  
	}
	/****************************************************************/
	f_user.close();
	f_movie.close();
}
////////////////////////////////////////////////////////// 
void insert_movie(){
	fstream f_movie ;   // add new movie
	movie m ;
	f_movie.open("movie.txt",ios::out|ios::app);
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
		cout<<" Record insert sucessfull \n";
		cout<<" _________________________________________________\n";
		
	f_movie.close();
}
////////////////////////////////////////////////////////// 
void view_all_movie(){
	fstream f_movie;      // show all movie
	movie m;  // object 
	int code=0;       
	int c=0;   // counter of record
	f_movie.open("movie.txt",ios::in);
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
////////////////////////////////////////////////////////// 
void search(){
	fstream f_movie ;    //shearch by name
	movie m ; 
	int code = 0 ;
	string check ;
	int c = 0 ;
	cout<<"please ..!Enter movie name  : ";
	cin>>check;
	f_movie.open("movie.txt",ios::in);
	int flag = 0 ;
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
		cout<<"this movie not found..!\n";
		cout<<" _________________________________________________\n";
	}
	f_movie.close();
}
////////////////////////////////////////////////////////// 
void update(){
//	view_all_movie();
	fstream  f_movie ;    //update Movie
	movie m ;
	string  check;
	int c=0; //conter
	cout<<"\nplease ..!Enter movie name  : ";
	cin>>check;
	f_movie.open("movie.txt",ios::in | ios::out);
	int flag=0;
	f_movie.read((char*)&m,sizeof(m));
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
				     <<"\n\tpress (0) confirmation ";
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
	      }
	}
	if(flag==0){
		cout<<"this movie not found..!\n";
		cout<<" _________________________________________________\n";
	}
	f_movie.close();
}
//////////////////////////////////////////////////////////
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
		cout<<"this movie not found..!\n";
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
////////////////////////////////////////////////////////// 
void fun(){   //solve here
	  cout<<"\t\t\t******************************\n"
	      <<"\t\t\t**                          **\n"
	      <<"\t\t\t**   Movie Ticket booking   **\n"
	      <<"\t\t\t**                          **\n"
	      <<"\t\t\t******************************\n\n";
   	cout<<endl;
     	int cases;
	  cout<<"\t\t\t   Press (1) Insert Movie \n"
	      <<"\t\t\t   Press (2) View All Movie \n"
	      <<"\t\t\t   Press (3) Search Movie \n"
	      <<"\t\t\t   Press (4) Book Ticket \n"
	      <<"\t\t\t   Press (5) Update movie \n"
	      <<"\t\t\t   Press (6) Delete movie \n"
	      <<"\t\t\t   Press (0) Exit \n\n";
	  	   cin>>cases;
	      if(cases==0){
	      	cout<<"\t\t\tThank you !\n";
	      	return ;
			}
	  		else if(cases==1){  
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
	  		else if(cases==2){
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
	  		else if(cases==3){
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
			else if(cases==4){
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
			  else if(cases==5){
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
			  else if(cases==6){
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
////////////////////////////////////////////////////////// 
int main(int argc, char** argv) {
	 fun();
	return 0;
}