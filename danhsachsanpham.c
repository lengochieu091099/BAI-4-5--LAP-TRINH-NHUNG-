#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Sanpham
{
    char name[30];
    float prize;
    int so;
};
union Kichco
{
    int size;
    float weight;
};
enum Type {
    Clothing ,
    Footwear ,
    Electronics 
};

int main(int argc, char *argv[]){
    int i,n;
    char tk[100];
    do{
    printf("Enter the number of products: ");
    scanf("%d",&n);}
    while(n<=0);
    struct Sanpham a[n];
    union Kichco kc[n]; 
    for(i=1;i<=n;i++)
	{
		printf("\nEnter information for product %d \n",i);
	    printf("Name :");
	    scanf("%s",&a[i].name);
	    printf("Price :");
        scanf("%f",&a[i].prize);
        printf("Type (0: Clothing, 1: Footwear, 2: Electronics) :");
        scanf("%d",&a[i].so);	
        enum Type loaisanpham = a[i].so ;  
        if(a[i].so==2){
        	printf("Weight :");
    		scanf("%f",&kc[i].weight);
        	}
        else{
        	printf("Size :");
    		scanf("%d",&kc[i].size);
		}
           printf("\n");       
	}
    printf("Enter the name of the product to retrieve information :");
    scanf("%s",&tk);
    for(i = 1;i <= n; ++i){
        if(strcmp(a[i].name,tk)==0){
            printf("Product Information :\n");
	        printf("Name : %s\n",a[i].name);
	        printf("Price: %.2f\n",a[i].prize);
			switch (a[i].so) {
        		case Clothing:
            		printf("Type : Clothing.\n");
            		break;
        		case Footwear:
            		printf("Type : Footwear.\n");
            		break;
        		case Electronics:
           	 		printf("Type : Electronics.\n");
            		break;   	
        }
        if(a[i].so==2){
        	printf("Weight :%.2f",kc[i].weight);
        	}
        else{
        	printf("Size :%d",kc[i].size);
		}	
    }
}
}