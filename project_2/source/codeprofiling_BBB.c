#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
 
double time_diff(struct timeval x , struct timeval y);
int8_t my_memzero(uint8_t * src,uint32_t length);
int8_t my_memmove(uint8_t * src,uint8_t *dst,uint32_t length);

 
int main()
{  
	int i;
	
	struct timeval before , after;
	gettimeofday(&before , NULL);
  	
	uint8_t arr1[300]={'0'};
 	uint8_t arr2[300]={'\0'};
	 my_memmove(arr1,arr2,300);
	gettimeofday(&after , NULL);

	printf("\nTotal time elapsed for MY_MEMMOVE[300 bytes]: %.0lf us\n" , time_diff(before , after) ); 
  
	return 0;
}

double time_diff(struct timeval x , struct timeval y)
{
	double x_ms , y_ms , diff;
	
	x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
	y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;
	
	diff = (double)y_ms - (double)x_ms;
	
	return diff;
}

int8_t my_memmove(uint8_t * src,uint8_t *dst,uint32_t length)
{
 uint8_t i=0;
 if((dst<src)||(dst>src+(length-1))) //checking for memory overlap
 {
   for(i=0;i<length;i++)
   {
     *(dst+i)=*(src+i); //moving data from source to destination
   }
   return 1;
 }
 else
 {
   printf("error:mem move not possible \n");//error if memory overlaps 
   return 0;
 }
}




int8_t my_memzero(uint8_t * src,uint32_t length)
{
 uint32_t i;
 uint32_t check=0;
 for(i=0;i<length;i++)//fills zeros to src memory positions
  {
	*(src+i)=0;
  }
 for(i=0;i<length;i++)//checks if memory space is zero-ed out
  {
    if(*src==0)
      {
        check++;
      }
   }
 if(check==length)
  {
 	return 1;
  }
 else
  {
      printf("error:move failed");//error in case of  discrepancy
      return 0;
  }
}


my_malloc

int8_t my_reverse(uint8_t * src, uint32_t length)
{
 uint8_t *start;
 uint8_t *stop;
 char a;
 start=src;
 src += length-1;
 stop=src;
 src= src-length+1;
printf("\n");
 while(start<=stop)//reverses bytes using temporary pointer
  {
	 a=*start;
         *start=*stop;
         *stop=a;
         start++;
         stop--;
  }
return 0;
}
