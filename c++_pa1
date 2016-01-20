//The website * en.wikipedia.org/wiki/Magic_square * was used as a reference for the workings of a magic square, including sum equation//
//The website * cplusplus.com/doc/tutorial/arrays *  was used as a reference for how to initialize arrays      //

#include <iostream>

using namespace std;



int main(){



// User input below used for array size and sum reference//
	int N;
	cout<<"Enter the size of the *Magic Square*\n";
	cin>>N;
// Initialize the two dimensional array below with value N//
	int table[N][N];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			table[i][j]=0;
		}
	}
// Set row,column,diagonal sum equal to S=(N(N^2+1))/2   //
	///int realsum = ((N*N*N)+N)/2;
	///cout<<"realsum: "<<realsum<<"\n";
// Create incrementing value.  Set middle top value equal to 1.//
	int value=1;
	table[0][N/2]=1;
	///cout<<"Value: "<<value<<"\n";
//The set of loops below is just a reiteration of the same checks several times over//
//The loops have a temp integer that is used to check before the actual print row is changed//

		int row=0;
		int column=N/2;
		int temprow=0;
		int tempcolumn=N/2;

	while(value<=(N*N)-1){
		value = value+1;
		
				
		if((temprow-1)<0){
			
			temprow = (N-1);
		
			if((tempcolumn+1)>N-1){
				tempcolumn = 0;
			
				
					if(table[temprow][tempcolumn]==0){
	
						table[temprow][tempcolumn]=value;						
						
						row = temprow;
						column = tempcolumn;
					}else{
						
						if((row+1)>N-1){
			
						row = 0;
						
						table[row][column]=value;
					
						temprow = row;
						tempcolumn = column;
						
						}else{
							
							table[row+1][column]=value;
							
							temprow = row+1;
							tempcolumn = column;
							row=temprow;
							column=tempcolumn;
							
							}
					}
				
				
			
			}else if((tempcolumn+1)<=N-1){   
				tempcolumn=tempcolumn+1;
				
				
				if(table[temprow][tempcolumn]==0){
	
						table[temprow][tempcolumn]=value;													
						
						row = temprow;
						column = tempcolumn;
					}else{
						
						if((row+1)>N-1){
			
						row = 0;
						
						table[row][column]=value;							
						
						temprow = row;
						tempcolumn = column;
						
						}else{
							
							table[row+1][column]=value;								
							
							temprow = row+1;
							tempcolumn = column;
							row=temprow;
							column=tempcolumn;
							}
					}
				
			}
			
			
			
	
		}else if((temprow-1)>=0){
			
			
			temprow=(row-1);
			
			if((tempcolumn+1)>N-1){
				tempcolumn = 0;
				
				
				if(table[temprow][tempcolumn]==0){
	
						table[temprow][tempcolumn]=value;						
						
						row = temprow;
						column = tempcolumn;
					}else{
						
						if((row+1)>N-1){
			
						row = 0;
						
						table[row][column]=value;						
						
						temprow = row;
						tempcolumn = column;
						
						}else{
							
							table[row+1][column]=value;								
							
							temprow = row+1;
							tempcolumn = column;
							row=temprow;
							column=tempcolumn;
							}
					}
			
			}else if((tempcolumn+1)<=N-1){
				tempcolumn=tempcolumn+1;
			
				
				if(table[temprow][tempcolumn]==0){
	
						table[temprow][tempcolumn]=value;							
						
						row = temprow;
						column = tempcolumn;
					}else{
						
						if((row+1)>N-1){
			
						row = 0;
						
						table[row][column]=value;					
						
						temprow = row;
						tempcolumn = column;
						
						}else{
							
							table[row+1][column]=value;
													
							temprow = row+1;
							tempcolumn = column;
							row=temprow;
							column=tempcolumn;
						}
					}
			
			}
		
			
		
		}


		
//end of while loop//		
		}

	
// Prints the Table below//

cout<<"\n";	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
					
			cout<<table[i][j]<<" ";
					
		}
		cout<<"\n";
	}
cout<<"\n";			
cout<<"\n";	

//Check and print row, column, diagonal sums below//

int sum=0;

//rows checked first//	

for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sum = sum+table[i][j];
			///cout<<sum<<"\n";
		}
		cout<<"The sum of row "<<i<<" is: "<<sum;
		cout<<"\n";
		sum=0;
	}

//columns checked next//
	
for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sum = sum+table[j][i];
			///cout<<sum<<"\n";
		}
		cout<<"The sum of column "<<i<<" is: "<<sum;
		cout<<"\n";
		sum=0;
	}

//First diagonal check//	
	
for(int i=0;i<N;i++){
			sum = sum+table[i][i];
			///cout<<sum<<"\n";
	}
	cout<<"The sum of the first diagonal is: "<<sum;
		cout<<"\n";
		sum=0;

//Second diagonal check//

for(int i=0;i<N;i++){
			sum = sum+table[i][(N-1)-i];
			///cout<<sum<<"\n";
	}
	cout<<"The sum of the second diagonal is: "<<sum;
		cout<<"\n";
		sum=0;		

//end of main//
}
