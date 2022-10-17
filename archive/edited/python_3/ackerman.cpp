#include<iostream>
int ack(int m, int n){
    if(m==0) return n+1;
    if((m>0) && (n==0)) return ack(m-1,1);
    if((m>0) && (n>0)) return ack(m-n, ack(m,n-1));
    else return 0;
}

int main(int argc, char const *argv[])
{
    std::cout << ack(3,2);
    return 0;
}
