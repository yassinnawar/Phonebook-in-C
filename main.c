#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>

void load (void);
void menu (void);
void add (void);

void edit (void);
void edit_onecontact(int );

void print (void);
void print_one_contact(int );

void search_menu(void);
void search_by_firstname (void);
void search_by_lastname (void);
void search_by_email (void);
int search_name(char *, char *);

void save(void);
void save_delete(void);

void continue_or_exit_save(void);
void continue_or_exit(void);

void delete (void);
void delete_contact(int );
int search_full_name( char *, char *,char *, char * );
void swap(char * ,char * );
void swapn (unsigned int *,unsigned int *);

void sort_n(void);
void sort_d(void);

int count;
typedef struct {
    unsigned int day;
    unsigned int month;
    unsigned int year;
} date;
typedef struct {
    char f_name [15];
    char l_name [15];
    date birth_day;
    char address [50];
    char email [35];
    char number [15];

} contact;

contact c[50];



int main()
{
    load();
    menu();
    return 0;
}

//----//

void load()
{

    FILE *f;
    f=fopen("contacts.txt","r");
    printf("\n");
    while (!feof (f))
    {
        fscanf(f,"%[^,],",c[count].f_name);
        fscanf(f,"%[^,],",c[count].l_name);
        fscanf(f,"%u,",&c[count].birth_day.day);
        fscanf(f,"%u,",&c[count].birth_day.month);
        fscanf(f,"%u,",&c[count].birth_day.year);
        fscanf(f,"%[^,],",c[count].address);
        fscanf(f,"%[^,],",c[count].email);
        fscanf(f,"%s\n",c[count].number);
        count++;
    }
    fclose(f);

}

//----//

void menu()
{
    int s;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  Main Menu \t \t \t \t\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t1.Add Contact\t\t    \t2.Search Contact\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3.Delete Contact\t\t4.Edit Contact\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t5.Print Contacts\t\t6.Exit\n");

    printf("Enter Number: ");
    scanf("%d",&s);


    if(s<1||s>7)
    {   printf("\nWrong Input");
        menu();

    }

    else {
        switch(s)
        {
            case 1:
                add();
                break;
            case 2:
                search_menu();
                break;
            case 3:
                delete();
                break;
            case 4:
                edit();
                break;
            case 5:
                print();
                break;
            case 6:
                exit(0);
        }
    }
}

//----//


void print()
{
    int i;

    int s;

    printf("\t\t\t\t\t\t\t\t1.Sort By Name     2.Sort by Date of Birth\n");
    printf("\t\t\t\t\t\t\t\t3.Exit\n");
    printf("Enter Number: ");
    scanf("%d",&s);


    if(s<1||s>3)
    {   printf("\nWrong Input");
        menu();

    }

    else {
        switch(s)
        {
            case 1:
                sort_n();
                break;
            case 2:
                sort_d();
                break;

        }

    for(i=0;i<count;i++)
    {
        printf("Name: %s %s\n",c[i].f_name,c[i].l_name);
        printf("Birthday:%u-%u-%u\n",c[i].birth_day.day,c[i].birth_day.month,c[i].birth_day.year);
        printf("Address:%s \n",c[i].address);
        printf("E-mail:%s\n",c[i].email);
        printf("Mobile Number:%s\n",c[i].number);
        printf("\n");

    }
    printf("Number of contacts =%d\n",i);

    continue_or_exit();
    }}


void print_one_contact(int i)
{
    printf("Name: %s %s\n",c[i].f_name,c[i].l_name);
    printf("Birthday:%u-%u-%u\n",c[i].birth_day.day,c[i].birth_day.month,c[i].birth_day.year);
    printf("Address:%s \n",c[i].address);
    printf("E-mail:%s\n",c[i].email);
    printf("Mobile Number:%s\n",c[i].number);


}

//----//

