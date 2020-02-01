#include <iostream>

using namespace std;

int Find_MaxCross_SubArray(int arr[], int low, int mid, int high){


        int left_sum= 0; // sets left sum to be lowest possible value
        int sum=0;
        int max_left;
        int max_right;



    for(int i=mid; i > low; i--){ //iterates through left array starting at mid going down to lowest
            sum=sum+arr[i];

                if (sum >= left_sum){ //finds max sub of left
                    left_sum=sum;// updates left arrays sum to the left sum
                    max_left=i; // records this for index i
                }
}

     int right_sum= 0; // sets right sum to be lowest possible value

        sum=0;

     for(int j=mid+1; j <= high; j++){ //iterates through right array starting at the mid+1 to highest element
        sum=sum+arr[j];

            if(sum > right_sum){ //Finds max sub of right
                    right_sum=sum;  //updates right array sum to the left sum
                 max_right=j; // records this for index j

            }

     }





        return(max_left, max_right, left_sum+right_sum); //returns the max subarray crossing the midpoint.

//return(max_left, max_right, left_sum+right_sum);


}

int Find_Max_SubArray(int arr[], int low, int high){
int mid;
int left_high, left_low, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;

    if(high==low){ //test if subarray has only 1 element
        return (low, high, arr[low]); //returns the one element subarray
    }
    else{
        mid=(low+high)/2; // divides the starting array to get the mid

        (left_low, left_high, left_sum)=Find_Max_SubArray(arr,low,mid); //finds max subs of left subarray

        (right_low, right_high, right_sum)=Find_Max_SubArray(arr,mid+1,high); //finds max subs of right sub

        (cross_low, cross_high, cross_sum)=Find_MaxCross_SubArray(arr,low,mid,high); //finds max sub that crosses the midpoint.



        if(left_sum >= right_sum && left_sum>=cross_sum){  //Checks if Max Subarray is in left
            return(left_low,left_high,left_sum); //returns max sub array3
       }
        else if(right_sum >= left_sum && right_sum >= cross_sum){  //Checks if Max Subarray is in right
                return(right_low, right_high, right_sum);  //return max sub arrau
     }
        else{
            return(cross_low, cross_high, cross_sum); //Checks if Max Subarray crosses mid



		}
	}
}
int main(){

 int total;
    cin >> total;
    int arr[total];  //sets size of the array

   for(int i=0; i<total; i++){
        cin>> arr[i]; //takes in inputed values for the array

   }

       int result= Find_Max_SubArray(arr, 0, total-1); //Puts resulting Sum of the sub array in Variable

            cout << result;



}
