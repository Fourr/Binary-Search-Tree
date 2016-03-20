#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"nineth.h"



node *root = NULL;

node *createNode (int n)
{
	node *bust = (node *)malloc(sizeof(node) );
	bust->num =n;
	bust->left = NULL;
	bust->right =NULL;
	bust->height =1;
	return bust;
}
void changeHeight(node *ptr, int height)
{

if(ptr==NULL)
{
//printf("test\n");
return;
}
height++;
//ptr->height=height;
ptr->height = height;
changeHeight(ptr->left, height);
changeHeight(ptr->right, height);

return;
}

void delete(int n)

{

  node *y = NULL;
  node *ptr = root;
  node *p = NULL;
                                                                                                            
  while( ptr!=NULL)
    {
      if(ptr->num == n)
	{
	  break;
	}
      p=ptr;

      if( ptr->num > n)

	{
	  ptr = ptr->left;

	}

      else
	{
	  ptr = ptr->right;
	}
    }

  if( ptr == NULL)
    {
      printf("fail\n");
      return;
    }

  if( ptr->left !=NULL && ptr->right != NULL)
    {
      node *y = ptr->right;
      p = ptr;
      
	while(y->left !=NULL)
	{
	  p=y;
	  y=y->left;
	}
      ptr->num = y->num;
      ptr->height = y->height;
      ptr =y;
    }

  if(p ==NULL)
    {
      if(ptr->right != NULL)
	{
	  root = ptr->right;
	}
      else
	{
	  root = ptr->left;
	}
	printf("success\n");
//	printf("sucess %d\n", root->height);
      return;
    }
  if(ptr==p->left)
    {
      if(ptr->right !=NULL)
	{
	  p->left = ptr->right;
	}
      else
	{
	  p->left = ptr->left;
	}
    }

  else
    {
      if(ptr->right !=NULL)
	{
	  p->right = ptr->right;
	}

      else
	{
	  p->right = ptr->left;


	  p->height = ptr->height;
	  ptr= NULL;
	 // printf("%d", p->height);
	}
    }
 // printf("%d ", ptr->height);
  printf("success\n");
  return;

}


void search(node *trav,int n)
{// printf("In search");
	node *buster = root;
	if(trav == NULL)
	{	printf("absent\n");	
		return;
	}
	if(n == trav->num)
	{	

		//printf("[%d]Present %d\n",trav->num, trav->height);
		changeHeight(buster,0);
		printf("present %d\n", trav->height);
		return;
	}
	if(trav-> left==NULL  && trav->right==NULL)
	{
	printf("absent\n");
	return;
	}

	if(n < trav->num)
	{
		search(trav->left,n);
		return; 

	}	
	if(n> trav->num)
	{
		search(trav->right,n);
		return;
	}

}

void insert(node *ptr, node *trav)
{	
	if(root == NULL){
		root = ptr;

		//printf("Inserted [%d] Height [%d]\n", root->num, root->height);
		printf("inserted %d\n", root->height);
		return;	
	}

	if(trav->right == NULL && trav->left == NULL)
	{ 
		if(ptr->num >=  trav->num)
		{
			ptr->height++;
			if( trav->num == ptr->num)
			{
				//printf("[%d] Duplicate\n", ptr->num);
				printf("duplicate\n");
				return;
			}

			trav->right = ptr;
			
			//printf("Inserted [%d] Height [%d]\n", ptr->num, ptr->height);
			printf("inserted %d\n", ptr->height);
			return;
		}
		if( ptr->num <= trav->num)
		{
			ptr->height++;
			if( trav->num == ptr->num)
			{
		//		printf("[%d] Duplicate\n",ptr->num);
				printf("duplicate\n");
				return;
			}

			trav->left = ptr;
			printf("inserted %d\n", ptr->height);
	//		printf("Inserted [%d] Height [%d]\n", ptr->num, ptr->height);
			return;	
		}
		return;
	}

	if(ptr->num >= trav->num)
	{
		ptr->height++;
		if(trav->right == NULL)
		{
			if( trav->num == ptr->num)
			{
				printf("duplicate\n");
				//printf("[%d] Duplicate\n",ptr->num);
				return;
			}

			trav->right = ptr;
			printf("inserted %d\n", ptr->height);
			//printf("Inserted [%d] Height [%d]\n", ptr->num, ptr->height);
			return;
		}
		if(trav->num == ptr->num)
			{
			printf("duplicate\n");
	//		printf("[%d] duplicate\n", ptr->num);
			return;
			}
		insert (ptr, trav->right);
		return;
	} 
	if(ptr-> num <=  trav->num)
	{
		if(trav->num == ptr->num)
		{
		printf("duplicate\n");
	//	printf("[d] Duplicate\n", ptr->num);
		return;
		}
		ptr->height++;
		if(trav->left ==NULL)

		{
			if( trav->num == ptr->num)
			{
				printf("duplicate\n");
				//printf("[%d] Duplicate\n", ptr->num);
				return;
			}
			trav->left = ptr;
			printf("inserted %d\n", ptr->height);
			//printf("Inserted [%d] Height [%d]\n", ptr->num, ptr->height);
			return;
		}
		insert(ptr, trav->left);
		return;
	}

	return;


}


int main(int argc, char** argv)

{

	FILE *fp;

	char data[1024];

	fp = fopen(argv[1], "r");

	int i;
	int q=5;
	int n;

	node *ptr;



	if (fp == NULL)

	{

		printf("error\n");

		return -1;

	} else {
		do{


			i = fscanf(fp, "%s",data );
			if (i == -1)
			{
				break;
			}

			if(strcmp(data, "i") !=0 && strcmp(data, "s")!=0 && strcmp(data, "d") !=0)
			{

				//	printf("%s", data);
				printf("error\n");
				fscanf(fp, "%s", data);
			}
			if (strcmp(data, "i") == 0)
			{

				fscanf(fp,"%s", data);
				n = atoi(data);
				if(isdigit(n) != -1)
				{
					ptr = createNode(n);

					node *trav = root; 
					insert(ptr,trav);
				}



				else
				{
					printf("error\n");
					return 0;
				}

			}


			if (strcmp(data,"s") ==0)
			{	
				fscanf(fp,"%s",data);
				n = atoi(data);
				if(isdigit(n) != -1){
			
					node *test =root;
					search(test,n);

				}
				else{
					//  printf("Absent\n");
					return 0;
				}
			}
			if (strcmp(data,"d") ==0)
			{	
				fscanf(fp,"%s",data);
				n = atoi(data);
				if(isdigit(n) != -1){
				node * buster=root;
					changeHeight(buster,0);
					//node *test =root;
					delete(n);

				}
				else{
					//  printf("Absent\n");
					return 0;
				}
			}




		}while(i!=EOF);


	}
	return 0;
} 