void add()
{
    int i,m;
    printf("\t\t\t\t\t\t\t\t\t\t\t --Add Contact Menu--");
    printf("Enter Number of Contacts you want to add:");
    scanf("%d",&m);
    for(i=0;i<m;i++)

    {
        printf("Enter First Name:\n");

        if (scanf(" %50[a-zA-Z]", c[count].f_name) == 1) {

        }else{
            printf("Error: Invalid input!");
            search_menu();
        }

        printf("Enter Last Name:\n");

        if (scanf(" %50[a-zA-Z]", c[count].l_name) == 1) {

        }else{
            printf("Error: Invalid input!");
            search_menu();
        }

        printf("Birthday Entry:\n");

        printf("Enter day:");
        scanf("%u",&c[count].birth_day.day);

        printf("Enter Month:");
        scanf("%u",&c[count].birth_day.month);

        printf("Enter Year:");
        scanf("%u",&c[count].birth_day.year);

        printf("Enter Address\n");
        getchar();
        gets(c[count].address);

        printf("Enter Email address\n");
        gets(c[count].email);

        printf("Enter Phone Number\n");
        scanf("%15s",c[count].number);

        count++;
    }

    continue_or_exit_save();
}

//----//

void search_menu()
{

    int s;
    printf("\n\t  \t\t\t\t\t\t\t\t\t\t\t Search Menu \t \t \t \t\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t1.Search By First Name     2.Search by Last Name\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3.Search by email          4.Go back to main menu \n");
    printf("\t\t\t\t\t\t\t\t\t\t\t5.Exit\n");
    printf("Enter Number: ");
    scanf("%d",&s);


    if(s<1||s>6)
    {   printf("\nWrong Input");
        menu();

    }

    else {
        switch(s)
        {
            case 1:
                search_by_firstname ();
                break;
            case 2:
                search_by_lastname ();
                break;
            case 3:
                search_by_email ();
                break;
            case 4:
                menu();
                break;
            case 5:
                exit(0);
                break;

        }
    }
}


void search_by_firstname ()
{
    char ln[15];
    int temp;
    printf("Please Enter First Name: ");
    getchar();
    scanf("%[^\n]",ln);
    int f=0;
    int i;
    for (i=0;i<=count;i++)
    {
        f=search_name(&c[i].f_name[0],&ln[0]);
        { if(f==1)
        {  printf("%s %s found\n",c[i].f_name,c[i].l_name);
            print_one_contact(i);
            temp=1;
        }
        }

    }
    if (temp!=1)
        printf("contact not found");

    continue_or_exit();
}


void search_by_lastname ()
{
    int temp;
    char ln[15];
    printf("Please Enter Last Name: \n");
    getchar();
    scanf("%[^\n]",ln);

    int f;
    int i;
    for (i=0;i<=count;i++)
    {
        f=search_name(&c[i].l_name[0],&ln[0]);
        { if(f==1)
        {    printf("%s %s found\n",c[i].f_name,c[i].l_name);
            print_one_contact(i);
            temp=1;
        }
        }
    }  if (temp!=1)
        printf("contact not found");
    continue_or_exit();
}



int search_name( char *ptr1, char *ptr2 ){
    int i=0,j=0;

    while ((*(ptr1 + i) != '\0')&&(*(ptr2 +j ) != '\0')) {
        if (*(ptr2 +j ) != *(ptr1 +i )) {
            i++;
            j= 0;
        }
        else {
            j++;
            i++;
        }
    }
    if ((*(ptr2 +j ) == '\0')&&(*(ptr1 +i)=='\0'))
        return 1;
    else
        return -1;
}


void search_by_email ()
{
    int temp;
    char ln[35];
    printf("Please Enter Email: \n");
    scanf("%s",ln);

    int f;
    int i;
    for (i=0;i<=count;i++)
    {
        f=search_name(&c[i].email[0],&ln[0]);
        { if(f==1)
        {    printf("%s %s found\n",c[i].f_name,c[i].l_name);
            print_one_contact(i);
            temp=1;
        }
        }
    }  if (temp!=1)
        printf("contact not found");
    continue_or_exit();
}


int search_full_name( char *ptr1, char *ptr2,char *ptr3, char *ptr4 ){
    int i=0,j=0;
    int k=0,m=0;

    while ((*(ptr1 + i) != '\0')&&(*(ptr2 +j ) != '\0')) {
        if (*(ptr2 +j ) != *(ptr1 +i )) {
            j++;
            i=0;
        }
        else {
            j++;
            i++;
        }
    }

    while ((*(ptr3 + k) != '\0')&&(*(ptr4 +m ) != '\0'))
    {
        if (*(ptr4 +m ) != *(ptr3 +k )) {
            m++;
            k=0;
        }
        else {
            k++;
            m++;
        }
    }
    if ((*(ptr2 +j ) == '\0')&&(*(ptr1 +i)=='\0')&&((*(ptr4 +m ) == '\0')&&(*(ptr3 +k)=='\0')))
        return 1;
    else
        return -1;


}

