// Find the sum of first n natural numbers.



// using Loop
// #include<iostream>
// using namespace std;

// int main(){

// int n;
// cout<<"Enter n: ";
// cin>>n;
// int sum=0;
//     for (int i = 0; i < n; i++)
//     {
//         sum = sum + i;
//         // sum += i;
//     }
//     cout<<sum;
    
//     return 0;
// }



// direct mtd
// #include<iostream>
// using namespace std;

// int sum(int n){
//     return (n*(n+1))/2;
// }

// int main(){
//     cout<<sum(5);
    
//     return 0;
// }



// using Recursion
// #include<iostream>
// using namespace std;

// int sum(int n){
//     if (n == 0)
//     return 0;
//     else
//     return sum(n-1) + n;
// }

// int main(){
//     cout<<sum(5);
    
//     return 0;
// }









// Factorial of a given number

// using Recursion
// #include<iostream>
// using namespace std;

// int mul(int n){
//     if (n==0)
//     return 1;
//     else 
//     return mul(n-1)*n;
// }


// int fact(int n){
//     int o=1;
//     int i;
//     for (i = 1; i <= n; i++)
//     {
//         o=o*i;
//         return o;
//     }
    
// }

// int main(){
//     cout<<mul(4)<<endl;
//     cout<<fact(4);

//     return 0;
// }



// #include <iostream>  
// using namespace std;  
// int main()  
// {

// int n, j=1;
// cout<<"Enter: ";
// cin>>n;

//     for (int i = 1; i <= n; i++)
//     {
//         j = j*i;
//     }

//     cout<<j;
    

//   return 0;  
// }  







// #include<iostream>
// using namespace std;

// int power(int a, int b){
//         if (b == 0)
//         return 1;
//         else
//         return power(a,b-1)*a;
//     }

// int power1(int a, int b){
//     if (b==0)
//     return 1;
//     if (b%2==0)
//     return power1(a*a,b/2);
//     else
//     return a*power1(a*a,(b-1)/2);
// }

// int main(){

//     cout<<power(2,4)<<endl;
//     cout<<power1(2,5);
    
//     return 0;
// }






// Taylor's Series

// #include<iostream>
// using namespace std;

// double e(int x, int n){
//     static double p=1, f=1;
//     double r;
//     if (n==0)
//     return 1;
//     else
//     r = e(x,n-1);
//     p = p*x;
//     f = f*n;
//     return r + (p/f);
// }



// int main(){

//     cout<<e(4,10);
    
//     return 0;
// }




// Taylor series -1

// iterative

// #include<iostream>
// using namespace std;

// int e(int x, int n){
//     int s=1;
//     for (n>0; n--){
//         s = 1 + (x/n)*s;
//     }
//     return s;
// }


// int main(){

//     cout<<e(2,3);
    
//     return 0;
// }


// recursive- Horner's rule

// #include<iostream>
// using namespace std;


// double e(int x, int n)
// {
//     static double s;
//     if(n==0)
//     return s;
//     s=1 + x*s/n;
//     return e(x,n-1);
// }

// int main(){

//     cout<<e(1,10);
    
//     return 0;
// }


// by iterative mtd

// #include<iostream>
// using namespace std;

// double e(int x, int n)
// {
//     double s = 1;
//     double num = 1;
//     double den = 1;
//     int i;
//     for (i = 1; i <= n; i++)
//     {
//         num*=x;
//         den*=i;
//         s+=num/den;
//     }
//     return s;
// }

// int main(){
//     cout<<e(1,10);
    
//     return 0;
// }







// Fibonacci series

// 1. Using Recursion
// #include<iostream>
// using namespace std;

// int fib(int n){
//     if (n <= 1)
//     return n;
//     else
//     return fib(n-2) + fib(n-1);
// }

// int main(){

//     cout<<fib(5);    // 0 1 1 2 3 5 8
    
//     return 0;
// }



// 2. Using Iterative mtd (Loop) 

// #include<iostream>
// using namespace std;


// int fib(int n){
//     int t_0=0, t_1=1, sum=0;
//     if (n <= 1)
//     return n;
//     for (int i = 2; i <= n; i++)       // 0 1 1 2 3 5 8 13
//     {
//         sum = t_0 + t_1; 
//         t_0 = t_1;
//         t_1 = sum;
//     }
//     return sum;
// }

// int main(){

//     cout<<fib(7);
    
//     return 0;
// }





// 3. Memorization  - Superior mtd (Recursion)

// #include<iostream>
// using namespace std;

// int F[10];

// int fib(int n){
//     if (n <= 1){
//     F[n] = n;
//     return n;
//     }

//     else
//     {    
//     if (F[n-2] == -1)
//     F[n-2] = fib(n-2);

//     if (F[n-1] == -1)
//     F[n-1] = fib(n-1);

//     F[n] = F[n-2] + F[n-1];

//     return F[n-2] + F[n-1];
//     }
// }


// int main(){

//     for (int i = 0; i < 10; i++)
//     {
//         F[i] = -1;
//     }
    
    
//     cout<<fib(7);

//     return 0;
// }










// nCr using Recursion


// 1. by using normal mtd

// #include<iostream>
// using namespace std;

// int fact(int n){
//     if(n==0)
//     return 1;
//     else
//     return fact(n-1)*n;
// }

// int nCr(int n, int r){

//     int num, den;

//     num = fact(n);
//     den = fact(r)*fact(n-r);

//     return num/den;
// }


// int main(){

//     cout<<nCr(5,2);
    
//     return 0;
// }





// 2. Using recursive mtd (Pascal's Triangle)

#include<iostream>
using namespace std;

int nCr(int n, int r){
    if(n==r || r==0)
    return 1;
    return nCr(n-1,r-1) + nCr(n-1,r);
}

int main(){
    
    cout<<nCr(5,3);
    return 0;
}
