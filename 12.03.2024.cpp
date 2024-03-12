
class Solution {
  public:
    
    long long mat[3][3], res[3][3]; //Matrices for matrix multiplication
    
    //Function to multiply two matrices res and mat modulo m
    void mul(long long res[3][3], long long mat[3][3], long long m)
    {
        long long res1[3][3]; //Resultant matrix after multiplication
        memset(res1,0,sizeof(res1)); //Initializing the resultant matrix to 0
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    res1[i][j] += (res[i][k]*mat[k][j]);   //Multiplying the matrices
                    res1[i][j] %= m;    //Taking modulo m
                }
            }
        }
        
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                res[i][j]=res1[i][j];   //Updating the result matrix
    }
    
    //Function to calculate matrix exponential of n modulo m
    void mat_exp(long long n, long long m)
    {
        while(n>0)
        {
            if(n&1)
                mul(res, mat, m);   //Multiplying res and mat if n is odd
            mul(mat,mat,m);   //Multiplying mat with itself
            // for odd it is doing res*mat*mat
            // for even it is doing mat*mat
            n /= 2;   //Reducing n by half
        }
    }
    
    //Function to generate the n-th Fibonacci number modulo m
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        
        memset(res,0,sizeof(res));   //Initializing the result matrix to 0
        res[0][0] = res[1][1] = res[2][2] = 1;   //Initializing the result matrix as identity matrix
        mat[0][0] = a;   //Initializing the matrix mat
        mat[0][1] = b;
        mat[0][2] = mat[1][0] = mat[2][2] = 1;
        mat[1][1] = mat[1][2] = mat[2][0] = mat[2][1] = 0;
        if(n<=2)
            return (1%m);   //Returning 1 if n is 1 or 2
        else
        {
            mat_exp(n-2,m);   //Calculating matrix exponential
            return (res[0][0] + res[0][1] + c*res[0][2])%m;   //Returning the n-th Fibonacci number modulo m
        }
    }
};
