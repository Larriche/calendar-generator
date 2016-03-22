#include <iostream>
#include <iomanip>

using namespace std;

bool isLeap(int);
int getFirst(int );

int main()
{
	int year,first,rowItemCount;
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string names[] = {"January","February","March","April","May","June",
	      "July","August","September","October","November","December"};
	
	cout << "Enter year:";
	cin >> year;
	
	first = getFirst(year);
	
	if(isLeap(year))
	    months[1] = 29;
	
	for(int i = 0;i < 12;i++){
		cout << "_______________________________________________________" << "\n\n";
	    cout << "\t\t\t" << names[i] <<"  "<<year<< "\n\n";
	    cout << "_______________________________________________________" << endl;
	    
	    cout <<"\n" << setw(7) << "Sun" << setw(7) << "Mon" << setw(7) << "Tue" << setw(7) << "Wed" << setw(7) << "Thu"
	         << setw(7) << "Fri" << setw(7) << "Sat" << "\n\n";
	    
	    // spaces
	    rowItemCount = 0;
	    for(int j = 1;j < first;j++){
	    	cout << setw(7) << " ";
	    	rowItemCount++;
		}
	    
	    for(int j = 1;j <= months[i];j++){
	    	if(rowItemCount == 7){
	    		cout << "\n\n";
	    		rowItemCount = 0;
			}
			cout << setw(7) << j;
			rowItemCount++;
		}
		first = rowItemCount + 1;
		cout << "\n\n";
	}
	
	system("pause");
	return 0;
}

bool isLeap(int year)
{
	if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	    return true;
	return false;
}

int getFirst(int year)
{
	int first_day = (1+(year-1) + (year-1)/4 - (year-1)/100 + (year-1)/400)%7;
    return first_day + 1;
}
