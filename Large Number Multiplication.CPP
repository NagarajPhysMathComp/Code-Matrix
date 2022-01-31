                           //Code to multiply any two indefinitely large numbers 

#include<stdio.h>
#include<conio.h>

main()
{
int i,j,m,n,count1,count2,a[100],b[100],c[100][200],d[200],carry;
 clrscr();

    printf("Enter 2 numbers to find their product.\n");

    printf("How many digits in the first number? m=");
    scanf("%d",&m);
     printf("\nEnter the first number:\n");
     for(i=1;i<=m;i++)
      scanf("%1d",&a[i]);

    printf("\nHow many digits in the second number? n=");
      scanf("%d",&n);
    printf("\nEnter the second number:\n");

      for(i=1;i<=n;i++)
      scanf("%1d",&b[i]);  printf("\n");


		     //Code for the C-Matrix
    
     count1=0;  //used in shifting the non-trivial elements one column to the left in each subsequent row

       for(i=1;i<=n;i++)
       {   count2=0;

	 for(j=1;j<=m+n-1;j++)
	 {
	  if(j>=n-count1 && count2<m)
	  {
	   c[i][j]=a[count2+1]*b[n+1-i];  //non-trivial elements in the C-matrix
	   count2+=1;   //counts the number of non-trivial elements in any given row
	  }
	  else
	  c[i][j]=0; //trivial zeros
	 } //end j-loop
	   count1+=1;
       }   //end i-loop

		   //Code for the D-Matrix part 1

	for(i=m+n-1;i>=1;i--)
	{  d[i]=0;
	 for(j=1;j<=n;j++)
	 d[i]+=c[j][i];
	}
		  //Code for the D-Matrix part 2

	 for(i=m+n-1;i>=1;i--)
	 {
	   if(i==m+n-1) //last element of the D-array
	   {
	    carry=d[i]/10;
	    d[i]=d[i]%10;
	   }
	   else if(i>1)
	   {
	    d[i]+=carry;
	    carry=d[i]/10;
	    d[i]=d[i]%10;
	   }
	   else
	    d[i]=d[i]+carry; //first element of the D-array 
	 }

	   printf("\n");
	    for(i=1;i<=m;i++)
	    printf("%d",a[i]); //First number
	     printf(" X ");
	    for(i=1;i<=n;i++)
	    printf("%d",b[i]); //Second number
	     printf(" = ");

	     for(i=1;i<=m+n-1;i++)
	      printf("%d",d[i]);

 getch();
 return 0;
 }