//----//

void continue_or_exit_save()
{   int s;
    printf("\t\t\t\t\t\t\t\t\t\t\t1.Save and continue   2.Save and Exit\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3.Discard / Main Menu 4.Exit Without Saving   \n");
    printf("Enter Number: ");
    scanf("%d",&s);


    if(s<1||s>3)
    {   printf("\nWrong Input");
        menu();

    }

    else
    {
        switch(s)
        {
            case 1:
                save();
                menu();
                break;
            case 2:
                save();
                exit(0);
                break;
            case 3:
                menu();
            case 4:
                exit(0);
        }
    }

}


void continue_or_exit()
{
    int s;
    printf("\t\t\t\t\t\t\t\t\t\t\t1.Go to Main Menu  2.Exit\n");
    printf("Enter Number: ");
    scanf("%d",&s);

    if(s<1||s>2)
    {
        printf("\nWrong Input");
        menu();
    }
    else
    {
        switch(s)
        {
            case 1:
                menu();
                break;
            case 2:
                exit(0);
                break;

        }
    }
}

//----//

void edit()
{
    char temp;
    char ln[15];
    printf("Please Enter Last Name: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",ln);
    int m;
    int t=0;
    int f;
    int i;
    for (i=0;i<=count;i++)
    {
        f=search_name(&c[i].l_name[0],&ln[0]);
        { if(f==1)
        {   t=1;
            printf("%s %s found\n",c[i].f_name,c[i].l_name);
            printf("1. Continue Searching   2.Edit Contact\n");
            scanf("%d",&m);
            switch(m)
            {
                case 1:
                    i=i;
                    break;

                case 2:
                    edit_onecontact(i);
                    break;
            }
        }}
    }

    if (t!=1)
        printf("Contact not found");



    continue_or_exit_save();


}
void edit_onecontact(int k)
{

    print_one_contact(k);
    printf("Enter New First Name:\n");
    getchar();
    gets(c[k].f_name);

    printf("Enter New Last Name:\n");

    gets(c[k].l_name);

    printf("Birthday Entry:\n");

    printf("Enter day:");
    scanf("%u",&c[k].birth_day.day);

    printf("Enter Month:");
    scanf("%u",&c[k].birth_day.month);

    printf("Enter Year:");
    scanf("%u",&c[k].birth_day.year);

    printf("Enter New Address\n");
    getchar();
    gets(c[k].address);

    printf("Enter New Email address\n");
    gets(c[k].email);

    printf("Enter New Phone Number\n");
    scanf("%15s",c[k].number);



    continue_or_exit_save();



}

//----//

void delete()
{


    char ln[15];
    printf("Please Enter First Name: ");
    char temp;
    getchar();
    gets(ln);

    char fn[15];
    printf("Please Enter Last Name: ");
    gets(fn);
    int m;
    int f=0;
    int i;
    for (i=0;i<=count;i++)
    {
        f=search_full_name(&c[i].f_name[0],&ln[0],&c[i].l_name[0],&fn[0]);
        { if(f==1)
        {  printf("%s %s found\n",c[i].f_name,c[i].l_name);
            print_one_contact(i);
            printf("1. Continue Searching   2.delete Contact\n");
            scanf("%d",&m);
            switch(m)
            {
                case 1:
                    i==i;
                    break;

                case 2:
                    delete_contact(i);
                    break;

            }
        }
        }

        if (f==0)
            printf("No Contacts Found");}

    continue_or_exit_save();
}


