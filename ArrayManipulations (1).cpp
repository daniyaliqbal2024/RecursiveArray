#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int total(int values[], int size)
{
		/*for ( int i= 0; i< size; i++)
		{
			sum= sum + values[i];
		}*/
	    if (size == 0 )
	    {
	    	return 0;
	    }
	    else
	    {
	    	return (values[size-1] + total(values, size-1));
	    }

}

double mean(int values[], int size)
{
	/*for (int i= 0; i< size ; i++)
	{
		sum= sum+ values[i];
	}
	m= sum/size;
    return m;*/
	if (size==0)
	{
		return 0;
	}
	else
	{
		return ((values[size-1]+ total(values, size-1))/size);
	}


}

int count(int values[], int size, int find)
{
	/*int c=0;
	for ( int i = 0; i< size; i++)
	{
	  if (values[i]== find)
	  {
		 c= c+1;
	  }

	}

    return c;*/

	if (size == 0)
	{
		return 0;
	}
    int x= 0;
	if (find == values[size-1])
	{
		x= 1;
	}
	return (x + count(values, size-1, find));

}

double median(int values[], int size)
{
	int s;
	double m;
	int k;
	int c;

           sort (values, values + size);
//		   string inputs = "[";
//	       for (int i = 0; i < size; i++)
//	       {
//	           inputs += to_string(values[i]);
//	           if (i < size - 1)
//	           {
//	               inputs += ", ";
//	           }
//	       }
//	       inputs += "]\n";


	        if (size % 2== 1)
	  	       	    		{
	  	       	    	    s= (size + 1)/2;
	  	       	    	    m= values[s-1];
	  	       	    		}
	  	       	    		else if (size % 2 == 0)
	  	       	    		{
	  	       	    		 c= (size+2)/2;
	  	       	    		 k= (size)/2;
	  	       	    		 m= (values[c-1]+ values [k-1])/2.00;
	  	       	    		}


	return m;
}


int largest(int values[], int size)
{
	/*int max= values[0];
	for (int i =1; i<size; i++)
	{
    if (values[i]> max)
    {
    	max= values[i];
    }
	}
	return max;*/

	if (size == 0)
	{
		return 0;
	}
	int max= values[0];
	if (values[size-1]> max)
	{
		max= values[size-1];
	}
	return max;
}

int smallest(int values[], int size)
{
	/*int min= values[0];
	for (int i =1; i<size; i++)
    {
    if (values[i] < min)
    {
    	min= values[i];
    }
	}
	return min;*/
	if (size == 0)
		{
			return 0;
		}
		int min= values[0];
		if (values[size-1]< min)
		{
			min= values[size-1];
		}
		return min;
}

bool tentimesinner (int values[], int size, int pos)
{
if (pos == 0)
	{
		return false;
	}

    if (count(values, size, values[pos]*10)>0 && values[pos]!=0)
     {
    	 return true;
     }
       else
       {
        return (tentimesinner(values, size, pos-1));
       }
}

bool tenTimes(int values[], int size)
{


    /*for (int i= 0; i< size; i++)
    {
    	for (int j=0 ; j< size; j++)
    	{
         if (values[i]!= 0 && values[j]!= 0)
         {
         if (values[i]==(values[j])*10)
          {
           c= c+1;
          }
        }
    	}*/

  return (tentimesinner(values, size, size-1));


}
