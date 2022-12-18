#include <iostream>
using namespace std;

int mat[9][9];

int check_row(int row,int n)
{
    int check=0;
    for(int col=0;col<9;col++)
    {
        if(mat[row][col]==n)
        {
            check=1;
            break;
        }
    }
    return check;
}

int check_col(int col,int n)
{
    int check=0;
    for(int row=0;row<9;row++)
    {
        if(mat[row][col]==n)
        {
            check=1;
            break;
        }
    }
    return check;
}

int check_box(int row,int col,int n)
{
    int check=0;
    int a=row/3;
    int b=col/3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[a*3+i][b*3+j]==n)
            {
                check=1;
                break;
            }
        }
    }
    return check;
} 

int check_solved()
{
    int check=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(mat[i][j]==0)
            {
                check=1;
                break;
            }
        }
    }
    return check;
}

void print()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void colsolve()
{
        int xxx=0;
    while(xxx!=1)
    {
        xxx=1;
        for(int j=0;j<9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                int counttt=0;
                int xx=0;
                if(check_col(j,k)==0)
                {
                    for(int i=0;i<9;i++)
                    {
                        if(mat[i][j]==0)
                        {
                            if(check_row(i,k)==0 && check_box(i,j,k)==0)
                            {
                                counttt++;
                                xx=i;
                            }
                        }
                    }
                }
                if(counttt==1)
                {
                    mat[xx][j]=k;
                    xxx=0;
                }
            }
        }
    }
}

void boxsolve()
{
    int aaa=0;
    while(aaa!=1)
    {
        aaa=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=1;k<=9;k++)
                {
                    int countt=0;
                    int zy=0;
                    int zx=0;
                    if(check_box(i*3,j*3,k)==0)
                    {
                        for(int a=0;a<3;a++)
                        {
                            for(int b=0;b<3;b++)
                            {
                                if(mat[a+3*i][b+3*j]==0)
                                {
                                    if(check_row(a+3*i,k)==0 && check_col(b+3*j,k)==0)
                                    {
                                        countt++;
                                        zx=a+3*i;
                                        zy=b+3*j;
                                    }
                                }
                            }
                        }
                    }
                    if(countt==1)
                    {
                        mat[zx][zy]=k;
                        aaa=0;
                    }
                }
            }
        }
    }
}

int main()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>mat[i][j];
        }
    }
    int final=0;
    int zzz=0;
    while(zzz!=1)
    {
        zzz=1;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]==0)
                {
                    int count=0;
                    int z;
                    for(int k=1;k<=9;k++)
                    {
                        if(check_row(i,k)==0&&check_col(j,k)==0&&check_box(i,j,k)==0)
                        {
                            count++;
                            z=k;
                        }
                    }
                    if(count==1)
                    {
                        mat[i][j]=z;
                        zzz=0;
                    }
                }
            }
        }
    }

    int yyy=0;
    while(final!=1)
    {
        yyy=1;
        for(int i=0;i<9;i++)
        {
            for(int k=1;k<=9;k++)
            {
                int countt=0;
                int yy=0;
                if(check_row(i,k)==0)
                {
                    for(int j=0;j<9;j++)
                    {
                        if(mat[i][j]==0)
                        {
                            if(check_col(j,k)==0 && check_box(i,j,k)==0)
                            {
                                countt++;
                                yy=j;
                            }
                        }
                    }
                }
                if(countt==1)
                {
                    mat[i][yy]=k;
                    yyy=0;
                }
            }
        }
        if(yyy==0)
        {
            boxsolve();
            colsolve();
        }
        if(check_solved()==0)
        {
            final=1;
        }
    }
    print();
    return 0;
}
