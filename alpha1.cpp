# include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class game
{
	public:
	int i=0;
	int j=0;
	int x;
	int y;
	int q=0;
	int z=0;
	int lvl;
	int table[7][7];
	int win=0;
	int show_table[7][7];
	game() // menu ra level choose garni 
	{
		cout<<"********* Welcome to Minesweeper ******* "<<endl;
		cout<<"This is a 7*7 mine game with ur selected number of mines spread across the table"<<endl;
		cout<<"Try clearing the table by avoiding the mines"<<endl;
		cout<<"//////////////////////////////"<<endl;
		cout<<"------- BEST OF LUCK ---------"<<endl;
		cout<<"//////////////////////////////"<<endl;
		cout<<endl;
		cout<<endl;	
	}
	void lev_sel()
	{	do{
			cout<<"Choose Difficulty Level "<<endl;
			cout<<"++++++++++++++++++++++"<<endl;
			cout<< "1.  Easy ( 7 mines) "<<endl;
			cout<< "2.  Medium (17 mines) "<<endl;
			cout<< "3.  Hard (27 mines) "<<endl;
			cout<< " 1 or 2 or 3 ?"<<endl;
			cin>>lvl;
			cout<<endl;
			cout<<endl;
		}while(lvl>3);
			if(lvl==1){cout<<"Starting easy level with 7 mines"<<endl;lvl=7;}
			else if (lvl==2){cout<<"Starting Medium level with 17 mines"<<endl;lvl=17;}
			else if (lvl==3){cout<<"Starting Hard level with 27 mines"<<endl;lvl=27;}
		
	}
	void gc()
	{
		
		for(i=0;i<7;i++) // sabai value 0
       	 {for(j=0;j<7;j++)
            table[i][j] = 0;
    	}
    	srand(time(0));
    	do{
    		
		x = rand()%7; // 7 vitra kunai random number 
        y = rand()%7;
                         if(table[y][x] != 11)// sab ko value ko oripari 1 banauni
                         {
                                    table[y][x] = 11;
                                    lvl--;
                                    if((y-1) >= 0)
                                    if(table[y-1][x] != 11)
                                                  table[y-1][x]++;
                                    if((y-1) >= 0 && (x-1) >= 0)
                                    if(table[y-1][x-1] != 11)
                                                  table[y-1][x-1]++;
                                    if((x-1) >= 0)
                                    if(table[y][x-1] != 11)
                                                  table[y][x-1]++;
                                    if((y+1) < 7)
                                    if(table[y+1][x] != 11)
                                                  table[y+1][x]++;
                                    if((y+1) < 7 && (x+1) < 7)
                                    if(table[y+1][x+1] != 11)
                                                  table[y+1][x+1]++;
                                    if((x+1) < 7)
                                    if(table[y][x+1] != 11)
                                                  table[y][x+1]++;
                                    if((y-1) >= 0 && (x+1) < 7)
                                    if(table[y-1][x+1] != 11)
                                                  table[y-1][x+1]++;
                                    if((y+1) < 7 && (x-1) >= 0)
                                    if(table[y+1][x-1] != 11)
                                                  table[y+1][x-1]++;
                         }
                     }while(lvl>0);
                     
                         	for(i=0;i<7;i++) // sabai value 0
       	 					{for(j=0;j<7;j++)
            					show_table[i][j] = 0;}
            					
            					
            do{
                        	cout<<"  ";
                         for(i=0;i<7;i++)//table print garni
                                    cout << i << " ";
                         cout << endl;
                         cout << "----------------"<<endl;
                         for(i=0;i<7;i++) 
                         {
                            for(j=0;j<7;j++)
                            {
                                if(j==0)
                                    {cout << i << "|";}
                                if(show_table[i][j]==1)
                                    {
                                        if(table[i][j] == 0)
                         				cout << "0|";
           								else if(table[i][j] == 11)
                         				cout << "x|";
           								else
                         				cout << table[i][j] << "|";
									}
                                else
                                    {
									cout << "_|";}
                                if(j==6)
                                    cout << endl;
                                if(table[i][j]!=11 && show_table[i][j]==1)
                                    q++;
                            }
                         }
                         if(q>=49-lvl)   //// kasari win?
                         {
                         	cout<<"You Win"<<endl;
                         	win=1;
						}
						 if(win==0)
						 {
						 	cout<<"Enter Column value "<<endl; cin>>x;
        					cout<<"Enter Row value"<<endl;cin>>y;
        				}
        					if(table[y][x]==11)
        					{
        						cout<<"Sorry You hit a mine"<<endl;
        						win=1;
        						for(i=0;i<7;i++)
                                                  cout << i << " ";
                                    cout << endl;
                                    win = 1;
                                    for(i=0; i<7; i++)
                                    {
                                                  for(j=0;j<7;j++)
                                                  {
                                                                if(j==0)
                                                                           cout << i << " |";
                                                                if(table[i][j]==11)
                                                                           show_table[i][j]=1;
                                                                if(show_table[i][j]==1)
                                                                           {
																		   if(table[i][j] == 0)
                         													cout << "0|";
           																	else if(table[i][j] == 11)
                         													cout << "x|";
           																	else
                         													cout <<table[i][j]<< "|";}
                                                               				 else
                                                                           cout << "_|";
                                                                if(j==6)
                                                                           cout << endl;
                                                  }
        					}
							}
							show_table[y][x]=1;
	}while(win==0);
}
};

int main()
{
	game ms;
	ms.lev_sel();
	ms.gc();
	return 0;
}


