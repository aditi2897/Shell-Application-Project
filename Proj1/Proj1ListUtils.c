#include "csapp.h"
#include "Proj1.h"
static struct program *last_node( struct program *list )
{
while( list->next != NULL ) {
list = list->next;
}
return list;
}

	
static void append_node( struct program *list, struct program *node )
{
struct program *where = last_node( list );
node->next = NULL; /*The added node will be at the end of the list.*/
where->next = node;
}
void append_program_name( struct program *list, char *name )
{
int len = strlen(name);
char *string = Malloc( len + 1 ); /*strlen does NOT count the '\0' terminator!*/
struct program *node = Malloc( sizeof( struct program ) );
strcpy( string, name );
/*incrementing by Adding a program in according to the popularity*/
while(list->next != NULL)
{
	list=list->next;
	if(strstr(list->filename,name)>0)
	{
	list->n_times_used=list->n_times_used+1;
	return;
	}
	
	
	
}

node->n_times_used = 1; /* We are using it the first time.*/
node->filename = string;
append_node( list, node );
}
struct program *find_nth_node( struct program *list, int n )
{
while( n > 0 && list != NULL ) {
list = list->next;
n = n - 1;
}
return list;
}
void print_list(struct program *list){
/////////////////////////////////
int n = 0,i=0,j=0,temp=0,k=0,v;
struct program *list1,*list2,*list3;
char temp1[50];
list1=list;
list2=list;
///counting the no of elements
while( list1->next != NULL )
{
 	n++;
	list1 = list1->next;
}
/*code for insertion and deletion depending on the popularity rearrenging*/
for(i=0;i<n-1;i++)
{ 
	while(list->next!=NULL)
	{
	 	list=list->next;
	 	v=list->n_times_used;
	 	list3=list;
	 	for(j=i+1;j<n;j++)
		{
			while(list3->next!=NULL)
			{
				list3=list3->next;
				if(v<list3->n_times_used)
        			{
        				//swapping the numbers 
        				temp=v;
        				list->n_times_used=list3->n_times_used;
        				list3->n_times_used=temp;
        				//swapping the filenames according to he number of times it used!!!
        				strcpy(temp1,list->filename);
        				strcpy(list->filename,list3->filename);
        				strcpy(list3->filename,temp1);
        			}
        		}
        	}
        }
 }	
///Priinting the list
while( list2->next != NULL )
{

	k = k + 1;
	list2 = list2->next;
	printf("%d %s (Used %d times.)\n",
	k, list2->filename, list2->n_times_used);
}

}