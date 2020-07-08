/* Given a value N, total sum you have. You have to make change for Rs. N, 
and there is infinite supply of each of the denominations in Indian currency, i.e., 
you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, 
Find the minimum number of coins and/or notes needed to make the change for Rs N. */

int a[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

void minCoins(int n){
    if(n==0){
        cout << "0" << endl;
        return;
    }
    int i=0,temp;
    while(n>1){
        temp=n/a[i];
        n=n%a[i];
        while(temp>0){
            temp-=1;
            cout << a[i] << " ";
        }
        i++;
    }
    if(n==1)
        cout << 1 << endl;
    else
        cout << endl;
}
