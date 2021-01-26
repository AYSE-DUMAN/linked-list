#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list *create_list(struct list pl);
void insert(struct list *pl, struct student std);
void append(struct list *pl, struct student std);
void remove(struct list *pl, struct student std);
int length(struct list *pl);
void display(struct list *pl);
struct student *atEnd(struct list *pl);




  struct list
  {
  	struct student *list;
  	
  };
  
  struct student
  {
  	int std_no;
  	char name[30];
  	char dept[30];
  	struct student *next_student;
  };
  
  struct list *create_list(struct list *pl)
  {
  	
  	pl=(struct list *)malloc(sizeof(struct list));
  	pl->list=0;
  	return pl;
  	
  }
  
  struct student *create_student(int std_no, char name[], char dept[]) {
  	printf("%s %s\n", name, dept);
  	struct student *std = (struct student *)malloc(sizeof(struct student));
  	std->std_no = std_no;
  	strcpy(std->name, name);
  	strcpy(std->dept, dept);
  	return std;
}

int does_exist(struct list *pl, struct student *std) {
	int student_number = std->std_no;
	struct student *curr = pl->list;
	while(curr) {
		if (curr->std_no == student_number) return true;
		curr = curr->next_student;
	}
	return false;
}
  
  void add_student(struct list *pl, struct student *std)
  {
	if (pl->list == 0) {
		printf("hey1");
		pl->list = std;
		return;
	} else if (does_exist(pl, std)) {
		printf("hey2");
		return;
	} else if (pl->list->std_no > std->std_no) {
		printf("hey3");
		std->next_student = pl->list;
		pl->list = std;
		return;
	} else if (atEnd(pl)->std_no < std->std_no) {
		printf("hey4");
		atEnd(pl)->next_student = std;
		std->next_student = 0;
		return;
	} else {
		printf("hey5");
		struct student *prv, *pt = pl->list;
		for (prv = pt, pt = pt->next_student; pt != 0; prv = pt, pt = pt->next_student) {
			if (std->std_no > prv->std_no && std->std_no < pt->std_no) {
				prv->next_student = std;
				std->next_student = pt;
				return;
			}
		}
		return;
	}
	
}
  
  struct student *atEnd(struct list *pl)
  {
  	struct student *curr;
  	curr=pl->list;
  	while(curr->next_student)
  	 {
  	 	curr=curr->next_student;	
		} 
    return curr;
	}
  
void remove_student(struct list *pl, int std_no)
  {
  	struct student *prv,*pt=pl->list;
  	
  	if (pt && pt->std_no == std_no) 
	{
  		pl->list = pt->next_student;
  		free(pt);
  		return;
	}
	
	for (prv = pt, pt = pt->next_student; (pt) && (pt->std_no != std_no); prv = pt, pt = pt->next_student); {
		if ( (pt) && (pt->std_no == std_no)) {
			prv->next_student = pt->next_student;
			free(pt);
			return;
		}
	}
}

int length(struct list *pl) {
	int i = 0;
	struct student *pt = pl->list;
	while(pt) {
	pt = pt->next_student; i++; 
	}
	return i;
}

void display(struct list *pl)
{
	struct student *pt = pl->list;
	while(pt) {
		printf("No: %d Name: %s Department : %s\n", pt->std_no, pt->name, pt->dept);
		pt = pt->next_student;
	}	
}  
  
  
int main()
{
	struct list *student_list = create_list(student_list);
	add_student(student_list, create_student(3, "Yeliz Gok", "Mathematics"));
	add_student(student_list, create_student(1, "Ahmet Demir", "Civil Engineering"));
	/*add_student(student_list, create_student(5, "Tugrul Karabulut", "Mathematical Engineering"));
	add_student(student_list, create_student(19, "Ayse Duman", "Statistics"));
	add_student(student_list, create_student(21, "Fatma Kus", "Architecture"));*/
	display(student_list);
	return 0;
}
  
  
  
  
  
  
  
