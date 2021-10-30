#include<iostream>
#include<fstream>
#define GridSize 10
using namespace std;
int d=0;
    struct GameGrid{
    GameGrid(){
        Loaded = 0;
        for(int i = 0; i< 10; i++)
            for(int j = 0; j< 10; j++)
                Grid[i][j] = ' ';
    }
	void loadGame(string FileName){
        /*
        This function must open the file and load the game from the
        file into the array in this structure and marks that it has been loaded
        */
		ifstream IN(FileName.c_str()); // this command will possibly open the file
        if(IN)                        //You will write  the remaining code here
		{
			cout<<"Loaded Sucessfully"<<endl;
			d=1;
		} 
		else 
		cout<<"NOT LOADED"<<endl;
        for (int i=0;i<10;i++)
		{
			for (int j=0; j<10; j++)
			{
				char val;
				IN>>val;
				Grid[i][j]=val;
			}
		} 
        
    }
	void saveGame(string FileName){
        /*
        This function will save the game in the file specified
        as the parameter.
        It should not save the game if it is not already loaded
        */
        ofstream COUT(FileName.c_str());// try to Open the file for output
        if (COUT)
		{
			cout<<"Saved successfully"<<endl;
			for (int i=0;i<10;i++)          // You will write the remaining code here
				{
					for (int j=0; j<10; j++)
					COUT<<Grid[i][j]<<" ";
					COUT<<endl;
				}  
   		}
   		else 
   		cout<<"NOT SAVED"<<endl;
    }
    int Rotate(int Top, int Left, int Right, int Bottom, int Step){
	
    /*
        This function will perform the circular rotation
        of characters as described in the handout.
        The function must verify that
        top < bottom, left < right and that all these
        values are within the range
        Further it must verify that step size > 0.

        Rotation will be performed only if the game has been loaded already
    */
        if(Top>-1 && Left>-1 && Right<10 && Bottom<10)
		{
			if (Top<Bottom && Left<= Right && Step>0 && d==1 )
			{ for(int f=0;f<Step;f++)
			
		    	{
		    		int r=Right,l=Left,b=Bottom,t=Top;int R=Right,L=Left,B=Bottom-1,T=Top+1,y=(Right-Left),z=(r-l),ri=Right,le=Left,bo=Bottom-1,to=Top+1,x=B-T,n=(bo-to);
		    		char qq,rr,ss,tt;
		    		char temp4={};char temp1={};char temp={};char temp3={};
		    		int bb=Top,cc=Left,dd=Bottom,ee=Right,ff=(Top+1),gg=(Bottom-1);
		    		cout<<"Entered in Rotation area"<<endl;cout<<y<<z<<x<<endl;
					for(int i=0;i<y;i++)	
					{
						cout<<"left shift"<<endl;
						char temp={};
						temp=Grid[Bottom][Left];
						Grid[Bottom][Left]=Grid[Bottom][Left+1];
						Grid[Bottom][Left+1]=temp;
						Left++; cout<<temp<<endl;
						qq=temp;
					}
					for (int j=0;j<z;j++)
					{
						cout<<"right shift"<<endl;
						char temp1={};
						temp1=Grid[t][r];
						Grid[t][r]=Grid[t][r-1];
						Grid[t][r-1]=temp1;
						r--;cout<<temp1<<endl;
						rr=temp1;
					}
					for(int k=0;k<x;k++)
					{
						cout<<"shift up"<<endl;
						char temp3={};
						temp3=Grid[T][L];
						Grid[T][L]=Grid[T+1][L];
						Grid[T+1][L]=temp3;
						T++;cout<<temp3<<endl;
						ss=temp3;
					}
					for (int m=0;m<n;m++)
					{
						cout<<"shift down"<<endl;
						char temp4={};
						temp4=Grid[bo][ri];
						Grid[bo][ri]=Grid[bo-1][ri];
						Grid[bo-1][ri]=temp4;
						bo--;cout<<temp4<<endl;
						tt=temp4;
					}
					Grid[bb][cc]=ss;
					Grid[dd][ee]=tt;
					Grid[ff][ee]=rr;
					Grid[gg][cc]=qq;
					
					show();	
				}
			}
		}
		else
		{
			cout<<"Error in any of the given Arguments or Either file is not Loaded";
		}
}
    void show()
	{
    	if (d==1)
    	{
			for (int i=0;i<10;i++)  
				{
					for (int j=0; j<10; j++)
					cout<<Grid[i][j]<<" ";
					cout<<endl;
				} 
		}
		else 
		cout<<"The Game  is not loaded";
		
        /*
        This function will show the array on screen;
        The grid will be shown only if the game has been loaded already
        otherwise a message will be shown that game is not loaded.
        */
    }
    private:
    int Loaded; // to keep an indicator if the file has been loaded
    char Grid[GridSize][GridSize];
};
int main()
{
    /*
    This function will provide a menu with the following choices
    1. Load Game
    2. Save Game
    3. Show Grid
    4. Perform Rotation. {The Grid before rotation and after rotation will be shown}
    5. Exit.
    Complete the main function as specified in the handout
    */
	int Top,Left,Right,Bottom,Step,choose;
    GameGrid Game;
    
    //Game.Rotate(Top,Left,Right,Bottom,step);
    do
    {
    	cout<<"Enter the desired number to perform action";
	    cout<<"\n1. Load Game"<<endl;
	    cout<<"2. Save Game"<<endl;
	    cout<<"3. Show Grid"<<endl;
	    cout<<"4. Perform Rotation"<<endl;
	    cout<<"5. Exit."<<endl;
	    cout<<"Enter your Choice= ";cin>>choose;
    	if (choose==1)
    	{
    		Game.loadGame("Grid.txt");
		}
		if (choose==2)
		{
			Game.saveGame("save.txt");
		}
		if (choose==3)
		{
			Game.show();
		}
		if (choose==4)
		{
			cout<<"Enter the Top value= ";cin>>Top;
		    cout<<"Enter the left Value= ";cin>>Left;
		    cout<<"Enter the Right value= ";cin>>Right;
		    cout<<"Enter the Bottom value= ";cin>>Bottom;
		    cout<<"Enter step you want to move= ";cin>>Step;
			Game.Rotate(Top,Left,Right,Bottom,Step);
			//Game.show();
		}
	}
	while(choose!=5);
    return 0;
}

