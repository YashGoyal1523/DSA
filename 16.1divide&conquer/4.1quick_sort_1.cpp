
// babbar yt

// divide and conquer

#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];   // starting element ko lere as pivot  

//now setting array according to pivot element ie pivot ke left sab chote ya barabar and right m sab bade

// phle pivot uski position par lagadte
// pure array m pivot se chote ya barabar ginlete kitne h...usse pata chaljayega pivot kitne elements ke baad aaeyga starting se ie uski position pata chal jaaygei
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }
    //pivot lagadete apni pos par
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    // pivot wala toh apne index par lag gya par left right set nhi h abhi
    //left and right wala part smbhal lete h ie left m saare chote pahucha dete and right m bade
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    // sab set h ab, pivot index return krdo

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partition karenge by pivot element 
    int pindex = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, pindex-1);

    //right wala part sort karo
    quickSort(arr, pindex+1, e);


    return;
}

int main() {

    int arr[10] = {2,4,1,6,9,9,9,9,9,9};
    int n = 10;
    int s=0;
    int e=n-1;

    quickSort(arr, s, e);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}

// avg case,best case tc o(nlogn)
// worst case tc o(n^2)
// worst sc o(n)
// best avg sc o(logn)

// is this inplace? yes  Since all operations (partitioning and swapping) are performed within the original array without needing significant additional space, the quick sort algorithm is considered in-place. The only extra space used is for the recursion stack, which, as discussed, has a space complexity of O(log(n)) on average and in the best case, and O(n) in the worst case.

// is this stable? no