void delete_contact(int m)
{
    int a;



    for (;m<=count;m++)
    {

        for(a=0;a<15;a++)
        {
            swap(&c[m].f_name[a],&c[m+1].f_name[a]);
            swap(&c[m].l_name[a],&c[m+1].l_name[a]);

        }

        for(a=0;a<50;a++)
        {
            swap(&c[m].address[a],&c[m+1].address[a]);
        }
        for(a=0;a<35;a++)
        {
            swap(&c[m].email[a],&c[m+1].email[a]);
        }

        for(a=0;a<15;a++)
        {
            swap(&c[m].number[a],&c[m+1].number[a]);
        }
        swapn(&c[m].birth_day.day,&c[m+1].birth_day.day);
        swapn(&c[m].birth_day.month,&c[m+1].birth_day.month);
        swapn(&c[m].birth_day.year,&c[m+1].birth_day.year);



    }
    printf("Contact Deleted\n");
    save_delete();
    count=count-1;
    menu();
}


void swap (char *x, char *y)
{
    *x=*y;
}
void swapn (unsigned int *x, unsigned int *y)
{
    *x=*y;
}

//----//

void save()
{
    FILE*f;
    f=fopen("contacts.txt","w");
    int i;
    for(i=0;i<count;i++)
    {

        fprintf(f,"%s,",c[i].f_name);
        fprintf(f,"%s,",c[i].l_name);
        fprintf(f,"%u,",c[i].birth_day.day);
        fprintf(f,"%u,",c[i].birth_day.month);
        fprintf(f,"%u,",c[i].birth_day.year);
        fprintf(f,"%s,",c[i].address);
        fprintf(f,"%s,",c[i].email);
        fprintf(f,"%s\n",c[i].number);
    }
    fclose(f);



}


void save_delete()
{
    FILE*f;
    f=fopen("contacts.txt","w");
    int i;
    for(i=0;i<count-1;i++)
    {

        fprintf(f,"%s,",c[i].f_name);
        fprintf(f,"%s,",c[i].l_name);
        fprintf(f,"%u,",c[i].birth_day.day);
        fprintf(f,"%u,",c[i].birth_day.month);
        fprintf(f,"%u,",c[i].birth_day.year);
        fprintf(f,"%s,",c[i].address);
        fprintf(f,"%s,",c[i].email);
        fprintf(f,"%s\n",c[i].number);
    }
    fclose(f);



}

//----//


/*void vaildalph(char *ptr){
    int i;
    int alphabet = 0, number = 0,;

    for (i=0; *(ptr+i)!= '\0'; i++) {
        if (isalpha(*ptr+i) != 0)
        {
            alphabet++;
            i++;
        }
            else if (isdigit(*(ptr+i)) != 0)
            {  number++;
                menu();
            }

    }}
*/



void sort_n()
{
    int pass,x;
    contact temp;
    for (pass=1; pass<count; pass++)
    {
        for(x=0; x<count-1; x++)
        {
            if (strcmp(c[x].l_name,c[x+1].l_name)>0)
            {
                temp=c[x];

                c[x]=c[x+1];

                c[x+1]=temp;

            }
            else if(strcmp(c[x].l_name,c[x+1].l_name)==0)
            {
                if (strcmp(c[x].f_name,c[x+1].f_name)>0)
                {
                    temp=c[x];
                    c[x]=c[x+1];
                    c[x+1]=temp;
                }
                else if (strcmp(c[x].f_name,c[x+1].f_name)==0)
                {
                    if(atoi(c[x].number)>atoi(c[x+1].number))
                    {
                        temp=c[x];
                        c[x]=c[x+1];
                        c[x+1]=temp;
                    }
                    }
            }}}}



void sort_d()
{
    int pass,x;
    contact temp;
    for (pass=1; pass<=count; pass++)
    {
        for(x=0; x<count-1; x++)
        {
            if (c[x].birth_day.year>c[x+1].birth_day.year)
            {
                temp=c[x];

                c[x]=c[x+1];

                c[x+1]=temp;

            }
            else if(c[x].birth_day.year==c[x+1].birth_day.year)
            {
                if(c[x].birth_day.month>c[x+1].birth_day.month)
                {
                    temp=c[x];
                    c[x]=c[x+1];
                    c[x+1]=temp;
                }
                else if (c[x].birth_day.month==c[x+1].birth_day.month)
                {
                    if(c[x].birth_day.day>c[x+1].birth_day.day)
                    {
                        temp=c[x];
                        c[x]=c[x+1];
                        c[x+1]=temp;
                    }
                }
                }}}}
