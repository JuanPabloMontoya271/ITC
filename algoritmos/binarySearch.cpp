#include <iostream> 
#include <windows.h> // WinApi header 

using namespace std; // std::cout, std::cin 
void printArray(int arr[], int len, int i, int j, int mid){
        HANDLE hConsole; 
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
        for (int n = i; n<=j; n++){
                if (n==mid){
                SetConsoleTextAttribute(hConsole, 10); 
                
                }
                else if (n ==i || n==j){
                       SetConsoleTextAttribute(hConsole, 3
                       );  
                }
                else {

                        SetConsoleTextAttribute(hConsole, 7);

                }
       
        cout<<arr[n]<<"\t";
        }
        cout<<endl;
        cin.get();
}
int main() 
{ 
HANDLE hConsole; 
int blue = 3, white = 7, green = 10;
 
int a[] = {1,3,4,6,8,9,10,11,12,100};
int len = sizeof(a)/sizeof(a[0]);
int i = 0, j=len-1;
int target = 6;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
int g;
printArray(a, len, i, j, (i+j)/2);
while(i<=j){
    int mid = (i+j)/2;
    if (a[mid]==target){

            g == mid;
            cout<<"Target "<< target<<" was found at index" <<mid<<" with binary search, thanks for using our algorithm visualization tool";
            
            break;

    }
    else if (a[mid]>target){

            j = mid-1;
            printArray(a, len, i, j, mid);
    }
    
    else if (a[mid]<target){

            i = mid+1;
            printArray(a, len, i, j, mid);

    }
    
}
SetConsoleTextAttribute(hConsole, 7);
return 0; 
} 