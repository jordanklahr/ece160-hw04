#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major_school;
  char *year;
  int filled;
} Student;

void print_student(Mode m, Student s) 
{
	switch (m) 
	{
		case NAME_ONLY:
			printf("%s %s\n", s.first_name, s.last_name);
			break;
		case MAJOR_AND_NAME:
			printf("%s %s %s\n", s.major_school, s.first_name, s.last_name);
			break;
		case YEAR_AND_NAME:
			printf("%s %s %s\n", s.year, s.first_name, s.last_name);
			break;
		case YEARS_LEFT_AND_NAME:
			printf("%d %s %s\n", (atoi(s.year) - 2017),  s.first_name, s.last_name);
			break;	
	}
}




int main(int argc, char **argv)
{
	Student s[256];
	char *filename = argv[1];
	FILE *fp;
	fp = fopen(filename, "r");
	char *buffer = malloc(256);
	char buf[256];
	if(fp == NULL)
	{
		printf("Could not open %s\n", filename);
		return -1;
	}

	int i,j=0;
	while(fgets(buffer, 255, fp))
	{	
		i = 0;
		char *input;
		char * pbuf = buffer;
		while(input = strsep(&pbuf," \n"))
		{
			s[j].filled = 1;
			if( i == 0)
			{
				s[j].first_name = malloc(256);
				strcpy(s[j].first_name,input);
			}
			else if(i == 1)
			{
				s[j].last_name = malloc(256);
				strcpy(s[j].last_name,input);
			}
			else if( i == 2)
			{
				s[j].major_school = malloc(256);
				strcpy(s[j].major_school,input);
			}
			else if(i == 3)
			{
				s[j].year = malloc(256);
				strcpy(s[j].year,input);
			}
			i++;		
		}
		j++;
	}
	//free(buffer);
	int temp,sid;
	while(fgets(buf,255,stdin))
	{
		if(sscanf(buf, "%d %d\n", &sid, &temp) == 2)
		{
			Mode m = temp;
			if(s[sid].filled != 1)
			{
				printf("No Such Entry on Given File\n");
			}
			else if(m>3 || m < 0)
				printf("Not a Valid Mode\n");
			else 
				print_student(m,s[sid]);
		}
		else
			printf("Not a Valid Input\n");
	}	
		
		
		
		
}